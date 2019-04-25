//n叉树的前序遍历
class Solution {
public:

	vector<int> preorder(Node* root)
	{
		vector<int> v;
		FirstX(root, v);
		return v;
	}

	void FirstX(Node* root, vector<int>& v)
	{
		if (root == NULL)
			return;

		v.push_back(root->val);
		for (auto e : root->children)
		{
			FirstX(e, v);
		}
	}
};
//n叉树后序遍历
vector<int> postorder(Node* root)
{
	vector<int> v;
	FinalX(root, v);
	return v;
}

void FinalX(Node* root, vector<int>& v)
{
	if (root == NULL)
		return;

	for (auto e : root->children)
	{
		FinalX(e, v);
	}
	v.push_back(root->val);
}
//两数之和 四
void TreeFind(TreeNode* root, vector<int>& v)
{
	if (root == NULL)
		return;

	v.push_back(root->val);
	TreeFind(root->left, v);
	TreeFind(root->right, v);

}

bool findTarget(TreeNode* root, int k)
{
	vector<int> v;
	TreeFind(root, v);
	sort(v.begin(), v.end());
	int n = v.size() - 1;
	int i = 0;
	while (i < n)
	{
		if (v[i] + v[n] > k)
			n--;
		else if (v[i] + v[n] < k)
			i++;
		else
			return true;
	}
	return false;
}
//合并二叉树
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
	if (t1 == NULL)
		return t2;
	if (t2 == NULL)
		return t1;

	t1->val += t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;

}
//求平均值
vector<double> averageOfLevels(TreeNode* root)
{
	vector<double> v;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int count = q.size();
		int count1 = count;
		double num = 0;
		while (count)
		{
			TreeNode* cur = q.front();
			q.pop();
			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
			count--;
			num += cur->val;
		}

		v.push_back(num / count1);

	}
	return v;
}
};