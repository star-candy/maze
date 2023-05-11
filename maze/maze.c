#include "maze.h"

int main(void)
{
    int row = 2, col = 1;
    char level;
    CursorView(0);

    GotoXY(XP, YP - 3);
    printf("�̷�ã�� ����\n");
    GotoXY(XP, YP - 2);

    printf("���̵��� �����ϼ���. (1, 2, 3) ");
    scanf("%c", &level);
    LoadMaze(level);
    
    start = clock();

    while (1)
    {
        PrintMazeGame();
        MoveMaze(&row, &col);
    }
}

void LoadMaze(char num)
{
    char path[20] = "./Maze";
    strcat(path, &num);//strcat : ���ڿ� ��ġ��
    strcat(path, ".txt");//path�� ./Maze(num).txt�� ����

    char str_tmp[50] = { 0, };
    FILE* f = fopen(path, "r");//fopen : ���� ����

    for (int i = 0; i < SIZE; i++)
    {
        fgets(str_tmp, 50, f);//   FILE* f�� ���� str_tmp�� ����
        char* ptr = strtok(str_tmp, "\t");// /t = tab��ŭ ����
        for (int j = 0; j < SIZE; j++)
        {
            maze[i][j] = *ptr;//tab���� strtok���� �߸� ���� maze���ڿ��� ����
            ptr = strtok(NULL, "\t");//tab���� �߸��� ���� ���ڿ� ��ȯ
        }
    }
    fclose(f); //���� �ݱ�
}
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintMazeGame()
{
    for (int i = 0; i < SIZE; i++)
    {
        GotoXY(XP, YP + i);
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("��");
            else if (maze[i][j] == 'y')
                printf("��");
            else if (maze[i][j] == '0')
                printf("��");
            else
                printf("��");
        }
        printf("\n");
    }
}

void CursorView(char show)
{
    CONSOLE_CURSOR_INFO ConsoleCursor; //����ü
    ConsoleCursor.bVisible = show; //Ŀ�� ���� 
    ConsoleCursor.dwSize = 1; //Ŀ�� ����
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

//up244.72 D244.80 L244.75 R244.77 ����Ű ��� getch�ι� ȣ��(2byte)

void MoveMaze(int* row, int* col)
{
    int nkey;

    if (_kbhit())
    {
        nkey = _getch();

        if (nkey == 224)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                if (!(IsBlock(*row - 1, *col)))
                {
                    maze[*row][*col] = '0'; //road
                    maze[*row - 1][*col] = 'x'; //x ==player
                    *row -= 1;
                }
                else if (IsFinish(*row - 1, *col))
                {
                    maze[*row][*col] = '0';
                    maze[*row - 1][*col] = 'x';
                    PrintMazeGame();
                    Complete();
                }
                break;

            case DOWN:
               
                if (!(IsBlock(*row + 1, *col)))
                {
                    maze[*row][*col] = '0';
                    maze[*row + 1][*col] = 'x';
                    *row += 1;
                }
                else if (IsFinish(*row + 1, *col))
                {
                    maze[*row][*col] = '0';
                    maze[*row + 1][*col] = 'x';
                    PrintMazeGame();
                    Complete();
                }
                break;

            case LEFT:
                if (!(IsBlock(*row, *col - 1)))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col - 1] = 'x';
                    *col -= 1;
                }
                else if (IsFinish(*row, *col - 1))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col - 1] = 'x';
                    PrintMazeGame();
                    Complete();
                }
                break;

            case RIGHT:
                if (!(IsBlock(*row, *col + 1)))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col + 1] = 'x';
                    *col += 1;
                }
                else if (IsFinish(*row, *col + 1))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col + 1] = 'x';
                    PrintMazeGame();
                    Complete();
                }
                break;
            }
        }
    }
}

int IsBlock(int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

int IsFinish(int i, int j)
{

    if (maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

void Complete()
{
    end = clock();
    res = (float)(end - start) / CLOCKS_PER_SEC;

    GotoXY(XP, YP + SIZE);
    printf("Complete!\n");
    GotoXY(XP, YP + SIZE + 1);
    printf("����ð� : %.2f��", res);
    exit(0);
}

