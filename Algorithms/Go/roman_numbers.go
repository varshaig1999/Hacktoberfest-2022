package Go

import (
	"fmt"

	"log"
	"math/big"
	"time"
)

func main() {
	start := time.Now()
	r := new(big.Int)
	fmt.Println(r.Binomial(1000, 10))

	// input string
	s := "XLIV"

	var a []string
	sum := 0

	// prepare a map with roman - decimal numbers relation
	aValues := make(map[string]int)
	aValues["I"] = 1
	aValues["V"] = 5
	aValues["X"] = 10
	aValues["L"] = 50
	aValues["C"] = 100
	aValues["M"] = 1000

	for _, c := range s {
		a = append(a, string(c))
	}

	size := len(a)

	for i := 0; i < size; i++ {
		if i+1 < size {
			if aValues[a[i]] < aValues[a[i+1]] {
				sum -= aValues[a[i]]
			} else {
				sum += aValues[a[i]]
			}
		} else {
			sum += aValues[a[i]]
		}
	}

	fmt.Println(sum)

	elapsed := time.Since(start)
	log.Printf("Function took %s", elapsed)
}
