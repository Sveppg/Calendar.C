#ifndef DATASTRUCTURE_H
    #define DATASTRUCTURE_H

    #define MAXAPPOINTMENTS 100

    typedef enum {NotADay, Mo, Tu, We, Th, Fr, Sa, Su} eDayOfTheWeek;

    typedef struct
    {
        int Day;
        int Month;
        int Year;
        eDayOfTheWeek weekDay;
    } sDate;

    typedef struct
    {
        int Hour;
        int Minute;
        int Second;
    } sTime;
    
    typedef struct
    {
        sDate Date;
        sTime Time;
        char *Description;
        sTime Duration;
        char *Place;
    } sAppointment;

    extern int countAppointments;
    extern sAppointment Calendar[];

#endif