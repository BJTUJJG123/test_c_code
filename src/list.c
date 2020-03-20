/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Jul 2019 08:07:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "list.h"
ListNode *list_init(ListNode *head, int size)
{
    ListNode *org_p;// = head;
    ListNode *p;
    ListNode *head_p = (ListNode *)malloc(sizeof(ListNode));
    org_p = head_p;
    for (int i = 0; i < size; i++)
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        p->val = i+1;
        org_p->next = p;
        org_p = p;
    }
    org_p->next = NULL;
    return head_p;
}

void print_list(ListNode *head)
{
    int node = 0;
    printf("print list: \n");
    while(head != NULL)
    {
        printf("node %d = %d \n", node, head->val);
        node++;
        head = head->next;
    }
}

ListNode *list_revese(ListNode *head)
{
    ListNode *list_p = head;
    ListNode *h_p;
    head = NULL;

    while(list_p != NULL)
    {
        h_p = list_p;
        list_p = list_p->next;
        h_p->next = head;
        head = h_p;
    }
    return head;
}

ListNode *list_insert(int pos, ListNode *head, int val)
{
    if(NULL == head)
    return NULL;
    ListNode *pre_head = head;
    int i = 0;
    while(head != NULL && (i < pos))
    {
        head = head->next;
        i++;
    }

    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = head->next;
    head->next = new_node;

    return pre_head;
}

ListNode *list_del(ListNode *head, int pos)
{
    if(NULL == head)
    return NULL;
    ListNode *pre_head = head;
    int i = 0;
    while(head != NULL && (i < pos))
    {
        head = head->next;
        i++;
    }
    ListNode *cur_head = head->next;
    head->next = cur_head->next;

    return pre_head;
}
