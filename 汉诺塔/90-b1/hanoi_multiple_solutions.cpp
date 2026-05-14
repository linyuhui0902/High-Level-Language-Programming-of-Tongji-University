/*2553725 林于蕙 卓11*/
#include<iostream>
#include<iomanip>
#include<climits>
#include<conio.h>
#include<Windows.h>
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
#include"hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
static int a, speed;
static int A_num[10] = { 0 }, B_num[10] = { 0 }, C_num[10] = { 0 };
static int A_top = 0, B_top = 0, C_top = 0;
/***************************************************************************
  函数名称：void init()
  功    能：初始化
  输入参数：
  返 回 值：
  说    明：静态局部变量只有第一次调用会初始化一次，因此后续操作需人工初始化
***************************************************************************/
void init()
{
    a = 0;
    speed = 0;
    A_top = B_top = C_top = 0;
    for (int i = 0; i < 10; i++)
        A_num[i] = B_num[i] = C_num[i] = 0;
}
/***************************************************************************
  函数名称：void wait(int speed)
  功    能：设置延时功能
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait(int speed)
{
    if (speed == 0) {
        while ((_getch()) != '\r')
            ;
    }
    else
        Sleep(speed);
}
/***************************************************************************
  函数名称：move_disk(char src, char dst)
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void move_disk(char src, char dst)
{
    int t = 0;
    switch (src) {
        case 'A':
            if (A_top == 0)
                return;
            t = A_num[A_top - 1];
            A_num[--A_top] = 0;
            break;
        case'B':
            if (B_top == 0)
                return;
            t = B_num[B_top - 1];
            B_num[--B_top] = 0;
            break;
        case'C':
            if (C_top == 0)
                return;
            t = C_num[C_top - 1];
            C_num[--C_top] = 0;
            break;
        default:
            break;
    }
    switch (dst) {
        case 'A':
            A_num[A_top++] = t;
            break;
        case 'B':
            B_num[B_top++] = t;
            break;
        case 'C':
            C_num[C_top++] = t;
            break;
        default:
            break;
    }
}
/***************************************************************************
  函数名称：void horizontal_print()
  功    能：横向输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void horizontal_print()
{
    int i;
    cout << " A:";
    for (i = 0; i < 10; i++) {
        if (A_num[i] == 0)
            cout << "  ";
        else
            cout << setiosflags(ios::right) << setw(2) << A_num[i];
    }
    cout << " B:";
    for (i = 0; i < 10; i++) {
        if (B_num[i] == 0)
            cout << "  ";
        else
            cout << setiosflags(ios::right) << setw(2) << B_num[i];
    }
    cout << " C:";
    for (i = 0; i < 10; i++) {
        if (C_num[i] == 0)
            cout << "  ";
        else
            cout << setiosflags(ios::right) << setw(2) << C_num[i];
    }
    cout << endl;
}
/***************************************************************************
  函数名称：void fill(int n, char src)
  功    能：填充初始数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fill(int n, char src) {
    int i, j;
    for (i = n, j = 0; i > 0; i--) {
        switch (src) {
            case 'A':
                A_num[j] = i;
                break;
            case 'B':
                B_num[j] = i;
                break;
            case 'C':
                C_num[j] = i;
                break;
            default:
                break;
        }
        j++;
    }
    switch (src) {
        case 'A':
            A_top = j;
            break;
        case 'B':
            B_top = j;
            break;
        case 'C':
            C_top = j;
            break;
        default:
            break;
    }
}
/***************************************************************************
  函数名称：print_vertical(char src, char dst,int x, int y,int z)
  功    能：纵向输出字符数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_vertical(char src, char dst, int start_x, int start_y, int x_offset, int y_offset, int underpan_distance)
{

    int i = 0;
    cct_gotoxy(start_x + x_offset, start_y + y_offset);
    cout << 'A';
    for (i = 1; i < underpan_distance; i++)
        cout << " ";
    cout << 'B';
    for (i = 1; i < underpan_distance; i++)
        cout << " ";
    cout << 'C';
    cct_gotoxy(start_x + x_offset - 2, start_y + y_offset - 1);
    cout << setfill('=') << setw(underpan_distance * 2 + 2 * 2 + 2) << " ";
    cout << setfill(' ');//恢复为空格填充免得影响下面
    for (i = 0; i < 10; i++) {
        cct_gotoxy(start_x + x_offset - 1, start_y + y_offset - 2 - i);//盘号占两个字符，如果不减一中心不对齐
        if (A_num[i] != 0)
            cout << setiosflags(ios::right) << setw(2) << A_num[i];
        else {
            cout << "  ";
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        cct_gotoxy(start_x + x_offset + underpan_distance - 1, start_y + y_offset - 2 - i);
        if (B_num[i] != 0)
            cout << setiosflags(ios::right) << setw(2) << B_num[i];
        else {
            cout << "  ";
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        cct_gotoxy(start_x + x_offset + underpan_distance * 2 - 1, start_y + y_offset - 2 - i);
        if (C_num[i] != 0)
            cout << setiosflags(ios::right) << setw(2) << C_num[i];
        else {
            cout << "  ";
            break;
        }
    }
}
/***************************************************************************
  函数名称：print_column()
  功    能：画柱子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_column()
{
    hdc_set_pencolor(HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X, HDC_Start_Y, HDC_BasePlate_Width, HDC_Base_High, HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X_B, HDC_Start_Y, HDC_BasePlate_Width, HDC_Base_High, HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X_C, HDC_Start_Y, HDC_BasePlate_Width, HDC_Base_High, HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_StartColumn_X, HDC_StartColumn_Y, HDC_Base_Width, HDC_BaseColumn_High, HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_StartColumn_X_B, HDC_StartColumn_Y, HDC_Base_Width, HDC_BaseColumn_High, HDC_COLOR[MAX_LAYER + 1]);
    wait(HDC_Init_Delay);
    hdc_rectangle(HDC_StartColumn_X_C, HDC_StartColumn_Y, HDC_Base_Width, HDC_BaseColumn_High, HDC_COLOR[MAX_LAYER + 1]);
}
/***************************************************************************
  函数名称：print_plate(int n, char src)
  功    能：画盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_plate(int n, char src)
{
    wait(HDC_Init_Delay);
    int Plate_Base_x;
    int Plate_Base_y = HDC_Start_Y;
    if (src == 'A')
        Plate_Base_x = HDC_StartColumn_X;
    else if (src == 'B')
        Plate_Base_x = HDC_StartColumn_X_B;
    else
        Plate_Base_x = HDC_StartColumn_X_C;
    for (int i = n; i > 0; i--) {
        hdc_rectangle(Plate_Base_x - i * HDC_Base_Width, Plate_Base_y + (-1 + i - n) * HDC_Base_High,
            (i * 2 + 1) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[i]);
        wait(HDC_Init_Delay);
    }
}
/***************************************************************************
  函数名称：Move_Vertical_Up(char src, int speed，int choose)
  功    能：完成盘子的上移
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Move_Vertical_Up(char src,int speed,int choose)
{
    int Origin_X, Start_Location, Length_Flag;
    if (src == 'A') {
        Origin_X = HDC_StartColumn_X;
        Start_Location = A_top;
        Length_Flag = A_num[A_top - 1];
    }
    else if (src == 'B') {
        Origin_X = HDC_StartColumn_X_B;
        Start_Location = B_top;
        Length_Flag = B_num[B_top - 1];
    }
    else {
        Origin_X = HDC_StartColumn_X_C;
        Start_Location = C_top;
        Length_Flag = C_num[C_top - 1];
    }
    for (int i = HDC_Start_Y - Start_Location * HDC_Base_High; i > HDC_Top_Y; i -= HDC_Step_Y) {
        if(!(choose==8&&a>7))
           wait(speed);
        hdc_rectangle(Origin_X - Length_Flag * HDC_Base_Width, i + HDC_Base_High - HDC_Step_Y,
            (2 * Length_Flag + 1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);
        if (i + HDC_Base_High > HDC_Start_Y - (MAX_LAYER + 2) * HDC_Base_High)//需要矩形的下端完全离开柱子
            hdc_rectangle(Origin_X, i + HDC_Base_High - HDC_Step_Y, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[MAX_LAYER + 1]);
        hdc_rectangle(Origin_X - Length_Flag * HDC_Base_Width, i - HDC_Step_Y,
            (2 * Length_Flag + 1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[Length_Flag]);
    }
}
/***************************************************************************
  函数名称：Move_horizontal(char src, char dst, int speed,int choose)
  功    能：完成盘子的平移
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Move_horizontal(char src, char dst, int speed,int choose)
{
    int Src_X, Dst_X, Length_Flag;
    if (src == 'A') {
        Src_X = HDC_StartColumn_X;
        Length_Flag = A_num[A_top - 1];
    }
    else if (src == 'B') {
        Src_X = HDC_StartColumn_X_B;
        Length_Flag = B_num[B_top - 1];
    }
    else {
        Src_X = HDC_StartColumn_X_C;
        Length_Flag = C_num[C_top - 1];
    }
    if (dst == 'A')
        Dst_X = HDC_StartColumn_X;
    else if (dst == 'B')
        Dst_X = HDC_StartColumn_X_B;
    else
        Dst_X = HDC_StartColumn_X_C;
    if (src < dst) {
        for (int i = Src_X - Length_Flag * HDC_Base_Width; i < Dst_X - Length_Flag * HDC_Base_Width; i += HDC_Step_X) {
            if (!(choose == 8 && a > 7))
                wait(speed);
            hdc_rectangle(i, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(i + (2 * Length_Flag + 1) * HDC_Base_Width, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[Length_Flag]);
        }
    }
    else {
        for (int i = Src_X - Length_Flag * HDC_Base_Width; i > Dst_X - Length_Flag * HDC_Base_Width; i -= HDC_Step_X) {
            if (!(choose == 8 && a > 7))
                wait(speed);
            hdc_rectangle(i + (2 * Length_Flag + 1) * HDC_Base_Width - HDC_Step_X, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(i - HDC_Step_X, HDC_Top_Y, HDC_Step_X, HDC_Base_High, HDC_COLOR[Length_Flag]);
        }
    }
}
/***************************************************************************
  函数名称：void Move_Vertical_Down(char src, char dst, int speed,int choose)
  功    能：完成盘子的下移
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Move_Vertical_Down(char src, char dst, int speed, int choose)
{
    int Origin_X, End_Location, Length_Flag;
    if (src == 'A')
        Length_Flag = A_num[A_top - 1];
    else if (src == 'B')
        Length_Flag = B_num[B_top - 1];
    else
        Length_Flag = C_num[C_top - 1];
    if (dst == 'A') {
        Origin_X = HDC_StartColumn_X;
        End_Location = A_top;
    }
    else if (dst == 'B') {
        Origin_X = HDC_StartColumn_X_B;
        End_Location = B_top;
    }
    else {
        Origin_X = HDC_StartColumn_X_C;
        End_Location = C_top;
    }
    for (int i = HDC_Top_Y; i < HDC_Start_Y - (End_Location + 1) * HDC_Base_High; i += HDC_Step_Y) {
        if (!(choose == 8 && a > 7))
            wait(speed);
        hdc_rectangle(Origin_X - Length_Flag * HDC_Base_Width, i, (2 * Length_Flag + 1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[0]);
        if (i > HDC_Start_Y - 12 * HDC_Base_High)//需要矩形的下端完全离开柱子
            hdc_rectangle(Origin_X, i, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[MAX_LAYER + 1]);
        hdc_rectangle(Origin_X - Length_Flag * HDC_Base_Width, i + HDC_Base_High,
            (2 * Length_Flag + 1) * HDC_Base_Width, HDC_Step_Y, HDC_COLOR[Length_Flag]);
    }
}
/***************************************************************************
  函数名称：Move_Plate(char src, char dst, int speed,int choose)
  功    能：完成盘子的移动操作
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Move_Plate(char src, char dst, int speed,int choose)
{
    Move_Vertical_Up(src, speed,choose);
    Move_horizontal(src, dst, speed,choose);
    Move_Vertical_Down(src, dst, speed,choose);
}
/***************************************************************************
  函数名称：Hanoi_Game(int n, char dst)
  功    能：汉诺塔游戏（选项9）的实现
  输入参数：
  返 回 值：无
  说    明：最后通过判断目标柱的顶是否为盘1来判断游戏是否结束
***************************************************************************/
void Hanoi_Game(int n, char dst)
{
    char Input_src, Input_dst;
    int Get_element, Endbase_element;
    while (1)
    {
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 2);
        cout << "                                                                                ";//为了清除之前的错误提示
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 2);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
        Input_src = getchar();
        if (Input_src == '\n')
            continue;
        if (cin.good() == 0 || (Input_src != 'A' && Input_src != 'B' && Input_src != 'C' && Input_src != 'Q' &&
            Input_src != 'a' && Input_src != 'b' && Input_src != 'c' && Input_src != 'q')) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (Input_src == 'a' || Input_src == 'b' || Input_src == 'c' || Input_src == 'q')
            Input_src = Input_src - 32;
        Input_dst = getchar();
        if (Input_src == 'Q' && Input_dst == '\n'){
            cout << "游戏中止!!!!!"<<endl;
            break;
        }
        if (cin.good() == 0 || (Input_dst != 'A' && Input_dst != 'B' && Input_dst != 'C' &&
            Input_dst != 'a' && Input_dst != 'b' && Input_dst != 'c')) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (Input_dst == 'a' || Input_dst == 'b' || Input_dst == 'c' || Input_dst == 'q')
            Input_dst = Input_dst - 32;
        char Judge = getchar();
        if (Judge != '\n'){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (Input_src == Input_dst)
            continue;
        if (Input_src == 'A' && A_top > 0)
            Get_element = A_num[A_top - 1];
        else if (Input_src == 'B' && B_top > 0)
            Get_element = B_num[B_top - 1];
        else if (Input_src == 'C' && C_top > 0)
            Get_element = C_num[C_top - 1];
        else {
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
            cout << "源柱为空!" << endl;
            wait(HDC_Init_Delay);
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
            cout << "                                                                               ";//为了清除之前的错误提示
            continue;
        }
        if (Input_dst == 'A' && A_top > 0)
            Endbase_element = A_num[A_top - 1];
        else if (Input_dst == 'B' && B_top > 0)
            Endbase_element = B_num[B_top - 1];
        else if (Input_dst == 'C' && C_top > 0)
            Endbase_element = C_num[C_top - 1];
        else
            Endbase_element = MAX_LAYER+1;//把空柱子设定为一个比所有盘号都大的值
        if (Get_element > Endbase_element) {
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
            cout << "大盘压小盘，非法移动!" << endl;
            wait(HDC_Init_Delay);
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
            cout << "                                                                                ";//为了清除之前的错误提示
            continue;
        }
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
        cout << "第" << setiosflags(ios::right) << setw(4) << ++a << " 步("
            << setiosflags(ios::right) << setw(2) << Get_element << "#: " << Input_src << "-->" << Input_dst << ")" ;
        move_disk(Input_src, Input_dst);
        horizontal_print();
        print_vertical(Input_src, Input_dst, MenuItem9_Start_X, MenuItem9_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
        move_disk(Input_dst, Input_src);
        Move_Plate(Input_src, Input_dst, speed, 9);
        move_disk(Input_src, Input_dst);
        int Final_Plate;
        if (dst == 'A')
            Final_Plate = A_num[n - 1];
        else if (dst == 'B')
            Final_Plate = B_num[n - 1];
        else
            Final_Plate = C_num[n - 1];
        if (Final_Plate == 1)
        {
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
            cout << "游戏结束!!!!!" << endl;
            break;
        }
    }
}
/***************************************************************************
  函数名称：Main_print(int n, char src, char tmp, char dst, int speed, int choose)
  功    能：完成各类打印操作汇总
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Main_print(int n, char src, char tmp, char dst, int speed, int choose)
{
    switch (choose) {
        case 1:
            cout << n << "# " << src << "---->" << dst << endl;
            break;
        case 2:
            cout << "第" << setiosflags(ios::right) << setw(4) << ++a << " 步("
                << setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case 3:
            cout << "第" << setiosflags(ios::right) << setw(4) << ++a << "步("
                << setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")";
            move_disk(src, dst);
            horizontal_print();
            break;
        case 4:
            cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
            cout << "第" << setiosflags(ios::right) << setw(4) << ++a << "步("
                << setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")";
            move_disk(src, dst);
            horizontal_print();
            print_vertical(src, dst, MenuItem4_Start_X, MenuItem4_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
            wait(speed);
            break;
        case 7:
            Move_Plate(src, dst, speed,choose);
            move_disk(src, dst);
            break;
        case 8:
            cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
            cout << "第" << setiosflags(ios::right) << setw(4) << ++a << "步("
                << setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")";
            move_disk(src, dst);
            horizontal_print();
            print_vertical(src, dst, MenuItem8_Start_X, MenuItem8_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
            move_disk(dst, src);//约等于撤销刚才的move_disk，因为动画输出是要依赖栈内状态的
            Move_Plate(src, dst, speed,choose);
            move_disk(src, dst);//动画完成后，真正移动数据
            if (a <= 7)
                wait(speed);
            break;
    }
}
/***************************************************************************
  函数名称：hanoi(int n, char src, char tmp, char dst,int speed,int choose)
  功    能：汉诺塔递归主函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int speed, int choose)
{
    if (n == 1)
        Main_print(n, src, tmp, dst, speed, choose);
    else {
        hanoi(n - 1, src, dst, tmp, speed, choose);
        if (choose == 7)
            return;
        Main_print(n, src, tmp, dst, speed, choose);
        hanoi(n - 1, tmp, src, dst, speed, choose);
    }
}
/***************************************************************************
  函数名称：void input(char* src,char* tmp,char* dst,int* n,int speed_flag,int choose)
  功    能：输入
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input(char* src, char* tmp, char* dst, int* n, int speed_flag, int choose)
{
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else if (*n >= 1 && *n <= 10)
            break;
        else
            ;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        if (*src == 'a' || *src == 'b' || *src == 'c')
            *src = *src - 32;
        if (*src == 'A' || *src == 'B' || *src == 'C') {
            cin.ignore(INT_MAX, '\n');
            break;
        }
        else
            cin.ignore(INT_MAX, '\n');
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        if (*dst == 'a' || *dst == 'b' || *dst == 'c')
            *dst = *dst - 32;
        if (*dst == *src) {
            cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
            cin.ignore(INT_MAX, '\n');
        }
        else if (*dst == 'A' || *dst == 'B' || *dst == 'C') {
            cin.ignore(INT_MAX, '\n');
            break;
        }
        else
            cin.ignore(INT_MAX, '\n');
    }
    *tmp = 'A' + 'B' + 'C' - *src - *dst;
    if (speed_flag) {
        while (1)
        {
            if (choose == 4)
                cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms)";
            else if (choose == 7 || choose == 8 || choose == 9)
                cout << "请输入移动速度(0 - 20：0 - 按回车单步演示 1 - 20:延时1 - 20ms)";
            cin >> speed;
            if (cin.good() == 0) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else if (speed >= 0 && speed <= ((choose == 4) ? 200 : 20)) {
                cin.ignore(INT_MAX, '\n');
                break;
            }
            else
                ;
        }
    }
}
/***************************************************************************
  函数名称：hanoi_implement(int choose)
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_implement(int choose)
{
    char src = 'A', tmp = 'B', dst = 'C';
    int n = 0, speed_flag;
    speed_flag = ((choose == 4 || choose == 7 || choose == 8 || choose == 9) ? 1 : 0);
    if (choose == 5) {
        cct_cls();
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + offset_prompt_y);
        print_column();
        return;
    }
    cct_gotoxy(prompt_x, prompt_y);
    init();
    input(&src, &tmp, &dst, &n, speed_flag, choose);
    if (choose == 6 || choose == 7) {
        cct_cls();
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + offset_prompt_y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
        print_column();
        print_plate(n, src);
        if (choose == 6)
            return;
    }
    fill(n, src);
    if (choose == 4) {
        cct_cls();
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + offset_prompt_y);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n <<
            " 层，延时设置为 " << speed << "ms" << endl;
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        cout << "初始: ";
        horizontal_print();
        print_vertical(src, dst, MenuItem4_Start_X, MenuItem4_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
        wait(speed);
    }
    if (choose == 8) {
        cct_cls();
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y + 3);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n <<
            " 层，延时设置为 " << speed << "ms（前7步，后面自动变为0ms）" << endl;
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
        cout << "初始: ";
        horizontal_print();
        print_vertical(src, dst, MenuItem8_Start_X, MenuItem8_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
        print_column();
        print_plate(n, src);
        wait(speed);
    }
    if (choose == 9) {
        cct_cls();
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n <<
            " 层 " << endl;
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
        cout << "初始: ";
        horizontal_print();
        print_vertical(src, dst, MenuItem9_Start_X, MenuItem9_Start_Y, Underpan_A_X_OFFSET, Underpan_A_Y_OFFSET, Underpan_Distance);
        print_column();
        print_plate(n, src);
        wait(speed);
        Hanoi_Game(n,dst);
        return;
    }
    hanoi(n, src, tmp, dst, speed, choose);
    if (choose == 4) 
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + offset_prompt_y);
    if (choose == 8)
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y + 3 + 1);
    cout << endl;
}