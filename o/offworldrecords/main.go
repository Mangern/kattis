package main

import "fmt"

func main()  {
    var n int
    var r int
    var p int

    fmt.Scanf("%d %d %d", &n, &r, &p)

    ans := 0

    for i := 0; i < n; i++ {
        var x int
        fmt.Scanf("%d", &x)

        if x > r + p {
            p = r
            r = x
            ans++
        }
    }

    fmt.Printf("%d\n", ans)
}
