
// 居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。
// nowcoder这就去买猪肉，结果找来的零钱中有假币！！！
// 可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，
// 给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

// 输入描述:
// 1≤n≤2^30,输入0结束程序。


// 输出描述:
// 最多要称几次一定能把那个假币找出来？



#include <iostream>


int main()
{
    long long n ;
    while(std::cin >> n && n){
        if(n == 1){
            std::cout << 0 << std::endl;
        }else if(n == 2 || n == 3){
            std::cout << 1 << std::endl;
        }else{
            int count = 1;
            while(n > 3){
                if(n % 3 == 0){
                    n /= 3;
                }else
                    n = n / 3 + 1;
                count++;
            }
            std::cout << count << std::endl;
        }
    }
    return 0;
}