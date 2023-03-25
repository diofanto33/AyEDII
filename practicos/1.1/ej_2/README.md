# ej_2

***Transformar cada uno de los algoritmos anteriores en uno equivalente que utilice for . . . to .***

- *Inicializar cada componente del arreglo con el valor 0.*

```sh
	proc init_array_zero(out a: array[1..n] of nat) 
		var i : int	
		for i ≔ 1 to n do
			a[i] ≔ 0
		od 
	end proc
```

- Que hace?
    - Este procedimiento, llamado "init_array_zero", inicializa un arreglo de números naturales de tamaño n en cero.
- Como lo hace?
    - El procedimiento utiliza un bucle while que inicializa cada elemento del arreglo en cero, comenzando por el primer elemento y avanzando uno por uno hasta llegar al último. El bucle termina cuando se ha inicializado el último elemento del arreglo en cero.
    
- *Inicializar el arreglo con los primeros n  números naturales positivos.*

```sh
	proc init_array_nat(out a: array[1..n] of nat)
		var j ≔ 1
		for i ≔ 1 to n do
			a[i] ≔ j
			j ≔ j + 1
		od 
	end proc
```
- *Inicializar el arreglo con los primeros en números naturales impares.*
```sh
	proc init_array_odd(out a: array[1..n] of nat)
		var j : int
		j ≔ 1
		for i ≔ 1 to n do
		a[i] ≔ j
		j ≔ j + 2
		od 
	end proc
```

- *Incrementar las posiciones impares del arreglo y dejar intactas las posiciones pares:*

```sh
	proc inc_array_odd(out a: array[1..n] of nat)
		for i ≔ 1 to n do
			if i mod 2 ≠ 0 then a[i] ≔ a[i] + 1 fi
		od 
	end proc
```
