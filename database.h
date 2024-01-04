#ifndef DATABASE_H
#define DATABASE_H

#include "calendar.h" // Annahme: Es gibt ein Modul "calendar.h" mit den Strukturen für Kalender und Termine

// Funktion zum Speichern der Daten in einer Datei
void saveCalendar(const char* filename, Calendar* calendar);

// Funktion zum Laden der Daten aus einer Datei
void loadCalendar(const char* filename, Calendar* calendar);

#endif // DATABASE_H
