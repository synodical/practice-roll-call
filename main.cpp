//
//  main.cpp
//  roll_call
//
//  Created by LeeYeEun on 2021/10/14.
//

// 되돌리기 추가
// 나가기 추가

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

#define WELCOME_MESSAGE "Welcome to roll call!\n"
#define INFO "정상외박: ㅇ\n무단: ㅁ\n불응: ㅂ\n재실: ㅈ\n을 반드시 영어자판으로 입력하시오\n"
using namespace std;
int total = 0; // 총원
int overnight = 0; // 정상, 외박
int absence = 0; // 무단
int noncompliance = 0; // 불응
int occupancy = 0; // 재실
vector<string> mudan;
vector<string> bull;

int main(void) {
    
    printf(WELCOME_MESSAGE);
    printf(INFO);
    printf("\n");
    string str;
    ifstream file("input.txt");
    
    while (getline(file, str)) {
        cout << str ;
        char cmd;
        cin >> cmd;
        if (cmd == 'd') {
            overnight++;
        }
        else if (cmd == 'a') { // 무단
            absence++;
            mudan.push_back(str);
        }
        else if (cmd == 'q') { // 불응
            noncompliance++;
            bull.push_back(str);
        }
        else if (cmd == 'w') {
            occupancy++;
        }
    }
    char cmd_hand, cmd_tem;
    printf("손소독제는? 정상이면 w, 아니면 q");
    cin >> cmd_hand;
    printf("체온계는? 정상이면 w, 아니면 q");
    cin >> cmd_tem;
    
    total = overnight + absence + noncompliance + occupancy;
    cout << '\n';
    cout << "19-20층\n" << '\n' << "총원: " << total << '\n';
    cout << "정상: " << overnight << '\n';
    cout << "무단: " << absence << '\n';
    if (mudan.size() != 0) {
        for (int i = 0; i < mudan.size()-1; i++) {
            cout << mudan[i] << ", ";
        }
        cout << mudan[mudan.size()-1];
        cout << '\n';
    }
    cout << "점호 불응: " << noncompliance << '\n';
    if (bull.size() != 0) {
        for (int i = 0; i < bull.size()-1; i++) {
            cout << bull[i] << ", ";
        }
        cout << bull[bull.size()-1];
        cout << '\n';
    }
    cout << "재실: " << occupancy << '\n';
    printf("손소독제: ");
    if (cmd_hand == 'w') cout << "정상\n";
    else cout << "교체예정입니다.\n";
    printf("체온계: ");
    if (cmd_tem == 'w') cout << "정상\n";
    else cout << "교체예정입니다.\n";
    return 0;
}
