#ifndef _ESTRUCTURAGRAFO24_
#define _ESTRUCTURAGRAFO24_
#include <stdio.h>
#include <stdlib.h>             /* dynamic memory management*/
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>
#include "Vlist.h"

struct GrafoSt {
    vertex_list *neighbors; 
    u32 vertex_num ;
    u32 side_num ;
};

#endif