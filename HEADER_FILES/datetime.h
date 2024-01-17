#ifndef DATETIME_H
    #define DATETIME_H

    int isLeapYear(int Year);

    int isDateValid(sDate *Date);

    int isTimeValid(sTime *Time);

    int calculateWeekDay(sDate *Date);

    int getDateFromString(char *Input, sDate *Date);

    int getTimeFromString(char *Input, sTime *Time);

    void getDate(char prompt[], sDate *Date);

    void getTime(char prompt[], sTime *Time, int Optional);

    void printDate(sAppointment *Appointment);

    void printTime(sAppointment *Appointment);

#endif