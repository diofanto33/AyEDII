# ej_6

***Descifrar qué hacen los siguientes algoritmos, explicar como lo hacen y reescribirlos asignando nombres adecuados a todos los identificadores***

```sh
proc p (in/out a: array[1..n] of T)
	var x: nat
	for i:= n downto 2 do
		x:= f(a,i)
		swap(a,i,x)
	od
end proc

fun f (a: array[1..n] of T, i: nat) ret x: nat
	x:= 1
	for j:= 2 to i do
		if a[j] > a[x] then x:= j fi
	od
end fun

```
- *El procedimiento p es el algoritmo de Ordenación por Selección (selection_sort) disfrazado*

- Que hace?
	- Ordena un arreglo de tipo T

- Como lo hace?
	- Selenciona el mayor de todos los elementos, lo intercambia con el elemento que se encuentra en la ultima posición y asume que la ultima posición ya esta ordenada.
	- Selecciona el mayor de todos los restantes, lo intercambia con el elemento que se encuentra en la penultima posición y asume que la penultima posición ya esta ordenada.
	- En cada uno de estos pasos ordena un elemento.
	- Hasta terminar

- Nombres adecuados para el procedimiento p

```sh
proc ssort (in/out a: array[1..n] of T)
	var maxp: nat
	for i:= n downto 2 do
		maxp:= max_pos_from(a,i)
		swap(a,i,x)
	od
end proc
```

- *La funcion f es similar a la funcion min_pos_from(a, i) con la diferencia de buscar la posición del máximo en lugar de la posición del mínimo*

- Que hace la funcion f ?
	- Recibe dos parametros, un arreglo de tipo T y un entero positivo, busca la posición donde se encuentra el elemento máximo del arreglo que recibe hasta la posición indicada en el segundo parametro

- Como lo hace?
	- Utiliza un ciclo for y en cada iteracion verifica si la posición que asumio como la del elemento máximo es menor al siguiente elemento, y en caso de serlo asigna a una variable entera el numero de la posición del elemento máximo.

- Nombres adecuados para la funcion f

```sh
fun max_pos_from (a: array[1..n] of T, i: nat) ret maxp: nat
	maxp:= 1
	for j:= 2 to i do
		if a[j] > a[maxp] then maxp:= j fi
	od
end fun
```
