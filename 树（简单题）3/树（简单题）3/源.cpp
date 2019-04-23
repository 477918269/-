//对称二叉树
class Solution {
public:
	bool SameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
			return true;

		if (p == NULL && q != NULL)
			return false;

		if (p != NULL && q == NULL)
			return false;

		if (p->val == q->val && SameTree(p->left, q->right) && SameTree(p->right, q->left) && p && q)
			return true;

		return false;


	}


	bool isSymmetric(TreeNode* root)
	{
		if (root == NULL)
			return true;

		return SameTree(root->left, root->right);
	}
};
//相同的树
class Solution {
public:
	bool SameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
			return true;

		if (p == NULL && q != NULL)
			return false;

		if (p != NULL && q == NULL)
			return false;

		if (p->val == q->val && SameTree(p->left, q->right) && SameTree(p->right, q->left) && p && q)
			return true;

		return false;


	}


	bool isSymmetric(TreeNode* root)
	{
		if (root == NULL)
			return true;

		return SameTree(root->left, root->right);
	}
};
//层序遍历的简单解法
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> cur, pur;

		Put(root, cur, 0);

		pur.resize(cur.size());

		for (int i = 0; i < pur.size(); i++)
		{
			for (int j = 0; j < cur[cur.size() - i - 1].size(); j++)
				pur[i].push_back(cur[cur.size() - i - 1][j]);
		}
		return pur;
	}

	void Put(TreeNode* root, vector<vector<int>>& cur, int num)
	{
		if (root == NULL)
			return;

		if (num == cur.size())
			cur.resize(cur.size() + 1);

		cur[num].push_back(root->val);
		Put(root->left, cur, num + 1);
		Put(root->right, cur, num + 1);

	}
};