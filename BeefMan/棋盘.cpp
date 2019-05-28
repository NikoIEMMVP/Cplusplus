#include <iostream>


int CountStep(int n, int m)
{
    if(1 == n){
        return m + 1;
    }else if(1 == m)
        return n + 1;
    
    return CountStep(n - 1, m) + CountStep(n, m - 1);
}

int main()
{
    int n, m = 0;
    while(std::cin >> n >> m){
        int ret = CountStep(n,m);
        std::cout << ret << std::endl;
    }
    return 0;
}