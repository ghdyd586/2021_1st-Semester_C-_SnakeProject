#include <ncurses.h>
#include <iostream>
#include <clocale>
#include "map.h"

int main(){
  setlocale(LC_ALL, "");
  WINDOW *win1;
  WINDOW *win2;
  WINDOW *win3;
  initscr();
  //resize_term(75,120);
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_YELLOW); //1번 팔레트. 노란 배경 파란 글씨
  init_pair(2, COLOR_RED, COLOR_GREEN); //초록 배경 빨간 글씨
  bkgd(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  border('*', '*', '*', '*', '*', '*', '*', '*');
  mvprintw(1,45,"#SNAKE GAME made by J3#");
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(1));
  mvprintw(38, 3, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 3, " \u2B1B");
  mvprintw(40, 3, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 3, "          \u2B1B");
  mvprintw(42, 3, " \u2B1B \u2B1B \u2B1B \u2B1B");

  mvprintw(38, 25, " \u2B1C \u2B1C \u2B1C \u2B1C");
  mvprintw(39, 25, " \u2B1C       \u2B1C");
  mvprintw(40, 25, " \u2B1C       \u2B1C");
  mvprintw(41, 25, " \u2B1C       \u2B1C");
  mvprintw(42, 25, " \u2B1C       \u2B1C");

  mvprintw(38, 47, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 47, " \u2B1B       \u2B1B");
  mvprintw(40, 47, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 47, " \u2B1B       \u2B1B");
  mvprintw(42, 47, " \u2B1B       \u2B1B");

  mvprintw(38, 69, " \u2B1C     \u2B1C");
  mvprintw(39, 69, " \u2B1C   \u2B1C");
  mvprintw(40, 69, " \u2B1C \u2B1C");
  mvprintw(41, 69, " \u2B1C   \u2B1C");
  mvprintw(42, 69, " \u2B1C     \u2B1C");

  mvprintw(38, 91, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(39, 91, " \u2B1B");
  mvprintw(40, 91, " \u2B1B \u2B1B \u2B1B \u2B1B");
  mvprintw(41, 91, " \u2B1B");
  mvprintw(42, 91, " \u2B1B \u2B1B \u2B1B \u2B1B");

  attroff(COLOR_PAIR(1));
  refresh();


  win1 = newwin(30,60, 5, 3); //맵 나올 부분
  wbkgd(win1, COLOR_PAIR(1));
  wattron(win1, COLOR_PAIR(1));
  mvwprintw(win1, 1, 10, "<<Press arrow keys to move snake!>>");
  wborder(win1, '|','|','-','-','+','+','+','+');
  wrefresh(win1);

  win2 = newwin(15,35, 5, 70); //mission board
  wbkgd(win2, COLOR_PAIR(1));
  wattron(win2, COLOR_PAIR(1));
  mvwprintw(win2, 1, 13, "<<MISSION>>");
  wborder(win2, '|','|','-','-','+','+','+','+');
  wrefresh(win2);

  win3 = newwin(15,35, 20, 70); //score board
  wbkgd(win3, COLOR_PAIR(1));
  wattron(win3, COLOR_PAIR(1));
  mvwprintw(win3, 1, 13, "<<SCORE>>");
  wborder(win3, '|','|','-','-','+','+','+','+');
  wrefresh(win3);

  delwin(win1);
  delwin(win2);
  delwin(win3);

  mvprintw(3,30,"<<Press 1,2, or 3 to select a map and start game! >> ");
  getch();
  endwin();
  return 0;
}
