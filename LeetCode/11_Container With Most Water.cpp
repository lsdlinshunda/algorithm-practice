/*
水箱问题
给定一个vector作为纵线的高度输入，选择两条纵线使得他们和X轴一起构成的容器能够盛更多水。

假设最大容器两条纵线为i,j，那么：

a.在j的右端没有一条线会比它高

b.在i的左端也不会有比它高的线

c.所以从两头向中间靠拢，同时更新候选值；在收拢区间的时候优先从x，y中较小的边开始收缩；

2017.10.2
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int result = (height[l] > height[r]) ? height[r] * (r - l) : height[l] * (r - l);
        int tmpIndex, tmpResult;
        while (l < r) {
            if (height[l] < height[r]) {
                tmpIndex = l;
                while (l < r && height[tmpIndex] >= height[l]) ++l;
            } else {
                tmpIndex = r;
                while (l < r && height[tmpIndex] >= height[r]) --r;
            }
            tmpResult = (height[l] > height[r]) ? height[r] * (r - l) : height[l] * (r - l);
            if (tmpResult > result) result = tmpResult;
        }
        
        return result;
    }
};