//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		sort(v.begin(), v.end());
//		int mid = v.size() / 2;
//		cout << v[mid];
//
//	}
//	return 0;
//}

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	string s2;
	getline(cin, s);
	int i = 0;
	int j = 0;
	int count = 0;
	int max_count = 0;
	while (i < (int)s.size())
	{
		j = i;
		while (j < (int)s.size() && (s[j] >= '0' && s[j] <= '9'))
		{
			j++;
		}
		if (j > i)
		{
			int count = j - i;
			if (count > max_count)
			{
				max_count = count;
				string s1(s.substr(i, count));
				s2 = s1;
			}

			i = j;
		}
		i++;


	}
	cout << s2 << endl;
	return 0;
}