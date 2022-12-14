//
// Created by 이창보 on 2022/12/02.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YOONCHANG_STATION_H
#define YOONCHANG_STATION_H
#endif // YOONCHANG_STATION_H

int NODE_COUNT = 23; // 지하철역 개수

typedef int Time;

typedef struct StationAndLength SaL;

typedef struct Station {
    struct StationAndLength *stationAndLength[5];
} Station;

// 자기와 인접한 역과 그 역까지의 거리
typedef struct StationAndLength {
    struct station *station;
    Time time;
} StationAndLength;


char station_name_array[100][13] = {"BusanDae", "DongLae", "YounSan", "YangJeong", "SeoMyeon", "JwaCheon", "BusanYeog",
                                    "SeogDae", "SeoDong", "Nagmin", "MiNam", "DeogCheon", "NamsanJeong", "BaeSan",
                                    "SuYeong", "YulRi", "MoRa", "SaSang", "NaengJeong", "GaYa", "MunHyeon",
                                    "DaeYeon", "GeumLyeonSan"};


Station *Station_Array[23];

void stationInit() {

    /*-----------1호선----------*/

    /**
     * 부산대 <-> 동래
     */
    Station *BusanDae = (Station *) malloc(sizeof(Station)); // 부산대 구조체
    Station_Array[0] = BusanDae;
    Station *DongLae = (Station *) malloc(sizeof(Station));  // 동래 구조체
    Station_Array[1] = DongLae;


    StationAndLength *BusanDaeToDongLae = (StationAndLength *) malloc(sizeof(StationAndLength)); //부산대 -> 동래 가는 길
    StationAndLength *DongLaeToBusanDae = (StationAndLength *) malloc(sizeof(StationAndLength)); //동래 -> 부산대 가는 길

    //부산대 -> 동래
    BusanDaeToDongLae->station = DongLae;
    BusanDaeToDongLae->time = 6;
    BusanDae->stationAndLength[0] = BusanDaeToDongLae;
    BusanDae->stationAndLength[1] = NULL;

    //동래 -> 부산대
    DongLaeToBusanDae->station = BusanDae;
    DongLaeToBusanDae->time = 6;
    DongLae->stationAndLength[0] = DongLaeToBusanDae;

    /**
     * 동래 <-> 연산
     */
    Station *YounSan = (Station *) malloc(sizeof(Station)); // 연산 구조체
    Station_Array[2] = YounSan;

    StationAndLength *DongLaeToYounSan = (StationAndLength *) malloc(sizeof(StationAndLength)); //동래 -> 영상
    StationAndLength *YounSanToDongLae = (StationAndLength *) malloc(sizeof(StationAndLength)); //연산 -> 동래

    //동래 -> 연산
    DongLaeToYounSan->station = YounSan;
    DongLaeToYounSan->time = 4;
    DongLae->stationAndLength[1] = DongLaeToYounSan;

    // 연산 -> 동래
    YounSanToDongLae->station = DongLae;
    YounSanToDongLae->time = 4;
    YounSan->stationAndLength[0] = YounSanToDongLae;

    /**
     * 연산 <-> 양정
     */
    Station *YangJeong = (Station *) malloc(sizeof(Station)); //양정 구조체
    Station_Array[3] = YangJeong;

    StationAndLength *YangJeongToYounSan = (StationAndLength *) malloc(sizeof(StationAndLength));
    StationAndLength *YounSanToYangJeong = (StationAndLength *) malloc(sizeof(StationAndLength));

    //연산 -> 양정
    YounSanToYangJeong->station = YangJeong;
    YounSanToYangJeong->time = 4;
    YounSan->stationAndLength[1] = YounSanToYangJeong;

    YangJeongToYounSan->station = YounSan;
    YangJeongToYounSan->time = 4;
    YangJeong->stationAndLength[0] = YangJeongToYounSan;

    /**
     * 양정 <-> 서면
     */
    Station *SeoMyeon = (Station *) malloc(sizeof(Station)); //서면 구조체
    Station_Array[4] = SeoMyeon;

    StationAndLength *SeoMyeonToYangJeong = (StationAndLength *) malloc(sizeof(StationAndLength));
    StationAndLength *YangJoengToSeoMyeon = (StationAndLength *) malloc(sizeof(StationAndLength));

    //양정 -> 서면
    YangJoengToSeoMyeon->station = SeoMyeon;
    YangJoengToSeoMyeon->time = 3;
    YangJeong->stationAndLength[1] = YangJoengToSeoMyeon;
    YangJeong->stationAndLength[2] = NULL;

    //서면 -> 양정
    SeoMyeonToYangJeong->station = YangJeong;
    SeoMyeonToYangJeong->time = 3;
    SeoMyeon->stationAndLength[0] = SeoMyeonToYangJeong;

    /**
     * 서면 <-> 좌천
     */
    Station *JwaCheon = (Station *) malloc(sizeof(Station));
    Station_Array[5] = JwaCheon;

    StationAndLength *JwaCheonToSeoMyeon = (StationAndLength *) malloc(sizeof(StationAndLength));
    StationAndLength *SeoMyeonToJwaCheon = (StationAndLength *) malloc(sizeof(StationAndLength));

    //서면 -> 좌천
    SeoMyeonToJwaCheon->station = JwaCheon;
    SeoMyeonToJwaCheon->time = 6;
    SeoMyeon->stationAndLength[1] = SeoMyeonToJwaCheon;

    //좌천 -> 서면
    JwaCheonToSeoMyeon->station = SeoMyeon;
    JwaCheonToSeoMyeon->time = 6;
    JwaCheon->stationAndLength[0] = JwaCheonToSeoMyeon;

    /**
     * 좌천 <-> 부산역
     */
    Station *BusanYeog = (Station *) malloc(sizeof(Station)); // 부산역 구조체
    Station_Array[6] = BusanYeog;

    StationAndLength *BusanYeogToJwaCheon = (StationAndLength *) malloc(sizeof(StationAndLength));
    StationAndLength *JwaCheonToBusanYeog = (StationAndLength *) malloc(sizeof(StationAndLength));

    JwaCheonToBusanYeog->station = BusanYeog;
    JwaCheonToBusanYeog->time = 5;
    JwaCheon->stationAndLength[1] = JwaCheonToBusanYeog;
    JwaCheon->stationAndLength[2] = NULL;

    BusanYeogToJwaCheon->station = JwaCheon;
    BusanYeogToJwaCheon->time = 5;
    BusanYeog->stationAndLength[0] = BusanYeogToJwaCheon;
    BusanYeog->stationAndLength[1] = NULL;


    /*-----------4호선----------*/


    /**
     * 석대 <-> 서동
     */
    Station *SeogDae = (Station *) malloc(sizeof(Station)); // 석대 구조체
    Station_Array[7] = SeogDae;
    Station *SeoDong = (Station *) malloc(sizeof(Station)); // 석동 구조체
    Station_Array[8] = SeoDong;

    StationAndLength *SeogDaeToSeoDong = (StationAndLength *) malloc(sizeof(StationAndLength)); // 석대 -> 석동
    StationAndLength *SeoDongToSeogDae = (StationAndLength *) malloc(sizeof(StationAndLength)); // 석동 -> 석대

    //석대 -> 서동
    SeogDaeToSeoDong->station = SeoDong;
    SeogDaeToSeoDong->time = 5;
    SeogDae->stationAndLength[0] = SeogDaeToSeoDong;
    SeogDae->stationAndLength[1] = NULL;
    //서동 -> 석대
    SeoDongToSeogDae->station = SeogDae;
    SeoDongToSeogDae->time = 5;
    SeoDong->stationAndLength[0] = SeoDongToSeogDae;

    /**
     * 서동 -> 낙민
     */
    Station *Nagmin = (Station *) malloc(sizeof(Station)); // 낙민 구조체
    Station_Array[9] = Nagmin;

    StationAndLength *SeoDongToNagmin = (StationAndLength *) malloc(sizeof(StationAndLength)); // 서동 -> 낙민
    StationAndLength *NagminToSeoDong = (StationAndLength *) malloc(sizeof(StationAndLength)); // 낙민 -> 서동

    //석동 -> 낙민
    SeoDongToNagmin->station = Nagmin;
    SeoDongToNagmin->time = 6;
    SeoDong->stationAndLength[1] = SeoDongToNagmin;
    SeoDong->stationAndLength[2] = NULL;
    //낙민 -> 석동
    NagminToSeoDong->station = SeoDong;
    NagminToSeoDong->time = 6;
    Nagmin->stationAndLength[0] = NagminToSeoDong;

    /**
     * 낙민 <-> 동래
     */
    StationAndLength *NagminToDongLae = (StationAndLength *) malloc(sizeof(StationAndLength)); // 낙민 -> 동래
    StationAndLength *DongLaeToNagmin = (StationAndLength *) malloc(sizeof(StationAndLength)); // 동래 -> 낙민

    //낙민 -> 동래
    NagminToDongLae->station = DongLae;
    NagminToDongLae->time = 3;
    Nagmin->stationAndLength[1] = NagminToDongLae;
    Nagmin->stationAndLength[2] = NULL;

    //동래 -> 낙민
    DongLaeToNagmin->station = Nagmin;
    DongLaeToNagmin->time = 3;
    DongLae->stationAndLength[2] = DongLaeToNagmin; // 동래가 갈수 있는 곳은 4곳이다.

    /**
     * 동래 <-> 미남
     */
    Station *MiNam = (Station *) malloc(sizeof(Station)); // 미남 구조체
    Station_Array[10] = MiNam;

    StationAndLength *DongLaeToMiNam = (StationAndLength *) malloc(sizeof(StationAndLength)); // 동레 -> 미남
    StationAndLength *MiNamToDongLae = (StationAndLength *) malloc(sizeof(StationAndLength)); // 미남 -> 동래

    //동래 -> 미남
    DongLaeToMiNam->station = MiNam;
    DongLaeToMiNam->time = 3;
    DongLae->stationAndLength[3] = DongLaeToMiNam;
    DongLae->stationAndLength[4] = NULL;

    //미남 -> 동래
    MiNamToDongLae->station = DongLae;
    MiNamToDongLae->time = 3;
    MiNam->stationAndLength[0] = MiNamToDongLae;


    /*-----------3호선----------*/

    /**
     * 덕천 <-> 남산정
     */
    Station *DeogCheon = (Station *) malloc(sizeof(Station)); // 덕천 구조체
    Station_Array[11] = DeogCheon;
    Station *NamsanJeong = (Station *) malloc(sizeof(Station)); // 남산정 구조체
    Station_Array[12] = NamsanJeong;

    StationAndLength *DeogCheonToNamsanJeong = (StationAndLength *) malloc(sizeof(StationAndLength)); // 덕천 -> 남산정
    StationAndLength *NamsanJeongToDeogCheon = (StationAndLength *) malloc(sizeof(StationAndLength)); // 남산정 -> 덕천

    //덕천 -> 남산정
    DeogCheonToNamsanJeong->station = NamsanJeong;
    DeogCheonToNamsanJeong->time = 3;
    DeogCheon->stationAndLength[0] = DeogCheonToNamsanJeong;
    //남산정 -> 덕천
    NamsanJeongToDeogCheon->station = DeogCheon;
    NamsanJeongToDeogCheon->time = 3;
    NamsanJeong->stationAndLength[0] = NamsanJeongToDeogCheon;

    /**
     * 남산정 <-> 미남
     */

    //남산정 -> 미남
    StationAndLength *NamsanJeongToMiNam = (StationAndLength *) malloc(sizeof(StationAndLength)); // 남산정 -> 미남
    StationAndLength *MiNamToNamsanJeong = (StationAndLength *) malloc(sizeof(StationAndLength)); // 미남 -> 남산정

    //남산정 -> 미남
    NamsanJeongToMiNam->station = MiNam;
    NamsanJeongToMiNam->time = 6;
    NamsanJeong->stationAndLength[1] = NamsanJeongToMiNam;
    NamsanJeong->stationAndLength[2] = NULL;
    //미남 -> 남산정
    MiNamToNamsanJeong->station = DeogCheon;
    MiNamToNamsanJeong->time = 6;
    MiNam->stationAndLength[1] = MiNamToNamsanJeong;

    /**
     * 미남 <-> 연산
     */

    StationAndLength *MiNamToYounSan = (StationAndLength *) malloc(sizeof(StationAndLength)); // 미남 -> 연산
    StationAndLength *YoungSanToMiNam = (StationAndLength *) malloc(sizeof(StationAndLength)); // 연산 -> 미남

    //미남 -> 연산
    MiNamToYounSan->station = YounSan;
    MiNamToYounSan->time = 7;
    MiNam->stationAndLength[2] = MiNamToYounSan;
    MiNam->stationAndLength[3] = NULL;

    //연산 -> 미남
    YoungSanToMiNam->station = MiNam;
    YoungSanToMiNam->time = 7;
    YounSan->stationAndLength[2] = YoungSanToMiNam;

    /**
     * 연산 <-> 배산
     */

    Station *BaeSan = (Station *) malloc(sizeof(Station)); // 배산 구조체
    Station_Array[13] = BaeSan;

    StationAndLength *YounSanToBaeSan = (StationAndLength *) malloc(sizeof(StationAndLength)); // 연산 -> 배산
    StationAndLength *BaeSanToYounSan = (StationAndLength *) malloc(sizeof(StationAndLength)); // 배산 -> 연산

    //연산 -> 배산
    YounSanToBaeSan->station = BaeSan;
    YounSanToBaeSan->time = 5;
    YounSan->stationAndLength[3] = YounSanToBaeSan;
    YounSan->stationAndLength[4] = NULL;

    //배산 -> 연산
    BaeSanToYounSan->station = YounSan;
    BaeSanToYounSan->time = 5;
    BaeSan->stationAndLength[0] = BaeSanToYounSan;


    /**
     * 배산 <-> 수영
     */
    Station *SuYeong = (Station *) malloc(sizeof(Station)); // 수영 구조체
    Station_Array[14] = SuYeong;

    StationAndLength *BaeSanToSuYeong = (StationAndLength *) malloc(sizeof(StationAndLength)); // 배산 -> 수영
    StationAndLength *SuYeongToBaeSan = (StationAndLength *) malloc(sizeof(StationAndLength)); // 수영 -> 배산

    //배산 -> 수영
    BaeSanToSuYeong->station = SuYeong;
    BaeSanToSuYeong->time = 5;
    BaeSan->stationAndLength[1] = BaeSanToSuYeong;
    BaeSan->stationAndLength[2] = NULL;

    //수영 -> 배산
    SuYeongToBaeSan->station = BaeSan;
    SuYeongToBaeSan->time = 5;
    SuYeong->stationAndLength[0] = SuYeongToBaeSan;


    /*-----------2호선----------*/


    /**
     * 율리 <-> 덕천
     */
    Station *YulRi = (Station *) malloc(sizeof(Station)); //율리 구조체
    Station_Array[15] = YulRi;

    StationAndLength *YulRiToDeogCheon = (StationAndLength *) malloc(sizeof(StationAndLength)); //율리 -> 덕천
    StationAndLength *DeogCheonToYulRi = (StationAndLength *) malloc(sizeof(StationAndLength)); //덕천 -> 율리

    //율리 -> 덕천
    YulRiToDeogCheon->station = DeogCheon;
    YulRiToDeogCheon->time = 7;
    YulRi->stationAndLength[0] = YulRiToDeogCheon;
    YulRi->stationAndLength[1] = NULL;

    //덕천 -> 율리
    DeogCheonToYulRi->station = YulRi;
    DeogCheonToYulRi->time = 7;
    DeogCheon->stationAndLength[1] = DeogCheonToYulRi;

    /**
     * 덕천 <-> 모라
     */
    Station *MoRa = (Station *) malloc(sizeof(Station)); //모라 구조체
    Station_Array[16] = MoRa;

    StationAndLength *DeogCheonToMoRa = (StationAndLength *) malloc(sizeof(StationAndLength)); //덕천 -> 모라
    StationAndLength *MoRaToDeogCheon = (StationAndLength *) malloc(sizeof(StationAndLength)); //모라 -> 덕천

    //덕천 -> 모라
    DeogCheonToMoRa->station = MoRa;
    DeogCheonToMoRa->time = 6;
    DeogCheon->stationAndLength[2] = DeogCheonToMoRa;
    DeogCheon->stationAndLength[3] = NULL;

    //모라 -> 덕천
    MoRaToDeogCheon->station = DeogCheon;
    MoRaToDeogCheon->time = 6;
    MoRa->stationAndLength[0] = MoRaToDeogCheon;


    /**
     * 모라 <-> 사상
     */
    Station *SaSang = (Station *) malloc(sizeof(Station)); // 사상 구조체
    Station_Array[17] = SaSang;

    StationAndLength *MoRaToSaSang = (StationAndLength *) malloc(sizeof(StationAndLength)); //모라 -> 사상
    StationAndLength *SaSangToMoRa = (StationAndLength *) malloc(sizeof(StationAndLength)); //사상 -> 모라


    //모라 -> 사상
    MoRaToSaSang->station = SaSang;
    MoRaToSaSang->time = 6;
    MoRa->stationAndLength[1] = MoRaToSaSang;
    MoRa->stationAndLength[2] = NULL;

    //사상 -> 모라
    SaSangToMoRa->station = MoRa;
    SaSangToMoRa->time = 6;
    SaSang->stationAndLength[0] = SaSangToMoRa;


    /**
     * 사상 <-> 냉정
     */
    Station *NaengJeong = (Station *) malloc(sizeof(Station)); //냉정 구조체
    Station_Array[18] = NaengJeong;

    StationAndLength *SaSangToNaengJeong = (StationAndLength *) malloc(sizeof(StationAndLength)); //사상 -> 냉정
    StationAndLength *NaengJeongToSaSang = (StationAndLength *) malloc(sizeof(StationAndLength)); //냉정 -> 사상


    //사상 -> 냉정
    SaSangToNaengJeong->station = NaengJeong;
    SaSangToNaengJeong->time = 6;
    SaSang->stationAndLength[1] = SaSangToNaengJeong;
    SaSang->stationAndLength[2] = NULL;

    //냉정 -> 사상
    NaengJeongToSaSang->station = SaSang;
    NaengJeongToSaSang->time = 6;
    NaengJeong->stationAndLength[0] = NaengJeongToSaSang;

    /**
     * 냉정 <-> 가야
     */
    Station *GaYa = (Station *) malloc(sizeof(Station)); //냉정 구조체
    Station_Array[19] = GaYa;

    StationAndLength *GaYaToNaengJeong = (StationAndLength *) malloc(sizeof(StationAndLength)); //가야 -> 냉정
    StationAndLength *NaengJeongToGaYa = (StationAndLength *) malloc(sizeof(StationAndLength)); //냉정 -> 가야


    //냉정 -> 가야
    NaengJeongToGaYa->station = GaYa;
    NaengJeongToGaYa->time = 5;
    NaengJeong->stationAndLength[1] = NaengJeongToGaYa;
    NaengJeong->stationAndLength[2] = NULL;

    //가야 -> 냉정
    GaYaToNaengJeong->station = NaengJeong;
    GaYaToNaengJeong->time = 5;
    GaYa->stationAndLength[0] = GaYaToNaengJeong;


    /**
     * 가야 <-> 서면
     */

    StationAndLength *GaYaToSeoMyeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //가야 -> 서면
    StationAndLength *SeoMyeonToGaYa = (StationAndLength *) malloc(sizeof(StationAndLength)); //서면 -> 가야

    //가야 -> 서면
    GaYaToSeoMyeon->station = SeoMyeon;
    GaYaToSeoMyeon->time = 3;
    GaYa->stationAndLength[1] = GaYaToSeoMyeon;
    GaYa->stationAndLength[2] = NULL;

    //서면 -> 가야
    SeoMyeonToGaYa->station = GaYa;
    SeoMyeonToGaYa->time = 3;
    SeoMyeon->stationAndLength[2] = SeoMyeonToGaYa;


    /**
     * 서면 <-> 문현
     */
    Station *MunHyeon = (Station *) malloc(sizeof(Station)); //문현 구조체
    Station_Array[20] = MunHyeon;

    StationAndLength *SeoMyeonToMunHyeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //서면 -> 문현
    StationAndLength *MunHyeonToSeoMyeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //문현 -> 서면

    //서면 -> 문현
    SeoMyeonToMunHyeon->station = MunHyeon;
    SeoMyeonToMunHyeon->time = 7;
    SeoMyeon->stationAndLength[3] = SeoMyeonToMunHyeon;
    SeoMyeon->stationAndLength[4] = NULL;


    //문현 -> 서면
    MunHyeonToSeoMyeon->station = SeoMyeon;
    MunHyeonToSeoMyeon->time = 7;
    MunHyeon->stationAndLength[0] = MunHyeonToSeoMyeon;

    /**
     * 문현 <-> 대연
     */
    Station *DaeYeon = (Station *) malloc(sizeof(Station)); //대연 구조체
    Station_Array[21] = DaeYeon;

    StationAndLength *MunHyeonToDaeYeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //문현 -> 대연
    StationAndLength *DaeYeonToMunHyeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //대연 -> 문현

    //문현 -> 대연
    MunHyeonToDaeYeon->station = DaeYeon;
    MunHyeonToDaeYeon->time = 5;
    MunHyeon->stationAndLength[1] = MunHyeonToDaeYeon;
    MunHyeon->stationAndLength[2] = NULL;

    //대연 -> 문현
    DaeYeonToMunHyeon->station = MunHyeon;
    DaeYeonToMunHyeon->time = 5;
    DaeYeon->stationAndLength[0] = DaeYeonToMunHyeon;


    /**
     * 대연 <-> 금련산
     */
    Station *GeumLyeonSan = (Station *) malloc(sizeof(Station)); //금련산 구조체
    Station_Array[22] = GeumLyeonSan;

    StationAndLength *DaeYeonToGeumLyeonSan = (StationAndLength *) malloc(sizeof(StationAndLength)); //대연 -> 금련산
    StationAndLength *GeumLyeonSanToDaeYeon = (StationAndLength *) malloc(sizeof(StationAndLength)); //금련산 -> 대연



    //대연 -> 금련산
    DaeYeonToGeumLyeonSan->station = GeumLyeonSan;
    DaeYeonToGeumLyeonSan->time = 5;
    DaeYeon->stationAndLength[1] = DaeYeonToGeumLyeonSan;
    DaeYeon->stationAndLength[2] = NULL;

    //금련산 -> 대연
    GeumLyeonSanToDaeYeon->station = DaeYeon;
    GeumLyeonSanToDaeYeon->time = 5;
    GeumLyeonSan->stationAndLength[0] = GeumLyeonSanToDaeYeon;


    /**
     * 금련산 <-> 수영
     */
    StationAndLength *GeumLyeonSanToSuYeong = (StationAndLength *) malloc(sizeof(StationAndLength)); //금련산 ->  수영
    StationAndLength *SuYeongToGeumLyeonSan = (StationAndLength *) malloc(sizeof(StationAndLength)); //수영 -> 금련산


    //수영 -> 금련산
    SuYeongToGeumLyeonSan->station = GeumLyeonSan;
    SuYeongToGeumLyeonSan->time = 4;
    SuYeong->stationAndLength[1] = SuYeongToGeumLyeonSan;
    SuYeong->stationAndLength[2] = NULL;

    //금련산 -> 수영
    GeumLyeonSanToSuYeong->station = SuYeong;
    GeumLyeonSanToSuYeong->time = 4;
    GeumLyeonSan->stationAndLength[1] = GeumLyeonSanToSuYeong;
    GeumLyeonSan->stationAndLength[2] = NULL;
}

Station *findById(int id) {
    return Station_Array[id];
}


bool findBy(char name1[100], char name2[100]) {

    for (int i = 0; name1[i] != NULL && name2[i] != NULL; i++) {
        if (name1[i] != name2[i]) {
            return false;
        }
    }

    return true;
}


int findStationIdByStationName(char name[100]) {
    for (int i = 0; i < NODE_COUNT; i++) {
        if (findBy(name, station_name_array[i])) {
            return i;
        }
    }
    return -1;
}


int findIdByStation(Station *station) {
    for (int i = 0; i < NODE_COUNT; i++) {
        if (Station_Array[i] == station) {
            return i;
        }
    }
    return -1;
}



