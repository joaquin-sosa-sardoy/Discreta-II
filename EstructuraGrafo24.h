#ifndef _ESTRUCTURAGRAFO24_
#define _ESTRUCTURAGRAFO24_
#include <stdio.h>
#include <stdlib.h>             /* dynamic memory management*/
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>

typedef int u32 ;
typedef u32 color ;

typedef struct s_vlist *vertex_list ; 

struct s_vertex{
    u32 grado ;
    color color ;
};

struct s_vlist {
    struct s_vertex **vecinos; 
    u32 length;
}; 

struct GrafoSt {
    vertex_list *vertex; 
    u32 vertex_num ;
    u32 edges_num ;
};

/* TO DO:  agregar funciones para manipular lista con arreglos dinamicos*/
#endif