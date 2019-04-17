//有效的括号
//O（1）时间效率
class Solution {
public:
	bool isValid(string s)
	{
		if (s.empty())
			return true;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case'(':
			case'{':
			case'[':st.push(s[i]); break;
			case')':
			{
					   if (st.empty() || st.top() != '(') return false;
					   st.pop();
					   break;
			}
			case']':
			{
					   if (st.empty() || st.top() != '[') return false;
					   st.pop();
					   break;
			}
			case'}':
			{
					   if (st.empty() || st.top() != '{') return false;
					   st.pop();
					   break;
			}


			}
		}
		if (!st.empty())
			return false;

		return true;
	}
};
//O（n）时间效率
class Solution {
public:
	bool isValid(string s)
	{


		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (st.empty())
				st.push(s[i]);
			else if (st.top() == '(' && s[i] == ')')
				st.pop();
			else if (st.top() == '{' && s[i] == '}')
				st.pop();
			else if (st.top() == '[' && s[i] == ']')
				st.pop();
			else
				st.push(s[i]);
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};
//下一个更大元素
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> v;
		stack<int> s;

		for (int i = 0; i < nums2.size(); i++)
		{
			s.push(nums2[i]);
		}
		int count;
		for (int j = 0; j < nums1.size(); j++)
		{
			stack<int> ss(s);

			count = -1;
			while (!ss.empty())
			{
				if (ss.top() > nums1[j])
					count = ss.top();
				else if (ss.top() == nums1[j])
					break;
				ss.pop();
			}

			v.push_back(count);

		}
		return v;

	}
};
//用map的方法，往后再写
--
//棒球比赛
class Solution {
public:
	int calPoints(vector<string>& ops)
	{
		int res;
		stack<int> s;
		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i] == "C")
				s.pop();
			else if (ops[i] == "D")
			{
				s.push(s.top() * 2);
			}
			else if (ops[i] == "+")
			{
				int cur = s.top();
				s.pop();
				int pur = s.top() + cur;
				s.push(cur);
				s.push(pur);
			}
			else
			{
				stringstream out;
				out << ops[i];
				out >> res;
				s.push(res);
			}
		}
		int count = 0;
		while (!s.empty())
		{
			count += s.top();
			s.pop();
		}
		return count;
	}
};
//主要是stringstream用法
