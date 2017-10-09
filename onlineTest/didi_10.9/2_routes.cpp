/*
2017.10.9
滴滴在线笔试第二题

[编程题|20分] CIDR去重
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 65536K，其他语言 131072K
题目描述
无类别域间路由（CIDR）是一个用于对IPV4地址进行分类表述的方法。CIDR 路由描述的IP地址组的子网mask长度是可变长度, 例如10.0.0.0/22 表示前22位和10.0.0.0相同的网络地址都被覆盖, 22包含了10.0这前两个字段(0-7位,8-15位)和第三个字段的前6位(16-21,即0b000000**), 涵盖了 10.0.0.*, 10.0.1.*, 10.0.2.*, 10.0.3.* 四组ip地址. 在此前提下请实现IP网络中的一个常用的去重操作: 给定一系列 CIDR 路由地址, 其中没有完全等价的路由, 去掉被重复表示的 CIDR 路由, 即去掉已经被其他CIDR路由表示覆盖的路由地址. 例如 10.0.1.1/32 已经被 10.0.0.0/22覆盖了, 如果路由列表中已经有了后者, 就可以去掉前者.
输入描述:
k+1行, k表示输入的CIDR路由个数
第1行:表示路由个数k
第2~k+1行: 表示一个CIDR路由, 形如 x.x.x.x/x
输出描述:
n+1行, n表示去重后剩下的CIDR路由个数
第1行:n
第2~n+1行: 表示一个去重后的CIDR路由, 输出按照输入顺序
示例1
输入

13
192.168.0.0/16
172.24.96.17/32
172.50.137.225/32
202.139.219.192/32
172.24.68.0/24
192.183.125.71/32
201.45.111.138/32
192.168.59.211/32
192.168.26.13/32
172.24.0.0/17
172.24.5.1/32
172.24.68.37/32
172.24.168.32/32
输出

7
192.168.0.0/16
172.50.137.225/32
202.139.219.192/32
192.183.125.71/32
201.45.111.138/32
172.24.0.0/17
172.24.168.32/32

将每个CIDR路由转成二进制提取出网段，利用hash表判断是否已有更大的网段覆盖当前网段；AC
*/

#include<iostream> 
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//整数转成二进制字符串
string o2b(int a) {
	string str = "";
	while (a > 0) {
		str = to_string(a & 1) + str;
		a = a >> 1;
	}
	str = string(8 - str.size(), '0') + str;
	return str;
}

//地址转成二进制
string adressToBin(string a) {
	string result = "";

	int tmp = 0;
	int index = 0; 
	while (index < a.size()) {
		if (a[index] != '.' && a[index] != '/') {
			tmp = tmp * 10 + (a[index] - '0');
		} else {
			result += o2b(tmp);
			tmp = 0;
		}
		++index;
	}
	return result.substr(0, tmp);
}

int main() {
	int k;
	string input, bInput;
	vector<string> routes;
	vector<string> bRoutes;
	vector<bool> outFlag;
	unordered_map<string, int> hash;
	
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> input;
		bInput = adressToBin(input);
		routes.push_back(input);
		bRoutes.push_back(bInput);
		hash[bInput] = 1;
	}

	bool flag;
	string tmp;
	int count = 0;
	for (int i = 0; i < k; ++i) {
		flag = true;
		tmp = "";
		bInput = bRoutes[i];
		for (int j = 0; j < bInput.size() - 1; ++j) {
			tmp += bInput[j];
			if (hash.find(tmp) != hash.end()) {
				flag = false;
				break;
			}
		}
		count += flag ? 1 : 0;
		outFlag.push_back(flag);
	}

	cout << count << endl;
	for (int i = 0; i < k; ++i) {
		if (outFlag[i]) {
			cout << routes[i] << endl;
		}
	}

	return 0;
}
