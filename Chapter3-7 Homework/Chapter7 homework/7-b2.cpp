/*2553725 卓11 林于蕙*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "cmd_console_tools.h"
#include "7-b2.h"
using namespace std;

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

#define Topleft "╔"
#define Topright "╗" 
#define Bottomleft "╚"
#define Bottomright "╝"
#define Horizontal "═" 
#define Vertical  "║"

 /* 例：声明仅本源程序文件需要的结构体，不要放到.h中
     仅为示例，不需要可删除 */
struct Menucontext {
    const char* title;    //标题
    int title_width;      //标题长度
    int start_x;          //左上角x坐标
    int start_y;          //左上角y坐标
    int width;            //菜单宽度，不含左右边框（+4是显示的实际列数），必须是偶数
    int high;             //菜单高度，不含上下边框（+2是显示的实际行数），
    int bg_color;         //所用背景色（注：选中项background/foreground为反显）
    int fg_color;         //所用前景色
    int total_items;      //菜单项总数
    int top_item;         //菜单顶部显示的菜单项
    int selected_item;    //当前选中项(没选为0)
    int last_top_item;    //上次绘制的顶部项
    int last_selected_item; //上次选中的项
    bool initialized;     //是否已初始化
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int is_chinese(const char* p)
{
    return ((unsigned char)*p >= 0xA1) && ((unsigned char)*p <= 0xFE) &&
        ((unsigned char)*(p + 1) >= 0xA1) && ((unsigned char)*(p + 1) <= 0xFE);//char默认是有符号，0xA1会变成-95
}
static int width_of(const char* title)
{
    int width = 0;
    const char* p = title;
    while (*p) {
        if (is_chinese(p)) {
            width += 2;
            p += 2;
        }
        else {
            width++;
            p++;
        }
    }
    return width;
}
static void put_console(int x, int y, const char* s, int bg, int fg, int buffer_cols)
{
    int out_of_bounds = (x >= buffer_cols);
    int i = (out_of_bounds ? x - buffer_cols : x);
    int j = (out_of_bounds ? y + 1 : y);
    cct_showstr(i, j, s, bg, fg);
}

static void draw_items(const char menu[][MAX_ITEM_LEN], struct Menucontext& record)
{
    int start_x = record.start_x + 2;
    int start_y = record.start_y + 1;
    int end_x = start_x + record.width - 1;
    int end_y = start_y + record.high - 1;
    int bg = record.bg_color;
    int fg = record.fg_color;
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    if (record.initialized && record.top_item == record.last_top_item) {
        int old_selected_row = -1;
        if (record.last_selected_item >= record.last_top_item + 1 &&
            record.last_selected_item <= record.last_top_item + record.high) {
            old_selected_row = record.last_selected_item - record.last_top_item - 1;
        }
        int new_selected_row = -1;
        if (record.selected_item >= record.top_item + 1 &&
            record.selected_item <= record.top_item + record.high) {
            new_selected_row = record.selected_item - record.top_item - 1;
        }
        if (old_selected_row == new_selected_row && old_selected_row != -1) {
            old_selected_row = -1;
            new_selected_row = -1;
        }
        if (old_selected_row != -1 && old_selected_row != new_selected_row) {
            int row = record.last_top_item + old_selected_row;
            const char* p = menu[row];
            int y = start_y + old_selected_row;
            for (int x = start_x; x <= end_x; x++) {
                if (is_chinese(p)) {
                    if (x == end_x || x == buffer_cols - 1)
                        put_console(x, y, " ", bg, fg, buffer_cols);
                    else {
                        char temp[3] = { p[0], p[1], 0 };
                        put_console(x, y, temp, bg, fg, buffer_cols);
                        p += 2;
                        x++;
                    }
                }
                else if ((*p) && (!is_chinese(p))) {
                    char temp[2] = { p[0], 0 };
                    put_console(x, y, temp, bg, fg, buffer_cols);
                    p++;
                }
                else
                    put_console(x, y, " ", bg, fg, buffer_cols);
            }
        }
        if (new_selected_row != -1) {
            int row = record.top_item + new_selected_row;
            const char* p = menu[row];
            int y = start_y + new_selected_row;
            int sel_bg = fg;
            int sel_fg = bg;
            for (int x = start_x; x <= end_x; x++) {
                if (is_chinese(p)) {
                    if (x == end_x || x == buffer_cols - 1)
                        put_console(x, y, " ", sel_bg, sel_fg, buffer_cols);
                    else {
                        char temp[3] = { p[0], p[1], 0 };
                        put_console(x, y, temp, sel_bg, sel_fg, buffer_cols);
                        p += 2;
                        x++;
                    }
                }
                else if ((*p) && (!is_chinese(p))) {
                    char temp[2] = { p[0], 0 };
                    put_console(x, y, temp, sel_bg, sel_fg, buffer_cols);
                    p++;
                }
                else
                    put_console(x, y, " ", sel_bg, sel_fg, buffer_cols);
            }
        }
        record.last_top_item = record.top_item;
        record.last_selected_item = record.selected_item;
        return;
    }
    for (int y = start_y; y <= end_y; y++) {
        int row = y - start_y + record.top_item;
        if (row >= record.total_items) break;

        const char* p = menu[row];
        int item_bg = bg;
        int item_fg = fg;

        if (row + 1 == record.selected_item) {
            item_bg = fg;
            item_fg = bg;
        }
        for (int x = start_x; x <= end_x; x++) {
            if (is_chinese(p)) {
                if (x == end_x || x == buffer_cols - 1)
                    put_console(x, y, " ", item_bg, item_fg, buffer_cols);
                else {
                    char temp[3] = { p[0], p[1], 0 };
                    put_console(x, y, temp, item_bg, item_fg, buffer_cols);
                    p += 2;
                    x++;
                }
            }
            else if ((*p) && (!is_chinese(p))) {
                char temp[2] = { p[0], 0 };
                put_console(x, y, temp, item_bg, item_fg, buffer_cols);
                p++;
            }
            else
                put_console(x, y, " ", item_bg, item_fg, buffer_cols);
        }
    }
    record.last_top_item = record.top_item;
    record.last_selected_item = record.selected_item;
    record.initialized = true;
}
static void draw_frames(struct Menucontext& record)
{
    int frames_width = record.width + 4;
    int frames_high = record.high + 2;
    int start_x = record.start_x;
    int start_y = record.start_y;
    int end_x = start_x + frames_width - 2;
    int end_y = start_y + frames_high - 1;
    int bg = record.bg_color;
    int fg = record.fg_color;
    int title_start_x = start_x + 2 + (record.width - record.title_width) / 2;
    if (title_start_x % 2 != 0)
        title_start_x--;  // 让标题开头就是偶数列，避免出现最后一个字符是汉字情况
    int title_end = title_start_x + record.title_width - 1;
    const char* p = record.title;
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    for (int y = start_y; y <= end_y; y++) {
        for (int x = start_x; x <= end_x; x++) {
            if (y == start_y) {
                if (x == start_x)
                    put_console(x, y, Topleft, bg, fg, buffer_cols);
                else if (x == end_x)
                    put_console(x, y, Topright, bg, fg, buffer_cols);
                else if (x >= title_start_x - 1 && x <= title_end)
                    put_console(x, y, " ", bg, fg, buffer_cols);
                else
                    put_console(x, y, Horizontal, bg, fg, buffer_cols);
            }
            else if (y == end_y) {
                if (x == start_x)
                    put_console(x, y, Bottomleft, bg, fg, buffer_cols);
                else if (x == end_x)
                    put_console(x, y, Bottomright, bg, fg, buffer_cols);
                else
                    put_console(x, y, Horizontal, bg, fg, buffer_cols);
            }
            else if (x == start_x || x == end_x)
                put_console(x, y, Vertical, bg, fg, buffer_cols);
            else
                put_console(x, y, " ", bg, fg, buffer_cols);
        }
    }
    int y = start_y;
    for (int x = title_start_x; x <= title_end; x++) {
        if (is_chinese(p)) {
            if (x == title_end || x == buffer_cols - 1)
                put_console(x, y, " ", bg, fg, buffer_cols);
            else {
                char temp[3] = { p[0], p[1], 0 };
                put_console(x, y, temp, bg, fg, buffer_cols);
                p += 2;
                x++;
            }
        }
        else if ((*p) && (!is_chinese(p))) {
            char temp[2] = { p[0], 0 };
            put_console(x, y, temp, bg, fg, buffer_cols);
            p++;
        }
    }
}
/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    cct_setcursor(CCT_CURSOR_INVISIBLE);
    Menucontext record;
    record.title = original_para->title;
    record.title_width = width_of(record.title);
    record.start_x = original_para->start_x;
    record.start_y = original_para->start_y;
    record.width = original_para->width;
    record.high = original_para->high;
    record.bg_color = original_para->bg_color;
    record.fg_color = original_para->fg_color;
    record.last_top_item = 0;
    record.last_selected_item = 0;
    record.initialized = false;
    for (int i = 0;; i++) {
        if (menu[i] == NULL || menu[i][0] == '\0') {
            record.total_items = i;
            break;
        }
    }
    record.top_item = 0;
    record.selected_item = (record.total_items > 0) ? 1 : 0;
    if (record.high > record.total_items)
        record.high = record.total_items;
    char temp[MAX_ITEM_LEN] = { 0 };
    if (record.title_width % 2 != 0) {
        strcpy(temp, record.title);
        strcat(temp, " ");
        record.title = temp;
        record.title_width++;
    }
    if (record.width % 2 != 0)
        record.width++;
    if (record.width < record.title_width)
        record.width = record.title_width;
    draw_frames(record);
    draw_items(menu, record);
    int X = 0, Y = 0;
    int ret, maction;
    int keycode1, keycode2;
    bool need_redraw = true;
    while (1) {
        if (need_redraw) {
            draw_items(menu, record);
            need_redraw = false;
        }
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            if (keycode1 == 224) {
                if (keycode2 == KB_ARROW_DOWN) {
                    if (record.selected_item < record.total_items) {
                        record.selected_item++;
                        if (record.selected_item > record.top_item + record.high)
                            record.top_item++;
                        if (record.top_item > record.total_items - record.high)
                            record.top_item = record.total_items - record.high;
                        need_redraw = true;
                    }
                }
                else if (keycode2 == KB_ARROW_UP) {
                    if (record.selected_item > 1) {
                        record.selected_item--;
                        if (record.selected_item <= record.top_item)
                            record.top_item = record.selected_item - 1;
                        if (record.top_item < 0)
                            record.top_item = 0;
                        need_redraw = true;
                    }
                }
            }
            else if (keycode1 == 13)
                return record.selected_item;
        }
    }
    return record.selected_item;
}