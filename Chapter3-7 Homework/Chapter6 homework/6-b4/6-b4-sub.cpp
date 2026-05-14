/*2553725 林于蕙 卓11*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    if(str==NULL)
       return 0;
    else {
        for (; *str != '\0'; str++)
            i++;
        return i;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    for (; *s1 != '\0'; s1++)
        ;
    if (s2 == NULL)
        return p;
    for (; *s2 != '\0'; s1++,s2++)
        *s1 = *s2;
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    const char* p2 = s2;
    if (s1 == NULL)
        return p;
    for (; *s1 != '\0'; s1++)
        ;
    if (s2 == NULL)
        return p;
    for (; s2 - p2 < len && *s2 != '\0'; s1++, s2++)
        *s1 = *s2;
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return p;
    if (s2 == NULL) {
        *s1 = '\0';
        return p;
    }
    for (; *s2 != '\0'; s1++, s2++)
        *s1 = *s2;
    *s1 = '\0';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    const char* p2 = s2;
    int len2 = tj_strlen(s2);
    if (s1 == NULL || s2 == NULL)
        return p;
    for (; (s2 - p2) < (len>len2?len:len2) && *s2 != '\0'; s1++, s2++)
        *s1 = *s2;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else
        ;
    for(;*p==*p2;p++,p2++)
        if(*p=='\0')
           return 0;
    return *p - *p2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else
        ;
    for (; *p != '\0' || *p2 != '\0'; p++, p2++) {
        if (*p != *p2) {
            if (*p >= 'A' && *p <= 'Z') {//无法直接对*p的值进行修改
                if (*p - *p2 == 'A' - 'a')
                    continue;
                else
                    return *p - ('A' - 'a') - *p2;
            }
            if (*p2 >= 'A' && *p2 <= 'Z') {
                if (*p2 - *p == 'A' - 'a')
                    continue;
                else
                    return *p - (*p2 - ('A' - 'a'));
            }
            else
                return *p - *p2;
        }    
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else
        ;
    for (; (p - s1 < len) && (*p != '\0' || *p2 != '\0'); p++, p2++)
        if (*p != *p2)
            return *p - *p2;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL)
        return -1;
    else if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else
        ;
    for (; (p - s1 < len) && (*p != '\0' || *p2 != '\0'); p++, p2++)
        if (*p != *p2) {
            if (*p >= 'A' && *p <= 'Z') {//无法直接对*p的值进行修改
                if (*p - *p2 == 'A' - 'a')
                    continue;
                else
                    return *p - ('A' - 'a') - *p2;
            }
            if (*p2 >= 'A' && *p2 <= 'Z') {
                if (*p2 - *p == 'A' - 'a')
                    continue;
                else
                    return *p - (*p2 - ('A' - 'a'));
            }
            else
                return *p - *p2;
        }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    for (; *str != '\0'; str++)
        if (*str >= 'a' && *str <= 'z')
            *str += 'A' - 'a';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (str == NULL)
        return p;
    for (; *str != '\0'; str++)
        if (*str >= 'A' && *str <= 'Z')
            *str -= 'A' - 'a';
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(str);
    const char* p = str;
    if(str==NULL)
       return 0;
    for (; str - p < len && *str != ch; str++)
        ;
    if (str - p == len)
        return 0;
    else
        return str - p + 1;//位置从1开始
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1, len2;
    len1 = tj_strlen(str);
    len2 = tj_strlen(substr);
    const char* p = str;
    const char* p2 = substr;
    if (str == NULL || substr == NULL)
        return 0;
    for (; str - p < len1; str++)
        if (*str==*p2) {
            for (substr=p2; substr-p2 < len2; str++,substr++) {
                if (*str!=*substr)
                    break;
            }
            str -= substr - p2;
            if (substr-p2 == len2)
                return str-p + 1;
        }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(str);
    const char* p = str + len - 1;
    if (str == NULL)
        return 0;
    for (; *p != ch && p-str >= 0; p--)
        ;
    if (p - str < 0)
        return 0;
    else
        return p - str + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len1, len2;
    len1 = tj_strlen(str);
    len2 = tj_strlen(substr);
    const char* p = str + len1 - 1;
    const char* substr_end = substr + len2 - 1;
    if (str == NULL || substr == NULL)
        return 0;
    for (; p >= str; p--)
        if (*p == *substr_end) {
            const char* tmp_p = p;
            const char* tmp_sub = substr_end;
            for (; tmp_sub >= substr; tmp_p--, tmp_sub--) {
                if (tmp_sub < substr || *tmp_p != *tmp_sub)
                    break;
            }
            if (tmp_sub < substr)
                return tmp_p + 1 - str + 1;
        }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(str);
    char t;
    char* p = str;
    char* p2 = str + len - 1;
    if (str == NULL)
        return p;
    for (;str<p2; str++,p2--) {
        t = *str;
        *str = *p2;
        *p2 = t;
    }
    return p;
}
