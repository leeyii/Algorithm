//
//  main.c
//  016-平衡二叉树
//
//  Created by leeyii on 2020/5/18.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Status;

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERRPR 0

// 平衡二叉树（AVL）： 是一种二叉排序树，其中每一个节点的左子树和右子树的高度差至多等于1.

// 平衡因子（BF）：我们将二叉树上节点的左子树深度减去右子树深度称为平衡因子。

// 最小不平衡子树： 距离插入点最近，且平衡因子的绝对值大于1的节点为根的字数，我们称为最小不平衡子树

// 平衡二叉树构建的基本思想：就是在构建二叉排序树的过程中，没插入一个节点时，先检查是否因插入而破坏了树的平衡性，若是，则找到最小不平衡字数，在保持二叉排序树特性的前提下，调整最小不平衡子树各节点直接的链接关系，进行相应的旋转，使之成为新的平衡子树。

typedef struct BiNode {
    int data;
    int bf;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode, *BiTree;

// 左旋
void L_Rotate(BiTree *p) {
    // 将根节点的右子树，变为根节点
    //
    // 1. 记录R 为*p的右子树
    BiTree R = (*p)->rchild;
    // 2. 将*p的右子树指向R的左子树
    (*p)->rchild = R->lchild;
    // 3. 将R的左子树指向 *p
    R->lchild = *p;
    // 4. 将根节点指向R
    *p = R;
}

// 右旋
void R_Rotate(BiTree *p) {
    
    // 1. 记录L 为*p的左子树
    BiTree L = (*p)->lchild;
    // 2. 将*p的左子树指向，L的右子树
    (*p)->lchild = L->rchild;
    // 3. 将L的右子树指向*p
    L->rchild = *p;
    // 4. 将*p指向L
    *p = L;
}

#define LH 1
#define EH 0
#define RH -1

void LeftBalance(BiTree *T) {
    
    BiTree l, lr;
    
    l = (*T)->lchild;
    
    switch (l->bf) {
        case LH:
        {
            l->bf = (*T)->bf = EH;
            R_Rotate(T);
            break;
        }
        case RH:
        {
            lr = l->rchild;
            switch (lr->bf) {
                case LH:
                {
                    (*T)->bf = RH;
                    l->bf = EH;
                    break;
                }
                case EH:
                {
                    (*T)->bf = EH;
                    l->bf = EH;
                    break;
                }
                case RH:
                {
                    (*T)->bf = EH;
                    l->bf = LH;
                    break;
                }
            }
            lr->bf = EH;
            L_Rotate(&l);
            R_Rotate(T);
            break;
        }
    }
    
}

void RightBalance(BiTree *T) {
    
    BiTree r, rl;
    
    r = (*T)->rchild;
    
    switch (r->bf) {
        case RH:
        {
            r->bf = (*T)->bf = EH;
            L_Rotate(T);
            break;
        }
        case LH:
        {
            rl = r->lchild;
            switch (rl->bf) {
                case LH:
                {
                    (*T)->bf = EH;
                    r->bf = RH;
                    break;
                }
                case EH:
                {
                    (*T)->bf = EH;
                    r->bf = EH;
                    break;
                }
                case RH:
                {
                    (*T)->bf = LH;
                    r->bf = EH;
                    break;
                }
            }
            r->bf = EH;
            R_Rotate(&r);
            L_Rotate(T);
            break;
        }
    }
}

Status InsertAVLTree(BiTree *T, int key, int *taller) {
    
    if (T == NULL) {
        BiNode *node = (BiTree)malloc(sizeof(BiNode));
        node->data = key;
        node->bf = EH;
        node->lchild = NULL;
        node->rchild = NULL;
        *T = node;
        *taller = TRUE;
        return TRUE;
    } else {
        
        if (key < (*T)->data) {
            
            if (!InsertAVLTree(&(*T)->lchild, key, taller)) {
                return FALSE;
            } else {
                if (*taller) {
                    switch ((*T)->bf) {
                        case LH:
                        {
                            LeftBalance(T);
                            *taller = FALSE;
                            break;
                        }
                        case EH:
                        {
                            (*T)->bf = LH;
                            *taller = TRUE;
                            break;
                        }
                        case RH:
                        {
                            (*T)->bf = EH;
                            *taller = FALSE;
                            break;
                        }
                    }
                }
            }
            
        } else if (key > (*T)->data) {
            
            if (!InsertAVLTree(&(*T)->rchild, key, taller)) {
                return FALSE;
            } else {
                if (*taller) {
                    switch ((*T)->bf) {
                        case LH:
                        {
                            (*T)->bf = EH;
                            *taller = FALSE;
                            break;
                        }
                        case EH:
                        {
                            (*T)->bf = RH;
                            *taller = TRUE;
                            break;
                        }
                        case RH:
                        {
                            RightBalance(T);
                            *taller = FALSE; // note
                            break;
                        }
                    }
                }
            }
        } else {
            *taller = FALSE;
            return FALSE;
        }
    }
    return TRUE;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
