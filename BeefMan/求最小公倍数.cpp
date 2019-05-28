#include <iostream>

int highest_common_divisor(int a, int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    return a;
}

int main()
{
    int A,B;
    while(std::cin >> A >> B){
        std::cout << A * B / highest_common_divisor(A,B) << std::endl;
    }
    return 0;
}