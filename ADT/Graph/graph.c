#include "graph.h"
#include <stdlib.h>


adrVertex createVertex(int nomor, Map Wahana){
    elmtVertex* P;
    elmtVertex V;
    P = (elmtVertex*) malloc (sizeof(elmtVertex));
    *P = V;
    numVertex(P) = nomor;
    MapWahana(P) = Wahana;
    firstEdge(P) = NULL;
    nextVertex(P) = NULL;
    return P;
}


graph createGraph(Map M1, Map M2, Map M3, Map M4){
    graph G;
    adrVertex P;
    adrVertex Q;
    Q = firstSource(G);
    Q = nextVertex(Q);

    //Source
    P = createVertex(1,M1);
    firstSource(G) = P;
    P = createVertex(2,M2);
    nextVertex(firstSource(G)) = P;
    P = createVertex(3,M3);
    nextVertex(nextVertex(firstSource(G))) = P;
    P = createVertex(4,M4);
    nextVertex(nextVertex(nextVertex(firstSource(G)))) = P;
    
    //Destination
    P = createVertex(1,M1);
    firstDest(G) = P;
    P = createVertex(2,M2);
    nextVertex(firstDest(G)) = P;
    P = createVertex(3,M3);
    nextVertex(nextVertex(firstDest(G))) = P;
    P = createVertex(4,M4);
    nextVertex(nextVertex(nextVertex(firstDest(G)))) = P;

    //Create Edge

    addedge(G, 1,2);
    addedge(G, 2,1);

    addedge(G, 2,3);
    addedge(G, 3,2);

    addedge(G, 3,4);
    addedge(G, 4,3);

    addedge(G, 1,4);
    addedge(G, 4,1);
    

    return G;

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

void PrintSourceDest(adrVertex P){


}


