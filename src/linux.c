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
   getch();
   endwin();
}
