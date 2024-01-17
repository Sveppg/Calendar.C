#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "escapesequenzen.h"
#include "menu.h"
#include "calendar.h"

int main()
{
   int Menu;
   do
   {
      char MenuItems[7][100] = 
      {
         {"Neuen Termin anlegen"},
         {"Termin bearbeiten"},
         {"Termin loeschen"},
         {"Termin suchen"},
         {"Termine sortieren"},
         {"Termine auflisten"},
         {"Programm beenden"}
      };
      Menu = getMenu("Terminverwaltung V 0.2", 7, MenuItems);
      switch (Menu)
      {
         case 1: createAppointment(); break;
         case 2: editAppointment(); break;
         case 3: deleteAppointment(); break;
         case 4: searchAppointment(); break;
         case 5: sortCalendar(); break;
         case 6: listCalendar(); break;
      }
   } while (Menu != 7);
   if (Menu == 7)
   freeCalendar();
   return 0;
}