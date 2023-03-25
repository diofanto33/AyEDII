# ej_5

***Calcula de la manera más exacta y simple posible el número de asignaciones a la variable t de los siguientes algoritmos. Las ecuaciones que se encuentran al final del práctico pueden ayudarte.***

- *(a)*

```C
t := 0
for i := 1 to n do
	for j := 1 to n**2 do
		for k := 1 to n**3 do
			t := t + 1
		od
	od
od
```

**Recordemos la expresion para ops(for k ≔ n to m do C(k) od)  = 〈 ∑ k :  n ≤ k ≤ m : ops( C(k))〉**

*Sea m el algoritmo del iniciso (a)*  
*Calculemos ops(m)*

ops(m)  
**={ Def de ops }**  
ops(t := 0) + ops(for i := 1 to n do … od)  
**={ Def de ops en asignación }**  
1 + ops(for i := 1 to n do … od)  
**={ Def de ops en for }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n : ops(for j := 1 to n<sup>2</sup> do … od)〉  
**={ Def de ops en for }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n :〈 ∑ j :  1 ≤ j ≤ n<sup>2</sup> : ops( for k := 1 to n<sup>3</sup> do t := t + 1 od)〉〉  
**={ Def de ops en for }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n :〈 ∑ j :  1 ≤ j ≤ n<sup>2</sup> : 〈 ∑ k :  1 ≤ k ≤ n<sup>3</sup> : ops( t := t + 1)〉〉〉  
**={ Def	de ops en asignación }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n :〈 ∑ j :  1 ≤ j ≤ n<sup>2</sup> : 〈 ∑ k :  1 ≤ k ≤ n<sup>3</sup> : 1〉〉〉  
**={ Propiedad 〈 ∑ k :  1 ≤ k ≤ n : 1〉= n }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n :〈 ∑ j :  1 ≤ j ≤ n<sup>2</sup> : n<sup>3</sup> 〉〉  
**={ Distributividad del producto con respecto a la suma }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n :〈 ∑ j :  1 ≤ j ≤ n^2 : 1 〉・ n<sup>3</sup>〉  
**={ Propiedad 〈 ∑ k :  1 ≤ k ≤ n : 1〉= n }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n : n<sup>2</sup>・ n<sup>3</sup>〉  
**={ Producto de igual base se suman los exponentes }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n : n<sup>5</sup>〉  
**={ Distributividad del producto con respecto a la suma }**  
1 + 〈 ∑ i :  1 ≤ i ≤ n : 1〉・n<sup>5</sup>  
**={ Propiedad 〈 ∑ k :  1 ≤ k ≤ n : 1〉= n }**  
1 + n・n<sup>5</sup>  
**={ Producto de igual base se suman los exponentes }**  
1 + n<sup>6</sup>  

**⇒ Ө(n<sup>6</sub> )**


