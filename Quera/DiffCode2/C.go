package main

import (
	"fmt"
	"math"
)

var cnt [70]int64

func calc(w, h int64) {
	if w > h {
		w, h = h, w
	}
	if w == 0 {
		return
	}
	p := int(math.Log2(float64(w)))
	x := int64(math.Pow(2, float64(p)))
	for i, y := p, h; i >= 0 && y != 0; i-- {
		a := int64(math.Pow(2, float64(i)))
		cnt[i] += (x / a) * (y / a)
		y %= a
	}
	calc(w-x, h)
}

func main() {
	var w, h int64
	fmt.Scan(&w, &h)
	calc(w, h)
	for i := len(cnt) - 1; i >= 0; i-- {
		if cnt[i] != 0 {
			a := int64(math.Pow(2, float64(i)))
			fmt.Printf("%d %d*%d tiles\n", cnt[i], a, a)
		}
	}
}
