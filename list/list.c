/*************************************************************************
    > File Name: list.c
    > Author: color
    > mail: colorsu1922@163.com
    > Created Time: Sun 24 Feb 2019 09:29:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int val;
    struct list_node *next;
}list_node;

void add_to_tail(list_node **head, int val)
{
    list_node *new = (list_node *)malloc(sizeof(list_node));
    new->val = val;
    new->next = NULL;

    if(*head == NULL) {
        *head = new;
    }else {
        list_node *tmp = *head;

        while(tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = new;

    }


}

void rm_node(list_node **head, int val)
{
    if(*head == NULL || head == NULL) {
        return;
    }

    list_node *del_tmp = NULL;

    if((*head)->val == val) {
        del_tmp = *head;
        *head = (*head)->next;
    }else {
        list_node *tmp = *head;

        while(tmp->next != NULL && tmp->next->val != val) {
            tmp = tmp->next;
        }

        if(tmp->next != NULL && tmp->next->val == val) {
            del_tmp = tmp->next;
            tmp->next = tmp->next->next;
        }

        if(del_tmp != NULL) {
            free(del_tmp);
            del_tmp = NULL;
        }
    }
}





