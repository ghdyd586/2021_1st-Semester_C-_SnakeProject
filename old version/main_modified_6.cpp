#include <ncurses.h>
#include <iostream>
#include <vector>
#include <clocale>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <string>
#include "map.h"
#define COLOR_GRAY 1
using namespace std;

// snake body object class---------------------------------------------------------
struct snakebody{
  int x, y;
  snakebody(int col, int row);
  snakebody();
};
snakebody::snakebody(int col, int row){
  x=col;
  y=row;
}
snakebody::snakebody(){
  x=0;
  y=0;
}

// color setting function-------------------------------------------------------------
void color_setting(int selmap,WINDOW* win1){
  // color apply
  for (int i = 0; i < 30; i++) { //map print
    int temp=0; //temporary x positon. to equalize the map size
      for (int j = 0; j < 30; j++) {
        // null box is white
          if (map[selmap][i][j] == 0) {
              wattron(win1, COLOR_PAIR(12));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]); //space in behind
              wattroff(win1, COLOR_PAIR(12));
              temp+=2; //update x position

          }
          //Wall is gray
          else if (map[selmap][i][j] == 1) {
              wattron(win1, COLOR_PAIR(1));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(1));
              temp+=2;
          }
          // Immune Wall is black
          else if (map[selmap][i][j] == 2) {
              wattron(win1, COLOR_PAIR(2));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(2));
              temp+=2;
          }
          // Snake Head is cyan
          else if (map[selmap][i][j] == 3) {
              wattron(win1, COLOR_PAIR(3));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(3));
              temp+=2;
          }
          // Snake Body is blue
          else if (map[selmap][i][j] == 4) {
              wattron(win1, COLOR_PAIR(4));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(4));
              temp+=2;
          }
      }
  }
  wrefresh(win1);
}

// main start-----------------------------------------------------------------------------------------
int main() {
    setlocale(LC_ALL, "");

    initscr();
    resize_term(75,120);

    //color setting--------------------------------------------------------
    start_color();
    init_pair(10, COLOR_BLUE, COLOR_YELLOW);
    init_pair(11, COLOR_RED, COLOR_GREEN);

    init_pair(12, COLOR_WHITE, COLOR_WHITE); // null box
    init_color(COLOR_GRAY, 270, 270, 270);      // Gray
    init_pair(1, COLOR_GRAY, COLOR_GRAY);       // Wall
    init_color(COLOR_BLACK, 0, 0,0);
    init_pair(2, COLOR_BLACK, COLOR_BLACK); // Immune Wall


    init_pair(3, COLOR_CYAN, COLOR_CYAN);       // Snake Head
    init_pair(4, COLOR_BLUE, COLOR_BLUE);       // Snake Body

  //background setting---------------------------------------------------
    bkgd(COLOR_PAIR(10));
    attron(COLOR_PAIR(11));
    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 45, "#SNAKE GAME made by J3#");
    attroff(COLOR_PAIR(11));
    attron(COLOR_PAIR(10));
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

    //mvprintw(3, 30, "<<Press 1,2,3, or 4 and enter key to select a map and start game! >> ");
    mvprintw(36, 15, "<<Press arrow keys to move snake!>>");

    attroff(COLOR_PAIR(10));
    refresh();

    // window setting win1 = game board |win2 = mission board | win3= score board------------------------------
    WINDOW* win1;
    WINDOW* win2;
    WINDOW* win3;

    win1 = newwin(30, 60, 5, 3); //game board
    wbkgd(win1, COLOR_PAIR(10));
    wattron(win1, COLOR_PAIR(10));
    wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');


    win2 = newwin(15, 35, 5, 70); //mission board
    wbkgd(win2, COLOR_PAIR(10));
    wattron(win2, COLOR_PAIR(10));
    mvwprintw(win2, 1, 13, "<<MISSION>>");
    wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');


    win3 = newwin(15, 35, 20, 70); //score board
    wbkgd(win3, COLOR_PAIR(10));
    wattron(win3, COLOR_PAIR(10));
    mvwprintw(win3, 1, 13, "<<SCORE>>");
    wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');

//map setting--------------------------------------------------------------------------
    int selmap = 0; //should be modified. selected by player
    color_setting(selmap,win1);

//snake_positon---------------------------------------------------------------------------
  vector<snakebody> snake;
  //possible location (map, row, colum)
  int snake_positon[4][3][2]={
    //{{3,3}, {10,10},{19,18}},
    {{4, 23}, {6, 8}, {18, 16}},
    {{15, 14}, {21, 9}, {3, 18}},
    {{4, 15}, {27, 18}, {16, 15}},
    {{16, 15}, {6, 12}, {27, 17}}
  };

  // make random number-> random location and snake location setting
  srand((unsigned)time(0));
  int r = rand()%3;

  //head setting ->snake <vector> has head positon and body position
  for(int i=0; i<4; i++){
    snake.push_back(snakebody(snake_positon[selmap][r][1]+i, snake_positon[selmap][r][0]));}
  map[selmap][snake[0].y][snake[0].x] = 3;

  // body setting
  for(int i=1; i<4; i++){
    map[selmap][snake[i].y][snake[i].x] = 4;}
  refresh();
  color_setting(selmap, win1);

//--------------------------------------------------------------------------------------

    wrefresh(win2);
    wrefresh(win3);

    delwin(win1);
    delwin(win2);
    delwin(win3);

    getch();
    endwin();
    return 0;
}
