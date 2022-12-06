#include "shortestRouteTable.h"

int main() {
    stationInit();
    tableInit();

    for(int i = 0 ; i < NODE_COUNT ; i++, puts(""))
        for(int j = 0 ; j < NODE_COUNT ; j++)
            printf("%d ",shortestRouteTable[i][j]);

    return 0;
}
