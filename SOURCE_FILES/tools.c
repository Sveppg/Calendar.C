#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enter(int howManyTimes){
    for(int i=0;i<howManyTimes;i++) printf("\n");
}


void clearScreen(){
    system("CLS");
}


void clearBuffer(){
    char dummy;

    while(dummy != '\n') scanf("%c", &dummy);
}


void fclearBuffer(FILE *file){
    char Dummy;

    do{
        if(feof(file)) break;
        fscanf(file, "%c", &Dummy);
    }while(Dummy != '\n');
}


int askYesOrNo(char *question){
    char Input;

    do{
    printf("%s", question);
      scanf("%c", &Input);
      if (Input != '\n')   clearBuffer();
    }while ((Input != 'j') && (Input != 'J') && (Input != 'Y') && (Input != 'y') && (Input != 'n') && (Input != 'N'));

    return ((Input == 'j') || (Input == 'J') || (Input == 'Y') || (Input == 'y'));
}


void waitForEnter(char *text){
    printf("%s", text);
    clearBuffer();
}


void printLine(char look, int lenght){
    for(int i=0; i<lenght; i++){
        printf("%c", look);
    }
}


void title(char *name, char line){
    printf("%s", name);
    enter(1);
    printLine(line, strlen(name));
}


void Dog(){
    clearScreen();
    printf("Dog");
}


int getText(char *Prompt, int Maxlen, char **Text, int AllowEmpty){
    char *Input;
    char Format[20];
    unsigned Len = 0;
    int ok = 0;

    if((Text == NULL) || (Maxlen == 0)) return 0;
    
    *Text = NULL;

    Input = malloc(Maxlen+1);
    if(Input){
        sprintf(Format, "%%%i[^\n]", Maxlen);
        do{
            printf(Prompt);
            *Input = '\0';
            scanf(Format, Input);
            clearBuffer();

            Len = strlen(Input);
            if(Len > 0){
                *Text = malloc(Len + 1);
                if(*Text){
                    strcpy(*Text, Input);
                    ok = 1;
                }
            }
            else if(AllowEmpty) ok = 1;
        }while(ok != 1);

        free(Input);
        return 1;
    }
    else return 0;
}

int getMem(char **pPtr, int size){
    if(pPtr == NULL)
        return 0;

    pPtr = calloc(size, 1);
    return (*pPtr != NULL);
}

void freeMem(char **pPtr){
    if(pPtr){
        free(pPtr);
        pPtr = NULL;
    }
}