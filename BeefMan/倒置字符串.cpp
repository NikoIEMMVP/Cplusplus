//将一句话中的单词进行倒置，标点不倒置
//例：i like BeiJing.  -->    BeiJing. like  i

#include <iostream>
#include <algorithm>



int main()
{
    std::string s;
    while(getline(std::cin, s)){
        reverse(s.begin(), s.end());
        auto start = s.begin();
        while(start != s.end()){
            auto end = start;
            while(end != s.end() && *end != ' ')
                end++;
            reverse(start,end);
            if(end != s.end())
                start = end + 1;
            else
                start = end;
        }
        
        std::cout << s << std::endl;
    }
    return 0;
}