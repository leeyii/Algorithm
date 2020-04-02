//
//  main.c
//  001-顺序表
//
//  Created by leeyii on 2020/4/2.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0
#define MAX_SIZE 10

typedef int Element;
typedef int Status;

// 结构
typedef struct {
    Element * data;
    int length;
}SqList;

// 初始化 顺序表
Status initList(SqList *l) {
    // 入参判断
    if (l == NULL) return ERROR;
    // 分配内存
    l->data = (int *)malloc(sizeof(Element) * MAX_SIZE);
    // 内存开辟失败 返回error
    if (!l->data) return ERROR;
    l->length = 0;
    return OK;
}

// 打印顺序表
void printList(SqList l) {
    
    printf("=========begain==========\n");
    
    printf("list length: %d\n", l.length);
    
    for (int i = 0; i < l.length; i++) {
        printf("%5d\n", l.data[i]);
    }
    
    printf("==========end===========\n");
}


/// 顺序表插入 index从0开始计算
/// @param l 操作的顺序表
/// @param i 插入位置
/// @param e 插入元素
Status ListInsert(SqList *l, int i, Element e) {
    
    // 1. 入参合法判断
    // 2. 储存空间是否已满
    // 3. 插入位置是否在表尾
    // 3.1 在表尾直接插入
    // 3.2 不在表尾,插入位置之后的元素 包含插入位置 向右移动一位.将元素放在i
    // 4.长度+1
    
    // 1.
    if (i < 0 || i > l->length - 1) return ERROR;
    // 2.
    if (l->length == MAX_SIZE) return ERROR;
    // 3.2
    if (i < l->length - 1) {
        for (int j = l->length - 1; j >= i ; j--) {
            l->data[j + 1] = l->data[j];
        }
    }
    
    // 将新元素放在第i个位置上
    l->data[i] = e;
    // 长度 +1
    l->length++;
    
    return OK;
}


/// 删除顺序表中的元素
/// @param l 顺序表
/// @param i 删除元素的位置 (index 从0开始计算)
Status ListDelete(SqList *l, int i) {
    
    // 1. 入参安全判断
    // 2. 删除的元素是否在表尾
    // 2.1 在表尾 直接length - 1
    // 2.2 不在表尾 要删除位置之后的元素依次左移一位
    
    if (l->length == 0) return ERROR;
    
    if (l == NULL || i < 0 || i > l->length - 1) return ERROR; // 这行代码包含了上面代码的逻辑
    
    if (i < l->length - 1) {
        for (int x = i; x < l->length; x++) {
            l->data[x] = l->data[x+1];
        }
    }
    l->length--;
    
    return OK;
}

/// 获取指定位置的值, index从0开始计算
/// @param l 顺序表
/// @param i index
/// @param e 元素的值
Status GetElement(SqList l, int i, Element *e) {
    
    // 1. 入参判断
    // 2. 找到第i个元素
    
    if (i < 0 || i > l.length - 1) return ERROR;
    
    *e = l.data[i];
    
    return OK;
}

/// 清空
Status ClearList(SqList *l) {
    if (l == NULL) return ERROR;
    l->length = 0;
    return OK;
}

/// 判断是否为空
int ListIsEmpty(SqList l) {
    return l.length == 0;
}

/// 顺序表的长度
int ListLength(SqList l) {
    return l.length;
}


/// 查找第一个命中的元素,并返回他的index, 如果没有查找到,返回-1
/// @param l 顺序表
/// @param e 查找的元素
int LocateFirstElement(SqList l, Element e) {
    for (int i = 0; i < l.length; i++) {
        if (e == l.data[i]) return i;
    }
    return -1;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqList list;
    
    initList(&list);
    
    printList(list);
    
    ListInsert(&list, 1, 1);
    
    ListInsert(&list, 2, 2);
    
    printList(list);
    
    
    return 0;
}
