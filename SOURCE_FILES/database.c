#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "calendar.h"

void saveAppointment(FILE *Datei, int selectAppointment){

    fprintf(Datei, "%s" "%s", " <Appointment>", "\n");

    fprintf(Datei, "%s" "%02i.%02i.%04i" "%s" "%s", "  <Date>", Calendar[selectAppointment].Date.Day, Calendar[selectAppointment].Date.Month, Calendar[selectAppointment].Date.Year, "</Date>", "\n");
    fprintf(Datei, "%s" "%02i:%02i" "%s" "%s", "  <Time>", Calendar[selectAppointment].Time.Hour, Calendar[selectAppointment].Time.Minute, "</Time>", "\n");
    if(Calendar[selectAppointment].Duration) fprintf(Datei, "%s" "%02i:%02i:%02i" "%s" "%s", "  <Lenght>", Calendar[selectAppointment].Duration->Hour, Calendar[selectAppointment].Duration->Minute, Calendar[selectAppointment].Duration->Second, "</Lenght>", "\n");
    fprintf(Datei, "%s" "%s" "%s" "%s", "  <Description>", Calendar[selectAppointment].Description, "</Description>", "\n");
    if(Calendar[selectAppointment].Location) fprintf(Datei, "%s" "%s" "%s" "%s", "  <Location>", Calendar[selectAppointment].Location, "</Location>", "\n");

    fprintf(Datei, "%s %s", " </Appointment>", "\n");
}



int saveCalendar(){
    FILE *Datei = NULL;

    Datei = fopen("calendar.xml", "wt");
    if(Datei){
        int i;

        fprintf(Datei, "%s" "%s", "<Calendar>", "\n");
        for(i = 0; i<= countAppointments; i++){
            saveAppointment(Datei, i);
        }
        fprintf(Datei, "%s", "</Calendar>");
        fclose(Datei);
        return 1;
    }
    else{
        return 0;
    }
}


int loadAppointment(FILE *Datei, int selectAppointment){
    char row[101];
    char *ptrRow = row;
    unsigned len;

    do{
        fscanf(Datei, "%100[^\n]", row);
        fclearBuffer(Datei);
        ptrRow = row;
        while((*ptrRow == ' ') || (*ptrRow == 9))
            ptrRow++;

        if(strncmp(ptrRow, "<Date>", 6) == 0){
            len = strlen(ptrRow + 6) - 7;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+6+len, "</Date>", 7) == 0)
                getDateFromString(ptrRow+6, &(Calendar[selectAppointment].Date));
        }

        if(strncmp(ptrRow, "<Time>", 6) == 0){
            len = strlen(ptrRow + 6) - 7;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+6+len, "</Time>", 7) == 0)
                getTimeFromString(ptrRow+6, &(Calendar[selectAppointment].Time));
        }

        if(strncmp(ptrRow, "<Description>", 13) == 0){
            len = strlen(ptrRow + 13) - 14;
            if(len > 1000)
                len = 0;
            Calendar[selectAppointment].Description = calloc(len+1, sizeof(char));
            if(Calendar[selectAppointment].Description != NULL)
                strncpy(Calendar[selectAppointment].Description, ptrRow + 13, len);
            else
                return 0;
        }

        if(strncmp(ptrRow, "<Lenght>", 8) == 0){
            len = strlen(ptrRow + 8) - 9;
            if(len > 1000)
                len = 0;
            if(strncmp(ptrRow+8+len, "</Lenght>", 9) == 0)
                getTimeFromStringLite(ptrRow+8, Calendar[selectAppointment].Duration);
        }

        if(strncmp(ptrRow, "<Location>", 10) == 0){
            len = strlen(ptrRow + 10) - 11;
            if(len > 1000)
                len = 0;
            Calendar[selectAppointment].Location = calloc(len+1, sizeof(char));
            if(Calendar[selectAppointment].Location != NULL)
                strncpy(Calendar[selectAppointment].Location, ptrRow + 10, len);
        }
    }while(strncmp(ptrRow, "</Appointment>", 14));

    return 1;
}


int loadCalendar(){
    char row[101];
    char *ptrRow;
    FILE *Datei = NULL;

    Datei = fopen("calendar.xml", "rt");
    if(Datei){
        do{
            fscanf(Datei, "%100[^\n]", row);
            fclearBuffer(Datei);
            ptrRow = row;

            while((*ptrRow == ' ') || (*ptrRow == 9))
                ptrRow++;
            if (strncmp (ptrRow, "<Appointment>", 13) == 0) {
                if(countAppointments < MAXAPPOINTMENTS){
                    loadAppointment(Datei, countAppointments);
                    countAppointments++;
                }    
            }
            if(feof(Datei))
                break;
        }while(strncmp(ptrRow, "</Calendar>", 11) != 0);

        fclose(Datei);
        return 1;
    }
    else{
        printf("Keine Datenbank gefunden");
        return 0;
    }
}