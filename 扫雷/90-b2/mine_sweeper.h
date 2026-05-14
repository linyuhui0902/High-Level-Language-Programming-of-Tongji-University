/*2553725 林于蕙 卓11*/
#pragma once

/* 空文件，给出的目的是防止大家把文件名弄错 */

/*mine_sweeper_menu函数*/
int mine_sweeper_menu();
int mine_sweeper_submenu();

/*mine_sweeper_base*/
const int Boom_num_1 = 10;
const int Boom_num_2 = 40;
const int Boom_num_3 = 99;
const int MAX_ROWS_1 = 9;
const int MAX_COLUMNS_1 = 9;
const int MAX_ROWS_2 = 16;
const int MAX_COLUMNS_2 = 16;
const int MAX_ROWS_3 = 16;
const int MAX_COLUMNS_3 = 30;

struct Board_diffcult1 {
    int rows;
    int cols;
    int mines;
    char boom[MAX_ROWS_1 + 1][MAX_COLUMNS_1 + 1];   
    char cover[MAX_ROWS_1 + 1][MAX_COLUMNS_1 + 1];  
    unsigned char opened[MAX_ROWS_1 + 1][MAX_COLUMNS_1 + 1];
    unsigned char marked[MAX_ROWS_1 + 1][MAX_COLUMNS_1 + 1];
    int initialized;
};
struct Board_diffcult2 {
    int rows;
    int cols;
    int mines;
    char boom[MAX_ROWS_2 + 1][MAX_COLUMNS_2 + 1];
    char cover[MAX_ROWS_2 + 1][MAX_COLUMNS_2 + 1];
    unsigned char opened[MAX_ROWS_2 + 1][MAX_COLUMNS_2 + 1];
    unsigned char marked[MAX_ROWS_2 + 1][MAX_COLUMNS_2 + 1];
    int initialized;
};
struct Board_diffcult3 {
    int rows;
    int cols;
    int mines;
    char boom[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1];
    char cover[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1];
    unsigned char opened[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1];
    unsigned char marked[MAX_ROWS_3 + 1][MAX_COLUMNS_3 + 1];
    int initialized;
};

#define IR_COORD   0   /* 成功解析到坐标 */
#define IR_MARK    1   /* 标记（@A3） */
#define IR_UNMARK  2   /* 取消标记 (#A3) */
#define IR_TIME    3   /* 查询时间 (&) */
#define IR_QUIT    4   /* 退出 (q/Q) */

void print_col_labels(int cols);
void Print_InitBoard_diffcult(void* board, int difficulty);
void Print_TrueBoard_diffcult(void* board, int difficulty);
void Print_CurrentBoard_diffcult(void* board, int difficulty, int choose);
int Input_Parse(int choose, int rows, int cols, int* out_r, int* out_c);
void RunSpec_generic(int choose, int difficulty, void* board);
void spec_for_sub_choose(int sub_choose, int* rows, int* cols, int* mines);
int regenerate_with_safe_center(void* board, int difficulty, int mines, int center_r, int center_c);
void PlayWithSpec(int rows, int cols, int mines, int choose);
void PlayBysub_choose(int sub_choose, int choose);

/*mine_sweeper_tools*/
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);
void recompute_numbers_diffcult(void* board, int difficulty);
int is_initial_safe(void* board, int difficulty, int r, int c);
void Expand_region_diffcult(void* board, int difficulty, int r0, int c0);
int Judge_win_diffcult(void* board, int difficulty);

/*mine_sweeper_graph*/
#define Topleft "╔"
#define Topright "╗" 
#define Bottomleft "╚"
#define Bottomright "╝"
#define Horizontal "═" 
#define Vertical  "║"
#define Horizontal_top "╦"
#define Horizontal_bottom "╩"
#define Vertical_left "╠"
#define Vertical_right "╣"
#define Cross "╬"

void Print_framework(int rows, int cols);
void Print_InitGraph(int rows, int cols);
void Print_Leftboom(int Left_boom, int choose, int offsetX);
void Print_markboom_map(void* board, int difficulty);
void InitBoard(int difficulty, void* board);
void Graph_Output(int choose, int difficulty, void* board);
void Mouse_Operation(int choose, int difficulty, void* board, int& keydown1, int& keydown2, int& Keydown_ret, int& Left_boom);
void Graph_main(int difficulty, int choice);
