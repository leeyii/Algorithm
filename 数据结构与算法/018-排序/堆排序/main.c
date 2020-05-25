//
//  main.c
//  堆排序
//
//  Created by leeyii on 2020/5/24.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>


// 堆排序

// 堆得定义：
// 1.堆一定是完全二叉树
// 2.每一个节点的值都大于其左孩子和右孩子的值称为大顶堆， 每个节点都小于其左孩子和右孩子的值称为小顶堆

/*
  堆排序的实现思路：
 1.将整个无序的数组调整为堆
 2.然后将堆顶和最后一个元素进行交换，这样最大或最小的元素就到了数组的最后一个位置
 3.然后将数组[0 ... n-1]重新调整为堆，接着讲堆顶和n-1位置进行交换
 4.重复上述步骤
 */

// 如果需要升序排序，使用大顶堆，如果要降序则使用小顶堆。

// 问题1： 如何将无序的数组调整成堆？


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

void HeapAdjust(SqList *L, int s, int m) {
    int j;
    // 记录s位置的值
    int temp = L->r[s];
    for (j = s * 2; j <= m; j *= 2) {
        // 右孩子是否>m， 找到孩子中较大的一个。
        if (j + 1 <= m && L->r[j] < L->r[j+1])
            j++;
        
        // 如果temp 大于 较大的孩子，说明符合堆结构，结束循环
        if (temp > L->r[j]) break;
        
        // 将较大的孩子放到其双亲节点
        L->r[s] = L->r[j];
        // 记录temp最终应该放置的位置
        s = j;
    }
    
    L->r[s] = temp;
}

void HeapSort(SqList *L) {
    
    // 1. 将整个无序的数组，调整成符合大顶堆定义的数组
    // length / 2 可以得到 最后一个非叶子节点的序号
    // 然后按照从大到小的顺序，依次将每一个节点调整成符合堆结构
    // 通过这样的方式，就可以将整个数组，调整成堆
    for (int i = L->length / 2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }
    
    // 2.依次将堆顶元素 和 最后一个元素进行交换, 在将其调整成大顶堆
    for (int i = L->length; i > 1; i--) {
        
        swap(L, 1, i);
        
        HeapAdjust(L, 1, i - 1);
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
    
    printf("堆排序:\n");
    HeapSort(&l0);
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
    printf("\n");
    
    
    return 0;
}

