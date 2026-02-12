/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    if root==nil{
        return false
    }
    if same(root,subRoot){
        return true;
    }
    return isSubtree(root.Left,subRoot)||isSubtree(root.Right,subRoot)
}
func same(s *TreeNode,t *TreeNode)bool{
    if s==nil && t==nil{
        return true
    }
    if s==nil||t==nil{
        return false;
    }
    if s.Val!=t.Val{
        return false
    }
    return same(s.Left,t.Left) && same(s.Right,t.Right)
}