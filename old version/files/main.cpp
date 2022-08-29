#include <iostream>
#include <clocale>
#include <ncurses.h>
#include "map.h"
#include "map.cpp"

int main() {
    setlocale(LC_ALL, "");
    initscr(); //curses mode start
    resize_term(75,120); //terminal_size

    WINDOW* win1 = newwin(30, 60, 5, 3); //win1 = game board |win2 = mission board | win3= score board
    WINDOW* win2 = newwin(15, 35, 5, 70);
    WINDOW* win3 = newwin(15, 35, 20, 70);

    set_color(); //color setting
    back_setting();//background setting
    window_setting(win1, win2, win3); //window setting
    map_print(win1, map); //map print

//snake_positon---------------------------------------------------------------------------

    //int initial_position[4][3][2]

    int initial_position[3][2]={{14,2},{12,2},{10,2}}; //{y,x}. first element is head initial_position
/*
    int position_wieght[4][2]={
      {0,-1}, //up
      {0,1},  //down
      {-2,0}, //left
      {2,0}   //right
    }

    while(true){
      if (kbhit()){
        int key=getch();
        if (key==224){
          key=getch();
          switch(key){
            case 72: //up

            case 80: //down
            case 75: //left
            case 77: //right
          }
        }

      }
    }

*/
//snake_print------------------------------------------------------------------------------
/*
    wattron(win1, COLOR_PAIR(13)); //head_color
    mvwprintw(win1, initial_position[0][1], initial_position[0][0], "%c ", 'h'); //initial head print
    wattron(win1, COLOR_PAIR(14)); //body_color
    mvwprintw(win1, initial_position[1][1], initial_position[1][0], "%c ", 'b'); //initial body print
    mvwprintw(win1, initial_position[2][1], initial_position[2][0], "%c ", 'b');
    wattroff(win1, COLOR_PAIR(14));
*/

//--------------------------------------------------------------------------------------------
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);


    delwin(win1);
    delwin(win2);
    delwin(win3);

    getch();
    endwin();
    return 0;
}
