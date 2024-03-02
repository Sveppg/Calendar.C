#ifndef DATETIME_H
#define DATETIME_H
#include "datastructure.h"

/*
 Uses the datastructure and checks which
 value 'enum eDayOfTheWeek' has, calculating
 the weekday of the date, the datastructure has 
*/
int dayOfWeek(sDate *date);
/*
 * Checks if the 'int year' is a leap year  
*/
int isLeapYear(int year);

/*
 * Checks if the date from                  
 * 'getDateFromString' is valid, checking   
 * also including 'isLeapYear'              
*/
int isDateValid(sDate date);

/* 
 * 'char in[]' is the date input while      
 * 'sdate *dateptr' is the pointer in which 
 * the date gets set, so 'Day', 'Month' and 
 * 'Year' get their values from the input.
 */
int getDateFromString(char in[],sDate *dateptr);

/*
Used for scanning and saving a date-input.
First a if command checks, if calloc works or does not.
If it works the prompt will be printed, a scanf command
and 'clearBuffer' appears as long as 'getDateFromString'
does not work. After that the 'sDate *dateptr' values
are heading over to the 'Calendar[countAppointments].Time'
value.
*/
int getDate(char *prompt, sDate *dateptr);

/*
 * Same as 'isDateValid', 'isTimeValid'     
 * checks, if the time from                  
 * 'getTimeFromString' is the correct       
 * clocktime(uses german clock 0Uhr - 24Uhr)
*/
int isTimeValid(sTime time);

/*
 * Same as 'getDateFromString' but for time,
 * 'getTimeFromString' is seperating the    
 * hour, minute and second value from the   
 * input that is 'char[in]'.                
 * 'sTime *timeptr' is the pointer that will
 * set the hour, minute and second values to
 * the datastructure after the input got    
 * read(uses german clock 0Uhr - 23:59Uhr)  
*/
int getTimeFromString(char in[],sTime *timeptr);

/*
 * It's 'isTimeValid' but it allows the     
 * time to get more than 24 hours. Will be  
 * connected with 'getTimeFromStringLite'    
*/
int isTimeValidLite(sTime time);

/*
 * It's 'getTimeFromString' but it allows   
 * the time to get more than 24 hours. Uses 
 * 'isTimeValidLite' and get's used if the  
 * time has to be a amount/lenght instead of
 * a clock                                  
*/
int getTimeFromStringLite(char in[],sTime *timeptr);

/*
Used for scanning and saving a time-input.
First a if command checks, if calloc works or does not.
If it works the prompt will be printed, a scanf command
and 'clearBuffer' appears as long as 'getTimeFromString'
does not work. After that the 'sTime *timeptr' values
are heading over to the 'Calendar[countAppointments].Time'
value.
*/
int getTime(char *prompt, sTime *timeptr);

/*
Used for scanning and saving a time-input.
First a if command checks, if calloc works or does not.
If it works the prompt will be printed, a scanf command
and 'clearBuffer' appears as long as 'getTimeFromString'
does not work or the time input is not NULL, giving the
user the optional choice of putting it in or not.
After that the 'sDate *dateptr' values
are heading over to the 'Calendar[countAppointments].Lenght'
value.
*/
int getDuration(char *prompt, sTime *timeptr);

/*
Prints a date in format:
00.00.0000

For example the input is:
3.4.2001
the output will be:
03.04.2001
*/
void printDate(sDate *dateptr);

/*
Prints a time in format:
00:00

For example the input is:
1:2
the output will be:
01:02
*/
void printTime(sTime *timeptr);
#endif