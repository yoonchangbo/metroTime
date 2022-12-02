//
// Created by 이창보 on 2022/12/02.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef YOONCHANG_STATION_H
#define YOONCHANG_STATION_H
#endif //YOONCHANG_STATION_H


typedef int Time;

typedef struct StationAndLength SaL;

typedef struct {
    struct StationAndLength* stationAndLength[4];
} Station;

// 자기와 인접한 역과 그 역까지의 거리
typedef struct {
    struct station *station;
    Time time;
} StationAndLength;

void init() {
    /***
     * 부산대 -> 동래
     */
    Station* BusanDae = (Station*) malloc(sizeof(Station)); // 부산대 구조체
    Station* DongLae = (Station*) malloc(sizeof(Station));  // 동래 구조체

    StationAndLength* BusanDaeToDongLae = (StationAndLength*) malloc(sizeof(StationAndLength)); //부산대 -> 동래 가는 길
    StationAndLength* DongLaeToBusanDae = (StationAndLength*) malloc(sizeof(StationAndLength)); //동래 -> 부산대 가는 길

    //부산대 -> 동래
    BusanDaeToDongLae->station = DongLae;
    BusanDaeToDongLae->time = 8;
    BusanDae -> stationAndLength[0] = BusanDaeToDongLae;

    //동래 -> 부산대
    DongLaeToBusanDae->station = BusanDae;
    DongLaeToBusanDae->time = 8;
    DongLae -> stationAndLength[0] = DongLaeToBusanDae;

    /***
     * 동래 -> 영상
     */
    Station* YoungSang = (Station*) malloc(sizeof(Station)); // 영상 구조체

    StationAndLength* DongLaeToYoungSang = (StationAndLength*) malloc(sizeof(StationAndLength)); //동래 -> 영상
    StationAndLength* YoungSangToDongLae = (StationAndLength*) malloc(sizeof(StationAndLength)); //영상 -> 동래

    //동래 -> 영상
    DongLaeToYoungSang->station = YoungSang;
    DongLaeToYoungSang->time = 8;
    DongLae -> stationAndLength[1] = DongLaeToYoungSang;

    // 영산 -> 동래
    YoungSangToDongLae->station = DongLae;
    YoungSangToDongLae->time = 8;
    YoungSang -> stationAndLength[0] = YoungSangToDongLae;


    /***
     * 영상 -> 양정
     */
    Station* YangJeong = (Station*) malloc(sizeof(Station)); //양정 구조체

    StationAndLength* YangJeongToYoungSang = (StationAndLength*) malloc(sizeof(StationAndLength));
    StationAndLength* YoungSangToYangJeong = (StationAndLength*) malloc(sizeof(StationAndLength));

    //영상 -> 양정
    YoungSangToYangJeong->station = YangJeong;
    YoungSangToYangJeong->time = 8;
    YoungSang -> stationAndLength[1] = YoungSangToYangJeong;


    YangJeongToYoungSang->station = YoungSang;
    YangJeongToYoungSang->time = 8;
    YangJeong -> stationAndLength[0] = YangJeongToYoungSang;

    /***
     * 양정 -> 서면
     */
    Station* SeoMyeon = (Station*) malloc(sizeof(Station)); //서면 구조체

    StationAndLength* SeoMyeonToYangJeong = (StationAndLength*) malloc(sizeof(StationAndLength));
    StationAndLength* YoungSangToSeoMyeon = (StationAndLength*) malloc(sizeof(StationAndLength));

    //영상 -> 서면
    YoungSangToSeoMyeon->station = SeoMyeon;
    YoungSangToSeoMyeon->time = 8;
    YoungSang -> stationAndLength[1] = YoungSangToYangJeong;

    //서면 -> 양정
    SeoMyeonToYangJeong->station = YangJeong;
    SeoMyeonToYangJeong->time = 8;
    SeoMyeon -> stationAndLength[0] = SeoMyeonToYangJeong;


    /***
     * 서면 좌천
     */
    Station* JwaCheon = (Station*) malloc(sizeof(Station));

    StationAndLength* JwaCheonToSeoMyeon = (StationAndLength*) malloc(sizeof(StationAndLength));
    StationAndLength* SeoMyeonToJwaCheon = (StationAndLength*) malloc(sizeof(StationAndLength));

    //서면 -> 좌천
    SeoMyeonToJwaCheon->station = JwaCheon;SeoMyeonToJwaCheon->time = 8;
    SeoMyeon -> stationAndLength[1] = SeoMyeonToJwaCheon;

    //좌천 -> 서면
    JwaCheonToSeoMyeon->station = SeoMyeon;
    JwaCheonToSeoMyeon->time = 8;
    JwaCheon -> stationAndLength[0] = JwaCheon;

    /***
     * 좌천 -> 부산역
     */
    Station* BusanYeog = (Station*) malloc(sizeof(Station)); // 부산역 구조체

    StationAndLength* BusanYeogToJwaCheon = (StationAndLength*) malloc(sizeof(StationAndLength));
    StationAndLength* JwaCheonToBusanYeog = (StationAndLength*) malloc(sizeof(StationAndLength));

    JwaCheonToBusanYeog->station = BusanYeog;
    JwaCheonToBusanYeog->time = 8;
    JwaCheon -> stationAndLength[1] = JwaCheonToBusanYeog;

    BusanYeogToJwaCheon->station = SeoMyeon;
    BusanYeogToJwaCheon->time = 8;
    BusanYeog -> stationAndLength[0] = BusanYeogToJwaCheon;
}