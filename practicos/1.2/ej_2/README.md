# (a)

```sh
proc intercalar_cada(in/out a : array[1..2^n] of int in i : nat )
	var j, tam : nat
	k ≔ 0
	while (k+1) * 2^k ≤ 2^n do
		merge(a, k * 2^i + 1, (k+1) * 2^i, k * 2^i)
		k ≔ k + 1
	od
end proc

```

# (b)

```sh
proc merge_sort (in/out a : array[1..2^n] of int)
	for i ≔ 1 to n do
		intercalar_cada(a, i)
	od
end proc
```
