/**
 * 1 번 문제
 * 2자리 9개 or 3자리 6개의 숫자들이 입력으로 들어옴
 * 배열하여 가장 큰 수, 가장 작은수를 만들어서 더하기
 * https://www.acmicpc.net/problem/16496
 *
 */
#include <stdlib.h>

#include <algorithm>
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

int main() {
  string str;
  vector<ll> v;
  vector<ll> possNum;
  vector<int> idx;
  getline(cin, str);

  stringstream ss(str);

  string word;
  vector<string> words;

  while (getline(ss, word, ' ')) {
    words.push_back(word);
  }

  sort(words.begin(), words.end());

  int sze = words.size();

  // 순열
  for (int i = 0; i < sze; i++)
    idx.push_back(i);

  do {
    string tmp = "";
    for (int i = 0; i < sze; i++) {
      tmp += words[idx[i]];
    }

    possNum.push_back(stoll(tmp));

  } while (next_permutation(idx.begin(), idx.end()));

  sort(possNum.begin(), possNum.end());

  cout << possNum[0] + possNum[possNum.size() - 1];
}
