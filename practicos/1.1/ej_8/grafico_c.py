import matplotlib.pyplot as plt

# Coordenadas de los puntos
x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
y = [2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7]

# Crear la figura y el eje
fig, ax = plt.subplots()

# Graficar los puntos
ax.scatter(x, y)

# Etiquetas de los ejes
ax.set_xlabel('n')
ax.set_ylabel('ops')
ax.set_xticks(range(1, 13))
ax.set_yticks(range(1, 6))

# Título del gráfico
ax.set_title('Inciso d')

# Guardar el gráfico como imagen
plt.savefig('grafico_c.png')
