/*
ƴ�����Եڶ��⣬�԰���
��һ�����ӵ����ʶȺ����ʶ�ÿ����ٵ��ٶ�
ÿ������������ʶȲ�����0�Ͳ��ܳ�
�ɳԵİ�������mʱ������������а��ӵ�״̬
�ⷨ��ֱ��ģ�������԰��ӵĹ���
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
