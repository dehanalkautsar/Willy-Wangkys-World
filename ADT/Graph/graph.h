#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdlib.h>
#include "boolean.h"
#include "../Map/map.h"

typedef elmtVertex *adrVertex;
typedef elmtEdge *adrEdge;

typedef struct Vertex{
    int numVertex;
    Map Wahana;
    adrEdge firstEdge;
    adrVertex nextVertex;
}elmtVertex;

typedef struct Edge{
    int source;
    int dest;
    adrEdge sNextEdge;
    adrEdge dNextEdge;
}elmtEdge;

typedef struct {
    adrVertex firstSource;
    adrVertex firstDest;
}graph;
#define NilG NULL

#define numVertex(V) V->numVertex
#define firstEdge(V) V->firstEdge
#define MapWahana(V) V->Wahana
#define nextVertex(V) V->nextVertex
#define source(E) E->source
#define dest(E) E->dest
#define sNextEdge(E) E->sNextEdge
#define dNextEdge(E) E->dNextEdge
#define firstSource(G) G.firstSource
#define firstDest(G) G.firstDest

adrVertex createVertex(int nomor, Map Wahana);
graph createGraph(Map M1, Map M2, Map M3, Map M4);
adrEdge createEdge(int asal, int tujuan);
adrVertex sourceVertex(int x, graph G);
adrVertex destinationVertex(int x, graph G);
void addedge(graph G, int asal, int tujuan);

void PrintSourceDest(adrVertex P);

// > < ^ v

#endif // GRAPH_H_INCLUDED
