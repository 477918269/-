//两数之和 II - 输入有序数组
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> v;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				v.push_back(i + 1);
				v.push_back(j + 1);
				return v;

			}

		}

	}
	return v;
}



int main()
{
	vector<int> vv;
	vv.push_back(5);
	vv.push_back(25);
	vv.push_back(75);
	int i = 100;

	twoSum(vv, 100);
	system("pause");
}
//双指针
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> v;
		int begin = 0;
		int end = numbers.size() - 1;
		while (end > begin)
		{
			if (numbers[end] + numbers[begin] < target)
			{
				begin++;
			}

			if (numbers[begin] + numbers[end] > target)
			{
				end--;
			}

			if (numbers[begin] + numbers[end] == target)
				break;
		}
		v.push_back(begin + 1);
		v.push_back(end + 1);
		return v;
	}
};
//求众数
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

class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		int mid = nums.size() / 2;
		sort(nums.begin(), nums.end());

		return nums[mid];
	}
};
//买股票的最佳时间2
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (!prices.empty() == 0)
			return 0;
		int money = 0;
		for (int i = 0; i < prices.size() - 1; i++)
		{
			if (prices[i + 1] > prices[i])
				money += prices[i + 1] - prices[i];
		}
		return money;
	}
};