## (a)
- **Dar un algoritmo que obtenga la menor temperatura mínima (TempMin) histórica registrada en la ciudad de Córdoba según los datos del arreglo.**

```py
fun min_TempMin_of_med( in med : array[1980..2016, enero.. diciembre, 1..28, Temp..Prec] of nat) ret min_temp : nat
    min_temp ≔ med[1980, enero, 1, TempMin]
    for año ≔ 1980 to 2016 
    do
	    for mes ≔ enero to diciembre 
	    do
		    for dia ≔ 1 to 28 
		    do 
			    if min_temp > med[año, mes, dia, TempMin] 
                then
				    min_temp ≔ med[año, mes, día, TempMin]
			    fi
		    od
	    od
    od
end fun
```

## (b)
- **Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 la mayor temperatura máxima (TempMax) registrada durante ese año**

```py
proc array_TempMax_of_med( in med : array[1980..2016, 
                                          enero.. diciembre, 
                     			  1..28,
 		                          Temp..Prec] of nat,
                           out tempMax_by_year : array[1980..2016] of nat) 
		
    var year_tempMax : nat
    for año ≔ 1980 to 2016
    do	
	    year_tempMax  ≔  med[año, enero, 1, TempMax]
	    for mes ≔ enero to diciembre
	    do
		    for dia ≔ 1 to 28
		    do 
			    if year_tempMax < med[año, mes, dia, TempMax]
				    then
				        year_tempMax ≔ med[año, mes, dia, TempMax]
			    fi
		    od 
	    od
	    tempMax_by_year[año] ≔ year_tempMax
    od
end proc
```

## (c)
- **Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones**
```py
proc array_PrecMax_of_med( in med : array[1980..2016, 
                                          enero.. diciembre, 
                     			  1..28,
 		                          Temp..Prec] of nat,
                            out precMax_by_year : array[1980..2016] of mes) 

    var prec_max : nat	
        sum_by_month : nat
        sum_by_month_aux : nat
        month_aux : nat
    sum_by_month_aux ≔ med[1980, enero, 1, PrecMax] 
    for año ≔ 1980 to 2016
    do  
	    for mes ≔ enero to diciembre 
	    do  
            sum_by_month ≔ 0
		    for dia ≔ 1 to 28 
		    do
			    sum_by_month ≔ sum_by_month + med[año, mes, dia, PrecMax]
		    od
			if sum_by_month_aux ≤ sum_by_month then
                then sum_by_month_aux ≔ sum_by_month
                month_aux ≔ mes             
            fi
        od
        precMax_by_year[año] ≔ month_aux
    od
end proc
```
