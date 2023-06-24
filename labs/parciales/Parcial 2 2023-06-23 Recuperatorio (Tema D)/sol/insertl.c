#include <stdlib.h>
#include <stdio.h>

#include "tape.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough parameters\n\n");
        exit(EXIT_FAILURE);
    }
    tape_t t=tape_create();
    printf("[create     ] ");
    tape_dump(t);
    for (int i=0; argv[1][i] != '\0'; i++) {
        printf("[insertl '%c'] ", argv[1][i]);
        t = tape_insertl(t, argv[1][i]);
        tape_dump(t);
    }
    if (argc > 2) {
        for (int i=2; i < argc; i++) {
            printf("\nMoving...\n\n");
            tape_dump(t);
            printf("[rewind] ");
            t = tape_rewind(t);
            tape_dump(t);
            int pos_erase=atoi(argv[i]);
            for (int j=0; j < pos_erase; j++) {
                printf("[step  ] ");
                t = tape_step(t);
                tape_dump(t);
                if (tape_at_stop(t)) {
                    fprintf(stderr, "Can't erase position [%i] due it's out of range\n\n", pos_erase);
                    exit(EXIT_FAILURE);
                }
            }
            printf("[erase ] ");
            t = tape_erase(t);
            tape_dump(t);
        }
    }
    t =tape_destroy(t);
    printf("[END]\n\n");

    return EXIT_SUCCESS;
}
