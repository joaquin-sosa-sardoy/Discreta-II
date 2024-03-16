#include "APIG24.h"
/* To do: implementar funciones de APIG24.h"*/

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


/* lee un grafo desde
standard input en el formato indicado en la última sección, lo carga en la estructura, colorea todos los vertices
con el color 0, y devuelve un puntero a la estructura.
En caso de error, la función devolverá un puntero a NULL */

Grafo ConstruirGrafo(){
    Grafo g = malloc(sizeof(GrafoSt));
    g->vertexes= list_init() ;

}

void DestruirGrafo(Grafo G){
    if( G != NULL){
        G->vertexes = list_destroy(G->vertexes);
        free(G);
    }
}

u32 NumeroDeVertices(Grafo G){
    return G->vertex_num ;
}
u32 NumeroDeLados(Grafo G){
    return G->edges_num ;
}
u32 Delta(Grafo G){
    return G->delta ;
}

u32 Grado(u32 i,Grafo G){
    return G->vertexes[i]->grado ;
}
color Color(u32 i,Grafo G){
    return G->vertexes[i]->color ;
}
u32 Vecino(u32 j,u32 i,Grafo G){
    if( i >= G->vertex_num || (i < G->vertex_num && j >= Grado(i,G))){
        return 4294967295 ; //2^32 -1 
    } else if (i < G->vertex_num && j < Grado(i, G)){
        return j ; //G->vertexes[i]->vecinos[j];
    }
     
}

void AsignarColor(color x,u32 i,Grafo  G){
    if(i < G->vertex_num){
        G->vertexes[i]->color = x ;
    }
}
void ExtraerColores(Grafo G,color* Color){
    for (u32 i = 0 ; i < G->vertex_num; i+=1){
        Color[i] = G->vertexes[i]->color ;
    }
}
void ImportarColores(color* Color,Grafo  G){

}