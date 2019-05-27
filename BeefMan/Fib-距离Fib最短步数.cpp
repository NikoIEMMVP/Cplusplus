// 给一个整数 N （1 ～ 1000000）
// 距离一个斐波那且数列中的数的最短步数
// Fib[] = {0,1,1,2,3,5,8,13}
// 例如 N = 15
// 最短步数为 2



#include <iostream>

int main()
{
    long N = 0;
    while(std::cin >> N){
        long ret = 999999;
        long count = 0;
        int Fib[1000] = {0,1};
        int i = 2;
        while(i){
            Fib[i] = Fib[i - 1] + Fib[i - 2];
            count = abs(N - Fib[i]);
            if(count < ret){
                ret = count;
            }
            else if(count >= ret){
                break;
            }

            i++;
        }
        
        std::cout << ret << std::endl;
    }
    return 0;
}