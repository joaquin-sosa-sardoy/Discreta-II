/* ESTO NO SE ENTREGA */
//To do : construir test para ver funcionalidad

#include "APIG24.h"
#include"EstructuraGrafo24.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define DGB(a) printf(#a);printf(" = %s\n", a)

//programa para testear

int main( void ){
    //Esta parte armaria el grafo que este en un archivo test.txt.
    //para cuando quieran testear, creen el archivo y copien el ejemplo del enunciado.

    close(0);
    int fd = open("test.txt" , O_RDONLY);
    Grafo g = ConstruirGrafo();

    //Esta parte printea por pantalla los resultados de las funciones sobre el grafo.
    //Hay que confirmar que esten bien a mano

    DGB(NumeroDeVertices(g));
    DGB(NumeroDeLados(g));
    DGB(Delta(g));

    //Esto testea las funciones de los vertices y la asignacion de colores de a uno
    //Para cada vertice en orden printea si grado, color y vecinos 
    for(int i = 0; i<NumeroDeVertices(g); ++i){
        DGB(Grado(i,g));
        AsignarColor(i,i,g);
        DGB(Color(i,g));
        if(Color(i,g)!=i){
            printf("ERROR: NO SE ESTAN ASIGNANDO/LEYENDO BIEN LOS COLORES\n");
        }
        for(int j = 0; j<Grado(i,g); ++j){
            DGB(Vecino(j,i,g));
        }
    }

    //Aca testeamos importar y extraer colores
    int n = NumeroDeVertices(g);
    color ctestout[n], ctestin[n];
    for(int i = 0; i<n; ++i){
        ctestin[i] = rand()%100;
    }
    ImportarColores(ctestin, g);
    ExtraerColores(g, ctestout);
    for(int i = 0; i<n; ++i){
        if(ctestin[i]!=ctestout[i]){
            printf("ERROR: NO SE ESTAN IMPORTANDO/EXPORTANDO BIEN LOS COLORES\n");
        }
    }
    return 0;
}
