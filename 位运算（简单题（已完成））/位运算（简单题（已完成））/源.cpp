//字母大小写全排列
//递归算法
//回溯算法（未解决）
class Solution {
public:
	vector<string> v;

	void fun(string s, int i)
	{
		if (s.size() == i)
		{
			v.push_back(s);
			return;
		}
		fun(s, i + 1);

		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 'a' + 'A';
			fun(s, i + 1);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 'A' + 'a';
			fun(s, i + 1);
		}

	}

	vector<string> letterCasePermutation(string S)
	{
		fun(S, 0);
		return v;

	}
};
//数字转换十六进制
//用0xf比最后四位
class Solution {
public:
	string toHex(int num)
	{
		if (num == 0) return "0";
		string hex = "0123456789abcdef", ans = "";
		while (num && ans.size() < 8){
			ans = hex[num & 0xf] + ans;//0xf表示看二进制的最后四位，这四位都为1.如果是负数呢？？？？
			num >>= 4;
		}
		return ans;
	}

};
//

//交替位二进制数
//-1异或
class Solution {
public:
	bool hasAlternatingBits(int n)
	{
		long long temp = n ^ (n >> 1);
		return (temp & (temp + 1)) == 0;

	}
};
//二进制表示中质数个计算置位
class Solution {
public:


	int countPrimeSetBits(int L, int R)
	{
		int num = 0;
		int z[33];
		memset(z, 0, 33);
		z[0] = 0;
		z[1] = 0;
		z[2] = 1;

		for (int i = 3; i < 33; i++)
		{
			int j = 2;
			for (; j < i; j++)
			{
				if (i % j == 0)
					break;

			}
			if (j == i)
				z[i] = 1;
		}

		for (int i = L; i <= R; i++)
		{
			int k = i;
			int count = 0;
			while (k)
			{
				count++;
				k = (k & (k - 1));

			}
			if (z[count] == 1)
				num++;
		}
		return num;
	}
};
//补数
class Solution {
public:
	int findComplement(int num)
	{
		int tmp = num;
		int n = 0;
		while (tmp)//tmp动几次,c就有几个1
		{
			tmp >>= 1;
			n = (n << 1) + 1;
		}
		return num ^ n;
	}
};
//汉明距离
class Solution {
public:
	int hammingDistance(int x, int y)
	{
		int n = x ^ y;
		int count = 0;
		while (n)
		{
			count++;
			n &= (n - 1);//消掉二进制n的最后一个1
		}
		return count;

	}
};
