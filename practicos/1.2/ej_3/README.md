---
ej_3: "Ordenar los arreglos del ejercicio 4 del practico anterior utilizando el algoritmo de  ordenación rápida."
---

# Algoritmo de ordenación por rápida

```sh
proc quick_sort_rec (in/out a: array[1..n] of T, in lft,rgt: nat)
    var ppiv: nat
    if rgt > lft then 
        partition(a,lft,rgt,ppiv)
        quick_sort_rec(a,lft,ppiv-1)
        quick_sort_rec(a,ppiv+1,rgt)
    fi
end proc
```

```sh
proc partition (in/out a: array[1..n] of T, in lft, rgt: nat, out ppiv: nat)
	var i,j: nat
	ppiv:= lft
	i:= lft+1
	j:= rgt
	while i ≤ j do 
		if  a[i] ≤ a[ppiv] then i:= i+1
		    a[j] ≥ a[ppiv] then j:= j-1
			  a[i] > a[ppiv] & a[j] < a[ppiv] then  swap(a,i,j)
								i:= i+1
								j:= j-1
		fi
	od
	swap(a,ppiv,j)
	ppiv:= j
end proc
```

```sh
proc quick_sort (in/out a: array[1..n] of T)
    quick_sort_rec(a,1,n)
end proc
```
