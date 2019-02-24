/*************************************************************************
    > File Name: replace_space.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 02:15:28 PM CST
 ************************************************************************/

#include <stdio.h>

int replace_blank(char *str_src, int len)
{
    int space_cnt = 0;
    int real_len = 0;

    if(str_src == NULL || len <= 0) {
        return -1;
    }

    for(int i=0; str_src[i] != '\0'; i++) {
        if(str_src[i] == ' ') {
            space_cnt ++;
        }

        real_len ++;
    }

    if(real_len > len) {
        return -1;
    }

    char *dest = str_src + real_len + space_cnt*2;//每替换一个空格数组空间要加大两个单位
    char *src = str_src + real_len;

    while(src >= str_src && dest >= src) {
        if(*src == ' '){
            *dest -- = '0';
            *dest -- = '2';
            *dest -- = '%';
        }else {
            *dest -- = *src;
        }

        -- src;
    }


    printf("str real len:%d space count:%d\n", real_len, space_cnt);

    return space_cnt;

}


int main(void)
{

    char str[20] = "we are happy.";
    printf("origin:%s\n", str);

    replace_blank(str, 20);

    printf("result:%s\n", str);

    char str1[20] = "";
    printf("origin:%s\n", str1);

    replace_blank(str1, 20);

    printf("result:%s\n", str1);

    char str2[20] = "   ";
    printf("origin:%s\n", str2);

    replace_blank(str2, 20);

    printf("result:%s\n", str2);

    return 0;
}
