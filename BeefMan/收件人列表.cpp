// NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人
// ，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
// 现在给你一组收件人姓名，请你帮他生成相应的收件人列表。

// 输入描述:
// 输入包含多组数据。

// 每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。

// 紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。


// 输出描述:
// 对应每一组输入，输出一行收件人列表。
// 示例1
// 输入
// 3
// Joe
// Quan, William
// Letendre,Bruce
// 2
// Leon
// Kewell
// 输出
// Joe, "Quan, William", "Letendre,Bruce"
// Leon, Kewell

// write your code here cpp// write your code here cpp

#include <iostream>
#include <string>

int main()
{
    int n;
    while(std::cin >> n){
        // 换行符会存在输入缓冲区中，先要将换行符取出(enter)
        std::cin.get();
        std::string name;
        for(int i = 0; i < n; i++){
            getline(std::cin , name);
            if(i != n - 1){
                if(name.find(',') != std::string::npos || name.find(' ') != std::string::npos){
                    std::cout << '"' << name << '"' << ',' << ' ';
                }else{
                    std::cout << name << ',' << ' ';
                }
            }else{
                if(name.find(',') != std::string::npos || name.find(' ') != std::string::npos){
                    std::cout << '"' << name << '"' << std::endl;
                }else{
                    std::cout << name << std::endl;
                }
            }
        }
    }
    return 0;
}