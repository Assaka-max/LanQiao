#include<iostream>
using namespace std;
double a, b, c, d;
double fuction(double x){
  return a*x*x*x + b*x*x + c*x + d;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b >> c >> d;
  int s = 0;
  for(int i = -100; i <= 100; i++){
    double l = i;
    double r = i+1;
    double x1 = fuction(l);
    double x2 = fuction(r);
    if(!x1) {
      printf("%.2lf ", l);
      s++;
    }
    if(x1 * x2 < 0){
      while (r-l >= 0.001){
        double mid = (l+r)/2;
        if(fuction(mid)*fuction(r) <= 0) l = mid;
        else r = mid;
      }
      printf("%.2lf ", l);
      s++;
    }
    if(s == 3) break;
    
  }
  
  return 0;
}