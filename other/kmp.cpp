/*
KMPËã·¨Æ¥Åä×Ö·û´®
²Î¿¼£ºhttp://blog.csdn.net/power721/article/details/6132380
2017.10.7
*/

#include<iostream>
#include<string>

using namespace std;

int kmp(const string source, const string pattern) {
	int patternLen = pattern.size();
	int sourceLen = source.size();
	if (sourceLen == 0 || patternLen == 0) return -1;
	int *coverLen = new int[patternLen];
	coverLen[0] = -1;

	int index;
	for (int i = 1; i < patternLen; ++i) {
		index = coverLen[i - 1];
		while (index >= 0 && pattern[i] != pattern[index + 1]) {
			index = coverLen[index];
		}
		
		if (pattern[i] == pattern[index + 1]) {
			coverLen[i] = index + 1;
		} else {
			coverLen[i] = -1;
		}
	}

	int target_index = 0, pattern_index = 0;

	while (target_index < sourceLen && pattern_index < patternLen) {
		if (source[target_index] == pattern[pattern_index]) {
			++target_index;
			++pattern_index;
		}
		else if (pattern_index == 0) {
			++target_index;
		}
		else {
			pattern_index = coverLen[pattern_index - 1] + 1;
		}

		if (pattern_index == patternLen) {
			return target_index - patternLen;
		}
	}

	return -1;
}

int main() {
	string source = "annbcdanacadsannannabnna";
	string pattern = "sannanna";
	cout << kmp(source, pattern) << endl;
	cin.get();
	return 0;
}
