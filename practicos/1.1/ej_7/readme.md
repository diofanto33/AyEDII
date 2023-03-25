---
ej_7a: "Insertion sort execution"
---

# Algoritmo de Ordenación por inserción:
```sh
proc insertion_sort (in/out a: array[1..n] of T)
	for i:= 2 to n do 
		insert(a,i)
	od
end proc
 
proc insert (in/out a: array[1..n] of T, in i: nat)
	var j: nat
	j:= i 
	while j > 1 ∧ a[j] < a[j − 1]  do 
		swap(a,j-1,j)
		j:= j-1
	od
end proc
```
*La traza del ciclo for  del proc insertion_sort se identifica como δ.*  
*La traza del ciclo (anidado) while del proc insert se identifica como  φ.*  
*Recordemos que este ***-{ comentario }-***  es un comentario en*  ***ΔΔLang*** 

*input: arr ≔ [ 7, 1 , 10 , 3, 4, 9, 5]*  
**insertion_sort**(arr)  
**for** i ≔ 2 **to** 7 **do**  
- **δ**<sub>**2**</sub> : insert(arr, 2)  
	- **φ<sub>2</sub>** :  2 > 1 & arr[2] < arr[1]  
	 ***-{ True }-***  
		- swap(arr, 1, 2)  
		 ***-{ arr = [ 1, 7, 10, 3, 4, 9, 5] }-***  
		- j≔ j - 1  
		 ***-{ j = 1 }***
	- **φ**<sub>**1**</sub> : 1 > 1 & arr[1] < arr[0]  
	 ***-{ False }-***
- **δ**<sub>**3**</sub> : insert(arr, 3)
	- **φ**<sub>**3**</sub>:  3 > 1 & arr[3] < arr[2]  
	 ***-{ False }-***
- **δ**<sub>**4**</sub>: insert(arr, 4)
	- **φ**<sub>**4**</sub> : 4 > 1  & arr[4] < arr[3]  
	 ***-{ True }-***  
		- swap(arr, 3, 4)  
		 ***-{ arr = [ 1, 7, 3, 10, 4, 9, 5] }-***  
		- j ≔ j - 1  
		 ***-{ j = 3 }***
	- **φ**<sub>**3**</sub> :  3 > 1 & arr[3] < arr[2]  
	 ***-{ True }-***  
		- swap(arr,  2,  3)
	 	  ***-{ [ 1, 3, 7, 10, 4, 9, 5] }-***
	 	- j ≔ j - 1  
		***-{ j = 2 }***
	- **φ**<sub>**2**</sub> : 2 > 1 & arr[2] < arr[1]  
	 ***-{False}-***
- **δ**<sub>**5**</sub> : insert(arr, 5)  
	- **φ**<sub>**5**</sub> : 5 > 1 & arr[5] < arr[4]  
	 ***-{ True }-***  
		- swap(arr, 4, 5)  
		  ***-{ arr = [ 1, 3, 7, 4, 10, 9, 5] }-***  
		- j ≔ j - 1  
		 ***-{ j = 4 }***
	- **φ**<sub>**4**</sub> : 4 > 1 & arr[4] < arr[3]  
	 ***-{ True }-***  
		- swap(arr, 3, 4)  
		  ***-{ arr = [ 1, 3, 4, 7, 10, 9, 5] }-***  
		- j ≔ j - 1  
		 ***-{ j = 3 }***
	- **φ**<sub>**3**</sub> : 3 > 1 & arr[3] < arr[2]  
	 ***-{ False }-***  
- **δ**<sub>**6**</sub> : insert(arr, 6)  
	- **φ**<sub>**6**</sub> : 6 > 1 & arr[6] < arr[5]  
	 ***-{ True }-***  
		- swap(arr, 5, 6)  
		  ***-{ [ 1, 3, 4, 7, 9, 10, 5] }-***  
		- j ≔ j - 1  
		 ***-{ j = 5 }***
	- **φ**<sub>**5**</sub> : 5 > 1 & arr[5] < arr[4]  
	 ***-{ False }-***
- **δ**<sub>**7**</sub>: insert(arr, 7)
	- **φ**<sub>**7**</sub> : 7 > 1 & arr[7] < arr[6]  
	 ***-{ True }-***  
		- swap(arr, 6, 7)  
		  ***-{ arr = [ 1, 3, 4, 7, 9, 5, 10] }-***  
		- j ≔ j - 1  
		 ***-{ j = 6 }***
	- **φ**<sub>**6**</sub> : 6 > 1 & arr[6] < arr[5]  
	 ***-{ True }-***  
		- swap(arr, 5, 6)  
		  ***-{ arr = [ 1, 3, 4, 7, 5, 9, 10] }-***  
		- j ≔ j - 1  
		 ***-{ j = 5 }***
	- **φ**<sub>**5**</sub>  : 5 > 1 & arr[5] < arr[4]  
	 ***-{ True }-***  
		- swap(arr, 4, 5)  
		  ***-{ arr = [ 1, 3, 4, 5, 7, 9, 10] }-***  
		- j ≔ j - 1  
		 ***-{ j = 4 }***
	- **φ**<sub>**4**</sub> : 4 > 1 & arr[4] < arr[5]  
	 ***-{ False }-***  
  
**od**

*output: arr = [ 1, 3, 4, 5, 7, 9, 10]* 
