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


int findShortestRoute(){
    int min = INF;
    int index;
    for(int i = 0 ; i < NODE_COUNT ; i++){
        if(distence[i] < min && !isChecked[i]){
            min = distence[i];
            index = i;
        }
    }
    return index;
}

int dijkstraLogic(int start){
    isUsedBefore[start] = true; //전에 사용이 되었다!

    for(int i = 0 ; i < NODE_COUNT ; i++){
        distence[i] = shortestRouteTable[start][i];
    }
    isChecked[start] = true;
    for(int i = 0 ; i < NODE_COUNT -2 ; i++){
        int current = findShortestRoute();
        isChecked[current] = true;
        for(int j = 0 ; j < NODE_COUNT - 2; j++){
            if(!isChecked[j]){
                if(distence[j] + shortestRouteTable[start][j] < distence[j]){
                    distence[j] = distence[j] + shortestRouteTable[start][j];
                }
            }
        }
    }
    //찾았던거 다시 최단경로로 넣어서 캐싱
    for(int i = 0 ; i < NODE_COUNT ; i++){
        shortestRouteTable[start][i] = distence[i];
    }
}


int dijnstraService(int start, int end){
    if(isUsedBefore[start]) return shortestRouteTable[start][end];
    if(isUsedBefore[end]) return shortestRouteTable[start][end];
    else dijkstraLogic(start);

    return shortestRouteTable[start][end];
}
