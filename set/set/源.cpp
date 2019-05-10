#include<iostream>
#include<set>

using namespace std;
//void Test()
//{
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	cout << s.size() << endl;
//
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	s.insert(10);
//	s.erase(5);
//	set<int> ::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	
//	cout << s.count(1) << endl;
//}

void Test1()
{
	int a[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	multiset<int> s(a, a + sizeof(a) / sizeof(a[0]));
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	s.insert(5);
	cout << s.count(5) << endl;
	s.erase(5);
	s.insert(5);
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


}

int main()
{
	Test1();
	system("pause");
}