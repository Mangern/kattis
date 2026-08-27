package main

import (
    "fmt"
    "strings"
)

func main() {
    var S string
    fmt.Scanf("%s", &S)

    forb := []rune(S)

    for {
        var x string
        _, err := fmt.Scanf("%s", &x)
        if err != nil {
            break
        }

        fail := false
        for _, c := range forb {
            if strings.ContainsRune(x, c) {
                fail = true
                break
            }
        }

        if fail {
            fmt.Printf("%s ", strings.Repeat("*", len(x)))
        } else {
            fmt.Printf("%s ", x)
        }
    }
    fmt.Println()
}
