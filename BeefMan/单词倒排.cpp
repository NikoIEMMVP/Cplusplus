// 对字符串中的所有单词进行倒排。

// 说明：

// 1、每个单词是以26个大写或小写英文字母构成；

// 2、非构成单词的字符均视为单词间隔符；

// 3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

// 4、每个单词最长20个字母；


// 输入描述:
// 输入一行以空格来分隔的句子



// 输出描述:
// 输出句子的逆序

// 示例1
// 输入
// I am a student
// 输出
// student a am I

#include<iostream>
#include<vector>
#include<string>


int main()
{
    std::string input;
    while(getline(std::cin,input))
    {
        std::vector<std::string> v;
        v.clear();
        std::string temp="";
        for(size_t i = 0; i < input.size();++i)
        {
            if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
                temp += input[i];
            else
            {
                if(temp.size() > 0)
                {
                    v.push_back(temp);
                    temp="";
    }
   }
  }
        if(!temp.empty())
            v.push_back(temp);
        for(size_t i = v.size() - 1; i > 0; --i)
            std::cout << v[i]<<' ';
        std::cout << v[0] ;
 }
    return 0;
}