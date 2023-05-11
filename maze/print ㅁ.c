#include "print ㅁ.h"

/*int main()
{
    CursorView(0);
    while (1)
    {
        PrintDownㅁ();
        PrintUpㅁ();
    }
    return 0;
}

void PrintDownㅁ()
{
    int i = 5;
    while (i < 30)
    {
        GotoXY(40, i);
        printf("ㅁ");
        Sleep(500);
        GotoXY(40, i);
        system("cls");
        i++;
    }
    //xp 40 yp = 5
}

void PrintUpㅁ()
{
    int i = 30;
    while (i > 4)
    {
        GotoXY(40, i);
        printf("ㅁ");
        Sleep(500);
        GotoXY(40, i);
        system("cls");
        i--;
    }
    //xp 40 yp = 5

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

