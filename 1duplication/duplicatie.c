/*************************************************************************
    > File Name: duplicatie.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sat 23 Feb 2019 03:24:10 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool duplicate(int num[], int len, int *duplication)
{
    if(num == NULL || len <= 0) {
        return false;
    }

    for(int i=0; i<len; ++i) {
        if(num[i]<0 || num[i] > len - 1) {
            return false;
        }
    }

    for(int i=0; i<len; ++i) {
        while(num[i] != i) {
            if(num[i] == num[num[i]]) {
                *duplication = num[i];
                for(int i=0; i<len; i++) {
                    printf("%d ",num[i]);
                }
                printf("\n");
                return true;
            }

            int tmp = num[i];
            num[i] = num[tmp];
            num[tmp] = tmp;

        }

    }

    for(int i=0; i<len; i++) {
        printf("%d ",num[i]);
    }

    printf("\n");

    return false;
}

int count_range(const int *nums, int len, int start, int end)
{
    if (nums == NULL) {
        return 0;
    }

    int cnt = 0;

    for(int i=0; i<len; i++) {
        if(nums[i] >= start && nums[i] <= end) {
            ++cnt;
        }
    }

    printf("cnt:%d\n", cnt);
    return cnt;
}

int get_duplication(const int *nums, int len)
{
    if(nums == NULL || len <= 0) {
        printf("PARAM INVALID\n");
        return -1;
    }

    int start = 1;
    int end = len - 1;

    while(end >= start) {
        int mid = ((end - start) >> 1) + start;
        int cnt = count_range(nums, len ,start, mid);

        printf("start:%d mid:%d end:%d\n", start, mid, end);

        if(end == start) {
            if(cnt > 1) {
                return start;
            }else {
                printf("cnt <= 1\n");
                break;
            }
        }

        if(cnt > (mid - start + 1)) {
            end = mid;
        }else {
            start = mid + 1;
        }

    }

    return -1;
}

int main(void)
{
    int nums[8] = {1, 0, 2, 3, 4, 5, 6, 7};

#if 0
    int dup[10] = {0};

    duplicate(nums, 7, dup);

    for(int i=0; i<10; i++) {
        printf("%d ",dup[i]);
    }

    printf("\n");
#endif

    int dup_num = get_duplication(nums, 8);

    printf("found duplicate number: %d\n", dup_num);

    return 0;

}




