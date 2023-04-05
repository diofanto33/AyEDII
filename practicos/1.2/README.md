---
ej_1: "Ordenar los arreglos del ejercicio 4 del practico anterior utilizando el algoritmo de  ordenación por intercalación."
---

# Algoritmo de ordenación por intercalación

```sh
proc merge_sort_rec (in/out a: array[1..n] of T, in lft,rgt: nat)
    var mid: nat
    if rgt > lft then
        mid:= (rgt+lft) ÷ 2
        merge_sort_rec(a,lft,mid)
        merge_sort_rec(a,mid+1,rgt)
        merge(a,lft,mid,rgt)
    fi
end proc
```

```sh
proc merge (in/out a: array[1..n] of T, in lft,mid,rgt: nat)
    var tmp: array[1..n] of T
    j,k: nat
    for i:= lft to mid do tmp[i]:=a[i] od
    j:= lft
    k:= mid+1
    for i:= lft to rgt do
    	if j ≤ mid ∧ (k > rgt ∨ tmp[j] ≤ a[k]) then 
    		a[i]:= tmp[j]
                j:=j+1
        else  
		a[i]:= a[k]
       		k:=k+1
        fi
    od
end proc
```

```sh
proc merge_sort (in/out a: array[1..n] of T)
    merge_sort_rec(a, 1, n)
end proc
```

![Árbol Merge Sort](merge_sort_tree.png)

*En el procedimiento merge no se escribe la traza del primer for que copia en tmp*  
*Ademas en el segundo for se usa ψ<sub>i</sub> para identificar la i-esima iteracion de su traza*

**Sea a := [7, 1, 10, 3, 4, 9, 5] el input**  

#
merge_sort(a)
- merge_sort_rec(a, 1, 7)
	- if 7 > 1
	- **-{ True }**
		- mid := 4
		- merge_sort_rec(a, 1, 4)
		- merge_sort_rec(a, 5, 7)
		- merge(a, 1, 4, 7)
	- fi

#
- merge_sort_rec(a, 1, 4)
	- if 4 > 1
	- **-{ True }**
		- mid := 2
		- merge_sort_rec(a, 1, 2)
		- merge_sort_rec(a, 3, 4)
		- merge(a, 1, 2, 4)
	- fi

#
- merge_sort_rec(a, 1, 2)
	- if 2 > 1
	- **-{ True }-**
		- mid := 1
		- merge_sort_rec(a, 1, 1)
			- **-{ 1 > 1 ☰ False }-**
		- merge_sort_rec(a, 2, 2)
			- **-{ 2 > 2 ☰ False }-**
		- merge(a, 1, 1, 2)
	- fi

#
- merge(a, 1, 1, 2)
	- tmp[1] := {7}
	- j := 1
	- k := 2
	- for i := 1 to 2 do
	- ψ<sub>1</sub> : 
		- if 1 ≤ 2 & (2 > 2 v 7 ≤ 1)
			- **-{ False }-**
		- else 
			- a[1] := a[2]
			- **-{ a = [1, 1, 10, 3, 4, 9, 5] }-**
			- k := k + 1
			- **-{ k = 3 }-**
		- fi
	- ψ<sub>2</sub> : 
		- if 1 ≤ 2 & (3 > 2 v 7 ≤ 10)
			- **-{ True }-**
			- a[i] := tmp[1]
			- **-{ a = [1, 7, 10, 3, 4, 9, 5] }-**
			- j := j + 1
			- **-{ j = 2 }-**
		- fi
	- od

#
- merge_sort_rec(a, 3, 4)
	- if 4 > 3
	- **-{ True }-**
		- mid := 3
		- merge_sort_rec(a, 3, 3)
			- **-{ 3 > 3 ☰ False }-**
		- merge_sort_rec(a, 4, 4)
			- **-{ 4 > 4 ☰ False }-**
		- merge(a, 3, 3, 4)
	- fi

