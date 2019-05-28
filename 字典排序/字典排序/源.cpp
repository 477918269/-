#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool StringTree(string s, string s1)
{
	int i = 0;
	while (!s.empty() && !s1.empty())
	{
		if ((int)s[i] > (int)s1[i])
			return false;
		i++;
	}
	if (i < s.size() && i == s1.size())
		return false;
	return true;
}


int main()
{
	vector<string> vs;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vs.push_back(s);
	}
	int num = 0;
	int num1 = 0;
	int j;
	for (j = 0; j < vs.size() - 1; j++)
	{
		if (vs[j].size() > vs[j + 1].size())
		{
			break;
		}
	}
	if (j + 1 == vs.size())
		num++;

	for (j = 0; j < vs.size() - 1; j++)
	{
		if (!StringTree(vs[j], vs[j + 1]))
			break;
	}
	if (j + 1 == vs.size())
		num1++;

	if (num == num1)
		cout << "both";
	else if (num == 0 && num1 == 1)
		cout << "lexicographically";
	else if (num == 1 && num1 == 0)
		cout << "lengths";
	else
		cout << "none";

	return 0;
}