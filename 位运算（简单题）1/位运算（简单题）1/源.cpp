//4的幂次方
//除法
class Solution {
public:
	bool isPowerOfFour(int num)
	{
		while (num > 3)
		{
			if (num % 4 == 0)
			{
				num /= 4;
			}
			else
				return false;
		}
		if (num == 1)
			return true;
		return false;
	}
};
//位运算
class Solution {
public:
	bool isPowerOfFour(int num)
	{
		if (num <= 0)
			return false;
		if ((num & (num - 1)) != 0)
			return false;
		if (num == 1)
			return true;

		else
		{
			while (num >= 1)
			{
				num >>= 2;
				if (num == 1)
					return true;
			}
			return false;
		}



	}
};
//两整数之和
//异或相（^）加，与(&)进位。
class Solution {
public:
	int getSum(unsigned int a, unsigned int b)
	{

		int sum, count;

		sum = a ^ b;

		count = (a & b) << 1;

		if (count != 0)
			return getSum(sum, count);
		return sum;
	}
};
//