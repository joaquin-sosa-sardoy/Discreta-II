#ifndef _ESTRUCTURAGRAFO24_
#define _ESTRUCTURAGRAFO24_
#include <stdio.h>
#include <stdlib.h>             /* dynamic memory management*/
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>

typedef unsigned int u32 ;
typedef u32 color ;

typedef struct s_list *list ;
typedef struct s_vertex *vertex ;

struct s_list {
    u32 *chunk; //points to an array with the actual list elements
    u32 length; //number of elements in the list
    u32 allocd; //how much memory has been alloc´d to the list
}; 

struct s_vertex{
    u32 grado ; //d(v)
    color color ; //c(v)
    list vecinos ; //list with the number of neigbouring vertexes
};

struct GrafoSt {
    vertex *vertexes; //array of all the vertexes
    u32 vertex_num ; //total number of vertexes
    u32 edges_num ; //total number of edges
};

/* TO DO:  agregar funciones para manipular lista con arreglos dinamicos*/
#endif