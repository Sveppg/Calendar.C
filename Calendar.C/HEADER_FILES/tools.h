#ifndef TOOLS_H
    #define TOOLS_H

    int getMem(int **, int );

    void freeMem(int **);

    void clearBuffer();

    void waitForEnter();

    void clearScreen();

    int askYesOrNo(char *Question);

    void printLine(char sign, int length);

    void getText(char prompt[], int maxLength, char *Text[], int Optional);

    char Usage(); 

#endif