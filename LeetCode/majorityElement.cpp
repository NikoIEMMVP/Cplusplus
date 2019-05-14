// 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在众数。

class Solution {
public:
//排序，因为众数出现的次数大于一半，排序之后中位数就是众数

//       static bool compare(const int& a, const int& b){
//         return a < b;
//     }
    
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end(),compare);
//         return nums[nums.size() / 2];
//     }

//从第一个计数开始，遇到相同的+1，不同的-1，count 等于 0 时换下一个数
//因为众数个数大于一半，当count等于0的时候，循环过的和没循环过的数的个数都是偶数，两侧众数出现的次数依旧是大于一半，所以数组指针直接指向下一个数就可以
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(cur == nums[i]){
                ++count;
            }
            else{
                --count;
                if(count == 0){
                    cur = nums[i + 1];
                }
            }
        }
        
        return cur;
    }
};
