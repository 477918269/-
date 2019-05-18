//反转字符串中的元音字母
class Solution {
public:
	bool find(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
	string reverseVowels(string s)
	{

		int i = 0;
		int j = s.size() - 1;
		while (i < j)
		{
			while (!find(s[i]) && i < j)
				i++;
			while (!find(s[j]) && i < j)
				j--;
			swap(s[i++], s[j--]);
		}
		return s;


	}
};
//区域和检索 - 数组不可变
class NumArray {
	vector<int> v;//记忆方式和算法
public:
	NumArray(vector<int>& nums) {
		int sum = 0;
		v.push_back(sum);
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			v.push_back(sum);
		}
	}

	int sumRange(int i, int j)
	{
		return v[j + 1] - v[i];
	}
};
//4的幂
class Solution {
public:

	bool isPowerOfFour(int num) {
		long long i = 1;
		while (i < INT_MAX && i <= num) {
			if (i == num) return true;
			else i <<= 2;
		}
		return false;
	}
};