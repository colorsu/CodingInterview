/*************************************************************************
    > File Name: 2_dimention_array_find.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 01:22:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool matrix_find(int *matrix, int rows, int columns, int num)
{
    bool found = false;
    if(matrix == NULL || rows <= 0 || columns <= 0) {
        return found;
    }

    int row = 0;
    int column = columns - 1;

    while(row < rows && column >= 0) {
        if(matrix[row*columns + column] == num) {
            found = true;
            break;
        }else if(matrix[row*columns + column] > num){
            --column;
        }else {
            ++row;
        }
    }


    if(found) {
        printf("found row:%d col:%d\n", row, column);
    }else {
        printf("number not found\n");
    }

    return found;
}


int main(void)
{
    int num_array[4][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15},
    };

    matrix_find(*num_array, 4, 4, 7);


    return 0;
}
