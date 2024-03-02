#ifndef DATABASE_H
#define DATABASE_H

void saveAppointment(FILE *Datei, int selectAppointment);

int saveCalendar();

int loadCalendar();

int loadAppointment(FILE *Datei, int selectAppointment);

int loadCalendar();

#endif