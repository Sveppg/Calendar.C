#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "calendar.h"
#include "datastructure.h"
#include "datetime.h"
#include "database.h"


/*
 Older Version...
void loadAppointment(FILE *Datei)
{
    //printf("START APPOINTMENT\n");
    //printf("countAppintments = %i\n", countAppointments);
    char Zeile[101];
    char *Zeilenanfang;
    do
    {
        fscanf(Datei, "%100[^\n]", Zeile);
        clearBuffer(Datei);
        Zeilenanfang = Zeile;
        while ((*Zeilenanfang == ' ') || (*Zeilenanfang == 9))
            Zeilenanfang++;
        if (strncmp(Zeilenanfang, "<Date>", 6) == 0)
        {
            int len = strlen(Zeilenanfang + 6) - 8;
            if (strncmp(Zeilenanfang + 6 + len, "</Date>", 7) == 0)
            {
                char *Date = calloc(len + 1, sizeof(char));
                if (Date)
                {
                    strncpy(Date, Zeilenanfang + 6, len);
                    if(getDateFromString(Date, &Calendar[countAppointments].Date) == 0)
                    {
                        Calendar[countAppointments].Date.Year = 0;
                        Calendar[countAppointments].Date.Month = 0;
                        Calendar[countAppointments].Date.Day = 0;
                        Calendar[countAppointments].Date.weekDay = 0;
                    }
                    //printf("Date: %s\n", Date);
                    //printDate(&Calendar[countAppointments]);
                    free(Date);
                }
            }

        }
        if (strncmp(Zeilenanfang, "<Time>", 6) == 0)
        {
            int len = strlen(Zeilenanfang + 6) - 8;
            if(strncmp(Zeilenanfang + 6 + len, "</Time>", 7) == 0)
            {
                char *Time = calloc(len + 1, sizeof(char));
                if(Time)
                {
                    strncpy(Time, Zeilenanfang + 6, len);
                    if(getTimeFromString(Time, &Calendar[countAppointments].Time) == 0)
                    {
                        Calendar[countAppointments].Time.Hour = 0;
                        Calendar[countAppointments].Time.Minute = 0;
                        Calendar[countAppointments].Time.Second = 0;
                    }
                    //printf("Time: %s\n", Time);
                    //printTime(&Calendar[countAppointments]);
                    free(Time);
                }
            }

        }
        if (strncmp(Zeilenanfang, "<Description>", 13) == 0)
        {

            int len = strlen(Zeilenanfang + 13) - 15;
            if(strncmp(Zeilenanfang + 13 + len, "</Description>", 15))
            {
                Calendar[countAppointments].Description = calloc(len + 1, sizeof(char));
                if (Calendar[countAppointments].Description)
                    strncpy(Calendar[countAppointments].Description, Zeilenanfang + 13, len);
                //printf("Description: %s\n", Calendar[countAppointments].Description);
            }

        }
        if (strncmp(Zeilenanfang, "<Duration>", 10) == 0)
        {

            int len = strlen(Zeilenanfang + 10) - 12;
            if(strncmp(Zeilenanfang + 10 + len, "</Duration>", 12))
            {
                char *Duration = calloc(len + 1, sizeof(char));
                if(Duration)
                {
                    strncpy(Duration, Zeilenanfang + 10, len);
                    if(getTimeFromString(Duration, &Calendar[countAppointments].Duration ) == 0)
                    {
                        Calendar[countAppointments].Duration.Hour = 0;
                        Calendar[countAppointments].Duration.Minute = 0;
                        Calendar[countAppointments].Duration.Second = 0;
                    }
                    //printf("Duration: %s\n", Duration);
                    //printf("Duration2: %02i:%02i\n", Calendar[countAppointments].Duration.Hour, Calendar[countAppointments].Duration.Minute);
                    free(Duration);
                }
            }
        }
        if (strncmp(Zeilenanfang, "<Location>", 10) == 0)
        {
            int len = strlen(Zeilenanfang + 10) - 12;
            if(strncmp(Zeilenanfang + 10 + len, "</Location>", 12))
            {
                Calendar[countAppointments].Place = calloc(len + 1, sizeof(char));
                if(Calendar[countAppointments].Place)
                    strncpy(Calendar[countAppointments].Place, Zeilenanfang + 10, len);
                //printf("Location: %s\n", Calendar[countAppointments].Place);
            }
        }
        if (feof(Datei))
            break;
    } while (strncmp(Zeilenanfang, "</Appointment>", 14) != 0);
    //printf("END APPOINTMENT\n");
    countAppointments += 1;
}

void loadCalendar(int args, char *argv[])
{
    if (argv[1] == NULL)
    {
        argv[1] = "calendar.xml";
    }
    char Zeile[101];
    char *Zeilenanfang;
    FILE *Datei = fopen(argv[1], "r");
    if (Datei)
    {
        do
        {
            fscanf(Datei, "%100[^\n]", Zeile);
            clearBuffer(Datei);
            Zeilenanfang = Zeile;
            while ((*Zeilenanfang == ' ') || (*Zeilenanfang == 9))
                Zeilenanfang++;
            if (strncmp(Zeilenanfang, "<Appointment>", 13) == 0)
                loadAppointment(Datei);
            if (feof(Datei))
                break;
            //printf("Zeilenanfang: %s\nstrlen(Zeilenanfang): %lu\n", Zeilenanfang, strlen(Zeilenanfang));
        } while (strncmp(Zeilenanfang, "</Calendar>", 11) != 0);
        printf("Calendar geladen!\n");
        fclose(Datei);
    }
    else if (args < 2)
    {
        //usage(argv);
    }
    else
        printf("Datei '%s' konnte nicht geoeffnet werden.\n", argv[1]);
    waitForEnter();
}

void saveCalendar()
{
    if (askYesOrNo("Moechten Sie ihre Termine speichern? "))
    {
        FILE *Datei = fopen("calendar.xml", "w");
        if (Datei == NULL)
            printf("Datei konnte nicht geoeffnet werden.\n");
        else
        {
            int i;
            fprintf(Datei, "<Calendar>\n");
            for (i = 0; i < countAppointments; i++)
            {
                fprintf(Datei, " <Appointment>\n");
                fprintf(Datei, "  <Date>%02i.%02i.%04i</Date>\n", Calendar[i].Date.Day, Calendar[i].Date.Month, Calendar[i].Date.Year);
                fprintf(Datei, "  <Time>%02i:%02i:%02i</Time>\n", Calendar[i].Time.Hour, Calendar[i].Time.Minute, Calendar[i].Time.Second);
                fprintf(Datei, "  <Location>%s</Location>\n", Calendar[i].Place);
                fprintf(Datei, "  <Duration>%02i:%02i:%02i</Duration>\n", Calendar[i].Duration.Hour, Calendar[i].Duration.Minute, Calendar[i].Duration.Second);
                fprintf(Datei, "  <Description>%s</Description>\n", Calendar[i].Description);
                fprintf(Datei, " </Appointment>\n");
            }
            fprintf(Datei, "</Calendar>");
        }
        fclose(Datei);
        printf("Termine gespeichert\n");
    }
}

*/

