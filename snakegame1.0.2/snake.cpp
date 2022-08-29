// #include "main.h"
#include <time.h>


// snake body object class---------------------------------------------------------
struct snakebody{
  int r, c, snake_len;
  snakebody(int row, int col);
  snakebody();
};
snakebody::snakebody(int row, int col){
  r=row;
  c=col;
  snake_len=3;
}
snakebody::snakebody(){
  r=0;
  c=0;
  snake_len=3;
}

// input directon function---------------------------------------------------------
int input_Direction(int input_key){
  switch(input_key) {
    case KEY_UP:
        return 0;
        break;
    case KEY_LEFT:
        return 1;
        break;
    case KEY_RIGHT:
        return 2;
        break;
    case KEY_DOWN:
        return 3;
        break;
  }
  return 1;
}

void snake_make(vector<snakebody>& snake, int selmap){
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
  int sel_r = rand()%3;

  //head setting ->snake <vector> has head positon and body position
  //######################
  // #####Important######
  //#######################
  //ex) row ==4 colum==23
  for(int i=0; i<3; i++){
    snake.push_back(snakebody(snake_positon[selmap][sel_r][0], snake_positon[selmap][sel_r][1]+i));}
  map[selmap][snake[0].r][snake[0].c] = 3; //snake head is 3

  // body setting
  for(int i=1; i<3; i++){
    map[selmap][snake[i].r][snake[i].c] = 4;} //snake body is 4
}
  // item ----------------------------------------------------------------------------------------------
void make_item(int selmap){
    srand((unsigned) time(0));
    int num_growth = rand() % 4; //0~3 growth item can be generated
    int num=0,tmpX=0,tmpY=0; //num of growth item, location

    while(num<3){ //while lower than maximum item num
      tmpX = rand()%28+1;
      tmpY = rand()%28+1;

      if(map[selmap][tmpY][tmpX] != 0) //can place item only if it's blank
        continue;

      else if(num<num_growth){
        map[selmap][tmpY][tmpX] = 5; //set the growth item location
        num++;
        continue;
      }
      map[selmap][tmpY][tmpX]=6; //set the poison item location
      num++;
    }
}


// moving process--------------------------------------------------------------------------------
void snake_move(vector<snakebody>& snake, int snake_direction, int selmap){

  int new_head_row=snake[0].r;
  int new_head_col=snake[0].c;
  switch (snake_direction) {
      case 0:
        new_head_row--;
        break;
      case 1:
        new_head_col--;
        break;
      case 2:
        new_head_col++;
        break;
      case 3:
        new_head_row++;
        break;
      default:
        break;
      }

  snake.insert(snake.begin(), snakebody(new_head_row, new_head_col));
  snake.pop_back();
  map[selmap][snake[snake.size()].r][snake[snake.size()].c] = 0;
  map[selmap][snake[0].r][snake[0].c] = 3;
  map[selmap][snake[1].r][snake[1].c] = 4;
  refresh();



}
