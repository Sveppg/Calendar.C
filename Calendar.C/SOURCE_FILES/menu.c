#include <stdio.h>
#include <string.h>
#include "escapesequenzen.h"
#include "calendar.h"
#include "tools.h"


int notValidChoice(int choice, int NumberOfMenuItems)
{
    if(choice >= 1 && choice <= NumberOfMenuItems)
        return 0;
    else
        return 1;
}
int getMenu(char MenuTitel[], int NumberOfMenuItems, char MenuItems[NumberOfMenuItems][100])
{
    int choice, scan;
    do
    {
        clearScreen();
        printf("%s\n", MenuTitel);
        printLine('=', strlen(MenuTitel));
        for (int i = 0; i < NumberOfMenuItems; ++i)
        {
            printf("%i. %s\n", i+1 ,MenuItems[i]);
        }
        printf("\n");
        do
        {
            printf("Ihre Wahl: ");
            scan = scanf("%i", &choice);
            clearBuffer();
            if (scan == 0 || notValidChoice(choice, NumberOfMenuItems) == 1)
                printf("Falsche Eingabe\n");

        }while (scan == 0 || notValidChoice(choice, NumberOfMenuItems) == 1);

    } while (notValidChoice(choice, NumberOfMenuItems) == 1);
    return choice;
}