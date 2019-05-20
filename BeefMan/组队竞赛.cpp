
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n = 0;
    while(std::cin >> n){
        std::vector<int> v;
        v.resize(3*n);
        long long max = 0;
        for(int i = 0; i < 3 * n; ++i){
            std::cin >> v[i];
        }
        sort(v.begin(), v.end());
        int count = n;
        for(int i = n; i < 3 * n - 1; i += 2){
           max += v[i];
       }
        
        std::cout << max << std::endl;
    }
    return 0;
}