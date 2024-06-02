/**
 * 2번문제
 * 타입, 암호키, 회전횟수, 원본메세지 입력시
 * 조건에 맞게 암호화 또는 복호화 하는 문제
*/
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#define pii pair<int, int>
#define mp make_pair
#define ll long long

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

char typ[50], key[50], msg[50];
int charSum[50];
int rotatedSum[50];
int rot;

int main() {
  cin >> typ >> key >> rot >> msg;
  int sze = strlen(msg);

  if (strcmp(typ, "encrypt") == 0) {
    rot = rot % sze;
    for (int i = 0; i < strlen(msg); i++) {
      charSum[i] = (key[i] - 'a' + msg[i] - 'a') % 26;
    }
    // 1이면 1
    //  -1 이면 9
    int idxx;
    if (rot < 0)
      idxx = (rot + sze) % sze;
    else
      idxx = rot % sze;

    for (int i = idxx; i < sze; i++) {
      rotatedSum[i] = charSum[i];
      printf("%c", rotatedSum[i] + 'a');
    }
    for (int i = 0; i < idxx; i++) {
      rotatedSum[i] = charSum[i];
      printf("%c", rotatedSum[i] + 'a');
    }




  } else if (strcmp(typ, "decrypt") == 0) {
    // 1. 메세지 복호화
    for (int i = 0; i < sze; i++) {
      rotatedSum[i] = msg[i] - 'a';
      // cout << rotatedSum[i] << " ";
    }

    // 2 메세지 돌리기
    rot = -rot;
    rot = rot % sze;
    int idxx;
    if (rot < 0)
      idxx = (rot + sze) % sze;
    else
      idxx = rot % sze;

    vector<char> orderMsg;
    for (int i = idxx; i < sze; i++) {
      charSum[i] = rotatedSum[i];
      orderMsg.push_back(charSum[i]);
    }
    for (int i = 0; i < idxx; i++) {
      charSum[i] = rotatedSum[i];
      orderMsg.push_back(charSum[i]);
    }

    for (int i = 0; i < sze; i++) {
      printf("%c", (orderMsg[i] + 26 - (key[i] - 'a')) % 26 + 'a');
    }

  } else {
    cout << "@";
  }
}
