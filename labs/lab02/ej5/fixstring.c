#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    /* copiá acá la implementación que hiciste en el ejercicio 0 */
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    /*
     * COMPLETAR
     *
     */
}


