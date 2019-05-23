#include <iostream>
#include <vector>

void Sugar(std::vector<int>& v){
    if((v[0] + v[2]) % 2 == 1 && (v[1] + v[3]) % 2 == 1 
        && (v[3] - v[1]) % 2 == 1){
        std::cout << "No" << std::endl;
        return ;
    }
    
    int A = (v[0] + v[2]) / 2;
    int B = (v[1] + v[3]) / 2;
    int C = (v[3] - v[1]) / 2;
    
    std::cout << A << " " << B << " " << C ;
        
}


int main()
{
    std::vector<int> v(4);
    for(int i = 0; i < 4; i++){
        std::cin >> v[i];
    }
    
    Sugar(v);
    return 0;
}