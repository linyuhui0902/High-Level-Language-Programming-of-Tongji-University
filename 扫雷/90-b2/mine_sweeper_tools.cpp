/*2553725 林于蕙 卓11*/

/* 加入必要的头文件、命名空间、你觉得应该属于工具类的其它函数 */
#include<iostream>
#include<conio.h>
#include"mine_sweeper.h"
#include"cmd_console_tools.h"
using namespace std;
/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
void to_be_continued(const char* prompt, const int X , const int Y )
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;
	cout << endl;
	//cct_cls();

	return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ****************************************************************************/
void recompute_numbers_diffcult(void* board, int difficulty)
{
    int i, j, di, dj;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j) {
                if (b->boom[i][j] == '*')
                    continue;
                int cnt = 0;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols)
                            if (b->boom[ni][nj] == '*')
                                ++cnt;
                    }
                b->boom[i][j] = (char)('0' + cnt);
            }
        return;
    }
    if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j) {
                if (b->boom[i][j] == '*')
                    continue;
                int cnt = 0;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols)
                            if (b->boom[ni][nj] == '*')
                                ++cnt;
                    }
                b->boom[i][j] = (char)('0' + cnt);
            }
        return;
    }
    {
        Board_diffcult3* b = (Board_diffcult3*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j) {
                if (b->boom[i][j] == '*')
                    continue;
                int cnt = 0;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols)
                            if (b->boom[ni][nj] == '*')
                                ++cnt;
                    }
                b->boom[i][j] = (char)('0' + cnt);
            }
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
int is_initial_safe(void* board, int difficulty, int r, int c)
{
    int di, dj;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        if (b->boom[r][c] == '*')
            return 0;
        for (di = -1; di <= 1; ++di)
            for (dj = -1; dj <= 1; ++dj) {
                int ni = r + di, nj = c + dj;
                if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                    if (b->boom[ni][nj] == '*')
                        return 0;
                }
            }
        return 1;
    }
    if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        if (b->boom[r][c] == '*')
            return 0;
        for (di = -1; di <= 1; ++di)
            for (dj = -1; dj <= 1; ++dj) {
                int ni = r + di, nj = c + dj;
                if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                    if (b->boom[ni][nj] == '*')
                        return 0;
                }
            }
        return 1;
    }
    {
        Board_diffcult3* b = (Board_diffcult3*)board;
        if (b->boom[r][c] == '*')
            return 0;
        for (di = -1; di <= 1; ++di)
            for (dj = -1; dj <= 1; ++dj) {
                int ni = r + di, nj = c + dj;
                if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                    if (b->boom[ni][nj] == '*')
                        return 0;
                }
            }
        return 1;
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ****************************************************************************/
int regenerate_with_safe_center(void* board, int difficulty, int mines, int center_r, int center_c)
{
    int rows = 0, cols = 0;
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
    else {
        Board_diffcult3* b = (Board_diffcult3*)board;
        rows = b->rows;
        cols = b->cols;
    }
    int forbidden = 0;
    int fi, fj;
    for (fi = center_r - 1; fi <= center_r + 1; ++fi)
        for (fj = center_c - 1; fj <= center_c + 1; ++fj)
            if (fi >= 1 && fi <= rows && fj >= 1 && fj <= cols)
                ++forbidden;
    int total = rows * cols;
    int available = total - forbidden;
    if (mines > available)
        return 0;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        int i, j;
        for (i = 1; i <= rows; ++i)
            for (j = 1; j <= cols; ++j)
                b->boom[i][j] = '0';
        srand((unsigned int)time(0));
        int placed = 0;
        while (placed < mines) {
            int x = rand() % rows + 1;
            int y = rand() % cols + 1;
            if (x >= center_r - 1 && x <= center_r + 1 && y >= center_c - 1 && y <= center_c + 1)
                continue;
            if (b->boom[x][y] != '*') {
                b->boom[x][y] = '*';
                ++placed;
            }
        }
        recompute_numbers_diffcult(b, 1);
        return 1;
    }
    if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        int i, j;
        for (i = 1; i <= rows; ++i)
            for (j = 1; j <= cols; ++j)
                b->boom[i][j] = '0';
        srand((unsigned int)time(0));
        int placed = 0;
        while (placed < mines) {
            int x = rand() % rows + 1;
            int y = rand() % cols + 1;
            if (x >= center_r - 1 && x <= center_r + 1 && y >= center_c - 1 && y <= center_c + 1)
                continue;
            if (b->boom[x][y] != '*') {
                b->boom[x][y] = '*';
                ++placed;
            }
        }
        recompute_numbers_diffcult(b, 2);
        return 1;
    }
    {
        Board_diffcult3* b = (Board_diffcult3*)board;
        int i, j;
        for (i = 1; i <= rows; ++i)
            for (j = 1; j <= cols; ++j)
                b->boom[i][j] = '0';
        srand((unsigned int)time(0));
        int placed = 0;
        while (placed < mines) {
            int x = rand() % rows + 1;
            int y = rand() % cols + 1;
            if (x >= center_r - 1 && x <= center_r + 1 && y >= center_c - 1 && y <= center_c + 1)
                continue;
            if (b->boom[x][y] != '*') {
                b->boom[x][y] = '*';
                ++placed;
            }
        }
        recompute_numbers_diffcult(b, 3);
        return 1;
    }
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ****************************************************************************/
void Expand_region_diffcult(void* board, int difficulty, int r0, int c0)
{
    const int MAX_CELLS = MAX_ROWS_3 * MAX_COLUMNS_3;
    int stack_r[MAX_CELLS];
    int stack_c[MAX_CELLS];
    int top = 0;
    if (top < MAX_CELLS) {
        stack_r[top] = r0;
        stack_c[top] = c0;
        top++;
    }
    while (top > 0) {
        top--;
        int r = stack_r[top];
        int c = stack_c[top];
        if (difficulty == 1) {
            Board_diffcult1* b = (Board_diffcult1*)board;
            if (r < 1 || r > b->rows || c < 1 || c > b->cols)
                continue;
            if (b->opened[r][c])
                continue;
            b->opened[r][c] = 1;
            b->cover[r][c] = b->boom[r][c];
            if (b->boom[r][c] == '0') {
                int di, dj;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = r + di, nj = c + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                            if (!b->opened[ni][nj]) {
                                if (top < MAX_CELLS) {
                                    stack_r[top] = ni; stack_c[top] = nj; top++;
                                }
                            }
                        }
                    }
            }
        }
        else if (difficulty == 2) {
            Board_diffcult2* b = (Board_diffcult2*)board;
            if (r < 1 || r > b->rows || c < 1 || c > b->cols)
                continue;
            if (b->opened[r][c])
                continue;
            b->opened[r][c] = 1;
            b->cover[r][c] = b->boom[r][c];
            if (b->boom[r][c] == '0') {
                int di, dj;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = r + di, nj = c + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                            if (!b->opened[ni][nj]) {
                                if (top < MAX_CELLS) {
                                    stack_r[top] = ni; stack_c[top] = nj;
                                    top++;
                                }
                            }
                        }
                    }
            }
        }
        else {
            Board_diffcult3* b = (Board_diffcult3*)board;
            if (r < 1 || r > b->rows || c < 1 || c > b->cols)
                continue;
            if (b->opened[r][c])
                continue;
            b->opened[r][c] = 1;
            b->cover[r][c] = b->boom[r][c];
            if (b->boom[r][c] == '0') {
                int di, dj;
                for (di = -1; di <= 1; ++di)
                    for (dj = -1; dj <= 1; ++dj) {
                        int ni = r + di, nj = c + dj;
                        if (ni >= 1 && ni <= b->rows && nj >= 1 && nj <= b->cols) {
                            if (!b->opened[ni][nj]) {
                                if (top < MAX_CELLS) {
                                    stack_r[top] = ni; stack_c[top] = nj;
                                    top++;
                                }
                            }
                        }
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
 ****************************************************************************/
int Judge_win_diffcult(void* board, int difficulty)
{
    int i, j;
    if (difficulty == 1) {
        Board_diffcult1* b = (Board_diffcult1*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j)
                if (b->boom[i][j] != '*' && b->opened[i][j] == 0)
                    return 0;
        return 1;
    }
    if (difficulty == 2) {
        Board_diffcult2* b = (Board_diffcult2*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j)
                if (b->boom[i][j] != '*' && b->opened[i][j] == 0)
                    return 0;
        return 1;
    }
    if (difficulty == 3) {
        Board_diffcult3* b = (Board_diffcult3*)board;
        for (i = 1; i <= b->rows; ++i)
            for (j = 1; j <= b->cols; ++j)
                if (b->boom[i][j] != '*' && b->opened[i][j] == 0)
                    return 0;
        return 1;
    }
    return 0;
}