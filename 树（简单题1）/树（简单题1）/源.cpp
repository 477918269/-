//查找最近的公共祖先
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == NULL)
			return 0;

		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		return root;
	}
};
//二叉树的最小深度
class Solution {
public:
	int minDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left;
		int right;
		if (root->left && root->right)
		{
			left = minDepth(root->left);
			right = minDepth(root->right);
			return left > right ? right + 1 : left + 1;
		}
		else if (root->left && !root->right)
		{
			return minDepth(root->left) + 1;
		}
		else if (!root->left && root->right)
		{
			return minDepth(root->right) + 1;
		}
		else
			return left > right ? right + 1 : left + 1;
		return 0;
	}
};
//路径总和
class Solution {
public:


	bool hasPathSum(TreeNode* root, int sum)
	{
		if (root == NULL)
			return false;

		if (root->left == NULL && root->right == NULL)
			return sum == root->val;

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

	}
};
//翻转二叉树
class Solution {
public:

	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL)
			return NULL;

		if (root->left == NULL && root->right == NULL)
			return root;

		TreeNode* pur = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(pur);

		return root;
	}
};