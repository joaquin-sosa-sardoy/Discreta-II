#include "APIG24.h"
static u32 get_delta(Grafo g){
    //TO DO
    return 0;
}
/* lee un grafo desde
standard input en el formato indicado en la última sección, lo carga en la estructura, colorea todos los vertices
con el color 0, y devuelve un puntero a la estructura.
En caso de error, la función devolverá un puntero a NULL */

Grafo ConstruirGrafo(){
    char Fchar;
    u32 aristas = 0u;
    u32 grado = 0u;
    u32 vertexs = 0u;
    u32 aux;
    u32 r ;
    u32 l ; 

    Grafo g = malloc(sizeof(GrafoSt));
    
    if(g == NULL){
        return NULL;
    }
    //lee hasta que la primera letra es p 
    while (fscanf(stdin, "%c", &Fchar) != EOF && Fchar != 'p') {
        while (fscanf(stdin, "%c", &Fchar) != EOF && Fchar != '\n');
    }
    // lee cantidad de vertices y aristas
    aux = fscanf(stdin, "%*s %u %u\n", &vertexs, &aristas);
    if (aux != 2) {
        return -1;
    }
    g->delta = 0 ;
    g->vertex_num = vertexs ;
    g->edges_num = aristas ;
    
    while (fscanf(stdin, "%c", &Fchar) != EOF && Fchar) {
        while (fscanf(stdin, "%c", &Fchar) != EOF && Fchar != '\n');
        if(Fchar == 'c'){
            aux = fscanf(stdin, "%u %u/n", &l, &r);
            if(aux != 2){
                return -1 ;
            }
            list_append( g->vertexes[l]->vecinos, r) ; 
        }
    }
    g->delta = get_delta(g); // calcula delta de g
    // coloreo
    for(unsigned int i=0u; i<vertexs; i++){
        g->vertexes[i]->color = 0;
    }
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
    if(i < G->vertex_num){
        return G->vertexes[i]->color ;
    } else {
        return 4294967295;
    }
}
u32 Vecino(u32 j,u32 i,Grafo G){
    if( i >= G->vertex_num || (i < G->vertex_num && j >= Grado(i,G))){
        return 4294967295 ; //2^32 -1 
    } else if (i < G->vertex_num && j < Grado(i, G)){
        return j ; 
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
    u32 n = G->vertex_num;
    
    for(unsigned int i = 0; i < n ; i++){
        G->vertexes[i]->color = Color[i];
    }

}