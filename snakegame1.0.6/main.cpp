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
#define COLOR_GRAY 8
#include "map.cpp"
#include "snake.cpp"
#include "gate.cpp"


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
    window_setting(win1);




//map setting--------------------------------------------------------------------------
    int selmap = 0; //should be modified.
    int item  = 0;
    int poison = 0;
    score (win2, win3,selmap, item,poison);
    wrefresh(win2);
    wrefresh(win3);
    color_apply(selmap,win1);


//snake_positon---------------------------------------------------------------------------
    vector<snakebody> snake;

    snake_make(snake,selmap);
    make_item(selmap);
    color_apply(selmap, win1);
    refresh();

//Snake moving --------------------------------------------------------------------------------------
    int snake_direction =1;
    int cnt;


    while(TRUE){
    // directon decide
      keypad(stdscr, TRUE);
      nodelay(stdscr, TRUE); //to move snake without input
      int input_key=getch();
      if(input_key==KEY_F(1)){
        break;
    }
      snake_direction=input_Direction(input_key, snake_direction);
      snake_move(snake, snake_direction, selmap,item,poison);
      color_apply(selmap, win1);
      usleep(250000); //move snake per 0.25 sec
      cnt+=1;
      if (cnt%20==0){ //generate item per 5sec
        make_item(selmap);
      }
      if(cnt == 40){
        make_gate(selmap);
      }
      color_apply(selmap, win1);
      refresh();

  }

      delwin(win1);
      delwin(win2);
      delwin(win3);

      getch();
      endwin();
      return 0;
}
