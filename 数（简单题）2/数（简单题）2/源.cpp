//路径之和
class Solution {
public:
	int RootSum(TreeNode* root, int sum)
	{
		int cur = 0;
		if (root == NULL)
			return cur;

		if (sum == root->val)
			cur++;

		cur += RootSum(root->left, sum - root->val);
		cur += RootSum(root->right, sum - root->val);

		return cur;

	}

	int pathSum(TreeNode* root, int sum)
	{
		if (root == NULL)
			return 0;

		return RootSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};
//层序遍历
vector<vector<int>> levelOrder(TreeNode* root)
{
	queue<TreeNode*> q;
	vector<vector<int>> vv;
	if (root == NULL)
		return vv;
	q.push(root);
	while (!q.empty())
	{
		vector<int> v;
		int count = q.size();
		while (count)
		{
			TreeNode* cur = q.front();
			q.pop();
			v.push_back(cur->val);
			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
			count--;
		}
		vv.push_back(v);
	}
	return vv;
}