#include <stdlib.h>
#include <stdio.h>

#include "tape.h"

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Incorrect number of parameters\n\n");
        exit(EXIT_FAILURE);
    }
    char *input=argv[1];
    tape_t t=tape_create();
    printf("[create     ] ");
    tape_dump(t);
    for (int i=0; input[i] != '\0'; i++) {
        printf("[insertr '%c'] ", input[i]);
        t = tape_insertr(t, input[i]);
        tape_dump(t);
    }
    printf("\nCopying...\n\n");
    printf("[original] ");
    tape_dump(t);
    printf("[copy    ] ");
    tape_t copy=tape_copy(t);
    tape_dump(copy);
    if (argc == 3) { 
        printf("\n\nInserting in copy...\n");
        char *to_insert=argv[2];
        for (int i=0; to_insert[i] != '\0'; i++) {
            printf("[insertr '%c'] ", to_insert[i]);
            copy = tape_insertr(copy, to_insert[i]);
            tape_dump(copy);
        }
        printf("\n\nFinal status...\n");
        printf("[original] ");
        tape_dump(t);
        printf("[copy    ] ");
        tape_dump(copy);
    }
    copy =tape_destroy(copy);
    t =tape_destroy(t);
    printf("[END]\n\n");
    return EXIT_SUCCESS;
}
