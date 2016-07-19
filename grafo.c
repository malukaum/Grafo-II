#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct listaVertices{
    int idVertice;
    ListaEstrelas estrela;
    ListaVertices proximo;
};

struct listaArestas{
    int idAresta;
    ListaVertices alfa;
    ListaVertices omega;
    ListaArestas proximo;
};

struct listaEstrelas{
    ListaArestas aresta;
    ListaEstrelas proximo;    
};

struct grafo {
    int numVertices , numArestas ;
    int sementeVertices , sementeArestas ;
    ListaVertices pv ;
    ListaArestas pa ;
};

Grafo GGcriaGrafo(int sementeVertice, int sementeAresta){
    Grafo grafo = (Grafo) malloc(sizeof(Grafo));
    grafo->numArestas=0;
    grafo->numVertices=0;
    grafo->pa=NULL;
    grafo->pv=NULL;
    grafo->sementeArestas=sementeAresta;
    grafo->sementeVertices=sementeVertice;
    return grafo;
};

int GVcriaVertice(Grafo grafo, int idVertice){
    grafo->numVertices++;
    ListaVertices vertice = (ListaVertices) malloc(sizeof(ListaVertices));
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    vertice->idVertice=idVertice;
    vertice->proximo=NULL;
    vertice->estrela=NULL;
    aux=grafo->pv;
    if (grafo->pv==NULL){
        grafo->pv=vertice;
    }else{
        while (aux <> NULL){
            aux=aux->proximo;
        }
        aux->proximo=vertice;
    }
    return grafo->numVertices;
}

int GAcriaAresta(Grafo grafo, int idAresta, int alfa, int omega){
    grafo->numArestas++;
    ListaArestas aresta = (ListaArestas) malloc(sizeof(ListaArestas));
    aresta->alfa=findVertice(alfa);
    aresta->omega=findVertice(omega);
    aresta->idAresta=idAresta;
    aresta->proximo=NULL;
    if (grafo->pa==NULL){
        grafo->pa=aresta;
    }else{
        ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
        aux=grafo->pa;
        while (aux->proximo<>NULL){
            aux=aux->proximo;
        }
        aux->proximo=aresta;
    }
    ListaEstrelas estrela = (ListaEstrelas) malloc(sizeof(ListaEstrelas));
    estrela->proximo=NULL;
    estrela->aresta=aresta;
    if (aresta->alfa->estrela==NULL){
        aresta->alfa->estrela=estrela;
    }else{
        ListaEstrelas auxE = (ListaEstrelas) malloc(sizeof(ListaEstrelas));
        auxE=aresta->alfa->estrela;
        while(auxE->proximo<>NULL){
            auxE=auxE->proximo;
        }
        auxE->proximo=estrela;
    }
    return aresta->idAresta;
}

ListaVertices findVertice(Grafo grafo,int idVertice){
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    aux=grafo->pv;
    while (aux->proximo <> NULL){
        if (aux->idVertice==idVertice){
            return aux;
        }
    }
}

