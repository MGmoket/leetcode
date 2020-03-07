/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

#include <string>
#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p438 {

}

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int slen = s.size();
		if (!slen)
			return ans;
		int plen = p.size();
		if (!plen || plen > slen)
			return ans;
		//��¼ÿ����ĸ���ֶ��ٴ�
		int a[26] = { 0 };
		//�����ж�������ĸΪ0(û��),��������ж�ƥ��
		int nz = 26;
		for (int i = 0; i < plen; i++) {
			if (a[p[i] - 'a'] == 0)
				nz--;
			a[p[i] - 'a']++;
		}
		for (int i = 0; i < slen; i++) {
			//�������plen����ĸ,ÿ��Ҫ����ǰ��һ����ĸȥ��(Ҳ�����ڱ��мӻ���)
			if (i >= plen) {
				//ȥ����ǰ�����ĸ
				//�ж�һ�µ�ǰ����,����Ѿ���0��Ҫ�ǵ���Ϊ0��-1
				if (a[s[i - plen] - 'a'] == 0)
					nz--;
				a[s[i - plen] - 'a']++;
				//����ӻ���֮����0,��ô��Ϊ0��Ҫ+1
				if (a[s[i - plen] - 'a'] == 0)
					nz++;
			}
			//�ѵ�ǰ��ĸ��¼����(���ӱ�����ɾȥһ��)
			//�����¼֮ǰ��0,��ô��¼����Ϊ0��Ҫ-1
			if (a[s[i] - 'a'] == 0)
				nz--;
			a[s[i] - 'a']--;
			//�����¼֮����0.��ô��Ϊ0��Ҫ+1
			if (a[s[i] - 'a'] == 0)
				nz++;
			//���26����ĸ����0��,��ôƥ��ɹ�
			if (i >= plen - 1 && nz == 26)
				ans.push_back(i - (plen - 1));//��¼������ʼλ������
		}
		return ans;
	}
};

int test_p438_findAnagrams() {
	using namespace p438;
	
	string s, p;

	s = "cbaebabacd";
	p = "abc";
	vector<int> res;

	res = Solution().findAnagrams(s, p);
	println(res.begin(), res.end());


	return 0;
}
