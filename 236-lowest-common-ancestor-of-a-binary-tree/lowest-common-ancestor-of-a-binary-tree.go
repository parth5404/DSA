/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)

	if root == p || root == q {
		return root
	}

	if root == p && (left == q || right == q) {
		return root
	}
	if root == q && (left == p || right == p) {
		return root
	}
	if (right == p && left == q) || (left == p && right == q) {
		return root
	}

	if left != nil {
		return left
	}
	return right
}