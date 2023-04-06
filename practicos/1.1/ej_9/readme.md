# Ejercicio 3

Calcular el orden del numero de comparaciones del algoritmo del ejercicio 3.

```C
fun ord_array(in a: array[1..n] of int) ret b : bool 
    b := true
    for i := 1 to n-1 do
        b := b & a[i] ≤ a[i+1]
	od
end fun
```
ops(b := true) + ops(for i:=1 to n-1 do .... od)  
={ Def de ops asignacion & def de ops en for }  
1 +〈 ∑ i :  1 ≤ i ≤ n : ops(b := a[i]≤ a[i+1])〉  
={ Def de ops en asignacion }  
1 +〈 ∑ i :  1 ≤ i ≤ n : 1 + ops(a[i]≤ a[i+1])〉
??????????
