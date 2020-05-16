//
//  main.c
//  015-搜索
//
//  Created by leeyii on 2020/5/14.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>


/// 顺序查找
/// @param a 查找的数组
/// @param n 数组的长度
/// @param key 查找的关键字
int Sequential_Search(int *a, int n, int key) {
    
    for (int i = 1; i < n; i++) {
        if (a[i] == key)
            return i;
    }
    return 0;
}


/// 顺序查找(哨兵)
/// @param a 查找的数组
/// @param n 数组的长度
/// @param key 查找的关键字
int Sequential_Search2(int *a, int n, int key) {
    
    int i = n;
    // 设置a[0]为关键字,称为哨兵
    a[0] = key;
    // 从后往前遍历
    while (a[i] != key) {
        i--;
    }
    // 如果返回0说明查找失败
    return i;
}

/// 二分查找
/// 前提数组是有序的
int Binary_Search(int *a, int n, int key) {
    
    int low, mid, high;
    // 初始化 low high
    low = 0;
    high = n - 1;
    
    while (low <= high) {
        
        // 计算查找范围的中间index
        mid = low + (high - low) / 2;
        
        // 如果key比中间的值大, 则下次在 mid 和 high 范围内查找
        // 如果key比中间值小, 则下次在 low 和 min 范围内查找
        if (key > a[mid]) {
            low = mid + 1;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    // 没找到返回-1
    return -1;
}

/// 差值查找
int Interpolation_Search(int *a,int n,int key) {
    
    int low, mid, high;
    // 初始化 low high
    low = 0;
    high = n - 1;
    
    while (low <= high) {
        
        // 计算查找范围的中间index
        mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
        // 如果key比中间的值大, 则下次在 mid 和 high 范围内查找
        // 如果key比中间值小, 则下次在 low 和 min 范围内查找
        if (key > a[mid]) {
            low = mid + 1;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    // 没找到返回-1
    return -1;
}

/// 斐波那契数组
int F[100];

/// 斐波那契查找
int Fibonacci_Search(int *a,int n,int key) {
    
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    int i = 0;
    
    while (n > F[i]) {
        i++;
    }
    
    
    
    // 0 1 1 2 3 5 8 13
    while (low <= high) {
        
        mid = F[i - 1];
        
        if (a[mid] < key) {
            low = mid + 1;
            i = i - 2;
        } else if (a[mid] > key) {
            high = mid - 1;
            i = i - 1;
        } else {
            if (mid < n)
                return mid;
            else
                return n - 1;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    return 0;
}
