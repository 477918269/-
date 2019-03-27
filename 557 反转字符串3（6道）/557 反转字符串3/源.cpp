//反转字符串
class Solution {
public:
	string reverseWords(string s)
	{
		int i = 0, j = 0;
		int m = s.size();
		for (j; j < m; j++)
		{
			if (s[j] == ' ')
			{
				int end = j - 1;
				int begin = i;
				while (end >= begin)
				{
					swap(s[begin], s[end]);
					begin++;
					end--;
				}
				i = j + 1;
				j = i;
			}
		}
		j = j - 1;
		while (j >= i)
		{
			swap(s[j], s[i]);
			j--;
			i++;

		}
		return s;
	}
};

//strstr最优解
class Solution {
public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty())
			return 0;
		if (needle.size() > haystack.size())
			return -1;
		int i = 0;
		int j = 0;
		for (i = 0; i < haystack.size(); ++i)
		{
			if (j == needle.size())
				return i - needle.size();
			if (haystack[i] == needle[j])
				j++;
			else
			{
				i -= j;
				j = 0;
			}

		}
		if (j == needle.size())
			return i - needle.size();
		return -1;
	}
};
//移除元素
class Solution {
public:
	int removeElement(vector<int>& nums, int val)
	{
		int i = 0;
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[j] != val)
			{
				j++;
			}
			else if (nums[j] == val && nums[i] != val)
			{
				swap(nums[i], nums[j]);
				j++;
			}
		}
		return j;
	}
};
//删除排序数组重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int i = 0;
		for (int j = 1; j < nums.size(); ++j)
		{
			if (nums[i] != nums[j])
			{
				++i;
				nums[i] = nums[j];

			}
		}

		return i + 1;

	}
};
//最长特殊子序
class Solution {
public:
	int findLUSlength(string a, string b)
	{
		if (a == b)
			return -1;
		int i = a.size();
		int j = b.size();
		if (i >= j)
			return i;
		else return j;
	}
};
//转换成小写字母
class Solution {
public:
	string toLowerCase(string str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;

		}
		return str;
	}
};