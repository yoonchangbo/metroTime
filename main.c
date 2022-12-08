#include "findRouteAndTime.h"

int main() {

    char start[100];
    char end[100];

    stationInit();
    tableInit();

//    for(int i = 0 ; i < NODE_COUNT ; i++, puts(""))
//        for(int j = 0 ; j < NODE_COUNT ; j++)
//            printf("%d ",shortestRouteTable[i][j]);

    scanf("%s %s", start, end);
    int time = dijnstraService(start, end);

    printf("%d\n\n\n", time);

    for(int i = 0 ; i < NODE_COUNT ; i++, puts(""))
        for(int j = 0 ; j < NODE_COUNT ; j++)
            printf("%d ",shortestRouteTable[i][j]);



    return 0;
}
