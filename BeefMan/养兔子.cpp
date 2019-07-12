// 一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。
//  某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。


// 输入描述:
// 测试数据包括多组，每组一行，为整数n(1≤n≤90)。


// 输出描述:
// 对应输出第n天有几只兔子(假设没有兔子死亡现象)。
// 示例1
// 输入
// 1
// 2
// 输出
// 1
// 2

// write your code here cpp// write your code here cpp
#include <iostream>


long long rabbit(int n){
    long long arr[100] = {1,2};
    for(int i = 2; i < n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return arr[n - 1];
}

int main()
{
    int n;
    while(std::cin >> n){
        std::cout << rabbit(n) << std::endl;
    }
    return 0;
}