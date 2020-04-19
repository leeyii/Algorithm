//
//  main.c
//  爬楼梯
//
//  Created by leeyii on 2020/4/16.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

/*
 爬楼梯问题:(LeetCode-中等) 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不 同的⽅法可以爬到楼顶呢？注意：给定 n 是⼀个正整数å
 
 */

/*
 解法一:
 暴力解法
 */

int climbStairs1(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs1(n - 1) + climbStairs1(n - 2);
}

/*
 解法二:
 动态规划
 
 */
int climbStairs2(int n) {
    
    if (n < 3) {
        return n;
    }
    int arr[n];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}



int main(int argc, const char * argv[]) {
    // insert code here...

    
    return 0;
}
