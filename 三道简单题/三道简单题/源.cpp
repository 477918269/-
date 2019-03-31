//x的平方根(笨B解法)
class Solution {
public:
	int mySqrt(int x)
	{
		if (x == 1)
			return 1;
		long long i = 0;
		for (i = 0; i < x / 2; i++)
		{
			long long j = i + 1;
			if (i * i <= x && j * j > x)
				break;
		}
		return i;
	}
};
//666
class Solution {
public:
	int mySqrt(int x)
	{
		if (x == 0)
			return 0;
		if (x == 1)
			return 1;
		int r = x >> 1;
		while (r > x / r)
		{
			r = (r + x / r) >> 1;
		}
		return r;
	}
};
//数组+1
class Solution {
public:

	vector<int> plusOne(vector<int>& digits)
	{
		int j = digits.size() - 1;
		while (digits[j] == 9 && j != 0)
		{
			digits[j] = 0;
			j--;
		}
		if (j == 0 && digits[j] == 9)
		{
			digits[j] = 0;
			digits.insert(digits.begin(), 1);
		}
		else digits[j] += 1;

		return digits;


	}
};
//合并两个有序数组
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int> copy(nums1);
		int i = 0;
		int j = 0;
		int k = 0;
		while (j != m && i != n)
		{
			if (copy[j] <= nums2[i])
			{
				nums1[k++] = copy[j++];
			}
			else
			{
				nums1[k++] = nums2[i++];
			}
		}
		while (j != m)
		{
			nums1[k++] = copy[j++];
		}
		while (i != n)
		{
			nums1[k++] = nums2[i++];
		}
	}
};