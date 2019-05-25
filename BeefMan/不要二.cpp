// 一个 W * H 的 网格，每个格子至多放一个蛋糕，任意两个蛋糕的欧几里德距离不能等于 2
//输出一个最多可以放的蛋糕数目


// 任意两个蛋糕的欧几里德距离不能等于2 --> 任意两个蛋糕的横向和纵向距离不能等于 2
// 三种情况
// 1. 4 的倍数
// 2. 2 的倍数但不是4的倍数
// 3. 其他

#include <iostream>

int main()
{
    int W,H,count = 0;
    while(std::cin >> W >> H){
        if(W % 4 == 0 || H % 4 == 0){
            count = W * H / 2;
        }else if(W % 2 == 0 && H % 2 == 0){
            count = (W * H / 4 + 1) * 2;
        }else{
            count = W * H / 2 + 1;
        }
        
        std::cout << count << std::endl;
    }
    return 0;
}