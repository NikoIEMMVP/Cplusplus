// NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
// 现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。

// 输入描述:
// 输入有多组数据，每组数据有两行。

// 第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。

// 第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。


// 输出描述:
// 如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
// 示例1
// 输入
// Joe,Kewell,Leon
// Joe
// "Letendre, Bruce",Joe,"Quan, William"
// William
// 输出
// Ignore
// Important!

// write your code here cpp#include <iostream>
#include <iostream>
#include <string>


int main()
{
    std::string name_list,name;
    while(getline(std::cin, name_list)){
        getline(std::cin,name);
        std::string str;
        
        bool is = false;
        
        for(int i = 0; i < name_list.size(); i++){
            //std::string str;
            if(name_list[i] == '"'){
                str.clear();
                i++;
                while(i < name_list.size() && name_list[i] != '"'){
                    str += name_list[i];
                    i++;
                }
                
                if(str == name){
                    is = true;
                    break;
                }
            }else if(name_list[i] != ','){
                str.clear();
                while(i < name_list.size() && name_list[i] != ','){
                    
                    str += name_list[i];
                    i++;
                }
                
                if(str == name){
                    is = true;
                    break;
                }
            }
        }
        
        if(is){
            std::cout << "Ignore" << std::endl;
        }else{
            std::cout << "Important!" << std::endl;
        }
    }
    return 0;
}