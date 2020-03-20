#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "list.h"
#define LEN   (100)
void main (void)
{
  int arry[LEN];
  srand((int) time(NULL));//以当前时间作为随机种子，但是时间是秒为单位，程序运行的太快，导致种子一样
  for (int i = 0; i < LEN; i++)
  {
      int num = (rand() % 151);
    printf("%d ", num);
    arry[i] = num;
  }
  printf("\n");
  clock_t t1 = clock();
  QuickSort(arry, 0, LEN - 1);
  clock_t t2 = clock() - t1;
  printf("time %d \n", (int)t2);
  printf("arry0 %d \n", arry[0]);
  PrintArr(arry, LEN);

  DisorderArr(arry, LEN);
  PrintArr(arry, LEN);
  InsertSortBinary(arry, LEN);
  PrintArr(arry, LEN);

}
