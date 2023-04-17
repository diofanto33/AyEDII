---
ej_1a: "Escribir un algoritmo que dada una matriz a: array[1..n,1..m] of int calcule el elemento mínimo."
---

```py
fun array_min(in a: array[1..n, 1..m] of int) ret x : int
	var result : int
	result ≔ a[1,1]
	for i≔1 to n do
		for j≔1 to m do 
			if result ≤ a[i,j] then result ≔ a[i,j] fi 
		od
	od
	x ≔ result
end fun
```
