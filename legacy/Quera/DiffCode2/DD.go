package main

import "fmt"

var cnt [100010]int
var n, x int
var res int64

func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x)
		cnt[x]++
	}
	for i := 1; i < len(cnt); i++ {
		res += int64(cnt[i-1] * cnt[i])
	}
	fmt.Println(res)
}
