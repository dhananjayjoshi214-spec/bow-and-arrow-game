#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 50
#define BOW_X 2

int targetY = 10;
int arrowY = -1;
int arrowX = -1;
int hit = 0;

void drawGame() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == BOW_X && y == HEIGHT / 2) {
                printf(">");
            } else if (x == WIDTH - 2 && y == targetY) {
                printf("O");
            } else if (x == arrowX && y == arrowY) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\nPress SPACE to shoot. Hit the target (O)!\n");
    if (hit == 1)
        printf("?? Hit!\n");
    else if (hit == -1)
        printf("? Miss!\n");
}

void updateTarget() {
    static int dir = 1;
    targetY += dir;
    if (targetY <= 1 || targetY >= HEIGHT - 2)
        dir = -dir;
}

void updateArrow() {
    if (arrowX != -1) {
        arrowX++;
        if (arrowX >= WIDTH - 2) {
            if (arrowY == targetY)
                hit = 1;
            else
                hit = -1;
            arrowX = -1;
        }
    }
}

void shootArrow() {
    if (arrowX == -1) {
        arrowX = BOW_X + 1;
        arrowY = HEIGHT / 2;
        hit = 0;
    }
}

int main() {
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') {
                shootArrow();
            } else if (ch == 27) { // ESC to quit
                break;
            }
        }
        updateTarget();
        updateArrow();
        drawGame();
        Sleep(100);
    }
    return 0;
}

