#include <ncurses.h>
#include <clocale>
int main()
{
  setlocale(LC_ALL, "");
  WINDOW *win1;
  WINDOW *win2;
  WINDOW *win3;
  initscr();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_YELLOW);
  init_pair(2, COLOR_RED, COLOR_GREEN);
  bkgd(COLOR_PAIR(1));
  attron(COLOR_PAIR(1));
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  border('*', '*', '*', '*', '*', '*', '*', '*');
  mvprintw(1,1,"#SNAKE GAME made by J3#");
  mvprintw(38, 1, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 1, " \u2B1B");
  mvprintw(40, 1, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 1, "          \u2B1B");
  mvprintw(42, 1, " \u2B1B \u2B1B \u2B1B \u2B1B");

  mvprintw(38, 20, " \u2B1C \u2B1C \u2B1C \u2B1C");
  mvprintw(39, 20, " \u2B1C       \u2B1C");
  mvprintw(40, 20, " \u2B1C       \u2B1C");
  mvprintw(41, 20, " \u2B1C       \u2B1C");
  mvprintw(42, 20, " \u2B1C       \u2B1C");

  mvprintw(38, 40, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 40, " \u2B1B       \u2B1B");
  mvprintw(40, 40, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 40, " \u2B1B       \u2B1B");
  mvprintw(42, 40, " \u2B1B       \u2B1B");

  mvprintw(38, 60, " \u2B1C     \u2B1C");
  mvprintw(39, 60, " \u2B1C   \u2B1C");
  mvprintw(40, 60, " \u2B1C \u2B1C");
  mvprintw(41, 60, " \u2B1C   \u2B1C");
  mvprintw(42, 60, " \u2B1C     \u2B1C");

  mvprintw(38, 80, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 80, " \u2B1B");
  mvprintw(40, 80, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 80, " \u2B1B");
  mvprintw(42, 80, " \u2B1B \u2B1B \u2B1B \u2B1B");


  attroff(COLOR_PAIR(2));
  refresh();
  getch();
  endwin();

  win1 = newwin(30,60, 3, 3);
  wbkgd(win1, COLOR_PAIR(1));
  wattron(win1, COLOR_PAIR(1));
  mvwprintw(win1, 1, 8, "<<Press arrow keys to move snake!>>");
  wborder(win1, '@','@','@','@','@','@','@','@');
  wrefresh(win1);

  win2 = newwin(11,35, 3, 70);
  wbkgd(win2, COLOR_PAIR(1));
  wattron(win2, COLOR_PAIR(1));
  mvwprintw(win2, 1, 13, "<<SCORE>>");
  wborder(win2, '@','@','@','@','@','@','@','@');
  wrefresh(win2);

  win3 = newwin(18,35, 15, 70);
  wbkgd(win3, COLOR_PAIR(1));
  wattron(win3, COLOR_PAIR(1));
  mvwprintw(win3, 1, 13, "<<ITEMS>>");
  wborder(win3, '@','@','@','@','@','@','@','@');
  wrefresh(win3);

  getch();
  delwin(win1);
  delwin(win2);
  delwin(win3);
  endwin();
  char key;
  char selmap[1];
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();
  mvprintw(1,30,"<<Press 1,2, or 3 to select a map and start game! >> ");
  scanw("%s", selmap);
  refresh();
  getch();
  clear();
  endwin();
  return 0;
}
