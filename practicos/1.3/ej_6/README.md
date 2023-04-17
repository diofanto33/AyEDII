---
ej_6: "Escribir algoritmos cuyas complejidades sean (asumiendo que el lenguaje no tiene multiplicaciones ni logaritmos, o sea que no podes escribir for i:= 1 to n2 + 2 log n do . . . od:"
---

- (a)

***Ө(n<sup>2</sup> + 2Log(n))***

```C
fun fa(in n : nat) ret x : nat
    t ≔ 1  
    for i≔ 1 to n do  
        for j ≔ 1 to n do  
            t ≔ t + 1  
        od  
    od  
    for i≔1 to 2 do  
        t ≔ n  
        while t > 0 do   
            t ≔ t.div.2  
        od  
    od 
    x ≔ t
end proc
```

- (c)

***Ө(3<sup>n</sup>)***

```C
proc fc(in/out n : nat)  
    if(n==0)  
        skip  
    else  
        f3(n-1)  
        f3(n-1)  
        f3(n-1)  
    fi  
end proc
```
