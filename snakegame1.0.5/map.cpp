// #include "main.h"

void set_color(){
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
  init_pair(5, COLOR_GREEN, COLOR_GREEN);       // Growth item
  init_pair(6, COLOR_RED, COLOR_RED);     //Poison item
  init_color(COLOR_MAGENTA, 1000, 250, 500);
  init_pair(7, COLOR_MAGENTA,COLOR_MAGENTA); // gate

}

void back_setting(){
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

  mvprintw(36, 15, "<<Press arrow keys to move snake!>>");

  attroff(COLOR_PAIR(10));
  refresh();
}

void window_setting(WINDOW* win1, WINDOW* win2, WINDOW* win3){
  //window setting win1 = game board |win2 = mission board | win3= score board
  wbkgd(win1, COLOR_PAIR(10));
  wattron(win1, COLOR_PAIR(10));
  wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');

  wbkgd(win2, COLOR_PAIR(10));
  wattron(win2, COLOR_PAIR(10));
  mvwprintw(win2, 1, 13, "<<MISSION>>");
  wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');

  wbkgd(win3, COLOR_PAIR(10));
  wattron(win3, COLOR_PAIR(10));
  mvwprintw(win3, 1, 13, "<<SCORE>>");
  wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');

}

// color apply function-------------------------------------------------------------
void color_apply(int selmap,WINDOW* win1){
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
          // Growth item is green
          else if (map[selmap][i][j] == 5) {
              wattron(win1, COLOR_PAIR(5));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(5));
              temp+=2;
          }
          //Poison item is red
          else if (map[selmap][i][j] == 6) {
              wattron(win1, COLOR_PAIR(6));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(6));
              temp+=2;
          }
          // Gate is Bright pink
          else if (map[selmap][i][j] == 7) {
              wattron(win1, COLOR_PAIR(7));
              mvwprintw(win1, i, temp, "%d ", map[selmap][i][j]);
              wattroff(win1, COLOR_PAIR(7));
              temp+=2;
          }
      }
  }
  wrefresh(win1);
}
//initialize map function---------------------------------------------------
void initialize_map(int selmap){
  for (int i=0; i<30; i++){
    for(int j=0; j<30; j++){
      if (map[selmap][i][j]==5||map[selmap][i][j]==6){
        map[selmap][i][j]=0;
      }
      if(map[selmap][i][j]==7){
        map[selmap][i][j]==1;
      }
    }
  }
}
