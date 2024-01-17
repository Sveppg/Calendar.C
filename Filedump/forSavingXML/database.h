#ifndef DATABASE_H
#define DATABASE_H

int saveCalendar(const char *filename);
int loadCalendar(const char *filename);
int loadAppointment(FILE *file, sAppointment *appointment);

#endif
