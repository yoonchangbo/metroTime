#include "init.h"

 int main() {

    init();

    printf("--------1호선--------\nBusanDae\nDongLae\nYounSan\nYaangJeong\nSeoMyeon\nJwaCheon\nBusan\nSuYeog\n--------2호선--------\nSeogDae\nSeoDong\nNagmin\nDongLae\nMiNam\n--------2호선--------\nDeogCheon\nNamsanJeong\nMiNam\nYounSan\nBaeSan\nSuYeong\n--------2호선--------\nYulRi\nDeogCheon\nMoRa\nSaSang\nNaengJeong\nGaYa\nSeoMyeon\nMunHyeon\nDaeYeon\nGeumLyeonSan\nSuYeog");

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
