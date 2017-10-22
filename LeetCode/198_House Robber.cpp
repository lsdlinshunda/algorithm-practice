/*
198. House Robber (蜻蜓在线笔试最后一题)
https://leetcode.com/problems/house-robber/description/
2017.10.22
*/

class Solution {
	public:
		int max(int a, int b) {
			return (a>b)?a:b;
		}
		
		int rob(vector<int>& nums) {
			int a=0,b=0,len=nums.size();
			for (int i=0;i<len;++i) {
				if (i & 1) {
					a = max(a+nums[i], b);
				} else {
					b = max(b+nums[i], a);
				}
			}
			
			return max(a,b);
		}
};