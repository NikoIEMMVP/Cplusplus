// 给定一个整数数组，判断是否存在重复元素。

// 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。


//排序，相邻如果相同就有重复元素
#include<algorithm>

class Solution {
public:
    static bool compare(const int& a, const int& b){
        return a < b;
    }
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2){
            return false;
        }
        
        sort(nums.begin(),nums.end(),compare);
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        
        return false;
    }
};