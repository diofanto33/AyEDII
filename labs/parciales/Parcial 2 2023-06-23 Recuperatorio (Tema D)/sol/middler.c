#include <stdlib.h>
#include <stdio.h>

#include "tape.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Incorrect number of parameters\n\n");
        exit(EXIT_FAILURE);
    }
    int middle_pos=atoi(argv[2]);
    char *input=argv[1];
    char *to_insert=argv[3];
    tape_t t=tape_create();
    printf("[create     ] ");
    tape_dump(t);
    for (int i=0; input[i] != '\0'; i++) {
        printf("[insertr '%c'] ", input[i]);
        t = tape_insertr(t, input[i]);
        tape_dump(t);
    }
    printf("\nMoving...\n\n");
    tape_dump(t);
    printf("[rewind] ");
    t = tape_rewind(t);
    tape_dump(t);
    for (int j=0; j < middle_pos; j++) {
        printf("[step  ] ");
        t = tape_step(t);
        tape_dump(t);
        if (tape_at_stop(t)) {
            fprintf(stderr, "Can't insert at position [%i] due it's out of range\n\n", middle_pos);
            exit(EXIT_FAILURE);
        }
    }
    printf("\nInserting at middle...\n\n");
    for (int i=0; to_insert[i] != '\0'; i++) {
        printf("[insertr '%c'] ", to_insert[i]);
        t = tape_insertr(t, to_insert[i]);
        tape_dump(t);
    }
    t =tape_destroy(t);
    printf("[END]\n\n");

    return EXIT_SUCCESS;
}
