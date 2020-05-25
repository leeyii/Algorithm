//
//  main.c
//  希尔排序
//
//  Created by leeyii on 2020/5/23.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

// 希尔排序
// 原理： 在排序之前，将整体序列调整成基本有序，然后再对全体序列进行一次插入排序

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

// 排序算法的数据结构
#define MAXSIZE 10000
typedef struct
{
    //用于存储要排序数组，r[0]用作哨兵或临时变量
    int r[MAXSIZE+1];
    //用于记录顺序表的长度
    int length;
}SqList;

// 数组打印
void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d",L.r[i]);
    printf("\n");
}

// 交换
void swap(SqList *L, int i , int j) {
    
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}


// 希尔排序
//void ShellSort(SqList *L){
//    // 1. 以一定步长为间隔，对数组进行一次，插入排序，是数组变得基本有序
//    // 2. 然后缩短步长，在对数组进行插入排序
//    // 3. 直至步长为1时， 再次进行一次插入排序后，就变成有序数组了。
//    int increment = L->length;
//     do {
//         // 缩短步长
//         increment = increment / 3 + 1;
//
//         for (int i = 1; i < 1 + increment; i++) {
//             // 对每一组子数组进行插入排序
//             for (int j = i + increment; j <= L->length; j += increment) {
//                 if (L->r[j] < L->r[j-increment])  {
//                     // 利用哨兵保存变量
//                     L->r[0] = L->r[j];
//                     int k;
//                     for (k = j - increment; k > 0 && L->r[k] > L->r[0]; k -= increment) {
//                         L->r[k+increment] = L->r[k];
//                     }
//                     L->r[k + increment] = L->r[0];
////                 for (int k = j; k > 1; k -= increment) {
////                     if (L->r[k] < L->r[k-increment])
////                         swap(L, k, k - increment);
////                 }
//                 }
//             }
//         }
//
//     } while (increment > 1);
//}

void ShellSort(SqList *L){
    // 1. 以一定步长为间隔，对数组进行一次，插入排序，是数组变得基本有序
    // 2. 然后缩短步长，在对数组进行插入排序
    // 3. 直至步长为1时， 再次进行一次插入排序后，就变成有序数组了。
    int increment = L->length;
     do {
         // 缩短步长
         increment = increment / 3 + 1;
         
         for (int i = increment + 1; i <= L->length; i++) {
             if (L->r[i] > L->r[i - increment]) continue;
             L->r[0] = L->r[i];
             int j;
             for (j = i - increment; j > 0 && L->r[j] > L->r[0]; j -= increment) {
                 L->r[j+increment] = L->r[j];
             }
             L->r[j+increment] = L->r[0];
         }
        
     } while (increment > 1);
}

#define N 9
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int i;
    int d[N]={-7,1,5,8,3,7,4,6,2};
    //int d[N]={9,8,7,6,5,4,3,2,1};
    //int d[N]={50,10,90,30,70,40,80,60,20};
    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    
    for(i=0;i<N;i++)
        l0.r[i+1]=d[i];
    
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    
    printf("排序前:\n");
    print(l0);
    printf("\n");
    
    printf("希尔排序:\n");
    ShellSort(&l0);
    print(l0);
    printf("\n");
    
//    printf("冒泡排序2:\n");
//    BubbleSort0(&l1);
//    print(l1);
//    printf("\n");
//
//    printf("冒泡排序优化:\n");
//    BubbleSort0(&l2);
//    print(l2);
//    printf("\n");
    
    
    return 0;
}
