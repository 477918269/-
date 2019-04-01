//爬楼梯（动态规划）
class Solution {
public:
	int climbStairs(int n)
	{
		int* a = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			if (i < 3)
				a[i] = i;
			else
				a[i] = a[i - 1] + a[i - 2];
		}
		return a[n];
	}
};
//非递归
class Solution {
public:
	int climbStairs(int n)
	{
		if (n <= 1)
			return 1;
		if (n == 2)
			return 2;
		else
		{
			int res = 0;
			int i = 1;
			int j = 2;
			int key = 3;
			while (key <= n)
			{
				res = i + j;
				i = j;
				j = res;
				key++;
			}
			return res;
		}
	}
};
//杨辉三角
class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (int i = 0; i < numRows; i++)
		{
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};
//杨辉三角 II（动态规划）

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 0);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; ++i) {
			for (int j = i; j >= 1; --j) {
				res[j] += res[j - 1];
			}
		}
		return res;
	}

};
//买卖股票的最佳时间
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (!prices.empty() == 0)
			return 0;
		int count = 0;
		int i = 0;
		int m = prices.size();
		while (i < m - 1)
		{
			if (prices[i + 1] - prices[i] < 0)
				i++;
			else
			{
				if (count < prices[i + 1] - prices[i])
					count = prices[i + 1] - prices[i];
				else
			}
		}
	}
};
//只出现一次的数字 （排序+遍历）
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		if (nums.size() == 1)
			return nums[0];
		sort(nums.begin(), nums.end());
		int i;
		for (i = 0; i < nums.size() - 2; i += 2)
		{
			if (nums[i] != nums[i + 1])
				break;
		}
		return nums[i];
	}
};
//异或
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int len = nums.size();
		int result = 0;
		for (int i = 0; i < len; i++)
		{
			result ^= nums[i];
		}
		return result;
	}
};
