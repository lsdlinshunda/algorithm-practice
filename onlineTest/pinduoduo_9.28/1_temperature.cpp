/*
拼多多笔试第一题，给一组温度区间，求最大最小的置信温度
置信温度只可能出现在区间的边界，所以遍历所有的边界点计算被几个区间覆盖
2017.9.28
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Temper {
	int low;
	int high;
	Temper(int a, int b) :low(a), high(b) {}
};

bool lcomp(Temper a, Temper b) {
	return a.low < b.low;
}

bool hcomp(Temper a, Temper b) {
	return a.high < b.high;
}
int main() {
	vector<Temper>  temperature;
	vector<int> num;
	int n, k, low, high;
	cin >> n >> k;
	for (int i = 0; i<n; ++i) {
		cin >> low >> high;
		num.push_back(low);
		num.push_back(high);
		temperature.push_back(Temper(low, high));
	}
	sort(num.begin(), num.end());
	int count;
	low = 51;
	high = -51;

	for (int i = 0; i<num.size(); ++i) {
		count = 0;
		for (int j = 0; j<n; ++j) {
			if (num[i] >= temperature[j].low && num[i] <= temperature[j].high)
				++count;
			if (count >= k) {
				if (num[i]<low) low = num[i];
				if (num[i] > high) high = num[i];
				break;
			}
		}
	}

	if (low == 51 || high == -51) cout << "error"<<endl;
	else cout<<low<<" "<<high<<endl;
	
	return 0;
}