#
- merge(a, 3, 3, 4)
	- tmp[3] := {10}
	- j := 3
	- k := 4
	- for i := 3 to 4 do
	- ψ<sub>3</sub> :
		- if 3 ≤ 3 & (4 > 4 v 10 ≤ 3)
			- **-{ False }-**	
		- else 
			- a[3] := a[4]
			- **-{ a = [1, 7, 3, 3, 4, 9, 5] }-**
			- k := k + 1
			- **-{ k = 5 }-**
		- fi
	- ψ<sub>4</sub> :
		- if 3 ≤ 3 & (5 > 4 v 10 ≤ 4)
			- **-{ True }**
			- a[4] := tmp[3]
			- **a = [1, 7, 3, 10, 4, 9, 5]**
			- j := j + 1
			- **-{j = 4}-**
		- fi
	- od

#
- merge(a, 1, 2, 4)
	- tmp[1, 2] := {1, 7}
	- j := 1
	- k := 3
	- for i := 1 to 4 do
	- ψ<sub>1</sub> :
		- if 1 ≤ 2 & (3 > 4 v 1 ≤ 3)
			- **-{ True }-**
			- a[1] := tmp[1]
			- **a = [1, 7, 3, 10, 4, 9, 5]**
			- j := j + 1
			- **-{ j = 2 }-**
		- fi
	- ψ<sub>2</sub> :
		- if 2 ≤ 2 & (3 > 4 v 7 ≤ 3)
			- **-{ False }-**
		- else
			- a[2] := a[3]
			- **a = [1, 3, 3, 10, 4, 9, 5]**
			- k := k + 1
			- **-{ k = 4 }-**
		- fi
	- ψ<sub>3</sub> :
		- if 2 ≤ 2 & (4 > 4 v 7 ≤ 10)
			- **-{ True }-**
			- a[3] := tmp[2]
			- **-{ a = [1, 3, 7, 10, 4, 9, 5] }-**
			- j := j + 1
			- **-{ j = 3 }-**
		- fi
	- ψ<sub>4</sub> :
		- if 3 ≤ 2 & (4 > 4 v 7 ≤ 10)
			- **-{ False }-**
		- else 
			- a[4] := a[4]
			- **-{ a = [1, 3, 7, 10, 4, 9, 5] }-**
			- k := k + 1
			- **-{ k = 5 }-**
		-fi
	- od 

# Mitad izquierda ordenada

- merge_sort_rec(a, 5, 7)
	- if 7 > 5
	- **-{ True }-**
		- mid := 6
		- merge_sort_rec(a, 5, 6)
		- merge_sort_rec(a, 7, 7)
			- **-{ 7 > 7 ☰ False }-**	
		- merge(a, 5, 6, 7)
	- fi

#
- merge_sort_rec(a, 5, 6)
	- if 6 > 5
	- **-{ True }-**
		- mid := 5
		- merge_sort_rec(a, 5, 5)
			- **-{ 5 > 5 ☰ False }-**
		- merge_sort_rec(a, 6, 6)
			- **-{ 6 > 6 ☰ False }-**
		- merge(a, 5, 6, 6)
	- fi

#
- merge(a, 5, 6, 6)
	- tmp[5, 6] := {4, 9}
	- j := 5
	- k := 7
	- for i := 5 to 6 do
	- ψ<sub>5</sub> :
		- if 5 ≤ 6 & (7 > 6 v 4 ≤ 5)
			- **-{ True }-**
			- a[5] := tmp[5]
			- **-{ a = [1, 3, 7, 10, 4, 9, 5] }-**
			- j := j + 1
			- **-{ j = 6 }-**
		- fi
	- ψ<sub>6</sub> :
		- if 6 ≤ 6 & (7 > 6 v 9 ≤ 5)
			- **-{ True }**
			- a[6] := tmp[6]
			- **-{ a = [1, 3, 7, 10, 4, 9, 5] }-**
			- j := j + 1
			- **-{ j = 7 }-**
		- fi
	- od

