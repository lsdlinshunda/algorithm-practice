/*
ˮ������
����һ��vector��Ϊ���ߵĸ߶����룬ѡ����������ʹ�����Ǻ�X��һ�𹹳ɵ������ܹ�ʢ����ˮ��

�������������������Ϊi,j����ô��

a.��j���Ҷ�û��һ���߻������

b.��i�����Ҳ�����б����ߵ���

c.���Դ���ͷ���м俿£��ͬʱ���º�ѡֵ������£�����ʱ�����ȴ�x��y�н�С�ı߿�ʼ������

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