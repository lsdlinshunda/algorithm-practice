/*
拼多多笔试第二题，吃包子
给一批包子的新鲜度和新鲜度每天减少的速度
每天吃两个，新鲜度不大于0就不能吃
可吃的包子少于m时结束，输出所有包子的状态
解法是直接模拟整个吃包子的过程
2017.9.28
*/

#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int *delicious = new int[n];
	int *speed = new int[n];
	int *status = new int[n];
	int rest = 0;
	for (int i = 0; i<n; ++i) {
		cin >> delicious[i];
		cin >> speed[i];
		if (delicious[i]>0) {
			status[i] = delicious[i];
			++rest;
		}
		else status[i] = 0;
	}

	int max;
	int maxIndex = -1;
	while (rest >= m) {
		for (int i = 0; i<2; ++i) {
			max = 0;
			maxIndex = -1;
			for (int j = 0; j<n; ++j) {
				if (status[i] <= 0) continue;
				if (delicious[j] > max || (delicious[j] == max && speed[j] > speed[maxIndex])) {
					max = delicious[j];
					maxIndex = j;
				}
			}
			if (maxIndex != -1) {
				status[maxIndex] = -1;
			}
		}

		rest = 0;
		for (int i = 0; i<n; ++i) {
			if (status[i] > 0) {
				delicious[i] -= speed[i];
				status[i] = (delicious[i] > 0) ? delicious[i] : 0;
				if (status[i]>0) ++rest;
			}
		}
	}

	for (int i = 0; i<n; ++i)
		cout << status[i] << endl;

	delete[] delicious;
	delete[] speed;
	delete[] status;

	return 0;
}
