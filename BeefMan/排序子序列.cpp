#include <iostream>
#include <vector>

int ChildSequence(std::vector<int>& v, int n){
    int i = 0;
    int count = 0;
    while(i < n - 1){
        while(i < n - 1 && v[i] == v[i + 1]){
            i++;
        }
        //降序
        if(i < n - 1 && v[i] > v[i + 1]){
            ++count;
            while(i < n - 1 && v[i] >= v[i + 1]){
                i++;
            }
            i++;
        }
        else if(i < n - 1 && v[i] < v[i + 1]){
            ++count;
            while(i < n - 1 && v[i] <= v[i + 1]){
                i++;
            }
            i++;
        }
        
    }
    
    if(i == n - 1)
        return ++count;
    else
        return count;
}


int main()
{
    int n = 0;
    std::vector<int> v;
    
    while(std::cin >> n){
        v.resize(n);
        for(int i = 0; i < n; i++){
            std::cin >> v[i];
        }
        
        int ret = ChildSequence(v, n);
        std::cout << ret << std::endl;
        
    }
}