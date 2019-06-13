#include <iostream>
#include <vector>

int FindCommonDivisor(int a, int b){
     while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    return a;
}

int main()
{
    int level;
    int n;
    while(std::cin >> n >> level){
        std::vector<int> v(n);
        for(size_t i = 0; i < n; i++){
            std::cin >> v[i];
        }
        
        for(size_t i = 0; i < v.size(); i++){
            if(level >= v[i]){
                level += v[i];
            }else{
                level += FindCommonDivisor(level, v[i]);
            }
        }
        
        std::cout << level << std::endl;
    }
    return 0;
}