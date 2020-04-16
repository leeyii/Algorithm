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

int func1(int n) {
    if (n = 1) return 1;
    return func(n - 1) + func(n - 2);
}

int func2(int n) {
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
