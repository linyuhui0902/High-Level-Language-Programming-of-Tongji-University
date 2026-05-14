/*2553725 林于蕙 卓11*/
#include<iostream>
#include<ctime>
#include <conio.h> 
#include <windows.h>  
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
static void print_col_labels(int cols)
{
    int j;
    cout << "  |";
    for (j = 1; j <= cols; ++j) {
        if (j <= 9) 
            cout << j;
        else 
            cout << (char)('a' + (j - 10));
        if (j != cols) 
            cout << ' ';
    }
    cout << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void Print_InitBoard_diffcult(void* board, int difficulty)
{
    int rows, cols;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        rows = b->rows;
        cols = b->cols;
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows;
        cols = b->cols;
    }
    else if (difficulty == 3) {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows;
        cols = b->cols;
    }
    else 
        return;
    int i, j;
    cout << "内部数组：" << endl;
    print_col_labels(cols);
    cout << "--+";
    for (j = 1; j <= cols; ++j) 
        cout << (j == 1 ? "-" : "--");
    cout << "---" << endl;
    for (i = 1; i <= rows; ++i) {
        char alph = (char)('A' + (i - 1));
        cout << alph << " |";
        for (j = 1; j <= cols; ++j) {
            cout << 'X';
            if (j != cols) cout << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void Print_TrueBoard_diffcult(void* board, int difficulty)
{
    int rows, cols;
    char boom[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1];
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= MAX_ROWS_1; ++i)
            for (int j = 0; j <= MAX_COLUMNS_1; ++j)
                boom[i][j] = b->boom[i][j];
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= MAX_ROWS_2; ++i)
            for (int j = 0; j <= MAX_COLUMNS_2; ++j)
                boom[i][j] = b->boom[i][j];
    }
    else if (difficulty == 3) {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows;
        cols = b->cols;
        for (int i = 0; i <= MAX_ROWS_3; ++i)
            for (int j = 0; j <= MAX_COLUMNS_3; ++j)
                boom[i][j] = b->boom[i][j];
    }
    else
        return;
    int i, j;
    cout << "内部数组：" << endl;
    print_col_labels(cols);
    cout << "--+";
    for (j = 1; j <= cols; ++j) 
        cout << (j == 1 ? "-" : "--");
    cout << "---" << endl;
    for (i = 1; i <= rows; ++i) {
        char alph = (char)('A' + (i - 1));
        cout << alph << " |";
        for (j = 1; j <=cols; ++j) {
            cout << boom[i][j];
            if (j != cols) cout << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ****************************************************************************/
static void Print_CurrentBoard_diffcult(void* board, int difficulty, int choose)
{
    int rows = 0, cols = 0;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        rows = b->rows;
        cols = b->cols;
        if (choose == 2)
            cout << "点开后的数组：" << endl;
        if (choose == 3 || choose == 4)
            cout << "当前数组：" << endl;
        print_col_labels(cols);
        cout << "--+";
        for (int j = 1; j <= cols; ++j)
            cout << (j == 1 ? "-" : "--");
        cout << "---" << endl;
        for (int i = 1; i <= rows; ++i) {
            char alph = (char)('A' + (i - 1));
            cout << alph << " |";
            for (int j = 1; j <= cols; ++j) {
                if (b->marked[i][j] == 1) {
                    cct_setcolor(12, 0);
                    cout << b->cover[i][j];
                    cct_setcolor(0, 7);
                    if (j != cols)
                        cout << ' ';
                }
                else {
                    if (b->opened[i][j]) {
                        cct_setcolor(14, b->cover[i][j] - '0');
                        cout << b->cover[i][j];
                        cct_setcolor(0, 7);
                        if (j != cols)
                            cout << ' ';
                    }
                    else {
                        cout << b->cover[i][j];
                        if (j != cols)
                            cout << ' ';
                    }
                }
            }
            cout << endl;
        }
        cout << endl << endl;
        return;
    
    }
    if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows; 
        cols = b->cols;
        if (choose == 2) 
            cout << "点开后的数组：" << endl;
        if (choose == 3 || choose == 4) 
            cout << "当前数组：" << endl;
        print_col_labels(cols);
        cout << "--+";
        for (int j = 1; j <= cols; ++j) 
            cout << (j == 1 ? "-" : "--");
        cout << "---" << endl;
        for (int i = 1; i <= rows; ++i) {
            char alph = (char)('A' + (i - 1));
            cout << alph << " |";
            for (int j = 1; j <= cols; ++j) {
                if (b->marked[i][j] == 1) {
                    cct_setcolor(12, 7);
                    cout << b->cover[i][j];
                    cct_setcolor(0, 7);
                    if (j != cols) 
                        cout << ' ';
                }
                else {
                    if (b->opened[i][j]) {
                        cct_setcolor(14, b->cover[i][j] - '0');
                        cout << b->cover[i][j];
                        cct_setcolor(0, 7);
                        if (j != cols)
                            cout << ' ';
                    }
                    else {
                        cout << b->cover[i][j];
                        if (j != cols) 
                            cout << ' ';
                    }
                }
            }
            cout << endl;
        }
        cout << endl << endl;
        return;
    }

    if (difficulty == 3) {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows; 
        cols = b->cols;
        if (choose == 2) 
            cout << "点开后的数组：" << endl;
        if (choose == 3 || choose == 4) 
            cout << "当前数组：" << endl;
        print_col_labels(cols);
        cout << "--+";
        for (int j = 1; j <= cols; ++j)
            cout << (j == 1 ? "-" : "--");
        cout << "---" << endl;
        for (int i = 1; i <= rows; ++i) {
            char alph = (char)('A' + (i - 1));
            cout << alph << " |";
            for (int j = 1; j <= cols; ++j) {
                if (b->marked[i][j] == 1) {
                    cct_setcolor(12, 7);
                    cout << b->cover[i][j];
                    cct_setcolor(0, 7);
                    if (j != cols) cout << ' ';
                }
                else {
                    if (b->opened[i][j]) {
                        cct_setcolor(14, b->cover[i][j] - '0');
                        cout << b->cover[i][j];
                        cct_setcolor(0, 7);
                        if (j != cols)
                            cout << ' ';
                    }
                    else {
                        cout << b->cover[i][j];
                        if (j != cols) cout << ' ';
                    }
                }
            }
            cout << endl;
        }
        cout << endl << endl;
        return;
    }

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ****************************************************************************/
static int Input_Parse(int choose, int rows, int cols, int* out_r, int* out_c)
{
    *out_r = *out_c = 0;
    while (1) {
        int ch = _getch();
        if (ch == '&') {
            if (choose == 4) {
                putchar('&');
                return IR_TIME;
            }
            continue;
        }
        if (ch == 'q' || ch == 'Q') {
            putchar((char)ch);
            return IR_QUIT;
        }
        if (ch == '@') {
            if (choose == 4)
                putchar('@');
            else
                continue;
            int rowch = _getch();
            if (rowch >= 'A' && rowch <= 'Z') {
                cout << (char)rowch;
                *out_r = rowch - 'A' + 1;
                if (*out_r < 1 || *out_r > rows) 
                    continue;
            }
            else 
                continue;
            while (1) {
                int colch = _getch();
                if (colch >= '1' && colch <= '9') 
                    *out_c = colch - '0';
                else if (colch >= 'a' && colch <= 'z') 
                    *out_c = colch - 'a' + 10;
                else 
                    continue;
                if (*out_c < 1 || *out_c > cols) 
                    continue;
                if (cols <= 9 && (colch < '1' || colch > '9')) 
                    continue;
                if (*out_c >= 10 && (colch < 'a' || colch > 'z')) 
                    continue;
                cout << (char)colch;
                return IR_MARK;
            }
        }
        if (ch == '#') {
            if (choose == 4) 
                putchar('#');
            else
                continue;
            int rowch = _getch();
            if (rowch >= 'A' && rowch <= 'Z') {
                cout << (char)rowch;
                *out_r = rowch - 'A' + 1;
                if (*out_r < 1 || *out_r > rows) 
                    continue;
            }
            else 
                continue;
            while (1) {
                int colch = _getch();
                if (colch >= '1' && colch <= '9') 
                    *out_c = colch - '0';
                else if (colch >= 'a' && colch <= 'z') 
                    *out_c = colch - 'a' + 10;
                else 
                    continue;
                if (*out_c < 1 || *out_c > cols) 
                    continue;
                if (cols <= 9 && (colch < '1' || colch > '9')) 
                    continue;
                if (*out_c >= 10 && (colch < 'a' || colch > 'z')) 
                    continue;
                cout << (char)colch;
                return IR_UNMARK;
            }
        }
        if (ch >= 'A' && ch <= 'Z') {
            *out_r = ch - 'A' + 1;
            if (*out_r < 1 || *out_r > rows) 
                continue;
            putchar((char)ch);
            while (1) {
                int colch = _getch();
                if (colch >= '1' && colch <= '9') 
                    *out_c = colch - '0';
                else if (colch >= 'a' && colch <= 'z') 
                    *out_c = colch - 'a' + 10;
                else 
                    continue;
                if (*out_c < 1 || *out_c > cols) 
                    continue;
                if (cols <= 9 && (colch < '1' || colch > '9')) 
                    continue;
                if (*out_c >= 10 && (colch < 'a' || colch > 'z')) 
                    continue;
                putchar((char)colch);
                return IR_COORD;
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
 ****************************************************************************/
static void RunSpec_generic(int choose, int difficulty, void* board)
{
    LARGE_INTEGER freq, begin, now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&begin);

    int r = 0, c = 0;
    int rows = 0, cols = 0, mines = 0;
    int* initialized = NULL;

    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        rows = b->rows;
        cols = b->cols;
        mines = b->mines;
        initialized = &(b->initialized);
    }
    else if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        rows = b->rows;
        cols = b->cols;
        mines = b->mines;
        initialized = &(b->initialized);
    }
    else if (difficulty == 3) {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows;
        cols = b->cols;
        mines = b->mines;
        initialized = &(b->initialized);
    }
    else
        return;
    int first_click = (*initialized == 0);
    if (choose == 1) {
        if (!*initialized) {
            if (difficulty == 1) {
                Board_diffcult1* b = (Board_diffcult1*)board;
                srand((unsigned int)time(0));
                int placed = 0;
                while (placed < mines) {
                    int x = rand() % rows + 1;
                    int y = rand() % cols + 1;
                    if (b->boom[x][y] != '*') {
                        b->boom[x][y] = '*';
                        ++placed;
                    }
                }
                recompute_numbers_diffcult(b, 1);
            }
            if (difficulty == 2) {
                Board_diffcult2* b = (Board_diffcult2*)board;
                srand((unsigned int)time(0));
                int placed = 0;
                while (placed < mines) {
                    int x = rand() % rows + 1;
                    int y = rand() % cols + 1;
                    if (b->boom[x][y] != '*') {
                        b->boom[x][y] = '*';
                        ++placed;
                    }
                }
                recompute_numbers_diffcult(b, 2);
            }
            if (difficulty == 3) {
                Board_diffcult3* b = (Board_diffcult3*)board;
                srand((unsigned int)time(0));
                int placed = 0;
                while (placed < mines) {
                    int x = rand() % rows + 1;
                    int y = rand() % cols + 1;
                    if (b->boom[x][y] != '*') {
                        b->boom[x][y] = '*';
                        ++placed;
                    }
                }
                recompute_numbers_diffcult(b, 3);
            }
            *initialized = 1;
        }
        Print_TrueBoard_diffcult(board, difficulty);
        switch (difficulty) {
            case 1:
                to_be_continued(0, 0, MAX_ROWS_1 + 5);
                break;
            case 2:
                to_be_continued(0, 0, MAX_ROWS_2 + 5);
                break;
            case 3:
                to_be_continued(0, 0, MAX_ROWS_3 + 5);
                break;
        }
        return;
    }

    Print_InitBoard_diffcult(board, difficulty);

    if (choose == 2) {
        cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：Gf/A1，按Q/q退出）：";
        int t = Input_Parse(choose, rows, cols, &r, &c);
        if (t == IR_QUIT) {
            cout << endl;
            return;
        }
        if (t == IR_COORD) {
            cout << endl;
            if (!*initialized) {
                if (!regenerate_with_safe_center(board, difficulty, mines, r, c))
                    return;
                *initialized = 1;
            }
            Expand_region_diffcult(board, difficulty, r, c);
            Print_CurrentBoard_diffcult(board, difficulty, choose);
        }
        switch (difficulty) {
            case 1:
                to_be_continued(0, 0, (MAX_ROWS_1 + 5) * 2);
                break;
            case 2:
                to_be_continued(0, 0, (MAX_ROWS_2 + 5) * 2);
                break;
            case 3:
                to_be_continued(0, 0, (MAX_ROWS_3 + 5) * 2);
                break;
        }
        return;
    }
    if (choose == 3 || choose == 4) {
        while (1) {
            if (choose == 3)
                cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：Gf/A1，按Q/q退出）：";
            if (choose == 4)
                cout << "输入纵横坐标（如Gf、A1，按q退出，&显示时间，@A3表示标记A3为雷，#A3表示取消A3标记）：";
            int t = Input_Parse(choose, rows, cols, &r, &c);
            while (t == IR_TIME) {
                QueryPerformanceCounter(&now);
                double elapsed = (double)(now.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
                cout << endl << "已运行时间：" << elapsed << "秒" << endl;
                if (choose == 4)
                    cout << "输入纵横坐标（如Gf、A1，按q退出，&显示时间，@A3表示标记A3为雷，#A3表示取消A3标记）：";
                t = Input_Parse(choose, rows, cols, &r, &c);
            }
            if (t == IR_QUIT) {
                cout << endl;
                return;
            }
            if (t == IR_MARK) {
                if (difficulty == 1) {
                    Board_diffcult1* b = (Board_diffcult1*)board;
                    if (b->opened[r][c] == 0)
                        b->marked[r][c] = 1;
                }
                if (difficulty == 2) {
                    Board_diffcult2* b = (Board_diffcult2*)board;
                    if (b->opened[r][c] == 0)
                        b->marked[r][c] = 1;
                }
                if (difficulty == 3) {
                    Board_diffcult3* b = (Board_diffcult3*)board;
                    if (b->opened[r][c] == 0)
                        b->marked[r][c] = 1;
                }
                cout << endl << endl;
                Print_CurrentBoard_diffcult(board, difficulty, choose);
                continue;
            }
            if (t == IR_UNMARK) {
                if (difficulty == 1) {
                    Board_diffcult1* b = (Board_diffcult1*)board;
                    if (b->marked[r][c] == 1)
                        b->marked[r][c] = 0;
                }
                if (difficulty == 2) {
                    Board_diffcult2* b = (Board_diffcult2*)board;
                    if (b->marked[r][c] == 1)
                        b->marked[r][c] = 0;
                }
                if (difficulty == 3) {
                    Board_diffcult3* b = (Board_diffcult3*)board;
                    if (b->marked[r][c] == 1)
                        b->marked[r][c] = 0;
                }
                cout << endl << endl;
                Print_CurrentBoard_diffcult(board, difficulty, choose);
                continue;
            }
            if (t == IR_COORD) {
                if (!*initialized) {
                    if (!regenerate_with_safe_center(board, difficulty, mines, r, c)) 
                        continue;
                    *initialized = 1;
                }
                cout << endl;
                Expand_region_diffcult(board, difficulty, r, c);
                Print_CurrentBoard_diffcult(board, difficulty, choose);
                int win = Judge_win_diffcult(board, difficulty);
                if (win) {
                    cout << "恭喜胜利，游戏结束" << endl;
                    if (choose == 4) {
                        QueryPerformanceCounter(&now);
                        double elapsed = (double)(now.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
                        cout << "共用时:" << elapsed << "秒" << endl;
                    }
                    break;
                }

                int exploded = 0;
                if (difficulty == 1) {
                    Board_diffcult1* b = (Board_diffcult1*)board;
                    if (b->opened[r][c] && b->boom[r][c] == '*')
                        exploded = 1;
                }
                if (difficulty == 2) {
                    Board_diffcult2* b = (Board_diffcult2*)board;
                    if (b->opened[r][c] && b->boom[r][c] == '*')
                        exploded = 1;
                }
                if (difficulty == 3) {
                    Board_diffcult3* b = (Board_diffcult3*)board;
                    if (b->opened[r][c] && b->boom[r][c] == '*')
                        exploded = 1;
                }

                if (exploded) {
                    cout << "你输了，游戏结束" << endl;
                    if (choose == 4) {
                        QueryPerformanceCounter(&now);
                        double elapsed = (double)(now.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
                        cout << "共用时:" << elapsed << "秒" << endl;
                    }
                    cout << "按回车键继续...";
                    while (_getch() != '\r')
                        ;
                    cout << endl;
                    break;
                }
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
static void spec_for_sub_choose(int sub_choose, int* rows, int* cols, int* mines)
{
    if (sub_choose == 1) { 
        *rows = MAX_ROWS_1;
        *cols = MAX_COLUMNS_1; 
        *mines = 10; 
        return; 
    }
    else if (sub_choose == 2) { 
        *rows = MAX_ROWS_2; 
        *cols = MAX_COLUMNS_2; 
        *mines = 40; 
        return; 
    }
    else {
        *rows = MAX_ROWS_3;
        *cols = MAX_COLUMNS_3; 
        *mines = 100; 
        return; 
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void PlayWithSpec(int rows, int cols, int mines, int choose)
{
    if (rows == MAX_ROWS_1 && cols == MAX_COLUMNS_1) {
        Board_diffcult1 b;
        b.rows = MAX_ROWS_1;
        b.cols = MAX_COLUMNS_1;
        b.mines = mines;
        b.initialized = 0;
        for (int i = 0; i <= b.rows; ++i)
            for (int j = 0; j <= b.cols; ++j) {
                b.boom[i][j] = '0';
                b.cover[i][j] = 'X';
                b.opened[i][j] = 0;
                b.marked[i][j] = 0;
            }
        RunSpec_generic(choose, 1,(void*)&b);
        return;
    }

    if (rows == MAX_ROWS_2 && cols == MAX_COLUMNS_2) {
        Board_diffcult2 b;
        b.rows = MAX_ROWS_2; 
        b.cols = MAX_COLUMNS_2; 
        b.mines = mines;
        b.initialized = 0;
        for (int i = 0; i <= b.rows; ++i)
            for (int j = 0; j <= b.cols; ++j) {
                b.boom[i][j] = '0';
                b.cover[i][j] = 'X';
                b.opened[i][j] = 0;
                b.marked[i][j] = 0;
            }
        RunSpec_generic(choose, 2, (void*)&b);
        return;
    }
    Board_diffcult3 b;
    b.rows = MAX_ROWS_3; 
    b.cols = MAX_COLUMNS_3;
    b.mines = mines;
    b.initialized = 0;
    for (int i = 0; i <= b.rows; ++i)
        for (int j = 0; j <= b.cols; ++j) {
            b.boom[i][j] = '0';
            b.cover[i][j] = 'X';
            b.opened[i][j] = 0;
            b.marked[i][j] = 0;
        }
    RunSpec_generic(choose, 3, (void*)&b);
}

void PlayBysub_choose(int sub_choose, int choose)
{
    int rows, cols, mines;
    spec_for_sub_choose(sub_choose, &rows, &cols, &mines);
    PlayWithSpec(rows, cols, mines, choose);
}