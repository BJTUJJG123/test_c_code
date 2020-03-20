/*************************************************************************
	> File Name: test_online.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Jul 2019 04:30:57 PM CST
 ************************************************************************/
#include <string.h>
#include<stdio.h>
#include "list.h"
/*
 * 接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写
 *
 */
 
int char_in_string(char input_char, const char *strings, int len)
{
    int count = 0;
    int val = 0;
    if(input_char >= 'a' && input_char <= 'z')
        val = 'A' - 'a';
    else if (input_char >= 'A' && input_char <= 'Z')
        val = 'a' - 'A';
    for (int i = 0; i < len; i++)
    {
       if(input_char == *strings || *strings == input_char + val)//
        {
            count++;
        }
         strings++;
    }
    return count;
}
/*
 * 数组去重
 */
 int del_multi_in_arr(int a[], int n)
 {
     int q = 1, p = 0;
     InsertSortBinary(a, n);
     PrintArr(a, n);
     while (q < n)
     {
         if(a[p] != a[q])
         {
             p++;
             a[p] = a[q];
         }
         q++;
     }
     PrintArr(a, p+1);
     return p+1;
 }
//输入字符串，输出时按照8个字符串一组进行输出，不够的补0
//在网站上测试过了，在本地测试时输入的字符串在最后总是多余一个
//换行符。
//strlen函数在计算字符串长度的时候不包含换行符的。
void string_print(void)
{
        char string1[100];
    char string2[100] = {0};
    int size1 = 0;
    while(fgets(string1, 100, stdin))
    {
        size1 = strlen(string1)-1;// 必须-1，否则会多一个换行符
        int len = sizeof(string1);
        printf("size1 %d,len %d \n", size1, len);
        for (int i = 0 ; i < size1; i++)
        {
            printf("%c", string1[i]);
        }
        printf("\n");
        for(int i = 0; i < size1;)
        {
            printf("%c", string1[i]);
            i++;
            if((i % 8) == 0)
                printf("%d\n",i);
        }
        if(size1 % 8)
        {
             for(int j = 0; j < 8-(size1 % 8);j++)
            {
                printf("%d", 0);
            }
            printf("\n");
        }

    }

}
