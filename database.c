#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"

// Funktion zum Speichern eines Termins in einer Datei
void saveAppointment(FILE* file, Appointment* appointment) {
    fprintf(file, "<Appointment>\n");
    fprintf(file, "  <Date>%s</Date>\n", appointment->date);
    fprintf(file, "  <Time>%s</Time>\n", appointment->time);
    fprintf(file, "  <Description>%s</Description>\n", appointment->description);
    fprintf(file, "  <Location>%s</Location>\n", appointment->location);
    fprintf(file, "  <Duration>%s</Duration>\n", appointment->duration);
    fprintf(file, "</Appointment>\n");
}

// Funktion zum Speichern des Kalenders in einer Datei
void saveCalendar(const char* filename, Calendar* calendar) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei zum Speichern!\n");
        return;
    }

    fprintf(file, "<Calendar>\n");

    for (int i = 0; i < calendar->numAppointments; i++) {
        saveAppointment(file, &(calendar->appointments[i]));
    }

    fprintf(file, "</Calendar>\n");

    fclose(file);
}

// Funktion zum Laden eines Termins aus einer Datei
void loadAppointment(FILE* file, Appointment* appointment) {
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Hier muss der Code implementiert werden, um die Daten zu parsen und im Termin-Struktur zu speichern
        // Beispiel: sscanf(line, "  <Date>%s</Date>", appointment->date);
    }
}

// Funktion zum Laden des Kalenders aus einer Datei
void loadCalendar(const char* filename, Calendar* calendar) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei zum Laden!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "<Appointment>", 13) == 0) {
            Appointment newAppointment; // Annahme: Es gibt eine Struktur "Appointment" für Termine
            loadAppointment(file, &newAppointment);
            // Hier können Sie den neuen Termin zur Liste im Kalender hinzufügen
        }
    }

    fclose(file);
}
