#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdlib.h>
#include "boolean.h"

#define numVertex(V) V->numVertex
#define firstEdge(V) V->firstEdge
#define nextVertex(V) V->nextVertex
#define source(E) E->source
#define dest(E) E->dest
#define sNextEdge(E) E->sNextEdge
#define dNextEdge(E) E->dNextEdge
#define firstSource(G) G.firstSource
#define firstDest(G) G.firstDest


typedef struct elmtVertex *adrVertex;
typedef struct elmtEdge *adrEdge;

typedef struct {
    int numVertex;
    adrEdge firstEdge;
    adrVertex nextVertex;
}elmtVertex;

typedef struct {
    int source;
    int dest;
    adrEdge sNextEdge;
    adrEdge dNextEdge;
}elmtEdge;

typedef struct {
    adrVertex firstSource;
    adrVertex firstDest;
}graph;

adrVertex createVertex(int nomor);
graph createGraph();
adrEdge createEdge(int asal, int tujuan);
adrVertex sourceVertex(int x, graph G);
adrVertex destinationVertex(int x, graph G);
void addedge(graph G, int destionaon, int source);

#endif // GRAPH_H_INCLUDED
