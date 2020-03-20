/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Jul 2019 10:41:58 AM CST
 ************************************************************************/

#include<stdio.h>
//这个交换有个缺陷，当a和b值相等时，会把a和b的值都清零
//异或运算决定的，所以得加判断
void swap_ab(int *a, int *b)
{
    if(*a != *b)
    {
        *a = *a^*b;
        *b = *b^*a;
        *a = *a^*b;
    }
}
void DisorderArr(int A[], int size)
{
    for(int i = 0; i < size/2; i++)
    {
        swap_ab(&A[i+1], &A[size - i - 1]);
    }
}
void PrintArr(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}
//插入排序 从小到大进行排序
//平均时间复杂度为O(n^2)
//稳定
//对于少量元素的排序（量级小于千），比较快
//类似扑克牌排序，左手先拿一张牌，把右手上的牌一次插入左手中
void InsertSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int get = A[i];// 对于右手拿到一张牌
        int j = i - 1; // 左手上已经排好序的
        while (j >= 0 && A[j] > get)
        {
            A[j + 1] = A[j];// 往后移动
            j--;
        }
        A[j + 1] = get;//  找到位置插入进去
    }
}


//二分插入排序
//平均时间复杂度为 O(n^2)
//稳定
//
void InsertSortBinary(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int get = A[i];
        int left = 0;
        int right = i - 1;
        while (left <= right) // 先用二分法定位新牌的位置
        {
            int mid = (left + right)/2;
            if (A[mid] > get)
               right = mid -1;
            else
               left = mid + 1;

        }
        for (int j = i - 1; j >= left; j--) // 将插入位置的右边的牌整体右移一个单位
        {
            A[j+1] = A[j];
        }
        A[left] = get;
    }
}

//Quick sort
//Divide and Conquer
//平均时间复杂度为为O(nlgn)
//不稳定
/*从序列中挑出一个元素，作为基准；
 *把所有比基准小的元素放在基准前面，所有比基准大的元素放在基准的后面，成为分区；
 *对每个分区递归的进行1-2，递归的结束条件是序列的大小是0或是1，这时整体就排好序了；
 *
 */ 
int Partition(int A[], int left, int right)
{
    int pivot = A[right];// 选择最后一个元素为基准
    int tail = left - 1; 
    for (int i = left; i < right; i++)
    {
        if(A[i] < pivot)
        {
            swap_ab(&A[++tail], &A[i]); // 把小于基准的元素放在前一个子数组的头部
        }
    }

    swap_ab(&A[tail + 1], &A[right]); // 把本次的基准值放在前一个子数组的后边

    return tail+1; // 作为下一次的基准索引
}
/*start: 数组的起始下标
 * end: 数组的最后下标
 */
void QuickSort(int A[], int start, int end)
{
    if(start >= end)
       return;

    int pivot_index = Partition(A, start, end);
    QuickSort(A, start, pivot_index - 1);
    QuickSort(A, pivot_index + 1, end);
}


// 有序数组的二分查找
// 返回val所在位置
int BinarySearch(int A[], int size, int val)
{
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (left < right)
    {
      //mid maybe overflow
      //  mid = (left + right)>>1;
        mid = left + ((right  - left) >> 1);
        if (val < A[mid])
        {
            right = mid -1; 
        }
        else if(val > A[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;

}

//对于一个无序数组，查找它的最长连续的序列，并返回该序列的长度
//

 int SortArry(int A[], int len)
{
    //InsertSortBinary(A, len);
    PrintArr(A, len);
    for(int i = 1; i < len; ++i)
    {
        int right = i -1;
        int left = 0;
        int get = A[i];
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if(A[mid] > get)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; --j)
        {
            A[j+1] = A[j];
        }
        A[left] = get;

    } 
    PrintArr(A, len);
    int get0 = A[0];   int count = 1;
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
      
        if (get0 == A[i+1] || ++get0 == A[i+1])
        {
            ++count;
        }
        else
        {
            printf("%d \n", count);
            res = res > count? res:count;
            get0 = A[i+1];     
            count = 0;
        }
       
    }
    return res;
}
