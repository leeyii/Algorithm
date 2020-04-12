//
//  main.c
//  006-线性表练习题
//
//  Created by leeyii on 2020/4/10.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int Status;
typedef int Element;

typedef struct Node {
    Element data;
    struct Node *next;
}Node, *LinkList;

/// 初始化链表
/// @param l 链表
Status InitList(LinkList *l, int *arr, int count) {
    // 初始化头结点
    *l = malloc(sizeof(Node));
    // 初始化失败
    if (*l == NULL) return ERROR;
    // 将头结点指针域置空
    (*l)->next = NULL;
    
    Node *tail = *l;
    
    for (int i = 0; i < count; i++) {
        Node *n = (Node *)malloc(sizeof(Node));
        n->next = NULL;
        n->data = arr[i];
        tail->next = n;
        tail = n;
    }
    
    return OK;
}

/// 插入链表
/// @param l 链表
/// @param i 插入位置
/// @param e 插入元素
Status ListInsert(LinkList *l, int i, Element e) {
    
    LinkList p = *l;
    int j = 0;
    
    // 1.寻找i-1个结点
    while (p && j < i) {
        j++;
        p = p->next;
    }
    
    if (!p || j > i) return ERROR;
    
    // 创建新的结点
    Node *node = malloc(sizeof(Node));
    if (!node) return ERROR;
    node->data = e;
    // 新节点的next 指向p的next
    node->next = p->next;
    // p的next 指向新节点
    p->next = node;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;           /*  p指向第一个结点 */
    while(p)                /*  没到表尾 */
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;        /* 头结点指针域为空 */
    return OK;
}


/*
 题⽬1 :
 将2个递增的有序链表合并为⼀个链表的有序链表; 要求结果链表仍然使⽤两个链表的存储空间,
 不另外占⽤其他的存储空间. 表中不允许有重复的数据
 
 解题思路:
 题目要求 结果使用原始链表的储存空间,意味着我们不能去开辟结点,那么我们使用l1的头结点作为 输出链表的头结点.
 
 1. 创建两个指针 p1 p2 分别指向链表 l1 l2 的第一个结点, 创建链表指针l3, 指向l1的头结点, 创建结点指针p3指向l3的尾结点
 2. 比较p1和p2的数据大小
 3. 如果p1->data < p2->data, 将p3->next = p1, p1 = p1->next.
 4. 如果p1->data > p2->data, 将p3->next = p2, p2 = p2->next.
 5. 如果p1->data = p2->data, 我们默认使用p1的结点, 删除p2结点.
 6. 将p3指向当前的尾结点 p3 = p3->next;
 7. 重复支持 上面 2 - 6 步, 直到 p1 或 p2 中某一个指针为空,跳出循环
 8. 将p3->next 指向 p1 和 p2 中 不为空的结点
 
 时间复杂度: O(max(m, n))
 空间复杂度: O(1)
 */
LinkList * mergeTwoList(LinkList *l1, LinkList *l2) {
    
    Node *p1, *p2, *p3;
    LinkList *l3 = l1;
    // p1指向链表l1的首元结点
    p1 = (*l1)->next;
    // p2指向l2的首元结点
    p2 = (*l2)->next;
    // p3指向l3的尾结点, 当l3为空时,指向头结点
    p3 = *l3;
    
    // p1 和 p2 都不为空时继续循环, 任一为空则跳出循环
    while (p1 && p2) {
        if (p1->data > p2->data) {
            p3->next = p2;
            p2 = p2->next;
        } else if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        } else {
            p3->next = p1;
            p1 = p1->next;
            
            Node *temp = p2;
            p2 = p2->next;
            free(temp);
        }
        p3 = p3->next;
    }
    
    p3->next = p1 ?: p2;
    free(*l2);
    return l3;
}


