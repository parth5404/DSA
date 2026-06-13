/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, dia *int) int {
	if root == nil {
		return 0
	}
	lh := solve(root.Left, dia)
	rh := solve(root.Right, dia)
	*dia = max(*dia, lh+rh)
	return 1 + max(lh, rh)

}
func diameterOfBinaryTree(root *TreeNode) int {
	var dia int = 0
	solve(root, &dia)
	return dia
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}