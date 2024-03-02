#ifndef TOOLS_H
#define TOOLS_H

/*
 * Enter function that replaces the
 * 'backslash n'. Great use for greater
 * amounts of 'backslash n' and
 * structured code           
*/
void enter(int howManyTimes);

/*
 * Uses the "CLS" Windows shell       
 * command to clear your terminal     
 * screen                             
*/
void clearScreen();

/*
 * Should be used after every 'scanf' 
 * to wipe out potential input buffers    
*/
void clearBuffer();

/*
Clears potential input buffer after
fscanf and should alwqys be used
after fscanf
*/
void fclearBuffer(FILE *file);

/*
 * Question can be asked where the    
 * user should only anser yes 'y' or  
 * no 'n'. 'j' for german language    
 * included                           
*/
int askYesOrNo(char *question);

/*
 * Text appears that usually tells the
 * user to press enter and waits unti 
 * enter is pressed                   
*/
void waitForEnter(char *text);

void printLine(char look, int lenght);

/*
 * Prints a title text ('char *name')  
 * and puts an underline ('char line')
 * to it. The underline has the same  
 * lenght as the title. Can also be   
 * used as simple highlight instead   
 * of a title                         
*/
void title(char *name, char line);

//Dog
void Dog();

/*
 * 'char *Prompt' is the Text that will appear to
 * tell the user that he should enter/type something.
 * 'int Maxlen' is the maximum lenght of the user
 * input.
 * 'char **Text' is a pointer to the string in which
 * the user input get's saved.
 * 'AllowEmpty' is a truth value:
 *      - set 1 to allow the input to be empty.
 *      - set 0 to dencline the input to be empty.
*/
int getText(char *Prompt, int MaxLen, char **Text, int AllowEmpty);

int getMem(char **pPtr, int size);

void freeMem(char **pPtr);

#endif