#include<iostream>
using namespace std;
const int M = 21;
const int N = 105;
int k;
int step = 1;
char willto = 'E';
pair<int, int> worm[M];
char op[N];

bool out(){
  if(worm[1].first < 1 || worm[1].first > 50 || worm[1].second < 1 || worm[1].second > 50) return true;
  else return false;
}

bool move(char c){
  if(c == 'E'){
    if(willto == 'W') return false;
    for(int i = 20; i > 1; i--) worm[i] = worm[i-1];
    worm[1] = {worm[1].first, worm[1].second + 1};
    willto = 'E';
  }else if(c == 'W'){
    if(willto == 'E') return false;
    for(int i = 20; i > 1; i--) worm[i] = worm[i-1];
    worm[1] = {worm[1].first, worm[1].second - 1};
    willto = 'W';
  }else if(c == 'N'){
    if(willto == 'S') return false;
    for(int i = 20; i > 1; i--) worm[i] = worm[i-1];
    worm[1] = {worm[1].first - 1, worm[1].second};
    willto = 'N';
  }else if(c == 'S'){
    if(willto == 'N') return false;
    for(int i = 20; i > 1; i--) worm[i] = worm[i-1];
    worm[1] = {worm[1].first + 1, worm[1].second};
    willto = 'S';
  }
  for(int i = 2; i <= 20; i++){
    if(worm[1] == worm[i]) return false;
  }
  step++;
  return true;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while(cin >> k){
    if(k == 0) break;
    step = 1;
    bool wa = false;
    willto = 'E';
    for(int i = 1; i <= 20; i++) worm[i] = {25, 31 - i};
    for(int i = 1; i <= k; i++) cin >> op[i];
    for(int i = 1; i <= k; i++){
      if(!move(op[i])) {printf("The worm ran into itself on move %d.\n", step); wa = true; break;}
      if(out()) {printf("The worm ran off the board on move %d.\n", step-1); wa = true; break;}
    }
    if(!wa) printf("The worm successfully made all %d moves.\n", k);
  }
  return 0;
}