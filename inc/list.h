#ifndef LIST_H
#define LIST_H

typedef struct ListNode_s {
    int val;
    struct ListNode_s *next;
}ListNode;

ListNode *list_init(ListNode *head, int size);
void print_list(ListNode *head);
ListNode *list_revese(ListNode *head);
ListNode *list_insert(int pos, ListNode *head, int val);
ListNode *list_del(ListNode *head, int pos);

//sort.h
//
void InsertSortBinary(int A[], int size);
void InsertSort(int A[], int n);
void PrintArr(int A[], int size);
void DisorderArr(int A[], int size);
void QuickSort(int A[], int start, int end);
 int SortArry(int A[], int len);
int BinarySearch(int A[], int size, int val);


//test_online.h
//
int char_in_string(char input_char, const char *strings, int len);
int del_multi_in_arr(int a[], int n);
void string_print(void);

#endif
