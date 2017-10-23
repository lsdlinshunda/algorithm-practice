/*
213. House Robber 2(蜻蜓在线笔试最后一题)
https://leetcode.com/problems/house-robber-ii/description/
2017.10.23
*/

class Solution {
public:
    int max(int a, int b) {
        return (a>b)?a:b;
    }
    
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;    
        if (len == 1) return nums[0];
        int a=0,b=0;
        for (int i=0;i<len-1;++i) {
            if (i % 2 == 0) {
                a = max(a+nums[i], b);
            } else {
                b = max(b+nums[i], a);
            }
        }
        int result1 = max(a,b);
        
        a = 0; b = 0;
        for (int i=1;i<len;++i) {
            if (i % 2 == 0){
                a = max(a + nums[i], b);
            } else {
                b = max(b + nums[i], a);
            }
        }
        return max(result1,max(a,b));
    }
};