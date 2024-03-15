#include <stdio.h>
#include <stdlib.h>             /* dynamic memory management*/
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>
#include "Vlist.h"
/* implementar lista con arreglos dinamicos
lista que contiene los grados y colores de todos los vertices */

struct s_vertex{
    u32 grado ;
    color color ;
};

struct s_vlist {
    struct s_vertex **array; 
    u32 length;
};