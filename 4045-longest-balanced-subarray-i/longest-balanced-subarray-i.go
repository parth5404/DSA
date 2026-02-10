func longestBalanced(nums []int) int {
	ans := 0
	for i := 0; i < len(nums); i++ {
		odd := make(map[int]int)
		even := make(map[int]int)
		for j := i; j < len(nums); j++ {
			if nums[j]&1 == 0 {
				even[nums[j]]++
			} else {
				odd[nums[j]]++
			}
			if len(odd) == len(even) {
				ans = max(ans, j-i+1)
			}
		}
	}
	return ans
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}