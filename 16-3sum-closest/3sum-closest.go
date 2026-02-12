

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	n := len(nums)

	closestSum := nums[0] + nums[1] + nums[2]

	for i := 0; i < n-2; i++ {
		left := i + 1
		right := n - 1

		for left < right {
			currSum := nums[i] + nums[left] + nums[right]

			if abs(target-currSum) < abs(target-closestSum) {
				closestSum = currSum
			}

			if currSum < target {
				left++
			} else if currSum > target {
				right--
			} else {
				return target 
			}
		}
	}

	return closestSum
}

func abs(x int) int {
	return int(math.Abs(float64(x)))
}
