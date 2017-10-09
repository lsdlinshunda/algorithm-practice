/*
2017.10.9
�ε����߱��Ե�һ��

[�����|20��] ����ַ�����
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 65536K���������� 131072K
��Ŀ����
����һ���ǿ��ַ���, �������·�ʽ����, ʹ�ñ���󳤶���С, ���ر����ĳ���:
�������Ϊ: k[encoding_string], ��ʾ�ظ�k��encoding_strng,
����'abcdefabcdefabc'�ɱ�ʾΪ'2[abcdef]abc', ����'aaa'���ܱ����'aaa',
��Ϊlen('3[a]')>len('aaa').
����:
1. kΪ������, []�ڵ�encoding_string���ú��пո񲻵�Ϊ��;
2. []�ڵ�encoding_string �������Ϊ��������ַ���, ����'abcdabcdeabcdabcde' ���Ա���Ϊ '2[abcdabcde]'(����󳤶ȴ�18���ٵ�12), []�ڵ�'abcdabcde'�ֿ��Ա���Ϊ '2[abcd]e', ���ձ���Ϊ '2[2[abcd]e]', ����󳤶�Ϊ11, Ӧ����11; �������·��Ҳ����: 'abcdabcdeabcdabcde' -> '2[abcd]e2[abcd]e' -> '2[2[abcd]e]';
2. �����ַ���ΪȫСдӢ����ĸ, ����<=160;
3. �������󳤶�û�и�С, ����ԭ���ַ���;
��������:
һ������, ��ʾ�����ַ���
�������:
���һ���ַ�����ʾ����󳤶�
ʾ��1
����

aaa
���

3
˵��

aaa������3
ʾ��2
����

aaaaa
���

4
˵��

5[a]������4
ʾ��3
����

aabcaabcd
���

8
˵��

2[aabc]d������8

��ö�ٷ���ʵ���˵�����룻60%ͨ����
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.size();
	int  min = len;
	for (int i = 1; i <= len / 2; ++i) {
		for (int j = 0; j < len - 2 * i + 1; ++j) {
			int index = j;
			int count = 1;
			while (index < len - 2 * i + 1 && str.substr(index, i) == str.substr(index + i, i)) {
				++count;
				index += i;
			}
			if ((len - (count - 1)*i + 3) < min)
				min = len - (count - 1)*i + 3;
		}
	}
	cout << min << endl;

	return 0;
}
