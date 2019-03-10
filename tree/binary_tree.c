/*************************************************************************
    > File Name: binary_tree.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 10:06:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int node_cnt = 0;
void print_node(int val, int h)
{
    int i;
    for(i=0; i<h; i++) {
        printf("      ");
    }

    if(val == 99) {
        printf("*\n");
    }else {
        printf("%d\n", val);
    }
}

void show(binary_tree_node * r_tree, int h)
{
    if(r_tree == NULL) {
        print_node(99, h);
        return;
    }

    show(r_tree->right, h+1);
    print_node(r_tree->val, h);
    show(r_tree->left, h+1);
}

binary_tree_node *construct_core(int *pre_order_start, int *pre_order_end,
        int *mid_order_start, int *mid_order_end, binary_tree_node *parent)
{
    int root_val = pre_order_start[0];
    binary_tree_node *root = (binary_tree_node *)malloc(sizeof(binary_tree_node));
    root->val = root_val;
    root->parent = parent;

    //find the root node(the first of the pre_order)
    if(*pre_order_start == *pre_order_end) {
        if(*mid_order_start == *mid_order_end) {
            node_cnt++;
            printf("%d %p\n", node_cnt, &root);
            return root;
        }else {
            printf("invalid input\n");
            return NULL;
        }
    }

    //find the left tree and right tree by mid_order
    int *mid_order_root = mid_order_start;

    while(mid_order_root <= mid_order_end && *mid_order_root != root_val) {
        ++ mid_order_root;
    }

    if(*mid_order_root != root_val && mid_order_root == mid_order_end) {
        printf("invalid input");
        return NULL;
    }

    int left_len = mid_order_root - mid_order_start;
    int *left_pre_order_end = pre_order_start + left_len;

    if(left_len > 0) {
        root->left = construct_core(pre_order_start + 1, left_pre_order_end,
                mid_order_start, mid_order_root - 1, root);
        root->left->parent = root;
    }

    if(left_len < pre_order_end - pre_order_start) {
        root->right = construct_core(left_pre_order_end + 1, pre_order_end,
                mid_order_root + 1, mid_order_end, root);
        root->right->parent = root;
    }

    node_cnt++;
    printf("%d %p\n", node_cnt, &root);
    return root;

}

binary_tree_node *construct(int *pre_order, int *mid_order, int len)
{
    if(pre_order == NULL || mid_order == NULL || len <= 0) {
        return NULL;
    }

    return construct_core(pre_order, pre_order + len - 1,
            mid_order, mid_order + len -1, NULL);
}

binary_tree_node *get_next(binary_tree_node * node)
{
    if(node == NULL) {
        return NULL;
    }

    binary_tree_node *next = NULL;

    if(node->right != NULL) {
        binary_tree_node *right = node->right;

        while(right->left != NULL) {
            right = right->left;
        }

        next = right;

    }else if(node->parent != NULL) {
        binary_tree_node *current = node;
        binary_tree_node *parent = node->parent;

        while(parent != NULL && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }

        next = parent;
    }

    return next;
}

void test_1(void)
{
    int pre_order[15] = {8, 7, 9, 4, 1, 3, 2, 10, 5, 12, 11, 13, 15, 6, 14};
    int mid_order[15] = {4, 9, 1, 7, 2, 3, 10, 8, 11, 12, 13, 5, 6, 15, 14};

    binary_tree_node *b_tree;

    b_tree = construct(pre_order, mid_order, 15);

    show(b_tree, 1);

    binary_tree_node *node = b_tree;
    binary_tree_node * tmp = NULL;

    printf("nEXT\n");
    while(node != NULL) {
        printf("%d ",node->val);
        printf("%p\n", &node);
        tmp = node;
        node = get_next(b_tree);

        if(tmp == node) {
            printf("deap loop\n");
            return;
        }
    }

    printf("\n");


}

void test_2(void)
{
    int pre_order[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int mid_order[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    binary_tree_node *b_tree;

    b_tree = construct(pre_order, mid_order, 8);

    show(b_tree, 1);
}

void test_3(void)
{
    int pre_order[15] = {2, 3, 1, 10, 6, 9, 17, 4, 5, 8, 13, 18, 7, 15, 14};
    int mid_order[15] = {10, 1, 6, 3, 17, 9, 4, 2, 13, 8, 18, 5, 15, 7, 14};

    binary_tree_node *b_tree;

    b_tree = construct(pre_order, mid_order, 15);

    show(b_tree, 1);
}

int main(void)
{
    node_cnt = 0;

    test_1();
    //test_2();
    //test_3();
}


