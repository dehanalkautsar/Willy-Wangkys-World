#include "map.h"

int main() {
  Map M1;
  makeMap(&M1, 10, 10, 1);
  printMap(M1);
  return 0;
}