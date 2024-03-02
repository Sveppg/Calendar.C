#ifndef MENU_H
#define MENU_H

/*********************************************
 * Uses 'tools.h' to create a menutitle and  
 * creates the menuPoints. 'char *title' is  
 * the headline, while                       
 * 'char *menuPointTitles[]' are the names of
 * every menupoints(should be a array with   
 * every menupointname as a element) and     
 * 'int menuPoints' being the amount of the  
 * menuPoints (Should be the same amount as  
 * the amount of elements in                 
 * 'char *menuPointTitles[]'                 
*********************************************/
int getMenu(char *title, char *menuPointTitles[], int menuPoints);

#endif