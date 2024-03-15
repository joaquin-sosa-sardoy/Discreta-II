#include"EstructuraGrafo24.h"

// este .h es preliminar, supuestamente se va a subir una copia en el aula virtual


typedef struct Grafo *GrafoSt ;
//Funciones De Construcción/Destrucción del grafo
Grafo ConstruirGrafo();
void DestruirGrafo(Grafo G);

// Funciones para extraer informaci ́on de datos del grafo O(1)
u32 NumeroDeVertices(Grafo G);
u32 NumeroDeLados(Grafo G);
u32 Delta(Grafo G);

//Funciones para extraer información de los vertices O(1)
u32 Grado(u32 i,Grafo G);
color Color(u32 i,Grafo G);
u32 Vecino(u32 j,u32 i,Grafo G);

// Funciones para asignar colores
void AsignarColor(color x,u32 i,Grafo G);

void ExtraerColores(Grafo G,color* Color);

void ImportarColores(color* Color,Grafo G);