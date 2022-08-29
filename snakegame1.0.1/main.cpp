#include <ncurses.h>
#include <iostream>
#include <vector>
#include <clocale>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <string>
#include "map.h"
using namespace std;
#define COLOR_GRAY 1
#include "map.cpp"
#include "snake.cpp"


// main start-----------------------------------------------------------------------------------------
int main() {
    setlocale(LC_ALL, "");
    initscr();
    resize_term(75,120);
    //color setting--------------------------------------------------------
    set_color();

  //background setting---------------------------------------------------
    back_setting();
  // window setting win1 = game board |win2 = mission board | win3= score board------------------------------
    WINDOW* win1;
    WINDOW* win2;
    WINDOW* win3;
    win1 = newwin(30, 60, 5, 3); //game board
    win2 = newwin(15, 35, 5, 70); //mission board
    win3 = newwin(15, 35, 20, 70); //score board
    window_setting(win1,win2,win3);
    wrefresh(win2);
    wrefresh(win3);

//map setting--------------------------------------------------------------------------
    int selmap = 0; //should be modified. selected by player
    color_apply(selmap,win1);

//snake_positon---------------------------------------------------------------------------
  vector<snakebody> snake;
  snake_make(snake,selmap);
  refresh();
  color_apply(selmap, win1);

//Snake moving --------------------------------------------------------------------------------------
  int snake_direction =1;

  while(TRUE){
    // directon decide
    keypad(stdscr, TRUE);
    int input_key=getch();
    if(input_key==KEY_F(1)){
      break;
    }
    snake_direction=input_Direction(input_key);
    snake_move(snake, snake_direction, selmap);
    color_apply(selmap, win1);

  }

    delwin(win1);
    delwin(win2);
    delwin(win3);

    getch();
    endwin();
    return 0;
}
