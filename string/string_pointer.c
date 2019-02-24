/*************************************************************************
    > File Name: string_pointer.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 01:52:28 PM CST
 ************************************************************************/

#include <stdio.h>


int main(void)
{
    char str1[] = "hello";
    char str2[] = "hello";

    char *str3 = "hello";
    char *str4 = "hello";

    if(str1 == str2) {
        printf("str1 and str2 are same.\n");
    }else {
        printf("str1 and str2 are not same.\n");
    }

    if(str3 == str4) {
        printf("str3 and str4 are same.\n");
    }else {
        printf("str3 and str4 are not same.\n");
    }


    return 0;
}