/*
 题目2:
 已知两个链表A和B分别表示两个集合.其元素递增排列. 设计一个算法,用于求出A与B的交集,并存储在A链表中;
 例如:
 La = {2,4,6,8}; Lb = {4,6,8,10};
 Lc = {4,6,8}
 
 从头开始对比连个链表中的元素, 如果相等, 将链表A的next指向 链表A中的元素, 如果不相等, 将较小的那个元素删除.
 
 实现思路:
 1. 创建指针 pa pb 分别指向链表 A B 的首元结点
 2. 创建指针 tail 表示, 交集链表的 尾结点指针
 3. 比较 pa->data 和 pb->data
 4. 如果 pa->data == pb->data, 将新链表的next指向pa, 删除pb, pa 和 pb 分别指向他们的next
 5. 如果 pa->data > pb->data, 删除pb, pb=pb->next
 6. 如果 Pa->data < pb->data, 删除pa, pa=pa->next
 7. 重复上述 3 - 6步, 直到pa 或 pb 为空跳出循环
 8. 释放多出来的元素内存
 9. 释放Lb的首结点
 
 时间复杂度:O(max(la.length, lb.length))
 空间复杂度:O(1)
 */
void intersection(LinkList *la, LinkList *lb) {
    
    Node *pa = (*la)->next, *pb = (*lb)->next;
    Node *tail = *la;
    Node *temp = NULL;
    
    while (pa && pb) {
        if (pa->data == pb->data) {
            tail->next = pa;
            tail = pa;
            temp = pb;
            pa = pa->next;
            pb = pb->next;
            free(temp);
        } else if (pa->data > pb->data) {
            temp = pb;
            pb = pb->next;
            free(temp);
        } else {
            temp = pa;
            pa = pa->next;
            free(temp);
        }
    }
    
    temp = pa ?: pb;
    while (temp) {
        Node *n = temp;
        temp = temp->next;
        free(n);
    }
    
    free(*lb);
}

/*
 题⽬3 :
 设计⼀个算法,将链表中所有节点的链接⽅向"原地旋转",即要求仅仅利⽤原表的存储空间. 换句
 话说,要求算法空间复杂度为O(1);
 例如:L={0,2,4,6,8,10}, 逆转后: L = {10,8,6,4,2,0};
 
 时间复杂度: O(n)
 */
void reverseList(LinkList *l) {
    // 当前操作结点
    Node *p = (*l)->next;
    // 当前操作结点的下一个结点, 防止丢失
    Node *temp;
    (*l)->next = NULL;
    while (p) {
        temp = p->next;
        p->next = (*l)->next;
        (*l)->next = p;
        p = temp;
    }
}


/*
 题⽬4 :
 设计⼀个算法,删除递增有序链表中值⼤于等于mink且⼩于等于maxk(mink,maxk是给定的两个
 参数,其值可以和表中的元素相同,也可以不同)的所有元素;
 
 思路: 找到链表中第一个大于等于mink的元素的前一个元素, 和第一个大于maxk的元素, 将他们相连.
 
 步骤
 1. 遍历链表
 2. 找到第一个大于mink的元素, 记录他的前驱结点 per
 3. 继续遍历链表, 找到大于maxk的一个结点 p
 4. 将per的next指向p
 5. 释放 per和p直接的结点
 
 时间复杂度: O(n)
 空间复杂度: O(1)
 */
void deleteMinMax(LinkList *list, int mink, int maxk) {
    
    Node *p = (*list)->next;
    
    Node *per = NULL, *q = NULL;
    
    while (p && p->data < mink) {
        per = p;
        p = p->next;
    }
    
    while (p && p->data <= maxk) {
        p = p->next;
    }
    
    q = per->next;
    per->next = p;

    while (q != p) {
        Node *temp = q->next;
        free(q);
        q = temp;
    }
}

