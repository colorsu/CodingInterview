/*************************************************************************
    > File Name: tree.h
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 10:06:33 PM CST
 ************************************************************************/

#ifndef TREE_H
#define TREE_H

typedef struct binary_tree_node {
    int val;
    struct binary_tree_node *parent;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
}binary_tree_node;

#endif



