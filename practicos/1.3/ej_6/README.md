---
ej_6: "Escribir algoritmos cuyas complejidades sean (asumiendo que el lenguaje no tiene multiplicaciones ni logaritmos, o sea que no podes escribir for i:= 1 to n2 + 2 log n do . . . od:"
---

- (c)

**3<sup>n</sup>**

```sh
proc f3(in n : nat)  
    if(n==0)  
        skip  
    else  
        f3(n-1)  
        f3(n-1)  
        f3(n-1)  
        fi  
end proc
```
