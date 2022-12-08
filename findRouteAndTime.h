//
// Created by 이창보 on 2022/12/08.
//

#include <stdbool.h>
#include "shortestRouteTable.h"
#ifndef YOONCHANG_FINDROUTEANDTIME_H
#define YOONCHANG_FINDROUTEANDTIME_H

#endif //YOONCHANG_FINDROUTEANDTIME_H

int shortestRoute[26];
bool isChecked[26];


int findShortestRoute(){
    int min = INF;
    int index;
    for(int i = 0 ; i < NODE_COUNT ; i++){
        if(shortestRoute[i] < min && !isChecked[i]){
            min = shortestRoute[i];
            index = i;
        }
    }
    return index;
}

int dijkstra(int start){
    for(int i = 0 ; i < NODE_COUNT ; i++){
        shortestRoute[i] = shortestRouteTable[start][i];
    }
    isChecked[start] = true;
    for(int i = 0 ; i < NODE_COUNT -2 ; i++){
        int current = findShortestRoute();
        isChecked[current] = true;
        for(int j = 0 ; j < NODE_COUNT - 2; j++){
            if(!isChecked[j]){
                if(shortestRoute[j] + shortestRouteTable[start][j] < shortestRoute[j]){
                    shortestRoute[j] = shortestRoute[j] + shortestRouteTable[start][j];
                }
            }
        }
    }
}