/*
 题⽬5 :
 设将n(n>1)个整数存放到⼀维数组R中, 试设计⼀个在时间和空间两⽅⾯都尽可能⾼效的算法;将R
 中保存的序列循环左移p个位置(0<p<n)个位置, 即将R中的数据由(x0,x1,……,xn-1)变换为
 (xp,xp+1,...,xn-1,x0,x1,...,xp-1).
 例如: pre[10] = {0,1,2,3,4,5,6,7,8,9}, n = 10,p = 3; pre[10] = {3,4,5,6,7,8,9,0,1,2}
 
 
 */

void reverseArr1(int *arr, int start, int end) {
    int i = start, j = end;
    int temp;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void shiftArr(int *arr, int count, int n) {

    reverseArr1(arr, 0, n - 1);
    reverseArr1(arr, n, count - 1);
    reverseArr1(arr, 0, count - 1);
}


/*
 题⽬6 :
 已知⼀个整数序列A = (a0,a1,a2,...an-1),其中(0<= ai <=n),(0<= i<=n). 若存在ap1= ap2 = ...=
 apm = x,且m>n/2(0<=pk<n,1<=k<=m),则称x 为 A的主元素. 例如,A = (0,5,5,3,5,7,5,5),则5是主
 元素; 若B = (0,5,5,3,5,1,5,7),则A 中没有主元素,假设A中的n个元素保存在⼀个⼀维数组中,请设
 计⼀个尽可能⾼效的算法,找出数组元素中的主元素,若存在主元素则输出该元素,否则输出-1.
 
 题目解析:
 查找主元素, 如果一个数组中存在某一个元素数量大于数组长度的二分之一,那么这个元素就是数组的主元素,如果没有,那么这个数组就没有主元素.
 
 解题思路:
 定义连个变量, main 和 count, main表示主元素, 遍历数组, 当数组元素和主元素相同时,count+1, 如果不一样count-1, 当count到0时, 将主元素替换为当前元素.
 当遍历结束时, 会得到一个主元素, 再次遍历一个数组, 确定此元素是否是主元素
 
 步骤:
 1. 定义变量: main 和 count 设置初始值为 mian = arr[0], count = 1;
 2. 从数组第二个开始遍历,
 3. 如果元素 == main, count++
 4. 如果元素 != main, count--, 当count == 0 , main = 当前元素
 5. 重复 3, 4 找到主元素
 6. 遍历数组, 数组元素 == main ,count ++
 7. 遍历结束, 如果count > arr长度的二分之一, 那么这个元素就是数组的主元素, 否则数组没有主元素
 
 时间复杂度: O(n)
 空间复杂度: O(1)
 */
int findMain(int * arr, int length) {
    // 候选主元素
    int main = arr[0];
    // 计数 候选主元素的
    int count = 1;
    
    // 遍历数组
    for (int i = 1; i < length; i++) {
        int item = arr[i];
        // 如果item 和 候选主元素相等, count + 1
        if (item == main) {
            count++;
        } else {
            // 不相等 count - 1
            count--;
            // 如果count == 0, 更换候选主元素
            if (count == 0) {
                main = item;
                count = 1;
            }
        }
    }
    
    count = 0;
    // 再一次遍历, 确定候选主元素是不是主元素
    for (int i = 0; i < length; i++) {
        if (arr[i] == main) {
            count++;
        }
    }
    
    if (count > (length / 2)) {
        return main;
    } else {
        return -1;
    }
}

/*
 题⽬7 :
 ⽤单链表保存m个整数, 结点的结构为(data,link),且|data|<=n(n为正整数). 现在要去设计⼀个时
 间复杂度尽可能⾼效的算法. 对于链表中的data 绝对值相等的结点, 仅保留第⼀次出现的结点,⽽
 删除其余绝对值相等的结点.例如,链表A = {21,-15,15,-7,15}, 删除后的链表A={21,-15,-7};
 
 题目解析:
 创建一个长度为n+1数组, 数组内标识为0, 遍历单链表, 使用单链表的值得绝对值为key在数组中寻找,找的值为0, 说明是第一次出现, 保留这个元素, 并将数组中,这个key对应的值改为1, 如果找到的值为1, 说明这个元素,出现过,删除这个元素.
 
 解题步骤:
 1. 初始化长度为n+1的数组
 2. 遍历单链表
 3. 如果单链表中的元素 arr[|p->data|] == 0, arr[|p->data|] = 1
 4. 如果 arr[|p->data|] != 0, 删除此元素.
 5. 重复 3, 4 步
 
 时间复杂度: O(m)
 空间复杂度: O(n)
 */

void deleteEqual(LinkList *list, int n) {
    
    Node *p = (*list)->next;
    Node *r = *list;
    
    // 初始化数组
    int arr[n];
    
    while (p) {
        if (arr[abs(p->data)] == 0) {
            arr[abs(p->data)] = 1;
            r = p;
            p = p->next;
        } else {
            r->next = p->next;
            free(p);
            p = r->next;
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Status iStatus;
    LinkList La,Lb,Lc,L;
//    InitList(&La);
//    InitList(&Lb);
    
    //    ---------作业1--------
    //    printf("******题目1:********\n");
    //    //设计2个递增链表La,Lb
    //    for(int j = 10;j>=0;j-=2)
    //    {
    //        iStatus = ListInsert(&La, 0, j);
    //    }
    //    printf("La:\n");
    //    ListTraverse(La);
    //
    //    for(int j = 11;j>0;j-=2)
    //    {
    //        iStatus = ListInsert(&Lb, 0, j);
    //    }
    //    printf("Lb:\n");
    //    ListTraverse(Lb);
    //
    //    Lc = *(mergeTwoList(&La, &Lb));
    //    printf("Lc:\n");
    //    ListTraverse(Lc);
    
    /*---------作业2--------*/
//    printf("******题目2:********\n");
//    int arr1[] = {2, 4, 6, 8};
//    InitList(&La, arr1, (sizeof(arr1) / sizeof(int)));
//    printf("La:\n");
//    ListTraverse(La);
//
//
//    int arr2[] = {4, 6, 8, 10};
//    InitList(&Lb, arr2, (sizeof(arr2) / sizeof(int)));
//    printf("Lb:\n");
//    ListTraverse(Lb);
//
//    intersection(&La, &Lb);
//    printf("La:\n");
//    ListTraverse(La);
    
    /*---------作业3--------*/
//    printf("******题目3:********\n");
//
//    int arr[] = {1, 10};
//    InitList(&La, arr, sizeof(arr) / sizeof(int));
//    printf("逆转前:\n");
//    ListTraverse(La);
//    reverseList(&La);
//    printf("逆转后:\n");
//    ListTraverse(La);
    
    /*---------作业5--------*/
//    printf("******题目5:********\n");
//    int pre[10] = {0,1,2,3,4,5,6,7,8,9};
//    shiftArr(pre, 10, 3);
//    for (int i=0; i < 10; i++) {
//        printf("%d ",pre[i]);
//    }
//    printf("\n");
    
    //     /*---------作业6--------*/
//    printf("******题目6:********\n");
//    int  A[] = {0,5,5,3,5,7,5,5};
//    int  B[] = {0,3,5,3,3,1,3,3};
//    int  C[] = {0,1,2,3,4,5,6,7};
//
//    int value = findMain(A, 8);
//    printf("数组A 主元素为: %d\n",value);
//    value = findMain(B, 8);
//    printf("数组B 主元素为(-1表示数组没有主元素): %d\n",value);
//    value = findMain(C, 8);
//    printf("数组C 主元素为(-1表示数组没有主元素): %d\n",value);
    
     /*---------作业7--------*/
    //21,-15,15,-7,15
    printf("******题目7:********\n");
    int arr[] = {21,-15,15,-7,15};
    InitList(&L, arr, 5);
    deleteEqual(&L, 21);
    ListTraverse(L);
    
    
    return 0;
}
