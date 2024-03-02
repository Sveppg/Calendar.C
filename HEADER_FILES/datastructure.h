#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#define MAXAPPOINTMENTS 100

typedef enum {So, Mo, Di, Mi, Do, Fr, Sa} eDayofTheWeek;

typedef struct{
    int Day;
    int Month;
    int Year;
    eDayofTheWeek WeekDay;
} sDate;

typedef struct{
    int Hour;
    int Minute;
    int Second;
}sTime;

typedef struct{
    sDate Date;
    sTime Time;
    char *Description;
    char *Location;
    sTime *Duration;
}sAppointment;

extern int countAppointments;
extern sAppointment Calendar[MAXAPPOINTMENTS];

#endif