//4���ݴη�
//����
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
//λ����
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
//������֮��
//����ࣨ^���ӣ���(&)��λ��
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