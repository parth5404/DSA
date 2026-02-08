/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func height(root *TreeNode, val *bool) int {
	if root == nil {
		return 0
	}

	lh := height(root.Left, val)
	rh := height(root.Right, val)

	if abs(lh-rh) > 1 {
		*val = false
	}

	return max(lh, rh) + 1
}

func isBalanced(root *TreeNode) bool {
	val := true
	height(root, &val)
	return val
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