ListaArestas findAresta(Grafo grafo,int idAresta){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pa;
    while (aux->proximo <> NULL){
        if (aux->idAresta==idAresta){
            return aux;
        }
    }
}
//=====================================================
// Função que verifica a existência de um vértice por 
// seu ID
//=====================================================
int GBexisteIdVertice (Grafo grafo, int idVertice){
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    aux=grafo->pv;
    while (aux <> NULL){
        if (aux->idVertice==idVertice){
            return 1;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta por 
// sua ID
//=====================================================
int GBexisteIdAresta (Grafo grafo, int idAresta){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if (aux->idAresta==idAresta){
            return 1;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta 
// direcionada
//=====================================================
int GBexisteArestaDir (Grafo grafo, int x, int y){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if ((aux->alfa->idVertice==x)&&(aux->omega->idVertice==y)){
            return 1;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que verifica a existência de uma aresta não 
// direcionada
//=====================================================
int GBexisteAresta (Grafo grafo, int x, int y){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if (((aux->alfa->idVertice==x)&&(aux->omega->idVertice==y))||
                ((aux->alfa->idVertice==y)&&(aux->omega->idVertice==x))){
            return 1;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que pega a ID de uma aresta direcionada
//=====================================================
int GApegaArestaDir(Grafo grafo, int x, int y){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if ((aux->alfa->idVertice==x)&&(aux->omega->idVertice==y)){
            return aux->idAresta;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que pega a ID de uma aresta não direcionada
//=====================================================
int GApegaAresta(Grafo grafo, int x, int y){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if (((aux->alfa->idVertice==x)&&(aux->omega->idVertice==y))||
                ((aux->alfa->idVertice==y)&&(aux->omega->idVertice==x))){
            return aux->idAresta;
        }
        aux=aux->proximo;
    }
    return 0;
}
//=====================================================
// Função que pega o primeiro vértice
//=====================================================
int GVprimeiroVertice(Grafo grafo){
    if (grafo->pv<>NULL){
        return grafo->pv->idVertice;
    }else return 0;
}
//=====================================================
// Função que pega o próximo vértice
//=====================================================
int GVproximoVertice (Grafo grafo, int idVertice){
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    aux=findVertice(grafo,idVertice);
    if (aux->proximo<>NULL){
        return aux->proximo->idVertice;
    }else return 0;
}
//=====================================================
// Função que pega o ID da primeira aresta
//=====================================================
int GAprimeiraAresta(Grafo grafo){
    if (grafo->pa<>NULL){
        return grafo->pa->idAresta;
    }else return 0;
}
//=====================================================
// Função que pega o ID da próxima aresta
//=====================================================
int GAproximaAresta(Grafo grafo, int idAresta){
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=findAresta(grafo,idAresta);
    if (aux->proximo<>NULL){
        return aux->proximo->idAresta;
    }else return 0;
}
//=====================================================
// Função que pega a número de vértices
//=====================================================
int GInumeroVertices(Grafo grafo){
    return grafo->numVertices;
}
//=====================================================
// Função que retorna o número máximo de vértices que o
// grafo aceita
//=====================================================
int GInumeroVerticesMax(Grafo grafo){
    //a implementar
}
//=====================================================
// Função que pega o número de arestas
//=====================================================
int GInumeroArestas(Grafo grafo){
    return grafo->numArestas;
}
//=====================================================
// Função que pega o número máximo de arestas que o
// grafo suporta
//=====================================================
int GInumeroArestasMax(Grafo grafo){
    //a imlementar
}
//=====================================================
// Função que salva o grafo em um arquivo
//=====================================================
int GBsalvaGrafo(Grafo grafo, char caminho[]){
    int i;
    FILE *arq = fopen(caminho,"w");
    if (arq == NULL){
        fclose(arq);
        return 0;
    }else{
        //a implementar
        fclose(arq);
        return 1;
    }
}
//=====================================================
// Função que pega o grau do vértice
//=====================================================
int GIpegaGrau(Grafo grafo, int vertice){
    int grau=0;
    ListaArestas aux = (ListaArestas) malloc(sizeof(ListaArestas));
    aux=grafo->pv;
    while (aux <> NULL){
        if ((aux->alfa->idVertice==vertice)||(aux->omega->idVertice==vertice)){
            grau++;
            if ((aux->alfa->idVertice==vertice)&&(aux->omega->idVertice==vertice)){
                grau++;
            }
        }
        aux=aux->proximo;
    }
}
//=====================================================
// Função que pega a primeira aresta na estrela do 
// vértice
//=====================================================
ListaArestas GAprimaAresta(Grafo grafo, int vertice){
   ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
   aux=findVertice(vertice);
   return aux->estrela->aresta;
}
//=====================================================
// Função que pega a próxima aresta na estrela do 
// vértice
//=====================================================
ListaArestas GAproxAresta(Grafo grafo, int vertice, int aresta){
   ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
   aux=findVertice(vertice);
   ListaEstrelas auxE = (ListaEstrelas) malloc(sizeof(ListaEstrelas));
   auxE=aux->estrela;
   while (auxE<>NULL){
       if (auxE->aresta->idAresta==aresta){
           return auxE->proximo->aresta;
       }
   }
   return 0;
}
//=====================================================
// Função que pega a primeira aresta na estrela de 
// entrada de um vértice 
//=====================================================
int GAprimaEntrada(Grafo grafo, int vertice){
    for(i=0;i<grafo->NumAre;i++){
        if(grafo->aresta[i].y==vertice)
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que pega a próxima aresta na estrela de 
// entrada de um vértice 
//=====================================================
int GAproxEntrada(Grafo grafo, int vertice, int aresta){
    int i;
    for(i=0;i<grafo->NumAre;i++){
        if((grafo->aresta[i].y==vertice)&&(grafo->aresta[i].id>aresta))
            return grafo->aresta[i].id;
    }
    return 0;
}
//=====================================================
// Função que pega a primeira aresta na estrela de 
// saída de um vértice 
//=====================================================
int GAprimaSaida(Grafo grafo, int vertice){
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    aux=findVertice(vertice);
    return aux->estrela->aresta->idAresta;
}
//=====================================================
// Função que pega a próxima aresta na estrela de 
// saída de um vértice 
//=====================================================
int GAproxSaida(Grafo grafo, int vertice, int aresta){
    ListaVertices aux = (ListaVertices) malloc(sizeof(ListaVertices));
    aux=findVertice(vertice);
    ListaArestas auxA= (ListaArestas) malloc (sizeof(ListaArestas));
    auxA=findAresta(grafo, aresta);
    ListaEstrelas auxE= (ListaEstrelas) malloc (sizeof(ListaEstrelas));
    auxE=aux->estrela;
    while (auxE->aresta<>auxA){
        auxE=auxE->proximo;
    }
    return auxE->proximo->aresta->idAresta;
}
//=====================================================
// Função que diz se a aresta é ou não um laço
//=====================================================
int GBarestaLaco(Grafo grafo, int aresta){
    ListaArestas aux= (ListaArestas) malloc (sizeof(ListaArestas));
    aux=findAresta(grafo, aresta);
    if (aux->alfa==aux->omega){
        return 1;
    }else{
        return 0;
    }
}
//=====================================================
// Função que pega o alfa de uma aresta
//=====================================================
int GValfa(Grafo grafo, int aresta){
    ListaArestas aux= (ListaArestas) malloc (sizeof(ListaArestas));
    aux=findAresta(grafo, aresta);
    return aux->alfa->idVertice; 
}
//=====================================================
// Função que pega o ômega de uma aresta
//=====================================================
int GVomega(Grafo grafo, int aresta){
    ListaArestas aux= (ListaArestas) malloc (sizeof(ListaArestas));
    aux=findAresta(grafo, aresta);
    return aux->omega->idVertice;    
}
//=====================================================
// Função que pega o vértice vizinho na outra ponta da
// aresta
//=====================================================
int GVvizinho(Grafo grafo, int aresta, int vertice){
    ListaArestas aux= (ListaArestas) malloc (sizeof(ListaArestas));
    aux=findAresta(grafo, aresta);
    ListaVertices auxV = (ListaVertices) malloc(sizeof(ListaVertices));
    auxV=findVertice(vertice);
    if (aux->alfa=auxV){
        return aux->alfa->idVertice;
    }else{
        return aux->omega->idVertice;
    }
}