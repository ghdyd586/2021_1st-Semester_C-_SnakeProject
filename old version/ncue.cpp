#include <ncurses.h>
#include <iostream>
#include <locale.h>
#include "map.h"
#define COLOR_GRAY 8
#define COLOR_BLACK_A 9

int main()
{
  // Window object create
  WINDOW *win1, *win2, *win3;
  initscr();
  resize_term(700, 700); // window size setting
  win1= newwin(40,40,3,3); // window size setting, location setting
  win2= newwin(13,28,3,40);
  win3= newwin(13,32,20,40);

  // initial Setting
  int stage_num=0, stage_flag=0;
  int Head_Direction, Body_length, Growth_item, Poison_item, Gate_cnt, gate_posX, gate_posY;
  stage_flag = 0;
  Body_length = 0;
  Growth_item = 0;
  Poison_item = 0;
  Gate_cnt = 0;
  gate_posX = 0;
  gate_posY = 0;

  // color setting
  start_color();
  init_color(COLOR_GRAY, 150, 150, 150);      // Gray
  init_pair(1, COLOR_GRAY, COLOR_GRAY);       // Wall
  init_color(COLOR_BLACK_A, 0, 0, 0);         // Black
  init_pair(2, COLOR_BLACK_A, COLOR_BLACK_A); // Immune Wall
  init_pair(3, COLOR_CYAN, COLOR_CYAN);       // Snake Head
  init_pair(4, COLOR_BLUE, COLOR_BLUE);       // Snake Body
  init_pair(5, COLOR_GREEN, COLOR_GREEN);     // Growth Item
  init_pair(6, COLOR_RED, COLOR_RED);         // Poison Item
  init_pair(7, COLOR_YELLOW, COLOR_YELLOW);   // Gate
  init_pair(8, COLOR_WHITE, COLOR_WHITE);     // null box


// color apply
  for(int i=0; i<30; i++){
    for(int j=0; j<30; j++){
      if(map[stage_num][i][j] == 0){
        wattron(win1, COLOR_PAIR(8));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(8));
      }

      else if(map[stage_num][i][j] == 1){
        wattron(win1, COLOR_PAIR(1));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(1));
      }

      else if(map[stage_num][i][j] == 2){
        wattron(win1, COLOR_PAIR(2));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(2));
      }

      else if(map[stage_num][i][j] == 3){
        wattron(win1, COLOR_PAIR(3));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(3));
      }

      else if(map[stage_num][i][j] == 4){
        wattron(win1, COLOR_PAIR(4));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(4));
      }

      else if(map[stage_num][i][j] == 5){
        wattron(win1, COLOR_PAIR(5));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(5));
      }

      else if(map[stage_num][i][j] == 6){
        wattron(win1, COLOR_PAIR(6));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(6));
      }

      else if(map[stage_num][i][j] == 7){
        wattron(win1, COLOR_PAIR(7));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(7));
      }
    }
  }

//Mission and score Setting
  int goal[4][4] = {{5, 1, 1, 1}, {5, 1, 1, 1}, {5, 1, 1, 1}, {5, 1, 1, 1}};

  // Mission List Setting
  wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(win2, 1, 7, "<Mission List>");
  mvwprintw(win2, 3, 8, "Purpose : %d", goal[stage_num][0]);
  mvwprintw(win2, 5, 8, "Growth Item : %d", goal[stage_num][1]);
  mvwprintw(win2, 7, 8, "Posion Item : %d", goal[stage_num][2]);
  mvwprintw(win2, 9, 8, "Gate used : %d", goal[stage_num][3]);

  // int size = snake.size();
  int current_size = 1;
  // Body_length = max(size, Body_length); // max_size

  // Score List Setting
  wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(win3, 1, 8, "<Score List>");
  mvwprintw(win3, 3, 2, "Goal: %d(current) / %d(max)", current_size, Body_length);  // current / max
  mvwprintw(win3, 5, 2, "Growth Item :   %d   ", Growth_item);
  mvwprintw(win3, 7, 2, "Posion Item  :   %d   ", Poison_item);
  mvwprintw(win3, 9, 2, "Gate used :   %d   ", Gate_cnt);

  wrefresh(win1);
  wrefresh(win2);
  wrefresh(win3);
  getch();
  delwin(win3);
  delwin(win2);
  delwin(win1);
  endwin();
  return 0;
}
