//修建二叉树
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R)
	{
		if (root == NULL)
			return NULL;

		if (root->val < L)
			return trimBST(root->right, L, R);
		if (root->val > R)
			return trimBST(root->left, L, R);

		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);

		return root;
	}
};
//二叉树中第二小的节点
class Solution {
public:
	int min = -1;
	int secondCount = -1;
	int findSecondMinimumValue(TreeNode* root)
	{
		if (root == NULL)
			return secondCount;

		if (min == -1)
		{
			min = root->val;
		}
		else if (min != root->val)//找大于根节点的最小值
		{
			if (secondCount == -1)
				secondCount = root->val;
			else
				secondCount = root->val > secondCount ? secondCount : root->val;

		}
		findSecondMinimumValue(root->left);
		findSecondMinimumValue(root->right);
		return secondCount;
	}
};
//将有序数组转换为二叉搜索树
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.empty())
			return nullptr;

		return TreeBuild(nums, 0, nums.size() - 1);
	}

	TreeNode* TreeBuild(vector<int> nums, int left, int right)
	{
		if (left > right)
			return nullptr;

		int m = left + (right - left) / 2;
		TreeNode* cur = new TreeNode(nums[m]);

		cur->left = TreeBuild(nums, left, m - 1);
		cur->right = TreeBuild(nums, m + 1, right);

		return cur;


	}
};
//二叉树的直径
class Solution {

public:
	int max_num = 0;
	int diameterOfBinaryTree(TreeNode* root)
	{
		depth(root);
		return max_num;
	}
	int depth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		int left = depth(root->left);
		int right = depth(root->right);
		max_num = max(max_num, left + right);

		return 1 + max(left, right);

	}
};
