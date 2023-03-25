# ej_3

***Escribir un algoritmo que reciba un arreglo a de posiciones 1 a n y determine si el arreglo recibido está ordenado o no. Explicar en palabras que hace el algoritmo. Explicar en palabras como lo hace:***

```sh
fun ord_array(in a: array[1..n] of int) ret b : bool
    var i : int
    i := 1
    b := true
    while i < n ∧ b do
        b := a[i] ≤ a[i+1]
        i := i + 1
    od
end fun
```
- Que hace?
    - Determina si un arreglo esta ordenado o no.
- Como lo hace?
    - Declara un entero i con valor 1 para recorrer el arrelgo utilizando un ciclo while hasta n-1 inclusive (indexa en i+1), asigna al booleano b el valor de verdad resultande de comparar dos elementos consecutivos, al evaluar b en la guarda del while se detiene cuando exista al menos un elemento desordenado y retorna en b siendo False, caso contrario retorna en b siendo True 
