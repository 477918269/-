#include<iostream>

using namespace std;

bool PhraseString(string s, int begin, int end)
{
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

string longestPalindrome(string s)
{
	if (s.empty())
		return s;
	if (s.size() == 1)
		return s;
	string s1;
	int i = 0;
	int j;

	for (i = 0; i < s.size() - 1; i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				if (PhraseString(s, i, j))
				{
					if (j - i > s1.size())
					{
						s1.clear();
						for (int k = i; k <= j; k++)
						{
							s1 += s[k];
						}
					}
				}
			}
		}
	}
	if (s1.empty())
	{
		s1 += s[0];
		return s1;
	}
	return s1;

}

int main()
{
	string s;
	s += "ccc";
	longestPalindrome(s);

	system("pause");
}