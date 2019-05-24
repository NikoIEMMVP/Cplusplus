
// 十六进制需要用字母表示 10 -> a  ...

// #include <iostream>
// #include <stdio.h>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void Transfer(int M, int N){

//     std::vector<int> v;
//     //int i = 0;
//     int remain = 0;
//     int ret = 0;
//     if(N <= 9){
//         while(M != 0){
//             remain = M % N;
//             v.push_back(remain);
//             M /= N;
//         }

//         cout << v.size() << endl;
//         for(int i = v.size() - 1; i >= 0; i--){
//             ret = v[i] + ret*10;
//         }
//         cout << ret << endl;
//     }
//     else{
//         std::string s1;
//         while(M != 0){
//             char remain = M % 16;
//             if(10 == remain)
//                 s1.push_back('a');
//             else if(11 == remain)
//                 s1.push_back('b');
//             else if(12 == remain)
//                 s1.push_back('c');
//             else if(13 == remain)
//                 s1.push_back('d');
//             else if(14 == remain)
//                 s1.push_back('e');
//             else if(15 == remain)
//                 s1.push_back('f');
//             else 
//                 s1.push_back(remain);
//         }
//         reverse(s1.begin(), s1.end());
//         std::cout << s1 << std::endl;
        
//     }
// }

// int main()
// {
//     int M,N;
//     while(std::cin >>M >> N){
//         Transfer(M,N);
//     }
//     return 0;
// }


//十六进制用数字表示

// #include <iostream>

// char character[] = "0123456789abcdef";


// void Transfer(int M, int N){
//     if(M == 0){
//         return;
//     }

//     Transfer(M/N, N);
//     std::cout << character[M % N] << std::endl;
// }


// int main()
// {
//     int M,N = 0;
//     while(std::cin >> M >> N){
//         Transfer(M,N);
//         std::cout << std::endl;
//     }
//     return 0;
// }



//  以上均失败


#include <iostream>
#include <string>
#include <algorithm>s


int main()
{
    std::string table("0123456789ABCDEF");
    int M,N;
    bool flag = false;
    std::string s;
    while(std::cin >> M >> N){
        if(M < 0){
            M = 0 - M;
            flag = true;
        }

        while(M != 0){
            s += table[M % N];
            M /= N;
        }

        if(flag)
            s += '-';

        reverse(s.begin(),s.end());
        std::cout << s << std::endl;
    }

}
