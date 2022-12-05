//
// Created by 이창보 on 2022/12/02.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef YOONCHANG_STATION_H
#define YOONCHANG_STATION_H
#endif // YOONCHANG_STATION_H

typedef int Time;

typedef struct StationAndLength SaL;

typedef struct Station{
    int id;
    struct StationAndLength* stationAndLength[4];
} Station;

// 자기와 인접한 역과 그 역까지의 거리
typedef struct StationAndLength{
    struct station *station;
    Time time;
} StationAndLength;

void init() {

    /*-----------1호선----------*/

    /**
     * 부산대 <-> 동래
     */
    Station* BusanDae = (Station*)malloc(sizeof(Station)); // 부산대 구조체
    BusanDae->id = 1;
    Station* DongLae = (Station*)malloc(sizeof(Station));  // 동래 구조체
    DongLae->id = 2;

    StationAndLength* BusanDaeToDongLae = (StationAndLength*)malloc(sizeof(StationAndLength)); //부산대 -> 동래 가는 길
    StationAndLength* DongLaeToBusanDae = (StationAndLength*)malloc(sizeof(StationAndLength)); //동래 -> 부산대 가는 길

    //부산대 -> 동래
    BusanDaeToDongLae->station = DongLae;
    BusanDaeToDongLae->time = 8;
    BusanDae->stationAndLength[0] = BusanDaeToDongLae;

    //동래 -> 부산대
    DongLaeToBusanDae->station = BusanDae;
    DongLaeToBusanDae->time = 8;
    DongLae->stationAndLength[0] = DongLaeToBusanDae;

    /**
     * 동래 <-> 연산
     */
    Station* YounSang = (Station*)malloc(sizeof(Station)); // 연산 구조체
    YounSang->id = 3;

    StationAndLength* DongLaeToYounSang = (StationAndLength*)malloc(sizeof(StationAndLength)); //동래 -> 영상
    StationAndLength* YounSangToDongLae = (StationAndLength*)malloc(sizeof(StationAndLength)); //연산 -> 동래

    //동래 -> 연산
    DongLaeToYounSang->station = YounSang;
    DongLaeToYounSang->time = 8;
    DongLae->stationAndLength[1] = DongLaeToYounSang;

    // 연산 -> 동래
    YounSangToDongLae->station = DongLae;
    YounSangToDongLae->time = 8;
    YounSang->stationAndLength[0] = YounSangToDongLae;

    /**
     * 연산 <-> 양정
     */
    Station* YangJeong = (Station*)malloc(sizeof(Station)); //양정 구조체
    YangJeong->id = 4;

    StationAndLength* YangJeongToYounSan = (StationAndLength*)malloc(sizeof(StationAndLength));
    StationAndLength* YounSanToYangJeong = (StationAndLength*)malloc(sizeof(StationAndLength));

    //연산 -> 양정
    YounSanToYangJeong->station = YangJeong;
    YounSanToYangJeong->time = 8;
    YounSang->stationAndLength[1] = YounSanToYangJeong;

    YangJeongToYounSan->station = YounSang;
    YangJeongToYounSan->time = 8;
    YangJeong->stationAndLength[0] = YangJeongToYounSan;

    /**
     * 양정 -> 서면
     */
    Station* SeoMyeon = (Station*)malloc(sizeof(Station)); //서면 구조체
    SeoMyeon->id = 5;

    StationAndLength* SeoMyeonToYangJeong = (StationAndLength*)malloc(sizeof(StationAndLength));
    StationAndLength* YangJoengToSeoMyeon = (StationAndLength*)malloc(sizeof(StationAndLength));

    //양정 -> 서면
    YangJoengToSeoMyeon->station = SeoMyeon;
    YangJoengToSeoMyeon->time = 8;
    YounSang->stationAndLength[1] = YounSanToYangJeong;

    //서면 -> 양정
    SeoMyeonToYangJeong->station = YangJeong;
    SeoMyeonToYangJeong->time = 8;
    SeoMyeon->stationAndLength[0] = SeoMyeonToYangJeong;

    /**
     * 서면 <-> 좌천
     */
    Station* JwaCheon = (Station*)malloc(sizeof(Station));
    JwaCheon->id = 6;

    StationAndLength* JwaCheonToSeoMyeon = (StationAndLength*)malloc(sizeof(StationAndLength));
    StationAndLength* SeoMyeonToJwaCheon = (StationAndLength*)malloc(sizeof(StationAndLength));

    //서면 -> 좌천
    SeoMyeonToJwaCheon->station = JwaCheon;
    SeoMyeonToJwaCheon->time = 8;
    SeoMyeon->stationAndLength[1] = SeoMyeonToJwaCheon;

    //좌천 -> 서면
    JwaCheonToSeoMyeon->station = SeoMyeon;
    JwaCheonToSeoMyeon->time = 8;
    JwaCheon->stationAndLength[0] = JwaCheon;

    /**
     * 좌천 -> 부산역
     */
    Station* BusanYeog = (Station*)malloc(sizeof(Station)); // 부산역 구조체
    BusanDae->id = 7;

    StationAndLength* BusanYeogToJwaCheon = (StationAndLength*)malloc(sizeof(StationAndLength));
    StationAndLength* JwaCheonToBusanYeog = (StationAndLength*)malloc(sizeof(StationAndLength));

    JwaCheonToBusanYeog->station = BusanYeog;
    JwaCheonToBusanYeog->time = 8;
    JwaCheon->stationAndLength[1] = JwaCheonToBusanYeog;

    BusanYeogToJwaCheon->station = JwaCheon;
    BusanYeogToJwaCheon->time = 8;
    BusanYeog->stationAndLength[0] = BusanYeogToJwaCheon;


    /*-----------4호선----------*/


    /**
     * 석대 <-> 서동
     */
    Station* SeogDae = (Station*)malloc(sizeof(Station)); // 석대 구조체
    SeogDae->id = 8;
    Station* SeoDong = (Station*)malloc(sizeof(Station)); // 석동 구조체
    SeoDong->id = 9;

    StationAndLength* SeogDaeToSeoDong = (StationAndLength*)malloc(sizeof(StationAndLength)); // 석대 -> 석동
    StationAndLength* SeoDongToSeogDae = (StationAndLength*)malloc(sizeof(StationAndLength)); // 석동 -> 석대

    //석대 -> 서동
    SeogDaeToSeoDong->station = SeoDong;
    SeogDaeToSeoDong->time = 8;
    SeogDae->stationAndLength[0] = SeogDaeToSeoDong;
    //서동 -> 석대
    SeoDongToSeogDae->station = SeogDae;
    SeoDongToSeogDae->time = 8;
    SeogDae->stationAndLength[0] = SeoDongToSeogDae;

    /**
     * 서동 -> 낙민
     */
    Station* Nagmin = (Station*)malloc(sizeof(Station)); // 낙민 구조체
    Nagmin->id = 10;

    StationAndLength* SeoDongToNagmin = (StationAndLength*)malloc(sizeof(StationAndLength)); // 서동 -> 낙민
    StationAndLength* NagminToSeoDong = (StationAndLength*)malloc(sizeof(StationAndLength)); // 낙민 -> 서동

    //석동 -> 낙민
    SeoDongToNagmin->station = Nagmin;
    SeoDongToNagmin->time = 8;
    SeoDong->stationAndLength[1] = SeoDongToNagmin;
    //낙민 -> 석동
    NagminToSeoDong->station = SeoDong;
    NagminToSeoDong->time = 8;
    Nagmin->stationAndLength[0] = NagminToSeoDong;

    /**
     * 낙민 <-> 동래
     */
    StationAndLength* NagminToDongLae = (StationAndLength*)malloc(sizeof(StationAndLength)); // 낙민 -> 동래
    StationAndLength* DongLaeToNagmin = (StationAndLength*)malloc(sizeof(StationAndLength)); // 동래 -> 낙민

    //낙민 -> 동래
    NagminToDongLae->station = DongLae;
    NagminToDongLae->time = 8;
    Nagmin->stationAndLength[1] = NagminToDongLae;

    //동래 -> 낙민
    DongLaeToNagmin->station = Nagmin;
    DongLaeToNagmin->time = 8;
    DongLae->stationAndLength[2] = DongLaeToNagmin; // 동래가 갈수 있는 곳은 4곳이다.

    /**
     * 동래 <-> 미남
     */
    Station* MiNam = (Station*)malloc(sizeof(Station)); // 미남 구조체
    MiNam->id = 11;

    StationAndLength* DongLaeToMiNam = (StationAndLength*)malloc(sizeof(StationAndLength)); // 동레 -> 미남
    StationAndLength* MiNamToDongLae = (StationAndLength*)malloc(sizeof(StationAndLength)); // 미남 -> 동래

    //동래 -> 미남
    DongLaeToMiNam->station = MiNam;
    DongLaeToMiNam->time = 4;
    DongLae->stationAndLength[3] = DongLaeToMiNam;

    //미남 -> 동래
    MiNamToDongLae->station = DongLae;
    MiNamToDongLae->time = 4;
    DongLae->stationAndLength[0] = MiNamToDongLae;

    /**
     * 덕천 <-> 남산정
     */
    Station* DeogCheon = (Station*)malloc(sizeof(Station)); // 덕천 구조체
    DeogCheon->id = 12;
    Station* NamsanJeong = (Station*)malloc(sizeof(Station)); // 남산정 구조체
    NamsanJeong->id = 13;

    StationAndLength* DeogCheonToNamsanJeong = (StationAndLength*)malloc(sizeof(StationAndLength)); // 덕천 -> 남산정
    StationAndLength* NamsanJeongToDeogCheon = (StationAndLength*)malloc(sizeof(StationAndLength)); // 남산정 -> 덕천

    //덕천 -> 남산정
    DeogCheonToNamsanJeong->station = NamsanJeong;
    DeogCheonToNamsanJeong->time = 4;
    DeogCheon->stationAndLength[0] = DeogCheonToNamsanJeong;
    //남산정 -> 덕천
    NamsanJeongToDeogCheon->station = DeogCheon;
    NamsanJeongToDeogCheon->time = 4;
    NamsanJeong->stationAndLength[0] = NamsanJeongToDeogCheon;

    /**
     * 남산정 <-> 미남
     */

    //남산정 -> 미남
    StationAndLength* NamsanJeongToMiNam = (StationAndLength*)malloc(sizeof(StationAndLength)); // 남산정 -> 미남
    StationAndLength* MiNamToNamsanJeong = (StationAndLength*)malloc(sizeof(StationAndLength)); // 미남 -> 남산정

    //남산정 -> 미남
    NamsanJeongToMiNam->station = MiNam;
    NamsanJeongToMiNam->time = 4;
    NamsanJeong->stationAndLength[1] = NamsanJeongToMiNam;
    //미남 -> 남산정
    MiNamToNamsanJeong->station = DeogCheon;
    MiNamToNamsanJeong->time = 4;
    MiNam->stationAndLength[1] = MiNamToNamsanJeong;

    /**
     * 미남 <-> 연산
     */

    StationAndLength* MiNamToYounSang = (StationAndLength*)malloc(sizeof(StationAndLength)); // 미남 -> 연산
    StationAndLength* YoungSanToMiNam = (StationAndLength*)malloc(sizeof(StationAndLength)); // 연산 -> 미남

    //미남 -> 연산
    MiNamToYounSang->station = YounSang;
    MiNamToYounSang->time = 4;
    MiNam->stationAndLength[2] = MiNamToYounSang;

    //연산 -> 미남
    YoungSanToMiNam->station = MiNam;
    YoungSanToMiNam->time = 4;
    YounSang->stationAndLength[2] = YoungSanToMiNam;

    /**
     * 연산 <-> 배산
     */

    Station* BaeSan = (Station*)malloc(sizeof(Station)); // 배산 구조체
    BaeSan->id = 14;

    StationAndLength* YounSangToBaeSan = (StationAndLength*)malloc(sizeof(StationAndLength)); // 연산 -> 배산
    StationAndLength* BaeSanToYounSang = (StationAndLength*)malloc(sizeof(StationAndLength)); // 배산 -> 연산

    //연산 -> 배산
    YounSangToBaeSan->station = BaeSan;
    YounSangToBaeSan->time = 4;
    YounSang->stationAndLength[3] = YounSangToBaeSan;

    //배산 -> 연산
    BaeSanToYounSang->station = YounSang;
    BaeSanToYounSang->time = 4;
    BaeSan->stationAndLength[0] = BaeSanToYounSang;


    /**
     * 배산 <-> 수영
     */
    Station* SuYeong = (Station*)malloc(sizeof(Station)); // 수영 구조체
    SuYeong->id = 15;

    StationAndLength* BaeSanToSuYeong = (StationAndLength*)malloc(sizeof(StationAndLength)); // 배산 -> 수영
    StationAndLength* SuYeongToBaeSan = (StationAndLength*)malloc(sizeof(StationAndLength)); // 수영 -> 배산

    //배산 -> 수영
    BaeSanToSuYeong->station = SuYeong;
    BaeSanToSuYeong->time = 4;
    BaeSan->stationAndLength[1] = BaeSanToSuYeong;

    //수영 -> 배산
    SuYeongToBaeSan->station = BaeSan;
    SuYeongToBaeSan->time = 4;
    SuYeong->stationAndLength[0] = SuYeongToBaeSan;


    /*-----------2호선----------*/


    /**
     * 율리 <-> 덕천
     */
    Station* YulRi = (Station*)malloc(sizeof(Station)); //율리 구조체
    YulRi->id = 16;

    StationAndLength* YulRiToDeogCheon = (StationAndLength*)malloc(sizeof(StationAndLength)); //율리 -> 덕천
    StationAndLength* DeogCheonToYulRi = (StationAndLength*)malloc(sizeof(StationAndLength)); //덕천 -> 율리

    //율리 -> 덕천
    YulRiToDeogCheon -> station = DeogCheon;
    YulRiToDeogCheon -> time = 8;
    YulRi -> stationAndLength[0] = YulRiToDeogCheon;

    //덕천 -> 율리
    DeogCheonToYulRi -> station = YulRi;
    DeogCheonToYulRi -> time = 8;
    DeogCheon -> stationAndLength[1] = DeogCheonToYulRi;

    /**
     * 덕천 <-> 모라
     */
    Station* MoRa = (Station*)malloc(sizeof(Station)); //모라 구조체
    MoRa->id = 17;

    StationAndLength* DeogCheonToMoRa = (StationAndLength*)malloc(sizeof(StationAndLength)); //덕천 -> 모라
    StationAndLength* MoRaToDeogCheon = (StationAndLength*)malloc(sizeof(StationAndLength)); //모라 -> 덕천

    //덕천 -> 모라
    DeogCheonToMoRa -> station = MoRa;
    DeogCheonToMoRa -> time = 8;
    DeogCheon -> stationAndLength[2] = DeogCheonToMoRa;

    //모라 -> 덕천
    MoRaToDeogCheon -> station = DeogCheon;
    MoRaToDeogCheon -> time = 8;
    MoRa -> stationAndLength[0] = MoRaToDeogCheon;


    /**
     * 모라 <-> 사상
     */
    Station* SaSang = (Station*)malloc(sizeof(Station)); // 사상 구조체
    SaSang->id = 18;

    StationAndLength* MoRaToSaSang = (StationAndLength*)malloc(sizeof(StationAndLength)); //모라 -> 사상
    StationAndLength* SaSangToMoRa = (StationAndLength*)malloc(sizeof(StationAndLength)); //사상 -> 모라


    //모라 -> 사상
    MoRaToSaSang -> station = SaSang;
    MoRaToSaSang-> time = 8;
    MoRa -> stationAndLength[1] = MoRaToSaSang;

    //사상 -> 모라
    SaSangToMoRa -> station = MoRa;
    SaSangToMoRa -> time = 8;
    SaSang -> stationAndLength[0] = SaSangToMoRa;


    /**
     * 사상 <-> 냉정
     */
    Station* NaengJeong = (Station*)malloc(sizeof(Station)); //냉정 구조체
    NaengJeong->id = 19;

    StationAndLength* SaSangToNaengJeong = (StationAndLength*)malloc(sizeof(StationAndLength)); //사상 -> 냉정
    StationAndLength* NaengJeongToSaSang = (StationAndLength*)malloc(sizeof(StationAndLength)); //냉정 -> 사상


    //사상 -> 냉정
    SaSangToNaengJeong -> station = NaengJeong;
    SaSangToNaengJeong -> time = 8;
    SaSang -> stationAndLength[1] = SaSangToNaengJeong;

    //냉정 -> 사상
    NaengJeongToSaSang -> station = SaSang;
    NaengJeongToSaSang-> time = 8;
    NaengJeong-> stationAndLength[0] = NaengJeongToSaSang;

    /**
     * 냉정 <-> 가야
     */
    Station* GaYa = (Station*)malloc(sizeof(Station)); //냉정 구조체
    GaYa->id = 20;

    StationAndLength* GaYaToNaengJeong = (StationAndLength*)malloc(sizeof(StationAndLength)); //가야 -> 냉정
    StationAndLength* NaengJeongToGaYa = (StationAndLength*)malloc(sizeof(StationAndLength)); //냉정 -> 가야


    //냉정 -> 가야
    NaengJeongToGaYa -> station = GaYa;
    NaengJeongToGaYa -> time = 8;
    NaengJeong-> stationAndLength[1] = NaengJeongToGaYa;

    //가야 -> 냉정
    GaYaToNaengJeong -> station = NaengJeong;
    GaYaToNaengJeong -> time = 8;
    GaYa -> stationAndLength[0] = GaYaToNaengJeong;


    /**
     * 가야 <-> 서면
     */

    StationAndLength* GaYaToSeoMyeon  = (StationAndLength*)malloc(sizeof(StationAndLength)); //가야 -> 서면
    StationAndLength* SeoMyeonToGaYa = (StationAndLength*)malloc(sizeof(StationAndLength)); //서면 -> 가야

    //가야 -> 서면
    GaYaToSeoMyeon -> station = SeoMyeon;
    GaYaToSeoMyeon -> time = 4;
    GaYa -> stationAndLength[1] = GaYaToSeoMyeon;

    //서면 -> 가야
    SeoMyeonToGaYa-> station = GaYa;
    SeoMyeonToGaYa-> time = 4;
    SeoMyeon-> stationAndLength[2] = SeoMyeonToGaYa;


    /**
     * 서면 <-> 문현
     */
    Station* MunHyeon = (Station*)malloc(sizeof(Station)); //문현 구조체
    MunHyeon->id = 21;

    StationAndLength* SeoMyeonToMunHyeon = (StationAndLength*)malloc(sizeof(StationAndLength)); //서면 -> 문현
    StationAndLength* MunHyeonToSeoMyeon  = (StationAndLength*)malloc(sizeof(StationAndLength)); //문현 -> 서면

    //서면 -> 문현
    SeoMyeonToMunHyeon-> station = MunHyeon;
    SeoMyeonToMunHyeon-> time = 8;
    SeoMyeon-> stationAndLength[3] = SeoMyeonToMunHyeon;

    //문현 -> 서면
    MunHyeonToSeoMyeon -> station = SeoMyeon;
    MunHyeonToSeoMyeon -> time = 8;
    MunHyeon -> stationAndLength[0] = MunHyeonToSeoMyeon;

    /**
     * 문현 <-> 대연
     */
    Station* DaeYeon = (Station*)malloc(sizeof(Station)); //대연 구조체
    DaeYeon->id = 22;

    StationAndLength* MunHyeonToDaeYeon  = (StationAndLength*)malloc(sizeof(StationAndLength)); //문현 -> 대연
    StationAndLength* DaeYeonToMunHyeon = (StationAndLength*)malloc(sizeof(StationAndLength)); //대연 -> 문현

    //문현 -> 대연
    MunHyeonToDaeYeon -> station = DaeYeon;
    MunHyeonToDaeYeon -> time = 8;
    MunHyeon -> stationAndLength[1] = MunHyeonToDaeYeon;

    //대연 -> 문현
    DaeYeonToMunHyeon-> station = MunHyeon;
    DaeYeonToMunHyeon-> time = 8;
    DaeYeon-> stationAndLength[0] = DaeYeonToMunHyeon;


    /**
     * 대연 <-> 금련산
     */
    Station* GeumLyeonSan = (Station*)malloc(sizeof(Station)); //금련산 구조체
    GeumLyeonSan->id = 23;

    StationAndLength* DaeYeonToGeumLyeonSan = (StationAndLength*)malloc(sizeof(StationAndLength)); //대연 -> 금련산
    StationAndLength* GeumLyeonSanToDaeYeon  = (StationAndLength*)malloc(sizeof(StationAndLength)); //금련산 -> 대연



    //대연 -> 금련산
    DaeYeonToGeumLyeonSan-> station = GeumLyeonSan;
    DaeYeonToGeumLyeonSan-> time = 8;
    DaeYeon-> stationAndLength[1] = DaeYeonToGeumLyeonSan;

    //금련산 -> 대연
    GeumLyeonSanToDaeYeon -> station = DaeYeon;
    GeumLyeonSanToDaeYeon -> time = 8;
    GeumLyeonSan -> stationAndLength[0] = GeumLyeonSanToDaeYeon;


    /**
     * 금련산 <-> 수영
     */
    StationAndLength* GeumLyeonSanToSuYeong  = (StationAndLength*)malloc(sizeof(StationAndLength)); //금련산 ->  수영
    StationAndLength* SuYeongToGeumLyeonSan = (StationAndLength*)malloc(sizeof(StationAndLength)); //수영 -> 금련산


    //수영 -> 금련산
    SuYeongToGeumLyeonSan-> station = GeumLyeonSan;
    SuYeongToGeumLyeonSan-> time = 8;
    SuYeong-> stationAndLength[1] = SuYeongToGeumLyeonSan;

    //금련산 -> 수영
    GeumLyeonSanToSuYeong -> station = SuYeong;
    GeumLyeonSanToSuYeong -> time = 8;
    GeumLyeonSan -> stationAndLength[1] = GeumLyeonSanToSuYeong;
}

