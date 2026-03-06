#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right, vector<int> temp){
  int i = left;
  int j = mid + 1;
  int t = 0;
  while(i <= mid && j <= right){
    if(arr[i] < arr[j]) temp[t++] = arr[i++];
    else temp[t++] = arr[j++];
  }

  while(i <= mid) temp[t++] = arr[i++];
  while(j <= right) temp[t++] = arr[j++];

  t = 0;
  while(left <= right) arr[left++] = temp[t++];
}

void mSort(vector<int> &arr, int left, int right, vector<int> &temp){
  if(left < right){
    int mid = left + (right - left)/2;
    mSort(arr, left, mid, temp);
    mSort(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
  }
}

void mergeSort(vector<int> &arr){
  if(arr.empty()) return;
  vector<int> temp(arr.size());
  mSort(arr, 0, arr.size()-1, temp);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}