/*
小红书第三题，给一批优惠券的数量和金额及购物车的金额，求最少需要支付的金额
直接暴力解法只过了30%
2017.9.29
*/

#include <iostream>

using namespace std;

int min(int a, int b) {
	return (a<b) ? a : b;
}

int caculate(int *value, int* number, int p, int index, int total) {
	if (number[index] == 0) return p;
	if (p == 0) return 0;
	if (index >= total) return p;
	int minResult = p;
	int tmp, subResult;
	int i = min(p / value[index], number[index]);
	for (; i >= 0; i--) {
		tmp = p - i*value[index];
		if (index<total - 1) {
			subResult = caculate(value, number, tmp, index + 1 ,total);
		}
		else {
			subResult = tmp;
		}

		if (subResult < minResult)  minResult = subResult;
		if (minResult == 0) break;
	}

	return minResult;
}

int main() {
	int n, p;
	cin >> n >> p;
	int *value = new int[n];
	int *number = new int[n];

	for (int i = 0; i<n; ++i) {
		cin >> value[i] >> number[i];
		if (p % value[i] == 0 && p / value[i] <= number[i]) return 0;
		number[i] = min(p / value[i], number[i]);
	}

	int result = caculate(value, number, p, 0, n);

	cout << result;

	delete[] value;
	delete[] number;

	return 0;
}