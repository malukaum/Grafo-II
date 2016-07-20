#ifndef GRAFO_H
#define GRAFO_H
typedef struct listaArestas *ListaArestas;
typedef struct listaVertices *ListaVertices;
typedef struct listaEstrelas *ListaEstrelas;
typedef struct grafo *Grafo;

ListaVertices findVertice(Grafo grafo,int idVertice);
ListaArestas findAresta(Grafo grafo,int idAresta);
Grafo GGcriaGrafo();
int GVcriaVertice(Grafo grafo, int idVertice);
int GAcriaAresta(Grafo grafo, int idAresta, int alfa, int omega);
Grafo GGcarregaGrafo(char caminho[]);

#endif /* GRAFO_H */