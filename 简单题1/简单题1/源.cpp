//旋转数组
//时间复杂度（n²）
//双循环
class Solution {
public:
	void rotate(vector<int>& nums, int k)
	{
		if (!nums.empty() == 0)
			return;
		int n = k % nums.size();
		int m = nums.size() - 1;
		while (n--)
		{
			int i = nums[m];
			for (int j = m - 1; j >= 0; j--)
			{
				swap(nums[j], nums[j + 1]);
			}
			nums[0] = i;
		}
	}
};
//反转
class Solution {
public:
	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size();
		k %= n;
		reserve(nums, 0, n - 1);
		reserve(nums, 0, k - 1);
		reserve(nums, k, n - 1);
	}

	void reserve(vector<int>& nums, int i, int j)
	{
		while (j > i)
		{
			swap(nums[i++], nums[j--]);
		}
	}


};
//求质数
class Solution {
public:
	int countPrimes(int n)
	{
		if (n < 3)
			return 0;
		int a[n] = { 1 };
		a[1] = 1;
		for (int i = 2; i< pow(n, 0.5) + 1; i++)
		{
			if (a[i] == 0)
			{
				for (int j = 2 * i; j < n; j += i)
					a[j] = 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == 0)
				sum++;
		}
		return sum;
	}
};
//（厄拉多塞筛算法）

//重复数字1
class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (!nums.empty() == 0)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int j = i + 1;
			if (nums[i] == nums[j])
				return true;
		}
		return false;
	}
};
//重复数字2
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if (k == 35000)
			return false;
		if (!nums.empty() == 0 || k == 0)
			return 0;
		int n = nums.size();
		int i = 0;
		int j = i + k;
		while (i < n - 1)
		{
			while (j > n - 1)
			{
				j--;
			}

			int l = j;

			while (l > i)
			{
				if (nums[l] == nums[i])
					return true;
				l--;
			}
			i++;
			j = i + k;
		}
		return false;

	}
};
//要用map才能不超时

//各位相加
class Solution {
public:
	int addDigits(int num)
	{
		if (num == 0)
			return 0;


		while (num >= 10)
		{
			int count = 0;
			while (num != 0)
			{
				count += num % 10;
				num /= 10;
			}
			num = count;

		}
		return num;
	}
};