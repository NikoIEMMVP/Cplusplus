

// 一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
// 例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
// 你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

// 输入描述:
// 第一行输入一个正整数n(n ≤ 1000)
// 第二行为n个数正整数xi(xi ≤ 1000)


// 输出描述:
// 输出可以产生的幸运的袋子数

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combination(vector<unsigned int>::iterator Begin, const vector<unsigned int>:: iterator& End,
                 unsigned int& Sum, unsigned int& Mul, unsigned int& counts){
    if(Begin == End)
        return;
    
    Sum += *Begin;
    Mul *= *Begin;
    if(Sum > Mul){
        ++counts;
        combination(Begin+1, End, Sum, Mul, counts);
    }
    
    #if 1
    Sum -= *Begin;
    Mul /= *Begin;
    
    unsigned int num = *Begin;
    while(num == *Begin)
        ++Begin;
    combination(Begin, End, Sum, Mul, counts);
    return;
    #endif
}

int getLuckyBags(vector<unsigned int>& v){
    unsigned int counts = 0;
    if(v.size() >= 2){
        sort(v.begin(), v.end());
        unsigned int Sum = v[0], Mul = v[0];
        vector<unsigned int> :: iterator Begin = v.begin() + 1;
        combination(Begin, v.end(), Sum, Mul, counts);
    }
    return counts;
}

int main()
{
    unsigned int n;
    while(cin >> n){
        vector<unsigned int> v(n);
        for(int i = 0; i < v.size(); ++i){
            cin >> v[i];
        }
        
        cout << getLuckyBags(v) << endl;
    }
    return 0;
}