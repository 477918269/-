//最后一个单词长度
class Solution {
public:
	int lengthOfLastWord(string s)
	{
		if (s == "")
			return 0;
		int i = s.size() - 1;

		while (s[i] == ' ' && i >= 0)
		{
			i--;
		}

		int j = i;
		while (s[j] != ' ' && j >= 0)
		{
			j--;
		}
		return i - j;
	}
};
//最大子序列（动态规划）
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums[0];
		int sum = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			if (n > 0)
				n += nums[i];
			else
				n = nums[i];
			if (sum < n)
				sum = n;


		}
		return sum;
	}
};
//O（n²）
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		if (nums.size() == 1)
			return nums[0];
		int count = -100;
		int i;
		int j;
		int m = nums.size();
		for (i = 0; i < m; i++)
		{
			int count1 = nums[i];
			for (j = i + 1; j < m; j++)
			{
				count1 = count1 + nums[j];
				if (count < count1)
					count = count1;
			}
			if (count < nums[i])
				count = nums[i];
		}
		return count;

	}
};
//搜索插入位置
class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int i = 0;
		int m = nums.size();
		for (i = 0; i < m; i++)
		{
			if (nums[i] >= target)
				return i;
		}

		return i;
	}
};