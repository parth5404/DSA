func maxArea(height []int) int {
	i := 0
	j := len(height) - 1
	res := 0
	for i < j {
		minH := height[i]
		if height[j] < minH {
			minH = height[j]
		}
		area := (j - i) * minH
		if area > res {
			res = area
		}

		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return res
}
