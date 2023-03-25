#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

/* 
 * Tamaño maximo para el tablero de juego es 10x10
 * Se puede modificar el valor de MAX_SIZE para cambiar
 * el tamaño maximo del tablero de juego
 * */ 
#define MAX_SIZE 10

/*
 * La funcion charger_int() lee un entero desde teclado
 * y lo retorna. 
 * */

int charger_int()
{
	int n;
	printf("Establezer el tablero de juego\n");
	printf("Ingrese un entero mayor que 1 y menor que 11: ");
	int scanf_result = scanf("%d", &n);
	if (scanf_result <= 0) {
		printf("Error al leer un número desde teclado\n");
		exit(EXIT_FAILURE);
	}
	return n;
}

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[MAX_SIZE][MAX_SIZE], int len)
{
    int cell = 0;

    print_sep(len);
    for (int row = 0; row < len; ++row) {
        for (int column = 0; column < len; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(len);
    }
}

/* Funcion get_winner
 * 
 * Que hace? Determina el ganador en el tablero de juego 
 *
 * Como lo hace? Recorre el tablero de juego con un ciclo 
 * while y un ciclo while anidado. En cada iteracion del ciclo
 * verifica si hay una fila, columna o diagonal con el mismo 
 * caracter. Si hay una fila, columna o diagonal con el mismo 
 * caracter, entonces hay un ganador y devuelve el caracter que
 * gano, si no hay ganador devuelve '-'.
 *
 * Parametros: 
 * board: Tablero de juego de tamaño len x len
 *
 * Return: Caracter que gano o '-' si no hay ganador
 *
 * */

char get_winner(char board[MAX_SIZE][MAX_SIZE], int len)
{
	/* winner es variable de retorno, en principio asumimos que no hay ganador */
	char winner = '-';

	/* r_x variable booleana para recordar filas con mismo caracter */
	bool r_x;
	/* r_y variable booleana para recordar columnas con mismo caracter */
	bool r_y;
	/* r_d1 variable booleana para recordar diagonal 1 con mismo caracter */
	bool r_d1;
	/* r_d2 variable booleana para recordar diagonal 2 con mismo caracter */
	bool r_d2;

	/* contador para ciclo while anidado */
	int j; 

	/* contador para diagonal 2 */
	int n = len -1; 
	
	/* contador para ciclo while */
	int i = 0; 

	/* ciclo while para recorrer filas mientras no haya ganador */
	while(i < len && winner == '-' )
	{	
		/* reiniciamos variables booleanas y contador para while anidado */
		r_d1 = true;
		r_d2 = true;
		r_x = true;
		r_y = true;
		j = 0;
		/* ciclo while para recorrer columnas hasta len -2 ya que indexamos en j+1 */
		while(j < len -1)
		{
			/* verificamos si hay una fila, columna o diagonal con el mismo caracter */
			r_x = r_x && (board[i][j] == board[i][j+1]);
			r_y = r_y && (board[j][i] == board[j+1][i]);
			r_d1 = r_d1 && (board[j][j] == board[j+1][j+1]);
			r_d2 = r_d2 && (board[j][n] == board[j+1][n-1]);
			/* incrementamos contador */
			j = j + 1;
			/* decrementamos contador para diagonal 2 */
			n = n - 1;
		}
		/* verificamos si hay ganador y asignamos el caracter que gano */
		if (r_x)
		{
			winner = board[i][0];
		} 
		else if (r_y)
		{
			winner = board[0][i];
		}
		else if (r_d1)
		{
			winner = board[0][0];
		}
		else if (r_d2)
		{
			winner = board[0][len-1];
		}
		/* incrementamos contador */
		i = i + 1;
	}
    return winner;
}

/* Procedimiento init_array
 *
 * Que hace? Inicializa el tablero de juego con el caracter '-'.
 *
 * Como lo hace? declara un puntero al primer elemento del tablero
 * y recorre el tablero con un ciclo while asignando el caracter
 * '-' a cada elemento.
 *
 * Parametros:
 * board: Tablero de juego de tamaño len x len
 *
 * Despues de la ejecucion del procedimiento, el tablero de juego
 * de tamaño len x len debe estar inicializado con
 * el caracter '-'.
 * 
 * */

void init_array(char board[MAX_SIZE][MAX_SIZE], int len)
{	
	/* contador para ciclo while */
	int i = 0;
	while (i < len){
		int j = 0;
		while (j < len){
			board[i][j] = '-';
			j = j + 1;
		}
		/* incrementamos contador */
		i = i + 1;
	}
}

/* Funcion has_free_cell
 * 
 * Que hace? Determina si hay una celda libre en el tablero de juego
 *
 * Como lo hace? declara un puntero al primer elemento del tablero
 * y recorre el tablero con un ciclo while. En cada iteracion del
 * ciclo verifica si el elemento es igual al caracter '-'. Si el
 * elemento es igual al caracter '-' entonces hay una celda libre
 * y devuelve true, si no hay una celda libre devuelve false.
 *
 * Parametros:
 * board: Tablero de juego de tamaño len x len
 *
 * Return: true si hay una celda libre, false si no hay una celda libre
 *
 * */

bool has_free_cell(char board[MAX_SIZE][MAX_SIZE], int len)
{
	/* free_cell es variable de retorno, en principio asumimos que no hay celda libre */
    bool free_cell=false;
	/* tratamos a la matriz como un arreglo unidimensional para evitar utilizar ciclo anidado */
	/* puntero al primer elemento del tablero */
	char *p = &board[0][0];
	/* contador para ciclo while */
	int i = 0;
	/* mientras no se haya recorrido todo el tablero y no haya una celda libre */
	while (i < len*len && !free_cell){
		/* verificamos si hay una celda libre */
		free_cell = (*(p + i) == '-');
		/* incrementamos contador */
		i = i + 1;
	}
	/* retornamos variable de retorno */
    return free_cell;
}

int main(void)
{
    printf("TicTacToe NxN =D\n");
	/* declaracion del tablero de juego */
	int len = charger_int();
	/* verificamos que el tamaño del tablero sea valido */
	if (len > MAX_SIZE){
		printf("El tablero es muy grande :( \n");
		exit(EXIT_FAILURE);
	}
	if (len < 2){
		printf("El tablero es muy pequeño :( \n");
		exit(EXIT_FAILURE);
	}
	/* calculamos el numero maximo de celdas */
	int cell_max = len * len - 1;
	/* declaracion del tablero de juego */
    char board[MAX_SIZE][MAX_SIZE];
	/* inicializamos el tablero de juego */
	init_array(board, len);
	/* variables para controlar el turno y el ganador */
    char turn = 'X';
    char winner = '-';
    int cell = 0;
	/* ciclo while para jugar hasta que haya un ganador o no haya celdas libres */
    while (winner == '-' && has_free_cell(board, len)){
		/* imprimimos el tablero de juego */
        print_board(board, len);
		/* pedimos al usuario que ingrese una celda */
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               cell_max);
		/* leemos la celda ingresada por el usuario */
        int scanf_result = scanf("%d", &cell);
		/* verificamos que la lectura sea correcta */
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
		/* verificamos que la celda ingresada sea valida */
        if (cell >= 0 && cell <= cell_max) {
			/* calculamos la fila y la columna de la celda */
            int row = cell / len;
            int colum = cell % len;
			/* verificamos que la celda este libre */
            if (board[row][colum] == '-') {
				/* asignamos el caracter del turno a la celda */
                board[row][colum] = turn;
				/* cambiamos el turno */
                turn = turn == 'X' ? 'O' : 'X';
				/* verificamos si hay un ganador */
                winner = get_winner(board, len);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
	/* imprimimos el tablero de juego */
    print_board(board, len);
	/* imprimimos el ganador */
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
