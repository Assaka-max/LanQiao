#include<iostream>
#include<vector>
using namespace std;

struct SetTree{
  int n;
  vector<long long> tree;
  vector<long long> lazy;

  SetTree(int n){
    this->n = n;
    this->tree = vector<long long>(n*4, 0);
    this->lazy = vector<long long>(n*4, 0);
  }

  void build(int node, int l, int r, vector<int> &arr){
    if(l == r){
      tree[node] = arr[l];
      return;
    }
    int mid = (l+r)/2;
    build(node * 2, l, mid, arr);
    build(node * 2 + 1, mid + 1, r, arr);
    push_up(node);
  }

  void push_up(int node) {tree[node] = tree[node*2] + tree[node*2+1];}

  void push_down(int node, int l, int r){
    if(lazy[node] != 0){
      int mid = (l+r)/2;
      long long val = lazy[node];
      tree[node * 2] += val * (mid - l + 1);
      lazy[node * 2] += val;
      tree[node * 2 + 1] += val * (r - mid);
      lazy[node * 2 + 1] += val;
      lazy[node] = 0;
    }
  }

  void update(int node, int l, int r, int ql, int qr, long long val){
    if(ql <= l && r <= qr){
      tree[node] += val * (r-1+1);
      lazy[node] += val;
      return;
    }
    push_down(node, l, r);
    int mid = (l+r)/2;
    if(ql <= mid) update(node*2, l, mid, ql, qr, val);
    if(qr > mid) update(node*2 + 1, mid + 1, r, ql, qr, val);
    push_up(node);
  }

  long long query(int node, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return tree[node];
    push_down(node, l, r);
    int mid = (l+r)/2;
    long long ans = 0;
    if(ql <= mid) ans += query(node*2, l, mid, ql, qr);
    if(qr > mid) ans += query(node*2 + 1, mid + 1, r, ql, qr);
    return ans;
  }
};


int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  return 0;
}