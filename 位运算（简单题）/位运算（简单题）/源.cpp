//缺失数字O（2n）复杂算法
class Solution {
public:
	int missingNumber(vector<int>& nums)
	{
		if (!nums.empty() == 0)
			return 0;

		sort(nums.begin(), nums.end());
		if (nums.size() == 1 && nums[0] == 1)
			return 0;
		int i = 0;
		for (; i < nums.size() - 1; i++)
		{
			if (nums[i] != i)
				return i;
			if (nums[i] + 1 != nums[i + 1])
				return nums[i] + 1;
		}
		if (i + 1 == nums.size())
			return nums[i] + 1;
		return 1;
	}
};
//O（n）计算总数，然后减去下标
class Solution {
public:
	int missingNumber(vector<int>& nums)
	{
		int n = 0;
		int count = 0;
		int i;
		for (i = 0; i < nums.size(); i++)
		{
			n += i;
			count += nums[i];
		}
		return n + i - count;
	}
};
//有效的字母异位词
//计数排序原理
class Solution {
public:
	bool isAnagram(string s, string t)
	{
		int i;
		int x[26] = { 0 };
		int y[26] = { 0 };
		for (i = 0; i < s.size(); i++)
			x[s[i] - 'a']++;
		for (i = 0; i < t.size(); i++)
			y[t[i] - 'a']++;
		for (i = 0; i < 26; i++)
		if (x[i] != y[i])
			return false;
		return true;

	}
};
//丑数
//辗转相除
class Solution {
public:
	bool isUgly(int num)
	{
		if (num <= 0)
			return false;
		while (num > 1)
		{
			if (num % 2 == 0)
				num /= 2;
			else if (num % 3 == 0)
				num /= 3;
			else if (num % 5 == 0)
				num /= 5;
			else
				return false;
		}
		if (num == 1)
			return true;
		else
			return false;


	}
};
//求众数
//求摩尔票数/动态规划
class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		int a = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == a)
				count++;
			else
			{
				count--;
				if (count == 0)
					a = nums[i + 1];
			}

		}
		return a;
	}
};
//排序，取中位数
class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};
//2的幂次方
class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		return (n > 0) && ((n & -n) == n);
	}
};
//位1的个数
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int i = 0;
		int count = 0;
		while (n > 0)
		{
			n &= (n - 1);
			count++;
		}
		return count;
	}
};
//颠倒二进制位
class Solution {
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t count = 0;
		for (int i = 0; i < 32; i++)
		{
			count += ((n >> i) & 1) << (31 - i);
		}
		return count;
	}
};
//找不同
//计数排序
//只开一个空间
class Solution {
public:
	char findTheDifference(string s, string t)
	{
		int i;
		int a[26] = { 0 };
		for (i = 0; i < s.size(); i++)
		{
			a[s[i] - 'a']++;
			a[t[i] - 'a']--;
		}
		a[t[i] - 'a']--;
		for (i = 0; i < 26; i++)
		{
			if (a[i] == -1)
				return i + 'a';
		}
		return 0;

	}
};
//开两个空间
class Solution {
public:
	char findTheDifference(string s, string t)
	{
		int i;
		int a[26] = { 0 };
		int b[26] = { 0 };
		for (i = 0; i < s.size(); i++)
			a[s[i] - 'a']++;
		for (i = 0; i < t.size(); i++)
			b[t[i] - 'a']++;
		for (i = 0; i <26; i++)
		{
			if (a[i] != b[i])
				return i + 'a';
		}
		return 0;

	}
};
