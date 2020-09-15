package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	x int
	y int
}

var n int
var arr []int

func main() {
	fmt.Scan(&n)

	var x int
	seen := make(map[int]bool)
	for i := 0; i < n; i++ {
		fmt.Scan(&x)
		if !seen[x] {
			arr = append(arr, x)
			seen[x] = true
		}
	}
	sort.Ints(arr)

	var pairs []Pair
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			pairs = append(pairs, Pair{arr[i], arr[j]})
		}
	}
	sort.Slice(pairs, func(i, j int) bool {
		d1 := math.Abs(float64(pairs[i].x - pairs[i].y))
		d2 := math.Abs(float64(pairs[j].x - pairs[j].y))
		if d1 == d2 {
			return pairs[i].x < pairs[j].x
		}
		return d1 < d2
	})

	for _, p := range pairs {
		fmt.Printf("[%d, %d]\n", p.x, p.y)
	}
}
