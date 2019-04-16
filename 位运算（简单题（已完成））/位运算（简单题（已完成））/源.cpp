//��ĸ��Сдȫ����
//�ݹ��㷨
//�����㷨��δ�����
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
//����ת��ʮ������
//��0xf�������λ
class Solution {
public:
	string toHex(int num)
	{
		if (num == 0) return "0";
		string hex = "0123456789abcdef", ans = "";
		while (num && ans.size() < 8){
			ans = hex[num & 0xf] + ans;//0xf��ʾ�������Ƶ������λ������λ��Ϊ1.����Ǹ����أ�������
			num >>= 4;
		}
		return ans;
	}

};
//

//����λ��������
//-1���
class Solution {
public:
	bool hasAlternatingBits(int n)
	{
		long long temp = n ^ (n >> 1);
		return (temp & (temp + 1)) == 0;

	}
};
//�����Ʊ�ʾ��������������λ
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
//����
class Solution {
public:
	int findComplement(int num)
	{
		int tmp = num;
		int n = 0;
		while (tmp)//tmp������,c���м���1
		{
			tmp >>= 1;
			n = (n << 1) + 1;
		}
		return num ^ n;
	}
};
//��������
class Solution {
public:
	int hammingDistance(int x, int y)
	{
		int n = x ^ y;
		int count = 0;
		while (n)
		{
			count++;
			n &= (n - 1);//����������n�����һ��1
		}
		return count;

	}
};
