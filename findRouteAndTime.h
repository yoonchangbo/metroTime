//
// Created by 이창보 on 2022/12/08.
//

#include <stdbool.h>
#include "shortestRouteTable.h"
#ifndef YOONCHANG_FINDROUTEANDTIME_H
#define YOONCHANG_FINDROUTEANDTIME_H

#endif //YOONCHANG_FINDROUTEANDTIME_H

int distence[26]; // 다익스트라 알고리즘에서 경로별 최단거리 확인 알고리즘
bool isChecked[26]; // 다익스트라 알고리즘에서 노드가 체크되었는지 확인하는 배열
bool isUsedBefore[26]; // 이 노드에서 예전에 출발 혹은 도착되는데 사용되었는지확인

char routeTable[26][26][300];

void initDijkstra(){
    for(int i = 0 ; i < NODE_COUNT ; i++){
        isChecked[i] = false;
    }
}

int findShortestRoute(){
    int min = INF;
    int index = 0;
    for(int i = 0 ; i < NODE_COUNT ; i++){
        if(distence[i] < min && !isChecked[i]){
            min = distence[i];
            index = i;
        }
    }
    return index;
}

int dijkstraLogic(int startId){
    isUsedBefore[startId] = true; //전에 사용이 되었다!

    for(int i = 0 ; i < NODE_COUNT ; i++){
        distence[i] = shortestRouteTable[startId][i];
    }
    isChecked[startId] = true;
    for(int i = 0 ; i < NODE_COUNT - 2; i++){
        int current = findShortestRoute();
        isChecked[current] = true;
        for(int j = 0 ; j < NODE_COUNT; j++){
            if(!isChecked[j]){
                if(distence[current] + shortestRouteTable[current][j] < distence[j]){
                    distence[j] = distence[current] + shortestRouteTable[current][j];
                }
            }
        }
    }
    //찾았던거 다시 최단경로로 넣어서 캐싱
    for(int i = 0 ; i < NODE_COUNT ; i++){
        shortestRouteTable[startId][i] = distence[i];
    }
}

int dijnstraService(char start[100], char end[100]){
    initDijkstra();
    int startId = findStationIdByStationName(start);
    int endId = findStationIdByStationName(end);

    if(startId == -1 || endId == -1){
        printf("있는 역을 말해주십시오!");
        return 1;
    }

    if(isUsedBefore[startId]) return shortestRouteTable[startId][endId];
    else dijkstraLogic(startId);

    return shortestRouteTable[startId][endId];
}
