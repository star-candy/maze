#include "move.h"

/*int x = 40;
int y = 5;
int main()
{
    GotoXY(x, y);
    printf("ㅁ");
    CursorView(0);
    while (1)
    {
        printl();
        Moveㅁ();
    }
    return 0;
}

   
void Move()
{
    int nkey;
    if (_kbhit)
    {
        nkey = _getch();

        if (nkey == ARROW)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                system("cls");
                GotoXY(x, --y);
                printf("ㅁ");
                break;
            case DOWN:
                system("cls");
                GotoXY(x, ++y);
                printf("ㅁ");
                break;
            case LEFT:
                system("cls");
                GotoXY(--x, y);
                printf("ㅁ");
                if(x == 60)
                {
                    exit(0);
                }
                break;
            case RIGHT:
                system("cls");
                GotoXY(++x, y);
                printf("ㅁ");
                if (x == 60)
                {
                    exit(0);
                }
                break;

            }
        }
    }
}

void printl()
{
    int xl = 60;
    int yl = 0;
    
    for (int yl = 0; yl < 30; yl++)
    {
    GotoXY(xl, yl);
    printf("|");
    }

}

void CursorView(char show)
{
    CONSOLE_CURSOR_INFO ConsoleCursor; //구조체
    ConsoleCursor.bVisible = show; //커서 노출 
    ConsoleCursor.dwSize = 1; //커서 무께
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}*/

