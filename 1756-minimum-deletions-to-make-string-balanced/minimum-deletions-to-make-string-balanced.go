func minimumDeletions(s string) int {
    ans := 100000
    r_a := 0
    r_b := 0
    for i := 0; i < len(s); i++ {
        if s[i] == 'a' {
            r_a++
        }
    }

    for i := 0; i < len(s); i++ {
        if s[i] == 'a' {
            r_a--
        }

        ans = min(ans, r_a+r_b)

        if s[i] == 'b' {
            r_b++
        }
    }

    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
