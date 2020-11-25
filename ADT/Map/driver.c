#include "map.h"

int main()
{
    Map M1;
    makeMap(&M1, 10, 10, 1);
    updateMap(&M1, 4, 4, 'P');
    printMap(M1);
    return 0;
}