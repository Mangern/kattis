package main

import "fmt"

func main() {
    var m int
    fmt.Scanf("%d", &m)
    T_sum := 0

    for i := 0; i < m; i++ {
        var x int
        fmt.Scanf("%d", &x)
        T_sum += x
    }

    fmt.Printf("%d\n", T_sum / m)


}
