/*************************************************************************
    > File Name: test14.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 10 Mar 2019 01:45:23 PM CST
    剪繩子問題：有一根長度爲 n 的繩子，將繩子分成m段(m,n都是整數，且m > 1),每段繩子相乘得到最大乘積是多少？
    例如一根長度爲 8 的繩子,剪成2, 3, 3的三段時，得到最大乘積爲18.
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 動態規劃 O(n^2)*/
int max_product_after_cutting_1(int len)
{
    if(len < 2) {
        return 0;
    }

    if(len == 2) {
        return 1;
    }

    if(len == 3) {
        return 2;
    }

    //用來存儲長度爲i+1的繩子分段後，各段長度乘積的最大值
    int *products = (int *) malloc(len+1);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i=4; i<=len; i++) {
        max = 0;
        for(int j=1; j <= i/2; j++) {
            int product = products[j] * products[i-j];
            if(max < product) {
                max = product;
            }

            products[i] = max;
            printf("product %d:%d\n", i, products[i]);
        }
    }

    printf("len:%d\n", len);
    max = products[len];
    free(products);

    return max;

}


int main(int argc, char **argv)
{
    if(argc < 2 || argv == NULL) {
        printf("invalid parameters\n");
        return -1;
    }

    printf("\ninput para:");
    for (int i = 0; i < argc; i++) {
        printf(" %s", argv[i]);
    }

    int len;
    char * end_str = NULL;

    len = strtol(argv[1], &end_str, 10);
    printf("\ninput len :%d", len);

    int max = max_product_after_cutting_1(len);
    printf("\nMAX:%d\n", max);

    return 0;
}



