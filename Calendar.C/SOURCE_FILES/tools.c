#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "escapesequenzen.h"
#include "datastructure.h"

int getMem(int **pPtr, int Size)
{
	if (pPtr == NULL)
		return 0;
	
	*pPtr = calloc(Size, sizeof(int));

	return (*pPtr != NULL);
}

void freeMem(int **pPtr)
{
	free(*pPtr);
	if (pPtr)
		*pPtr = NULL;
}

void clearBuffer()
{
    char Leeren;
	do
		scanf("%c", &Leeren);
	while(Leeren != '\n');
}

void waitForEnter()
{
	char Eingabetaste;
	printf("Bitte druecken Sie die Eingabetaste...");
	do
		scanf("%c", &Eingabetaste);
	while(Eingabetaste != '\n');
}

void clearScreen()
{
    CLEAR;
}

int askYesOrNo(char *Question)
{
	char Eingabe;
		do{
			printf("%s", Question);
			scanf("%c", &Eingabe);
			clearBuffer();
			if(Eingabe != 'J' && Eingabe != 'j' && Eingabe != 'N' && Eingabe != 'n'){
				printf("Falsche Eingabe...\n");
				waitForEnter();
				LEFT(38);
				CLEAR_LINE;
				UP_LINE;
				CLEAR_LINE;
				UP_LINE;
				CLEAR_LINE;
				UP_LINE;
				CLEAR_LINE;
			}
		}while(Eingabe != 'J' && Eingabe != 'j' && Eingabe != 'N' && Eingabe != 'n');
		if (Eingabe == 'N' || Eingabe == 'n')
			return 0;
		else
			return 1;
}

void printLine(char sign, int length)
{
	int i;
	for (i = 1; i <= length; i++)
		printf("%c", sign);
	printf("\n");
}

void getText(char prompt[], int maxLength, char *Text[], int Optional)
{
	char *Input = NULL;
	Input = calloc(maxLength, sizeof(char));
	do
	{
		printf("%s", prompt);
		*Input = '\0';
		scanf("%99[^\n]", Input);
		clearBuffer();
	} while (*Input == '\0' && Optional == 0);
	*Text = calloc(strlen(Input), sizeof(char));
	strcpy(*Text, Input);
	free(Input);
}

char Usage() //just to display the Outputformat for new appointments
{
	char Timeformat[] = "The Timeformat is DD.MM.YYYY, HH:MM:SS";
	printf("%s\n", Timeformat);
	return 0;
} //Line 16 in calendar.c and Line 20 in tools.h