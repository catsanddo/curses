#include <stdio.h>
#include <curses.h>

int main(void)
{
    initscr();
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    printw("Hello, World!\n");
    attroff(COLOR_PAIR(1));
    getch();

    endwin();

    return 0;
}
