// 输入一系列整数，以空格隔开，
// 某个数出现的次数大于数组长度的一半，求那个数。
// ！！！个数不确定



#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int i = 0;
    std::vector<int> v;
    while(std::cin >> i){
        v.push_back(i);
        i++;
        if(std::cin.get() == '\n')
            break;
    }
    
    sort(v.begin(), v.end());
    std::cout << v[(v.size() - 1) / 2] << std::endl;
    return 0;
}