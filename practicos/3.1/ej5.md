<h1>Ejercicio 5</h1>
<p>
Sos el flamante dueño de un telefono satelital, y se lo ofreces a tus <strong>n</strong> amigos para que lo lleven con
ellos cuando salgan de vacaciones el proximo verano. Lamentablemente cada uno de ellos ira a un lugar
diferente y en algunos casos, los periodos de viaje se superponen. Por lo tanto es imposible prestarle el
telefono a todos, pero quisieras prestarselo al mayor numero de amigos posible.<br>
Suponiendo que conoces los dias de partida y regreso (pi y ri respectivamente) de cada uno de tus amigos,
¿cual es el criterio para determinar, en un momento dado, a quien conviene prestarle el equipo?<br>
Tener en cuenta que cuando alguien lo devuelve, recien a partir del dia siguiente puede usarlo otro.<br> 
Escribir un algoritmo voraz que solucione el problema.
</p>

<h3>Problema de Seleccion de Actividades</h3>
<p>
Este problema prensenta el esquema <strong>GREEDY-ACTIVITY-SELECTOR</strong> del libro 
de bibliografia complementaria referido por la catedra <strong>Cormen, Leiserson, Rivest & Stein. Introduction to Algorithms</strong>
pagina 418
<br>

Donde podemos identificar que la cantidad de amigos <strong>n</strong> son las actividades que deben usar un recurso <strong>Telefono</strong> que solo puede ser usado por una
actividad/amigo en cada instante.
</p>
<h4>Recordemos entonces que:</h4>
<ol>
    <li>
        Cada activdad tiene asociado un instante de comienzo <strong><em>S<sub>i</sub></em></strong> y un instante de finalizacion <strong><em>F<sub>i</sub></em></strong> tales que <strong><em>S<sub>i</sub> ≤ F<sub>i</sub></em></strong>
        de forma que la actividad <strong><em>i</em></strong>, si se realiza, debe hacerse durante <strong><em>[S<sub>i</sub>, F<sub>i</sub>)</em></strong>
    </li>
    <li>
        Dos actividades <strong><em>i, j</em></strong> se dicen compatibles si los intervalos <strong><em>[S<sub>i</sub>, F<sub>i</sub>)</em></strong> y <strong><em>[S<sub>j</sub>, F<sub>j</sub>)</em></strong> no se superponen<br>  
        (i.e.  <strong><em>F<sub>j</sub> ≤ S<sub>i</sub> v F<sub>i</sub> ≤ S<sub>j</sub></em></strong>)
    </li>
    <li>
        El problema de Seleccion de Actividades consiste en seleccionar un conjunto de actividades mutuamente compatibles que tenga cardinal maximo
    </li>
</ol>

<p>
    Definimos los arreglos S y F, donde S contiene las fechas de partida y F las fechas de regreso. Ambos arreglos indexan a los amigos, es decir, (S[1], F[1]) representa las fechas del primer amigo, (S[2], F[2]) las del segundo amigo y así sucesivamente.
</p>
<p>Notar que es precondicion ordenar las fechas de manera ascendente</p>

<h6>{ PRE: ∀ i ∈  1..n: S[i] ≤ F[i] & ∀ i ∈  1..n-1 : F[i] ≤ F[i+1] }</h6>

```pascal
fun cell_friends_selector(S, F : array[1..n] of Nat) ret m : Nat
    var i, j : Nat 
    A := {1}  {- Al menos un amigo debera usar el recurso -}
    j := 1 
    for i := 2 to n do 
        if S[i] > F[j] then A := A U {i} 
                            j := i 
        fi 
    od 
    m := length(A)
end fun 
```
<h6>{ POST: m es solución óptima del problema de la selección de amigos}</h6>

<p>Segun el libro el coste temporal es <strong><em>ө(n)</em></strong><br>
    o bien <strong><em>ө(n*log(n))</em></strong> si se tiene en cuenta ordenar los arreglos antes</p>
