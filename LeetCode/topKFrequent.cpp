// 给一非空的单词列表，返回前 k 个出现次数最多的单词。

// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

// 示例 1：

// 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出: ["i", "love"]
// 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//     注意，按字母顺序 "i" 在 "love" 之前。

// 示例 2：

// 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// 输出: ["the", "is", "sunny", "day"]
// 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//     出现次数依次为 4, 3, 2 和 1 次。
 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> count;
        //将字符串按照字母的顺序排序，并统计出字符串出现的次数
        for(const auto& e : words){
            count[e]++;
        }
        
        //将map翻转，将出现次数设为key，字符串设为value
        //因为出现次数可能会相同，所以选择用multimao
        //默认是从小打大排序，而我们需要的是从大到小
        multimap<int,string,greater<int>> sortMap;
        for(const auto& e : count){
            sortMap.insert(make_pair(e.second, e.first));
        }
        
        //遍历，取出前k个出现次数最多的字符串
        vector<string> v;
        auto mit = sortMap.begin();
        while(mit != sortMap.end() && k--){
            v.push_back(mit->second);
            ++mit;
        }
        
        return v;
    }
};