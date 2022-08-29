#include <ncurses.h>
#include <iostream>
#include <clocale>
#include "map.h"
#define COLOR_GRAY 8
#define COLOR_BLACK_A 9

int main() {
    setlocale(LC_ALL, "");

    initscr();
    //resize_term(75,120);
    // 
    //색 설정하기 color setting
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_YELLOW); //1번 팔레트. 노란 배경 파란 글씨
    init_pair(2, COLOR_RED, COLOR_GREEN); //초록 배경 빨간 글씨

    init_color(COLOR_GRAY, 150, 150, 150);      // Gray
    init_pair(3, COLOR_GRAY, COLOR_GRAY);       // Wall
    init_color(COLOR_BLACK_A, 0, 0, 0);         // Black 
    init_pair(4, COLOR_BLACK_A, COLOR_BLACK_A); // Immune Wall
    init_pair(8, COLOR_WHITE, COLOR_WHITE); // null box

  //배경세팅 background setting
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    border('*', '*', '*', '*', '*', '*', '*', '*');
    mvprintw(1, 45, "#SNAKE GAME made by J3#");
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

    // 각 창 설정 win1 = 게임창 win2 = 미션창 win3 = 점수창
    // window setting win1 = game board |win2 = mission board | win3= score board
    WINDOW* win1;
    WINDOW* win2;
    WINDOW* win3;

    win1 = newwin(30, 60, 5, 3); //맵 나올 부분
    wbkgd(win1, COLOR_PAIR(1));
    wattron(win1, COLOR_PAIR(1));
    mvwprintw(win1, 1, 10, "<<Press arrow keys to move snake!>>");
    wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');


    win2 = newwin(15, 35, 5, 70); //mission board
    wbkgd(win2, COLOR_PAIR(1));
    wattron(win2, COLOR_PAIR(1));
    mvwprintw(win2, 1, 13, "<<MISSION>>");
    wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');


    win3 = newwin(15, 35, 20, 70); //score board
    wbkgd(win3, COLOR_PAIR(1));
    wattron(win3, COLOR_PAIR(1));
    mvwprintw(win3, 1, 13, "<<SCORE>>");
    wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');



    // char key;
    // char selectmap[1];
    // initscr();
    // keypad(stdscr, TRUE);
    // curs_set(0);
    // noecho();
    mvprintw(3, 30, "<<Press 1,2,3, or 4 and enter key to select a map and start game! >> ");
    // scanw("%s", selectmap);
    // int selmap= selectmap[0]-'0';

    // for (int i=0;i<30;i++)
    //   for(int j=0;j<30;j++)
    // {
    //   if (map[selmap][i][j] == 0)
    //   {
    //     
    //     mvprintw(4,30,"<<Map 1 selected>>");
    //     mvwprintw(win1,i,j,"%d",map[selmap][i][j]);
    //     
    //   }
    //   else if (map[selmap][i][j] == 1)
    //   {
    //     
    //     mvprintw(4,30,"<<Map 2 selected>>");
    //     mvwprintw(win1,i,j,"%d",map[selmap][i][j]);
    //     
    //   }
    //   else if (map[selmap][i][j] == 2)
    //   {
    //
    //     mvprintw(4,30,"<<Map 3 selected>>");
    //     mvwprintw(win1,i,j,"%d",map[selmap][i][j]);
    //
    //   }
    //   else if (map[selmap][i][j] == 3)
    //   {
    //     mvprintw(4,30,"<<Map 4 selected>>");
    //     mvwprintw(win1,i,j,"%d",map[3][i][j]);
    //   }
    //   else
    //     mvprintw(4,30,"ERROR!");
    // }

    int selmap = 0; //임의 맵설정 나중에 맵 선택하도록 구현 

    // color apply
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (map[selmap][i][j] == 0) {
                wattron(win1, COLOR_PAIR(8));
                mvwprintw(win1, i, j, "%d", map[selmap][i][j]);
                wattroff(win1, COLOR_PAIR(8));
            }

            else if (map[selmap][i][j] == 1) {
                wattron(win1, COLOR_PAIR(3));
                mvwprintw(win1, i, j, "%d", map[selmap][i][j]);
                wattroff(win1, COLOR_PAIR(3));
            }
            else if (map[selmap][i][j] == 2) {
                wattron(win1, COLOR_PAIR(4));
                mvwprintw(win1, i, j, "%d", map[selmap][i][j]);
                wattroff(win1, COLOR_PAIR(4));
            }
        }
    }

// 창을 나타내는 명령어 맨 마지막에 배치 
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);

// 창 닫기 
    delwin(win1);
    delwin(win2);
    delwin(win3);

    getch();
    endwin();
    return 0;
}
