package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }
    sort.Ints(arr)
    var j, k int = 0, n - 1
    for i := 0; i < n; i++ {
        if i != 0 {
            fmt.Print(" ")
        }
        if i % 2 == 0 {
            fmt.Print(arr[k])
            k--
        } else {
            fmt.Print(arr[j])
            j++
        }
    }
    fmt.Println()
}
