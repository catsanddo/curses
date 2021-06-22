#include <curses.h>
#include <time.h>
#include <windows.h>

#define LINES 25
#define COLUMNS 40
#define MAX_SIE 50

enum Direction {
    D_UP,
    D_DOWN,
    D_LEFT,
    D_RIGHT
};

void tick(int fps);

// Global time
clock_t now;

int main(void)
{
    initscr(); noecho(); cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    resize_term(LINES, COLUMNS);

    int y = 1;
    int x = 1;
    enum Direction direction = D_RIGHT;

    box(stdscr, 0, 0);

    bool running = TRUE;
    while (running) {
        int input = getch();

        if (input == KEY_UP && direction != D_DOWN) {
            direction = D_UP;
        } else if (input == KEY_DOWN && direction != D_UP) {
            direction = D_DOWN;
        } else if (input == KEY_LEFT && direction != D_RIGHT) {
            direction = D_LEFT;
        } else if (input == KEY_RIGHT && direction != D_LEFT) {
            direction = D_RIGHT;
        }
        switch (input) {
            case 'q':
                running = FALSE;
            break;
        }

        mvprintw(y, x, " ");

        switch (direction) {
            case D_UP:
                y--;
            break;
            
            case D_DOWN:
                y++;
            break;

            case D_LEFT:
                x--;
            break;

            case D_RIGHT:
                x++;
            break;
        }

        mvprintw(y, x, "#");

        move(y, x);
        refresh();
        tick(15);
    }

    endwin();

    return 0;
}

void tick(int fps)
{
    int elapsed = clock() - now;
    elapsed = (float) elapsed / CLOCKS_PER_SEC * 1000.0;
    int spf = 1.0 / fps * 1000.0;
    Sleep(spf - elapsed);
    now = clock();
}
