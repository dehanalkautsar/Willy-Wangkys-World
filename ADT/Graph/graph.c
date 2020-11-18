#include "graph.h"
#include <stdlib.h>

adrVertex createVertex(int nomor){
    elmtVertex* P;
    elmtVertex V;
    P = (elmtVertex*) malloc (sizeof(elmtVertex));
    *P = V;
    numVertex(P) = nomor;
    firstEdge(P) = NULL;
    nextVertex(P) = NULL;
    return P;
}


graph createGraph(){
    /**graph G;
    adrVertex P;            BELUM, disesuaikan sesuai kebutuhan program

    //source
    P = createVertex(1);
    firstSource(G) = P;
    P = createVertex(10);
    nextVertex(firstSource(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstSource(G))) = P;

    //destination
    P = createVertex(1);
    firstDest(G) = P;
    P = createVertex(10);
    nextVertex(firstDest(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstDest(G))) = P;
    P = createVertex(21);
    nextVertex(nextVertex(nextVertex(firstDest(G)))) = P;

    return G;**/
}

adrEdge createEdge(int asal, int tujuan){
    elmtEdge* P;
    elmtEdge E;
    P = (elmtEdge*) malloc (sizeof(elmtEdge));
    *P = E;
    source(P) = asal;
    dest(P) = tujuan;
    sNextEdge(P) = NULL;
    dNextEdge(P) = NULL;
    return P;
}

adrVertex sourceVertex(int x, graph G){
    elmtVertex* P = firstSource(G);
    boolean found = false;
    while (P!=NULL && !found){
        if (numVertex(P) == x && !found){
            found = true;
        }
        else {
            P = nextVertex(P);
        }
    }
    return P;
}

adrVertex destinationVertex(int x, graph G){
    elmtVertex* P = firstDest(G);
    boolean found = false;
    while (P!=NULL && !found){
        if (numVertex(P) == x && !found){
            found = true;
        }
        else {
            P = nextVertex(P);
        }
    }
    return P;
}

void addedge(graph G, int asal, int tujuan){
    elmtVertex* P;
    elmtVertex* Q;
    P = firstSource(G);
    elmtEdge* E;
    E = createEdge(asal, tujuan);
    P = sourceVertex(asal, G);
    Q = destinationVertex(tujuan, G);
    if(P != NULL && Q != NULL){
        if(firstEdge(P) == NULL && firstEdge(Q) == NULL){
            firstEdge(P) = E;
            firstEdge(Q) = E;
            /**cout<< "SE: "<< source(E)<< " || ";
            cout<< "DE: "<< dest(E)<< endl;**/
        }
        else {
            sNextEdge(E) = firstEdge(P);
            firstEdge(P) = sNextEdge(E);
            dNextEdge(E) = firstEdge(Q);
            firstEdge(Q) = dNextEdge(E);
            /**cout<< "SE: "<< source(E)<< " || ";
            cout<< "DE: "<< dest(E)<< endl;**/
        }
    }
}
