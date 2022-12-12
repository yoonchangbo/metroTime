#include "logic.h"

 int main() {

    init();
    logic();

    for(int i=0;i<NODE_COUNT;i++, puts(""))
        for(int j = 0 ; j < NODE_COUNT ;j++)
            printf("%s ", routeTable[i][j]);

    return 0;
}
