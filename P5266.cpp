#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string, int> m;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q; cin >> q;
  for(int i = 1; i <= q; i++){
    int op; cin >> op;
    string name;
    if(op == 1){
      cin >> name;
      int score; cin >> score;
      m[name] = score;
      cout << "OK" << endl;
    }else if(op == 2){
      cin >> name;
      if(m.count(name)) cout << m[name] << endl;
      else cout << "Not found" << endl;
    }else if(op == 3){
      cin >> name;
      if(m.count(name)){
        m.erase(name);
        cout << "Deleted successfully\n";
      }else cout << "Not found" << endl;
    }else{
      cout << m.size() << endl;
    }
  }
  return 0;
}