#
- merge(a, 5, 6, 7)
	- tmp[5, 6] = {4, 9}
	- j := 5
	- k := 7
	- for i := 5 to 7 do
	- ψ<sub>5</sub> :	
		- if 5 ≤ 6 & (7 > 7 v 4 ≤ 5)
			- **-{ True }-**
			- a[5] := tmp[5]
			- **-{ a = [1, 3, 7, 10, 4, 9, 5] }-** 
			- j := j + 1
			- **-{ j = 6 }-**
		- fi
	- ψ<sub>6</sub> :
		- if 6 ≤ 6 & (7 > 7 v 9 ≤ 5)
			- **-{ False }-**
		- else
			- a[6] := a[7]
			- **-{ a = [1, 3, 7, 10, 4, 5, 5] }-**
			- k := k + 1
			- **-{ k = 8 }-**
		- fi
	- ψ<sub>7</sub>
		- if 6 ≤ 6 & (8 > 7 v 9 ≤ a[8])
			- **-{ True }-**
			- a[7] := tmp[6]
	  		- **-{ a = [1, 3, 7, 10, 4, 5, 9] }-**
			- j := j + 1
			- **-{ j = 7 }-**
		- fi
	- od

# Mitad derecha ordenada  
*Ahora merge de mitad izquierda y mitad derecha*  

- merge(a, 1, 4, 7)
	- tmp[1, 2, 3, 4] := {1, 3, 7, 10}
	- j := 1
	- k := 5
	- for i := 1 to 7 do
	- ψ<sub>1</sub> :
		- if 1 ≤ 4 & (5 > 7 v 1 ≤ 4)
			- **-{ True }-**
			- a[1] := tmp[1]
			- **-{ a = [1, 3, 7, 10, 4, 5, 9] }-** 
			- j := j + 1
			- **-{ j = 2 }-**
		- fi
	- ψ<sub>2</sub> :	
		- if 2 ≤ 4 & (5 > 7 v 3 ≤ 4)
			- **-{ True }-**
			- a[2] := tmp[2]
			- **-{ a = [1, 3, 7, 10, 4, 5, 9] }-** 
			- j := j + 1
			- **-{ j = 3 }-**
		- fi
	- ψ<sub>3</sub> :	
		- if 3 ≤ 4 & (5 > 7 v 7 ≤ 4)
			- **-{ False }-**
		- else
			- a[3] := a[5]
			- **-{ a = [1, 3, 4, 10, 4, 5, 9] }-**
			- k := k + 1
			- **-{ k = 6 }-**
		- fi
	- ψ<sub>4</sub> :
		- if 3 ≤ 4 & (6 > 7 v 7 ≤ 5)
 			- **-{ False }-**
		- else
			- a[4] := a[6]
			- **-{ a = [1, 3, 4, 5, 4, 5, 9] }-**
			- k := k + 1
			- **-{ k = 7 }-**
		- fi
	- ψ<sub>5</sub> :
		- if 3 ≤ 4 & (7 > 7 v 7 ≤ 9)
			- **-{ True }-**
			- a[5] := tmp[3]
			- **-{ a = [1, 3, 4, 5, 7, 5, 9] }-**
			- j = j + 1
			- **-{ j = 4 }-**
		- fi
	- ψ<sub>6</sub> :
		- if 4 ≤ 4 & (7 > 7 v 10 ≤ 9)
			- **-{ False }-**
		- else
			- a[6] := a[7]
			- **-{ a = [1, 3, 4, 5, 7, 9, 9] }-**
			- k := k + 1
			- **-{ k = 8 }-**
		- fi
	- ψ<sub>7</sub> :
		- if 4 ≤ 4 & (8 > 7 v tmp[4] ≤ a[8])
			- **-{ True }**
			- a[7] := tmp[4]
			- **-{ a = [1, 3, 4, 5, 7, 9, 10] }-**
			- k := k + 1
			- **-{ k = 9 }-**
		- fi
	- od

## output: a = [1, 3, 4, 5, 7, 9, 10]
