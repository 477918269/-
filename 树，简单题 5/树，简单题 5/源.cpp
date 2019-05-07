//��������������С���Բ�
//��Ϊ��������������������õ��������ǵ����ģ���˲�ֵ��С������϶�����������������ֵ��С�������
//�ݹ�д��
class Solution {
public:

	void GetMin(TreeNode* root, vector<int>& v)
	{
		if (root == NULL)
			return;

		GetMin(root->left, v);
		v.push_back(root->val);
		GetMin(root->right, v);

	}

	int getMinimumDifference(TreeNode* root)
	{
		vector<int> v;
		GetMin(root, v);

		int min = v[1] - v[0];
		for (int i = 1; i < v.size() - 1; i++)
		{
			min = abs(v[i] - v[i + 1]) < min ? abs(v[i] - v[i + 1]) : min;
		}
		return min;
	}
};
//�ǵݹ�д��
int getMinimumDifference(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* pur = nullptr;
	int count = INT_MAX;
	while (cur != NULL || !s.empty())
	{
		if (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			TreeNode* node = s.top();
			s.pop();
			if (pur != nullptr)
			{
				count = min(abs(node->val - pur->val), count);
			}
			pur = node;

			cur = node->right;
		}
	}
	return count;

}


//n / 3������
//Ħ����ͶƱ��
class Solution {
public:
	vector<int> majorityElement(vector<int>& v)
	{
		int x = 0;
		int y = 0;
		int ex = 0;
		int ey = 0;

		vector<int> v1;
		for (auto e : v)
		{
			if ((x == 0 || e == ex) && e != ey)
			{
				x++;
				ex = e;
			}
			else if (y == 0 || e == ey)
			{
				y++;
				ey = e;
			}
			else
			{
				x--;
				y--;
			}
		}

		int count = 0;
		for (auto e : v)
		{
			if (e == ex)
				count++;
		}
		if (count > v.size() / 3)
			v1.push_back(ex);

		count = 0;
		for (auto e : v)
		{
			if (e == ey)
				count++;
		}
		if (count > v.size() / 3 && ex != ey)
			v1.push_back(ey);

		return v1;
	}
};