/*2553725 林于蕙 卓11*/
#include<iostream>
#include<iomanip>
#include <conio.h> 
#include <Windows.h>
#include"cmd_console_tools.h"
#include"mine_sweeper.h"
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Print_framework(int rows, int cols)
{
    cout << endl;
    for (int i = 0; i < cols; i++)
        if (i < 26)
            cout << setw(i == 10 ? 7 : 6) << char('a' + i);
        else
            cout << setw(i == 10 ? 7 : 6) << i;
    cout << endl << "  ";
    cct_setcolor(15, 0);

    cout << Topleft << " ";
    for (int c = 0; c < cols - 1; c++)
        cout << Horizontal << " " << Horizontal << " " << Horizontal_top << " ";
    cout  << Horizontal << " " << Horizontal << " " << Topright << " " << endl;

    for (int r = 0; r < rows; r++){
        for (int line = 0; line < 2; line++) {
            cct_setcolor(0, 7);
            cout << "  ";
            cct_setcolor(15, 0);
            cout << Vertical;
            for (int c = 0; c < cols; c++)
                cout << "     " << Vertical ;
            cout << " " << endl;
        }

        if (r < rows - 1) {
            cct_setcolor(0, 7);
            cout << "  ";
            cct_setcolor(15, 0);
            cout << Vertical_left << " ";
            for (int c = 0; c < cols - 1; c++)
                cout << Horizontal << " " << Horizontal << " " << Cross << " ";
            cout << Horizontal << " " << Horizontal << " " << Vertical_right << " " << endl;
        }
    }

    cct_setcolor(0, 7);
    cout << "  ";
    cct_setcolor(15, 0);
    cout << Bottomleft << " ";
    for (int c = 0; c < cols - 1; c++)
        cout << Horizontal << " " << Horizontal << " " << Horizontal_bottom << " ";
    cout << Horizontal << " " << Horizontal << " " << Bottomright << " " << endl;

    cct_setcolor(0, 7);
    for (int i = 0; i < rows; i++) {
        cct_gotoxy(0, 3 * (i + 1) + 1);
        putchar('A' + i);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Print_InitGraph(int rows, int cols)
{
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= cols; j++) {
            cct_gotoxy(6 * j - 2, 3 * i);
            cct_setcolor(6, 6);
            cout << "    ";
            cct_gotoxy(6 * j - 2, 3 * i + 1);
            cout << "    ";
            cct_setcolor(0, 7);
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Print_Leftboom(int Left_boom, int choose, int offsetX)
{
    if (choose == 9) {
        cct_gotoxy(offsetX, 0);
        cct_setcolor(0, 14);
        if (Left_boom > 0)
            cout << setw(2) << Left_boom << " ";
        else
            cout << setw(2) << 0 << " ";
        cct_setcolor(0, 7);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Print_markboom_map(void* board, int difficulty)
{
    int rows = 0, cols = 0;
    char marked[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;  
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                marked[i][j] = b->marked[i][j];
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                marked[i][j] = b->marked[i][j];
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;  
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                marked[i][j] = b->marked[i][j];
    }

    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= cols; j++) {
            if (marked[i][j] == 1){
                cct_gotoxy(6 * j - 2, 3 * i);
                cct_setcolor(12, 4);
                cout << "    ";
                cct_gotoxy(6 * j - 2, 3 * i + 1);
                cout << " ";
                cct_setcolor(12, 7);
                cout << '#';
                cct_setcolor(12, 4);
                cout << "  ";
                cct_setcolor(0, 7);
            }
            else {
                cct_gotoxy(6 * j - 2, 3 * i);
                cct_setcolor(6, 6);
                cout << "    ";
                cct_gotoxy(6 * j - 2, 3 * i + 1);
                cout << "    ";
                cct_setcolor(0, 7);
            }
        }
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void InitBoard(int difficulty, void* board)
{
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        b->rows = MAX_ROWS_1;
        b->cols = MAX_COLUMNS_1;
        b->mines = Boom_num_1;
        b->initialized = 0;

        for (int i = 0; i <= b->rows; ++i)
            for (int j = 0; j <= b->cols; ++j) {
                b->boom[i][j] = '0';
                b->cover[i][j] = 'X';
                b->opened[i][j] = 0;
                b->marked[i][j] = 0;
            }
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        b->rows = MAX_ROWS_2;
        b->cols = MAX_COLUMNS_2;
        b->mines = Boom_num_2;
        b->initialized = 0;

        for (int i = 0; i <= b->rows; ++i)
            for (int j = 0; j <= b->cols; ++j) {
                b->boom[i][j] = '0';
                b->cover[i][j] = 'X';
                b->opened[i][j] = 0;
                b->marked[i][j] = 0;
            }
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;
        b->rows = MAX_ROWS_3;
        b->cols = MAX_COLUMNS_3;
        b->mines = Boom_num_3;
        b->initialized = 0;

        for (int i = 0; i <= b->rows; ++i)
            for (int j = 0; j <= b->cols; ++j) {
                b->boom[i][j] = '0';
                b->cover[i][j] = 'X';
                b->opened[i][j] = 0;
                b->marked[i][j] = 0;
            }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Graph_Output(int choose, int difficulty, void* board)
{
    int rows = 0, cols = 0;
    char cover[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };
    char boom[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };
    char marked[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };

    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;  
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                cover[i][j] = b->cover[i][j];
                boom[i][j] = b->boom[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;  
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                cover[i][j] = b->cover[i][j];
                boom[i][j] = b->boom[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;  
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                cover[i][j] = b->cover[i][j];
                boom[i][j] = b->boom[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }

    if (choose == 5 || choose == 6) {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                cct_gotoxy(6 * j - 2, 3 * i);
                cct_setcolor(7, 7);
                cout << "    ";
                cct_gotoxy(6 * j - 2, 3 * i + 1);
                cout << " ";
                if (boom[i][j] == '0') {
                    cout << " ";
                }
                else if (boom[i][j] == '*') {
                    cct_setcolor(7, 0);
                    cout << "*";
                }
                else {
                    cct_setcolor(7, boom[i][j] - '0');
                    cout << boom[i][j];
                }
                cct_setcolor(7, 7);
                cout << "  ";
                cct_setcolor(0, 7);
            }
        }
        if (difficulty == 1)
            cct_gotoxy(0, 31);
        else
            cct_gotoxy(0, 52);
    }

    if (choose == 7 || choose == 8 || choose == 9){
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= cols; j++){
                if (cover[i][j] == 'X' && marked[i][j] != 1) {
                    cct_gotoxy(6 * j - 2, 3 * i);
                    cct_setcolor(6, 6);
                    cout << "    ";
                    cct_gotoxy(6 * j - 2, 3 * i + 1);
                    cout << "    ";
                }
                else if (cover[i][j] == 'X' && marked[i][j] == 1){
                    cct_gotoxy(6 * j - 2, 3 * i);
                    cct_setcolor(12, 4);
                    cout << "    ";
                    cct_gotoxy(6 * j - 2, 3 * i + 1);
                    cout << " ";
                    cct_setcolor(12, 7);
                    cout << '#';
                    cct_setcolor(12, 4);
                    cout << "  ";
                }
                else{
                    cct_gotoxy(6 * j - 2, 3 * i);
                    cct_setcolor(7, 7);
                    cout << "    ";
                    cct_gotoxy(6 * j - 2, 3 * i + 1);
                    cout << " ";
                    if (boom[i][j] == '0') {
                        cout << " ";
                    }
                    else if (boom[i][j] == '*') {
                        cct_setcolor(7, 0);
                        cout << "*";
                    }
                    else {
                        cct_setcolor(7, boom[i][j] - '0');
                        cout << boom[i][j];
                    }
                    cct_setcolor(7, 7);
                    cout << "  ";
                }
            }
        }
    }
    cct_setcolor(0, 7);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Mouse_Operation(int choose, int difficulty, void* board, int& keydown1, int& keydown2, int& Keydown_ret, int& Left_boom)
{
    int rows = 0, cols = 0;
    char opened[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };
    char marked[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1] = { 0 };
    int infoY = 0;

    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        rows = b->rows;
        cols = b->cols;
        infoY = 30;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                opened[i][j] = b->opened[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows;
        cols = b->cols;
        infoY = 51;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                opened[i][j] = b->opened[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows;
        cols = b->cols;
        infoY = 51;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j) {
                opened[i][j] = b->opened[i][j];
                marked[i][j] = b->marked[i][j];
            }
    }

    bool loop = 1;
    int X = 0, Y = 0;
    int Event, Maction;
    int keycode1, keycode2;
    cct_enable_mouse();
    cct_setcursor(CCT_CURSOR_INVISIBLE);

    while (loop)
    {
        Event = cct_read_keyboard_and_mouse(X, Y, Maction, keycode1, keycode2);
        if (Event == CCT_MOUSE_EVENT)
        {
            cct_gotoxy(0, infoY);
            bool Legical = false;
            cout << "[当前光标]";
            switch (Maction)
            {
                case MOUSE_ONLY_MOVED:
                    for (int i = 1; i <= rows; i++) {
                        for (int j = 1; j <= cols; j++){
                            if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1){
                                Legical = true;
                                char ch = 'A';
                                char ch2 = 'a';
                                if (j > 26)
                                    cout << " " << (char)(ch + i - 1) << "行" <<  j - 1 << "列 ";
                                else
                                    cout << " " << (char)(ch + i - 1) << "行" << (char)(ch2 + j - 1) << "列 ";
                                break;
                            }
                        }
                    }
                    if (!Legical)
                        cout << " 位置非法";
                    break;

                case MOUSE_LEFT_BUTTON_CLICK:
                    for (int i = 1; i <= rows; i++)  {
                        for (int j = 1; j <= cols; j++) {
                            if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1){
                                if (choose == 6){
                                    loop = false;
                                    break;
                                }
                                keydown1 = i;
                                keydown2 = j;
                                if (marked[keydown1][keydown2] != 1)
                                    Legical = true;
                                if (marked[keydown1][keydown2] == 2)
                                    marked[keydown1][keydown2] = 0;
                            }
                        }
                    }
                    if (Legical)
                        loop = 0;
                    break;

                case MOUSE_RIGHT_BUTTON_CLICK:
                    if (choose == 8 || choose == 9) {
                        for (int i = 1; i <= rows; i++){
                            for (int j = 1; j <= cols; j++) {
                                if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1) {
                                    Legical = true;
                                    keydown1 = i;
                                    keydown2 = j;
                                    if (opened[i][j] == 0 && marked[i][j] != 1){
                                        marked[i][j] = 1;
                                        Left_boom--;
                                    }
                                    else if (marked[i][j] == 1){
                                        marked[i][j] = 2;
                                        Left_boom++;
                                    }
                                }
                            }
                        }
                    }
                    if (Legical)
                        loop = 0;
                    break;
                default:
                    break;
            }
        }
        else if ((choose == 8 || choose == 9) && Event == CCT_KEYBOARD_EVENT) {
            if (keycode1 == 27){
                loop = 0;
                Keydown_ret = 1;
                break;
            }
            if (keycode1 == 32 && choose == 9) {
                loop = 0;
                Keydown_ret = 2;
                break;
            }
        }
    }

    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                b->marked[i][j] = marked[i][j];
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                b->marked[i][j] = marked[i][j];
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;
        for (int i = 0; i <= rows; ++i)
            for (int j = 0; j <= cols; ++j)
                b->marked[i][j] = marked[i][j];
    }

    cct_disable_mouse();
    cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);


}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Graph_main(int difficulty, int choose)
{
    LARGE_INTEGER tick, start_point, end_point;
    QueryPerformanceFrequency(&tick);    
    QueryPerformanceCounter(&start_point); 
    end_point = start_point;

    int rows = 0, cols = 0, mines = 0;
    int console_width = 0, console_height = 0;
    int infoY = 0;

    if (difficulty == 1) {
        rows = MAX_ROWS_1;
        cols = MAX_COLUMNS_1;
        mines = Boom_num_1;
        console_width = 59;
        console_height = 35;
        infoY = 30;
    }
    else if (difficulty == 2) {
        rows = MAX_ROWS_2;
        cols = MAX_COLUMNS_2;
        mines = Boom_num_2;
        console_width = 101;
        console_height = 56;
        infoY = 51;
    }
    else {
        rows = MAX_ROWS_3;
        cols = MAX_COLUMNS_3;
        mines = Boom_num_3;
        console_width = 185;
        console_height = 56;
        infoY = 51;
    }

    cct_setfontsize("点阵字体", 16, 8);
    cct_setconsoleborder(console_width, console_height, console_width, console_height);

    void* board = NULL;
    Board_diffcult1 board1;
    Board_diffcult2 board2;
    Board_diffcult3 board3;

    if (difficulty == 1) {
        InitBoard(1, &board1);
        board = &board1;
    }
    else if (difficulty == 2) {
        InitBoard(2, &board2);
        board = &board2;
    }
    else {
        InitBoard(3, &board3);
        board = &board3;
    }

    int keydown1 = 0, keydown2 = 0;
    int Keydown_ret = 0;
    int Left_boom = mines;

    Print_framework(rows, cols);

    if (choose == 7 || choose == 8 || choose == 9){
        if (choose == 8) {
            cct_gotoxy(0, 0);
            cout << "按Esc退出";
        }
        if (choose == 9) {
            cct_gotoxy(0, 0);
            cout << "按Esc退出，空格显示时间  ";
            cct_setcolor(0, 14);
            cout << "剩余雷数：" << setw(2) << Left_boom;
        }

        Print_InitGraph(rows, cols);

        Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
        Print_Leftboom(Left_boom, choose, 35);

        while (Keydown_ret == 2)
        {
            QueryPerformanceCounter(&end_point);
            double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;

            cct_gotoxy(39, 0);
            cct_setcolor(0, 14);
            cout << "当前时间:" << played_time << "秒";
            cct_setcolor(0, 7);
            Keydown_ret = 0;
            Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
            Print_Leftboom(Left_boom, choose, 35);
        }

        if (Keydown_ret == 1){
            cct_gotoxy(0, infoY);
            return;
        }

        cct_gotoxy(39, 0);
        cout << "                   ";
        cct_setcolor(0, 7);

        int isMarked = 0;
        if (difficulty == 1) {
            Board_diffcult1* b = (Board_diffcult1*)board;
            isMarked = b->marked[keydown1][keydown2];
        }
        else if (difficulty == 2) {
            Board_diffcult2* b = (Board_diffcult2*)board;
            isMarked = b->marked[keydown1][keydown2];
        }
        else {
            Board_diffcult3* b = (Board_diffcult3*)board;
            isMarked = b->marked[keydown1][keydown2];
        }

        while (isMarked != 0){
            Print_markboom_map(board, difficulty);
            Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
            Print_Leftboom(Left_boom, choose, 35);

            while (Keydown_ret == 2) {
                QueryPerformanceCounter(&end_point);
                double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;

                cct_gotoxy(39, 0);
                cct_setcolor(0, 14);
                cout << "当前时间:" << played_time << "秒";
                cct_setcolor(0, 7);
                Keydown_ret = 0;
                Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
                Print_Leftboom(Left_boom, choose, 35);
            }

            if (Keydown_ret == 1) {
                cct_gotoxy(0, infoY);
                return;
            }

            cct_gotoxy(39, 0);
            cout << "                   ";

            if (difficulty == 1) {
                Board_diffcult1* b = (Board_diffcult1*)board;
                isMarked = b->marked[keydown1][keydown2];
            }
            else if (difficulty == 2) {
                Board_diffcult2* b = (Board_diffcult2*)board;
                isMarked = b->marked[keydown1][keydown2];
            }
            else {
                Board_diffcult3* b = (Board_diffcult3*)board;
                isMarked = b->marked[keydown1][keydown2];
            }
        }
    }

    int* initialized = NULL;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        initialized = &(b->initialized);
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        initialized = &(b->initialized);
    }
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;
        initialized = &(b->initialized);
    }

    int first_click = (*initialized == 0);

    if (choose == 5 || choose == 6 || choose == 7 || choose == 8 || choose == 9) {
        if (!*initialized){
            if (difficulty == 1){
                Board_diffcult1* b = (Board_diffcult1*)board;
                if (!regenerate_with_safe_center(board, difficulty, mines, keydown1, keydown2))
                    return;
                *initialized = 1;
            }
            else if (difficulty == 2) {
                Board_diffcult2* b = (Board_diffcult2*)board;
                if (!regenerate_with_safe_center(board, difficulty, mines, keydown1, keydown2)) 
                    return;
                *initialized = 1;
            }
            else
            {
                Board_diffcult3* b = (Board_diffcult3*)board;
                if (!regenerate_with_safe_center(board, difficulty, mines, keydown1, keydown2))
                    return;
                *initialized = 1;
            }
        }
    }

    if (choose == 5){
        Graph_Output(choose, difficulty, board);
        cout << endl;
        cout << "按回车键继续...";
        while (_getch() != '\r')
            ;
        cout << endl;
        return;
    }

    if (choose == 6){
        Graph_Output(choose, difficulty, board);
        Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
        cout << endl;
        cout << "按回车键继续...";
        while (_getch() != '\r')
            ;
        cout << endl;
        return;
    }

    if (choose == 7) {
        Expand_region_diffcult(board, difficulty, keydown1, keydown2);
        Graph_Output(choose, difficulty, board);
        cct_gotoxy(0, infoY);
        cout << endl;
        cout << "按回车键继续...";
        while (_getch() != '\r')
            ;
        cout << endl;
        return;
    }

    if (choose == 8 || choose == 9) {
        Expand_region_diffcult(board, difficulty, keydown1, keydown2);
        Graph_Output(choose, difficulty, board);

        while (1) {
            Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
            Print_Leftboom(Left_boom, choose, 35);

            while (Keydown_ret == 2){
                QueryPerformanceCounter(&end_point);
                double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;

                cct_gotoxy(39, 0);
                cct_setcolor(0, 14);
                cout << "当前时间:" << played_time << "秒";
                cct_setcolor(0, 7);
                Keydown_ret = 0;
                Mouse_Operation(choose, difficulty, board, keydown1, keydown2, Keydown_ret, Left_boom);
                Print_Leftboom(Left_boom, choose, 35);
            }

            if (Keydown_ret == 1) {
                cct_gotoxy(0, infoY);
                return;
            }

            cct_gotoxy(39, 0);
            cout << "                   ";
            cct_setcolor(0, 7);

            int isMarkOperation = 0;
            if (difficulty == 1) {
                Board_diffcult1* b = (Board_diffcult1*)board;
                isMarkOperation = b->marked[keydown1][keydown2];
            }
            else if (difficulty == 2) {
                Board_diffcult2* b = (Board_diffcult2*)board;
                isMarkOperation = b->marked[keydown1][keydown2];
            }
            else {
                Board_diffcult3* b = (Board_diffcult3*)board;
                isMarkOperation = b->marked[keydown1][keydown2];
            }

            if (isMarkOperation == 1 || isMarkOperation == 2){
                Graph_Output(choose, difficulty, board);
                continue;
            }

            int isMine = 0;
            if (difficulty == 1) {
                Board_diffcult1* b = (Board_diffcult1*)board;
                isMine = (b->boom[keydown1][keydown2] == '*');
                if (isMine){
                    b->opened[keydown1][keydown2] = 1;
                    b->cover[keydown1][keydown2] = b->boom[keydown1][keydown2];
                    Graph_Output(choose, difficulty, board);

                    cct_gotoxy(0, infoY);
                    cct_setcolor(0, 12);
                    cout << "踩雷了！游戏结束！" << endl;
                    cct_setcolor(0, 7);

                    if (choose == 9){
                        QueryPerformanceCounter(&end_point);
                        double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;
                        cout << "游戏时间: " << played_time << "秒" << endl;
                    }
                    cout << endl;
                    cout << "按回车键继续...";
                    while (_getch() != '\r')
                        ;
                    cout << endl;
                    break;
                }
                else {
                    Expand_region_diffcult(board, difficulty, keydown1, keydown2);
                    Graph_Output(choose, difficulty, board);
                }
            }
            else if (difficulty == 2) {
                Board_diffcult2* b = (Board_diffcult2*)board;
                isMine = (b->boom[keydown1][keydown2] == '*');
                if (isMine) {
                    b->opened[keydown1][keydown2] = 1;
                    b->cover[keydown1][keydown2] = b->boom[keydown1][keydown2];
                    Graph_Output(choose, difficulty, board);

                    cct_gotoxy(0, infoY);
                    cct_setcolor(0, 12);
                    cout << "踩雷了！游戏结束！" << endl;
                    cct_setcolor(0, 7);

                    if (choose == 9) {
                        QueryPerformanceCounter(&end_point);
                        double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;
                        cout << "游戏时间: " << played_time << "秒" << endl;
                    }
                    cout << endl;
                    cout << "按回车键继续...";
                    while (_getch() != '\r')
                        ;
                    cout << endl;
                    break;
                }
                else {
                    Expand_region_diffcult(board, difficulty, keydown1, keydown2);
                    Graph_Output(choose, difficulty, board);
                }
            }
            else {
                Board_diffcult3* b = (Board_diffcult3*)board;
                isMine = (b->boom[keydown1][keydown2] == '*');
                if (isMine){
                    b->opened[keydown1][keydown2] = 1;
                    b->cover[keydown1][keydown2] = b->boom[keydown1][keydown2];
                    Graph_Output(choose, difficulty, board);

                    cct_gotoxy(0, infoY);
                    cct_setcolor(0, 12);
                    cout << "踩雷了！游戏结束！" << endl;
                    cct_setcolor(0, 7);

                    if (choose == 9){
                        QueryPerformanceCounter(&end_point);
                        double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;
                        cout << "游戏时间: " << played_time << "秒" << endl;
                    }
                    cout << endl;
                    cout << "按回车键继续...";
                    while (_getch() != '\r')
                        ;
                    cout << endl;
                    break;
                }
                else {
                    Expand_region_diffcult(board, difficulty, keydown1, keydown2);
                    Graph_Output(choose, difficulty, board);
                }
            }
            int win = Judge_win_diffcult(board,difficulty); 
            if (win){
                cct_gotoxy(0, infoY);
                cct_setcolor(0, 10);
                cout << "恭喜你！扫雷成功！" << endl;
                cct_setcolor(0, 7);
                if (choose == 9){
                    QueryPerformanceCounter(&end_point);
                    double played_time = (double)(end_point.QuadPart - start_point.QuadPart) / tick.QuadPart;
                    cout << "胜利时间: " << played_time << "秒" << endl;
                    cct_gotoxy(35, 0);
                    cct_setcolor(0, 14);
                    cout << setw(2) << 0 << " "; 
                    cct_setcolor(0, 7);
                }
                cout << endl;
                cout << "按回车键继续...";
                while (_getch() != '\r')
                    ;
                cout << endl;
                break;
            }
        }
    }
}