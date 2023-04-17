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
## (b)
- Escribir otro algoritmo que devuelva un arreglo array[1..n] con el mínimo de cada fila de la matriz a.

```py
proc row_min(in a: array[1..n, 1..m] of int, out b: array[1..n] of int)  
    var min_elem : int  
    for i≔1 to n do  
        min_elem ≔ a[i,1]  
        for j≔1 to m-1 do  
            if min_elem > a[i, j+1] then  
                min_elem ≔ a[i, j+1]  
            fi  
        od  
        b[i] ≔ min_elem  
    od  
end proc
```
