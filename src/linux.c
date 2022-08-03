#include "../include/IO.h"


void init()
{
   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   scrollok(stdscr, TRUE);
   nodelay(stdscr, TRUE);
}

void restore_default()
{
   echo();
   nocbreak();
   keypad(stdscr, FALSE);
   scrollok(stdscr, FALSE);
   nodelay(stdscr, FALSE);

   getch();
   endwin();
}
