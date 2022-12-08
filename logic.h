//
// Created by 이창보 on 2022/12/08.
//
#include "init.h"
#include "showStations.h"

#ifndef YOONCHANG_LOGIC_H
#define YOONCHANG_LOGIC_H

#endif //YOONCHANG_LOGIC_H


int logic(){
    while(1) {
        printf("\n1 : 지하철역 보기\n2 : 최단경로 조회하기\n3 : 지금의 최단경로표 보기\n4 : 서비스 종료\n");
        int chooseNumber;
        printf("입력 : ");
        scanf("%d", &chooseNumber);
        switch (chooseNumber) {


            case 4:
                return 0;

            case 3: {
                for (int i = 0; i < NODE_COUNT; i++, puts(""))
                    for (int j = 0; j < NODE_COUNT; j++)
                        printf("%d ", shortestRouteTable[i][j]);
                continue;
            }

            case 2: {
                printf("역 두개를 입력해주세요\n");
                printf("입력 : ");
                scanf("%s %s", start, end);
                int time = dijnstraService(start, end);
                printf("%d분 걸립니다!", time);
                continue;
            }

            case 1: {
                printf("\n\n\n\n\n0 : 모든 역 보기\n1 : 1호선 보기\n2 : 2호선 보기\n3 : 3호선 보기\n4 : 4호선 보기\n");
                printf("입력 : ");
                scanf("%d", &chooseNumber);
                switch (chooseNumber) {
                    case 0:
                        printAll();
                    case 1:
                        print1Stations();
                    case 2:
                        print2Stations();
                    case 3:
                        print3Stations();
                    case 4:
                        print4Stations();
                }
            }
        }
    }
}