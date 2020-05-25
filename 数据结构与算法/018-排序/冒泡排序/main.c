//
//  main.c
//  冒泡排序
//
//  Created by leeyii on 2020/5/23.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

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

// 冒泡排序
void BubbleSort0(SqList *L) {
    
    for (int i = 1; i < L->length; i++) {
        for (int j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j])
                swap(L, i, j);
        }
    }
}

// 正宗的冒泡排序
void BubbleSort(SqList *L) {
    
    for (int i = 1; i < L->length; i++) {
        // 从后向前开始遍历数组
        for (int j = L->length - 1; j >= i; j--) {
            // 如果前者大于后者则交换， 与上一个算法的区别
            if (L->r[j] > L->r[j+1])
                swap(L, j, j+1);
        }
    }
}

// 优化冒泡排序
void BubbleSort2(SqList *L) {
    Status flag = TRUE;
    for (int i = 1; i < L->length && flag; i++) {
        flag = FALSE;
        for (int j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                // 有交换动作，将flag改为true
                flag = TRUE;
                swap(L, j, j+1);
            }
        }
    }
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
    
    printf("冒泡排序1:\n");
    BubbleSort0(&l0);
    print(l0);
    printf("\n");
    
    printf("冒泡排序2:\n");
    BubbleSort0(&l1);
    print(l1);
    printf("\n");
    
    printf("冒泡排序优化:\n");
    BubbleSort0(&l2);
    print(l2);
    printf("\n");
    
    
    return 0;
}
