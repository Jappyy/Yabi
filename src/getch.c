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
   nocbreak();
   echo();
   noraw();
   scrollok(stdscr, FALSE);
   nodelay(stdscr, FALSE);
   keypad(stdscr, FALSE);
   
   getch();
   endwin();
}


/*
int _getch()
{
   enable_raw_mode();
   int c = getchar();
   disable_raw_mode();

   return c;
}


/*
void enable_raw_mode()
{
   struct termios t = {0};
   tcgetattr(0, &t);

   t.c_lflag &= ~(ICANON|ECHO); 
   tcsetattr(0, TCSANOW, &t);
}



void disable_raw_mode()
{
   struct termios t = {0};
   tcgetattr(0, &t);
   
   t.c_lflag |= (ICANON|ECHO);
   tcsetattr(0, TCSANOW, &t);
}


/*bool kbhit()
{
   int c;
   ioctl(0, FIONREAD, &c);

   return c > 0;
}*/


bool kbhit(void)    /* comment */
{
    int ch, r;

    // check for input
   ch = wgetch(stdscr);

   if( ch == ERR)      // no input
      r = false;

   else                // input
   {
      r = true;
      ungetch(ch);
   }

    return(r);
}
