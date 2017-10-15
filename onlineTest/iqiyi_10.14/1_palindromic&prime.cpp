/*
2017.10.14 爱奇艺在线笔试第一题
回文素数
求一个区间[L,R]中既是回文数又是素数的数的个数
*/

#include <iostream>
#include <string>

using namespace std;

bool checkHuiwen(int x) {
	string num = to_string(x);
	int len = num.size();
	for (int i = 0; i < num.size() / 2; ++i) {
		if (num[i] == num[len - i - 1]) continue;
		else return false;
	}
	return true;
}

bool checkPrime(int x) {
	if (x <= 1) return false;

	for (int i = x / 2; i > 1; i--) {
		if (x % i == 0) return false;
	}

	return true;
}

int main() {
	int l, r;
	cin >> l >> r;
	int count = 0;
	for (int i = l; i <= r; ++i) {
		if (checkHuiwen(i) && checkPrime(i)) ++count;
	}
	
	cout << count << endl;

	return 0;
}
