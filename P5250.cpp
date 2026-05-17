#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q; cin >> q;
  while(q--){
    int op, length;
    cin >> op >> length;
    if(op == 1){
      auto it = upper_bound(a.begin(), a.end(), length);
      if(it != a.begin() && *(it-1) == length) cout << "Already Exist" << endl;
      else a.insert(it, length);
    }else{
      if(a.empty()) cout << "Empty" << endl;
      else{
        auto it = upper_bound(a.begin(), a.end(), length);
        auto remove_it = it;
        if(it == a.end()) remove_it = it-1;
        else if(it == a.begin() || *it - length < length - *(it-1)) remove_it = it;
        else remove_it = it-1;
        cout << *remove_it << endl;
        a.erase(remove_it);
      }
    }
  }
  return 0;
}