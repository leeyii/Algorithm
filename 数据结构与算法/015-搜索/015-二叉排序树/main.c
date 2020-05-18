//
//  main.c
//  015-二叉排序树
//
//  Created by leeyii on 2020/5/16.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct BiNode{
    int data;        // 数据
    struct BiNode *lChild; // 左孩子
    struct BiNode *rChild; // 右孩子
}BiNode, *BiTree;

/*
 二叉排序树
 在二叉排序树的任一子树,都有以下规则,他的左子树的节点小于根节点,右子树上的节点大于根节点.
 */


/// 1.1 二叉排序树-查找 (递归实现)
/// @param T 二叉树
/// @param key 关键字
/// @param f 树的双亲节点
/// @param p 如果找到返回节点,如果找不到,返回最后的一个节点
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    
    if (!T) { // 查找失败
        *p = f;
        return FALSE;
    }
    
    if (key == T->data) { // 找到关键字, 给*p 赋值
        *p = T;
        return TRUE;
    } else if (key < T->data)  // 关键字小于根节点,在树的左子树继续向下查找
        return SearchBST(T->lChild, key, T, p);
    else // 关键字大于根节点,在树的右子树继续向下递归查找
        return SearchBST(T->rChild, key, T, p);
}

//2.二叉排序树-插入
/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
Status InsertBST(BiTree *T, int key) {
    
    
    return TRUE;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
