// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

// 说明:

// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sum=m+n;
        int pos=0;//指向nums2准备存入的nums1的元素下标
        
        if(n<1) ;//若nums2没有元素则不用整合
        else 
        {
            for(int i=0;i<sum&&n;i++)
            {
                if(nums2[pos]<=nums1[i] || i>=m)
                {
                    for(int k=nums1.size() - 1;k>i;k--)//将元素后移一位
                    {
                        nums1[k]=nums1[k-1];
                    }
                    nums1[i]=nums2[pos];//插入元素
                    pos++;
                    n--;
                    m++;
                }
            }
        }
    }
};