//
// Created by 이창보 on 2022/12/05.
//

#include "station.h"
#include "string.h"

#ifndef YOONCHANG_SHORTESTROUTETABLE_H
#define YOONCHANG_SHORTESTROUTETABLE_H

#endif //YOONCHANG_SHORTESTROUTETABLE_H

int shortestRouteTable[30][30];

void makeShortestRouteTable(){
    for(int i = 0 ; i < NODE_COUNT ; i++){

        //아이디로 역 찾기
        Station* foundStation = findById(i);

        //찾은 역 이어진 곳 다 찾고 복사
        struct StationAndLength* pLength[4];
        strcpy(pLength, foundStation -> stationAndLength);


        //역 이어진 곳 찾아와서 거리 배열에 넣기
        for(int j = 0 ; pLength[j] != NULL ; j++){
            
            struct station *pStation = pLength[j]->station;
            int stationId = findIdByStation(pStation);
            shortestRouteTable[i][stationId] = pLength[j] -> time;
        }
    }
}

void TableInit(){
    makeShortestRouteTable();
}