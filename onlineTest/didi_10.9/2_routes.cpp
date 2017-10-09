/*
2017.10.9
�ε����߱��Եڶ���

[�����|20��] CIDRȥ��
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 65536K���������� 131072K
��Ŀ����
��������·�ɣ�CIDR����һ�����ڶ�IPV4��ַ���з�������ķ�����CIDR ·��������IP��ַ�������mask�����ǿɱ䳤��, ����10.0.0.0/22 ��ʾǰ22λ��10.0.0.0��ͬ�������ַ��������, 22������10.0��ǰ�����ֶ�(0-7λ,8-15λ)�͵������ֶε�ǰ6λ(16-21,��0b000000**), ������ 10.0.0.*, 10.0.1.*, 10.0.2.*, 10.0.3.* ����ip��ַ. �ڴ�ǰ������ʵ��IP�����е�һ�����õ�ȥ�ز���: ����һϵ�� CIDR ·�ɵ�ַ, ����û����ȫ�ȼ۵�·��, ȥ�����ظ���ʾ�� CIDR ·��, ��ȥ���Ѿ�������CIDR·�ɱ�ʾ���ǵ�·�ɵ�ַ. ���� 10.0.1.1/32 �Ѿ��� 10.0.0.0/22������, ���·���б����Ѿ����˺���, �Ϳ���ȥ��ǰ��.
��������:
k+1��, k��ʾ�����CIDR·�ɸ���
��1��:��ʾ·�ɸ���k
��2~k+1��: ��ʾһ��CIDR·��, ���� x.x.x.x/x
�������:
n+1��, n��ʾȥ�غ�ʣ�µ�CIDR·�ɸ���
��1��:n
��2~n+1��: ��ʾһ��ȥ�غ��CIDR·��, �����������˳��
ʾ��1
����

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
���

7
192.168.0.0/16
172.50.137.225/32
202.139.219.192/32
192.183.125.71/32
201.45.111.138/32
172.24.0.0/17
172.24.168.32/32

��ÿ��CIDR·��ת�ɶ�������ȡ�����Σ�����hash���ж��Ƿ����и�������θ��ǵ�ǰ���Σ�AC
*/

#include<iostream> 
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//����ת�ɶ������ַ���
string o2b(int a) {
	string str = "";
	while (a > 0) {
		str = to_string(a & 1) + str;
		a = a >> 1;
	}
	str = string(8 - str.size(), '0') + str;
	return str;
}

//��ַת�ɶ�����
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
