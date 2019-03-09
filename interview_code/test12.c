/*************************************************************************
    > File Name: test12.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sat 09 Mar 2019 06:57:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_visited(bool *visited, int len)
{
    if(visited == NULL || len <=0) {
        printf("invalid parameters\n");
        return;
    }


    printf("\nPath FOUND\nvisited array:");
    for(int i=0; i < len; i++) {
        printf("%d ", visited[i]);
    }
    printf("\n");

    return;
}

bool has_path_core(const char *matrix, int rows, int cols, int row,
        int col, const char *path_str, int *path_len, bool *visited)
{
    printf("path_len:%d,%c \t\t", *path_len, path_str[*path_len]);
    if(path_str[*path_len] == '\0') {
        return true;
    }

    bool has_path = false;
    if(row >= 0 && col >= 0) {
    printf("R:%2d  C:%2d  m:%c  s:%c  v:%d\n", row, col,
        matrix[row*cols+col], path_str[*path_len], !visited[row*cols+col]);
    }

    if(row >= 0 && row < rows && col >= 0 && col < cols
            && matrix[row*cols+col] == path_str[*path_len] && !visited[row*cols+col]) {

         ++(*path_len);
         visited[row *cols +col] = true;

         has_path = has_path_core(matrix, rows, cols, row, col - 1,//previous one in the same line
                                    path_str, path_len, visited)
                    || has_path_core(matrix, rows, cols, row - 1, col,
                                    path_str, path_len, visited)
                    || has_path_core(matrix, rows, cols, row, col + 1,
                            path_str, path_len, visited)
                    || has_path_core(matrix, rows, cols, row + 1, col,
                            path_str, path_len, visited);

         if(!has_path) {
            --(*path_len);
             visited[row * cols + col] = false;
         }else {
             printf("\nindex %d \t %c\n", row * cols +col,matrix[row * cols +col]);
         }

    }

    return has_path;
}

bool has_path(char *matrix, int rows, int cols, char *path_str)
{
    if(matrix == NULL || rows < 1 || cols < 1|| path_str == NULL) {
        printf("invalid parameters\n");
        return false;
    }

    bool *visited = malloc(rows * cols);
    memset(visited, 0, rows * cols);

    int path_len = 0;
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {

            printf("finding index:%d %d\n", row, col);

            if(has_path_core(matrix, rows, cols, row, col, path_str, &path_len, visited)) {
                print_visited(visited, rows*cols);
                return true;
            }

        }
    }

    free(visited);


    printf("\nno path found\n");
    return false;
}


int main(void)
{
    char path_str[] = "bfce";
    char matrix[][4] = {
        {'a','b','t','g'},
        {'b','f','c','s'},
        {'j','d','e','h'},
    };

    has_path(&matrix[0][0], 3, 4, &path_str[0]);

    return 0;
}









