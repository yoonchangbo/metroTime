//
// Created by 이창보 on 2022/12/05.
//

#include "station.h"
#include "string.h"

#ifndef YOONCHANG_SHORTESTROUTETABLE_H
#define YOONCHANG_SHORTESTROUTETABLE_H

#endif //YOONCHANG_SHORTESTROUTETABLE_H

int shortestRouteTable[30][30];
int INF = 100000000;

void initialTable(){
    for(int i = 0 ; i < NODE_COUNT ; i++){
        for(int j = 0 ; j < NODE_COUNT ; j++) {
            if(i == j)
                shortestRouteTable[i][j] == 0;
            else shortestRouteTable[i][j] = INF;
        }
    }
}
void makeShortestRouteTable(){
    initialTable();
    for(int i = 0 ; i < NODE_COUNT ; i++){

        //아이디로 역 찾기
        Station* foundStation = findById(i);

        //역 이어진 곳 찾아와서 거리 배열에 넣기
        for(int j = 0 ; foundStation->stationAndLength[j] != NULL ; j++){
            
            struct station *pStation = foundStation->stationAndLength[j]->station;
            int stationId = findIdByStation(pStation);
            if(stationId == -1) return;
            shortestRouteTable[i][stationId] = foundStation->stationAndLength[j] -> time;
        }
    }
}

void tableInit(){
    makeShortestRouteTable();
}