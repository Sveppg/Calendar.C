#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h> //
#include <stdlib.h> // vers.2
#include <string.h> //

#include "datastructure.h"
#include "tools.h"
#include "calendar.h"
#include "datetime.h"
#include "menu.h"
#include "escapesequenzen.h"




int isLeapYear(int Year)
{
    if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
        return 1;  // Leap year
    else
        return 0;  // Not a leap year
}

int isDateValid(sDate *Date) 
{
    int leapYear = isLeapYear(Date->Year);
    if (Date->Year > 9999 || Date->Year <= 0)
        return 0;
    if (Date->Month > 12 || Date->Month <= 0)
        return 0;
    if (Date->Day <= 0)
        return 0;
    if (Date->Month == 4 || Date->Month == 6 || Date->Month == 9 || Date->Month == 11)
    {
        if (Date->Day > 30)
            return 0;
    }
    else
    {
        if (Date->Day > 31)
            return 0;
    }
    if (Date->Day >= 29 && Date->Month == 2 && leapYear != 1)
        return 0;
    else
        return 1;

}

int isTimeValid(sTime *Time)
{
    if (Time->Hour > 24 || Time->Hour < 0)
    {
        printf("hours failed\n");
        return 0;
    }
    if (Time->Minute > 60 || Time->Minute < 0)
    {
        printf("Minutes failed\n");
        return 0;
    }
    if (Time->Second > 60 || Time->Second < 0)
    { 
        printf("Seconds failed\n");
        return 0;
    }
    else   
        return 1;
}
int calculateWeekDay(sDate *Date)
{
    double wDouble, d, m, y, c;
    int year;
    d = Date->Day;
    year = Date->Year;
    switch (Date->Month)
    {
        case 1: m = 11; break;
        case 2: m = 12; break;
        case 3: m = 1; break;
        case 4: m = 2; break;
        case 5: m = 3; break;
        case 6: m = 4; break;
        case 7: m = 5; break;
        case 8: m = 6; break;
        case 9: m = 7; break;
        case 10: m = 8; break;
        case 11: m = 9; break;
        case 12: m = 10; break;
    }
    if (Date->Month == 1 || Date->Month == 2)
    {
        year -= year;
    }
    for (int i = 0; i <= 3; i++)
    {
        y = (year % 100);
        c = (year / 100);
    }
    wDouble = (d + floor((2.6 * m) - 0.2 ) + y + floor(y/4) + floor(c/4) - (2*c));
    int weekDay;
    weekDay = wDouble;
    weekDay = weekDay % 7;
    while (weekDay < 0)
        weekDay += 7;
    if (weekDay == 0)
        weekDay = 7;
    return weekDay;
}

int getDateFromString(char *Input, sDate *Date)
{
    int Day, Month;
    long int Year;

    char DayStr[3], MonthStr[3], YearStr[5];
    
    if (sscanf(Input, "%2[^.].%2[^.].%4[^.]", DayStr, MonthStr, YearStr) != 3) {
       // schau mal der gibt das auch nach getDauer aus  printf("Entschuldige, ein falsches Zeitformat wurde verwendet, verwende DD.MM.YYYY\n");
        return 0; // Fehler Übergabe type
    }

    // Überprüfe länge der parameter = Day == 2 , month == 2, year == 4
    if (strlen(DayStr) > 2 || strlen(MonthStr) > 2 || strlen(YearStr) != 4) {
        return 0; // False = Inkorrekte Länge
    }

    // Übersetze in int
    Day = atoi(DayStr);
    Month = atoi(MonthStr);
    Year = strtol(YearStr, NULL, 10);

    //überprüfe richtige Anzahl pro parameter
    if (Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year < 1000 || Year > 9999) {
        return 0; // return false = falsche länge
    }

    // Übergebe datentypen zu datastruct
    Date->Day = Day;
    Date->Month = Month;
    Date->Year = (int)Year;
    Date->weekDay = calculateWeekDay(Date);

    return isDateValid(Date);
}


int getTimeFromString(char *Input, sTime *Time) // ver1.
{
    int Hour, Minute, Second;

    char HourStr[3], MinuteStr[3], SecondStr[3];
    
    if (sscanf(Input, "%2[^:]:%2[^:]:%2[^:]", HourStr, MinuteStr, SecondStr) != 3) {
        // same as in get date printf("Entschuldige, ein falsches Zeitformat wurde verwendet, verwende HH:MM:SS\n");
        return 0; // Parsing error
    }

    // überprüfe Länge für übergebene Strings
    if ((strlen(HourStr) > 2) || (strlen(MinuteStr) > 2) || (strlen(SecondStr) > 2)) {
        return 0; // Inkorrekte Länge
    }

    // übertrage als integer
    Hour = atoi(HourStr);
    Minute = atoi(MinuteStr);
    Second = atoi(SecondStr);

   
    if (Hour < 0 || Hour > 24 || Minute < 0 || Minute > 60 || Second < 0 || Second > 60) {
        return 0; //Werte passen nicht
    }

    // Übertrage werte zu time struc
    Time->Hour = Hour;
    Time->Minute = Minute;
    Time->Second = Second;

    return isTimeValid(Time);
}




void getDate(char prompt[], sDate *Date)
{
    char Input[20];
    do
    {
        printf("%s", prompt); 
        *Input = '\0';
        scanf("%19[^\n]", Input);
        clearBuffer();
    } while (getDateFromString(Input, Date) == 0);      
}

void getTime(char prompt[], sTime *Time, int Optional)
{
    char Input[20];
    do
    {
        printf("%s", prompt);
        *Input = '\0';
        scanf("%19[^\n]", Input);
        clearBuffer();
    } while (getTimeFromString(Input, Time) == 0 && Optional == 0);
}

void printDate(sAppointment *Appointment)
{
    switch (Appointment->Date.weekDay)
    {
        case 0: printf("Not a Day"); break;
        case 1: printf("Mo"); break;
        case 2: printf("Tu"); break;
        case 3: printf("We"); break;
        case 4: printf("Th"); break;
        case 5: printf("Fr"); break;
        case 6: printf("Sa"); break;
        case 7: printf("Su"); break;
    }
    printf(", %02i.%02i.%04i:\n", Appointment->Date.Day, Appointment->Date.Month, Appointment->Date.Year);
}

void printTime(sAppointment *Appointment)
{
    printf("%2i:%02i", Appointment->Time.Hour, Appointment->Time.Minute);
}
