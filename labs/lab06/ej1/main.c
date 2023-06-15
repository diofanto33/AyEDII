/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void
print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char
*parse_filepath(int argc, char *argv[]) 
{
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2)
	{
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb 
abb_from_file(const char *filepath)
{
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) 
	{
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1)
	{
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size)
	{
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1)
		{
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

abb_elem
user_input(void)
{
    abb_elem in;
    int res = 0;
    printf("Enter element: ");
    res = scanf("%d", &in);
    if(res != 1)
    {
        perror("Error al leer un elemento");
        exit(EXIT_FAILURE);
    }

    return(in);
}

void 
options_board(void)
{
    printf("1 ........ Mostrar árbol por pantalla\n");
    printf("2 ........ Agregar un elemento\n");
    printf("3 ........ Eliminar un elemento\n");
    printf("4 ........ Chequear existencia de elemento\n");
    printf("5 ........ Mostrar longitud del árbol\n");
    printf("6 ........ Mostrar raiz, máximo y mínimo del árbol\n");
    printf("7 ........ Salir\n");
}

int 
main(void)
{
/*
    char *filepath = NULL;

    // parse the filepath given in command line arguments 
    filepath = parse_filepath(argc, argv);

    // parse the file to obtain an abb with the elements 
    abb tree = abb_from_file(filepath);

    //dumping the tree
    abb_dump(tree);
    if (!abb_is_empty(tree))
	{
        printf("\n");
        printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } 
	else
	{
        printf("\nÁrbol vacío\n");
    }

    tree = abb_destroy(tree);
*/ 
    /*
     * Modificar e implementar con un ciclo una interfaz que permita al usuario
     * realizar una de las siguientes operaciones en cada iteración:
     *
     * 1 ........ Mostrar árbol por pantalla
     * 2 ........ Agregar un elemento
     * 3 ........ Eliminar un elemento
     * 4 ........ Chequear existencia de elemento
     * 5 ........ Mostrar longitud del árbol
     * 6 ........ Mostrar raiz, máximo y mínimo del árbol
     * 7 ........ Salir
     *
     * Se debe solicitar un número de entrada para realizar una de las acciones.
     *
     * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
     * elemento a agregar, eliminar o chequear respectivamente.
     *
     * Al salir debe liberarse toda la memoria utilizada.
     *
     */

    abb tree = abb_empty();
    unsigned int option = 0u;
    int res = 0;
    while(option != 7)
    {
        options_board();
        res = scanf("%u", &option);
        if(res != 1)
        {
            perror("Error al leer una opccion");
            exit(EXIT_FAILURE);
        }
        switch (option)
        {
            case 1:
                printf("Arbol: ");
                abb_dump(tree);
                printf("\n");
                break;
            case 2:
                tree = abb_add(tree, user_input());
                break;
            case 3:
                tree = abb_remove(tree, user_input());
                break;
            case 4:
                if(abb_exists(tree, user_input()))
                {
                    printf("El elemento existe\n");
                }
                else
                {
                    printf("El elemento no existe\n");
                }
                break;
            case 5:
                printf("Longitud del arbol: %u\n", abb_length(tree));
                break;
            case 6:
                if(!abb_is_empty(tree))
                {
                    printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                                   abb_min(tree),
                                                                   abb_max(tree));
                }
                else
                {
                    printf("Arbol vacio\n");
                }
                break;
            case 7:
                break;
            default:
                printf("Opcion invalida\n");
                break;
        } 

    }
    tree = abb_destroy(tree);

    return (EXIT_SUCCESS);
}
