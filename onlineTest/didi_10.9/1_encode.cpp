/*
2017.10.9
滴滴在线笔试第一题

[编程题|20分] 最短字符编码
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 65536K，其他语言 131072K
题目描述
给定一个非空字符串, 按照如下方式编码, 使得编码后长度最小, 返回编码后的长度:
编码规则为: k[encoding_string], 表示重复k次encoding_strng,
例如'abcdefabcdefabc'可表示为'2[abcdef]abc', 但是'aaa'仅能编码成'aaa',
因为len('3[a]')>len('aaa').
补充:
1. k为正整数, []内的encoding_string不得含有空格不得为空;
2. []内的encoding_string 本身可以为编码过的字符串, 例如'abcdabcdeabcdabcde' 可以编码为 '2[abcdabcde]'(编码后长度从18减少到12), []内的'abcdabcde'又可以编码为 '2[abcd]e', 最终编码为 '2[2[abcd]e]', 编码后长度为11, 应返回11; 这个编码路径也能是: 'abcdabcdeabcdabcde' -> '2[abcd]e2[abcd]e' -> '2[2[abcd]e]';
2. 输入字符串为全小写英文字母, 长度<=160;
3. 如果编码后长度没有更小, 则保留原有字符串;
输入描述:
一行数据, 表示输入字符串
输出描述:
输出一个字符串表示编码后长度
示例1
输入

aaa
输出

3
说明

aaa，长度3
示例2
输入

aaaaa
输出

4
说明

5[a]，长度4
示例3
输入

aabcaabcd
输出

8
说明

2[aabc]d，长度8

用枚举法先实现了单层编码；60%通过率
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
