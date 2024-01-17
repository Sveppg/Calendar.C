#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"


int countAppointments = 0;
sAppointment Calendar[2];

void createAppointment()
{
    clearScreen();
    printf("Erfassung eines neuen Termins\n");
    Usage();
    printLine('=', 29);
    getDate("Datum        : ", &Calendar[countAppointments].Date);
    getTime("Uhrzeit      : ", &Calendar[countAppointments].Time, 0);
    getText("Beschreibung : ", 100, &Calendar[countAppointments].Description, 0);
    getText("Ort          : ", 15, &Calendar[countAppointments].Place, 1);
    getTime("Dauer        : ", &Calendar[countAppointments].Duration,1);
    printf("Termin wurde gespeichert!\n\n");
    countAppointments++;
    waitForEnter();
}
void editAppointment(int *AppC)
{
    //int *AppC = malloc(sizeof(int));
    printf("Which Appointment do you want to edit?\n"); //Check for appList
    if (scanf("%d", AppC) != 1) 
    {
        printf("Invalid input. Please enter a number.\n");// Handle invalid input (maybe ask for input again)
    }

    
    printf("ToDo: editAppointment\n");
    waitForEnter();
}
void deleteAppointment()
{
    printf("ToDo: deleteAppointment\n");
    waitForEnter();
}
void searchAppointment()
{
    printf("ToDo: searchAppointment\n");
    waitForEnter();
}
void sortCalendar()
{
    printf("ToDo: sortCalendar\n");
    waitForEnter();
}
void listCalendar()
{   
    int i, j;
    int printedAppointments[MAXAPPOINTMENTS];
    
    for (i = 0; i < MAXAPPOINTMENTS; i++) // why MAX? change to countAppointments
    printedAppointments[i] = 0;
    
    clearScreen();
    printf("Liste der Termine\n");
    printLine('=', 17);
    printf("\n");
    if (countAppointments == 0) 
    {
        printf("Keine Termine vorhanden.\n");  //Meldung für keine Termine, solange countAppointments = 0
        printf("\n");
        waitForEnter();
        return;
    }
    for (i = 0; i < countAppointments; i++)
    {
        if(i >= 15)
            waitForEnter();
        if (printedAppointments[i] != 1)
        {
            printLine('=', 78);
            printDate(&Calendar[i]);
            printLine('-', 15);
            for (j = i; j < countAppointments; j++)
            {
                if (Calendar[j].Date.Day == Calendar[i].Date.Day && Calendar[j].Date.Month == Calendar[i].Date.Month && Calendar[j].Date.Year == Calendar[i].Date.Year)
                {
                    printTime(&Calendar[j]);
                    printf(" -> ");
                    printf("%-15.15s | ", Calendar[j].Place);
                    if (strlen(Calendar[j].Description) > 48)
                        printf("%.44s ...\n", Calendar[j].Description);
                    else
                        printf("%s\n", Calendar[j].Description);
                    printedAppointments[j] = 1;
                }   
            }
        }   
    }
    printf("\n");
    waitForEnter();
}

void freeAppointment(sAppointment *appointment)
{
    free(appointment->Description);
    free(appointment->Place);
}

void freeCalendar()
{
    for (int i = 0; i < countAppointments; i++)
    {
        freeAppointment(&Calendar[i]);
    }
}