#define MAX_LINE_LENGTH 256

int saveAppointment(FILE *file, const sAppointment *appointment);
int loadAppointment(FILE *file, sAppointment *appointment);

int saveCalendar(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return 0;
    }

    // Write the XML prolog
    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");

    // Write the start marker for the entire calendar data
    fprintf(file, "<Calendar>\n");

    for (int i = 0; i < countAppointments; i++)
    {
        if (!saveAppointment(file, &Calendar[i]))
        {
            fclose(file);
            return 0;
        }
    }

    // Write the end marker for the entire calendar data
    fprintf(file, "</Calendar>\n");

    fclose(file);
    return 1;
}

int loadCalendar(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return 0;
    }

    char line[MAX_LINE_LENGTH];

    // Read the XML prolog
    fgets(line, MAX_LINE_LENGTH, file);

    // Read the start marker for the entire calendar data
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL || strcmp(line, "<Calendar>\n") != 0)
    {
        fclose(file);
        return 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (strcmp(line, "</Calendar>\n") == 0)
            break; // Reached the end marker

        sAppointment appointment;
        if (loadAppointment(file, &appointment))
        {
            // Add the loaded appointment to the calendar
            Calendar[countAppointments] = appointment;
            countAppointments++;
        }
        else
        {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

int saveAppointment(FILE *file, const sAppointment *appointment)
{
    // Write the start marker for the appointment
    fprintf(file, "\t<Appointment>\n");

    // Write the appointment data
    fprintf(file, "\t\t<Date>%02d.%02d.%04d</Date>\n", appointment->Date.Day, appointment->Date.Month, appointment->Date.Year);
    fprintf(file, "\t\t<Time>%02d:%02d:%02d</Time>\n", appointment->Time.Hour, appointment->Time.Minute, appointment->Time.Second);
    fprintf(file, "\t\t<Description>%s</Description>\n", appointment->Description);
    fprintf(file, "\t\t<Place>%s</Place>\n", appointment->Place);
    fprintf(file, "\t\t<Duration>%02d:%02d:%02d</Duration>\n", appointment->Duration.Hour, appointment->Duration.Minute, appointment->Duration.Second);

    // Write the end marker for the appointment
    fprintf(file, "\t</Appointment>\n");

    return 1;
}

int loadAppointment(FILE *file, sAppointment *appointment)
{
    char line[MAX_LINE_LENGTH];

    // Initialize appointment fields
    appointment->Date = (sDate){0, 0, 0, NotADay};
    appointment->Time = (sTime){0, 0, 0};
    appointment->Description = NULL;
    appointment->Duration = (sTime){0, 0, 0};
    appointment->Place = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        // Check for the end marker
        if (strcmp(line, "\t</Appointment>\n") == 0)
            return 1;

        // Parse each line to extract data
        if (strncmp(line, "\t\t<Date>", 8) == 0)
            sscanf(line, "\t\t<Date>%d.%d.%d</Date>\n", &appointment->Date.Day, &appointment->Date.Month, &appointment->Date.Year);
        else if (strncmp(line, "\t\t<Time>", 8) == 0)
            sscanf(line, "\t\t<Time>%d:%d:%d</Time>\n", &appointment->Time.Hour, &appointment->Time.Minute, &appointment->Time.Second);
        else if (strncmp(line, "\t\t<Description>", 15) == 0)
        {
            // Allocate memory for description
            appointment->Description = malloc(strlen(line) - 29); // Subtracting the length of tags
            sscanf(line, "\t\t<Description>%[^<]</Description>\n", appointment->Description);
        }
        else if (strncmp(line, "\t\t<Place>", 11) == 0)
        {
            // Allocate memory for place
            appointment->Place = malloc(strlen(line) - 21); // Subtracting the length of tags
            sscanf(line, "\t\t<Place>%[^<]</Place>\n", appointment->Place);
        }
        else if (strncmp(line, "\t\t<Duration>", 13) == 0)
            sscanf(line, "\t\t<Duration>%d:%d:%d</Duration>\n", &appointment->Duration.Hour, &appointment->Duration.Minute, &appointment->Duration.Second);
    }

    return 0; // End marker not found
}






















