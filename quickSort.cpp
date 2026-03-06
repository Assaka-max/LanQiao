#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &vec, int left, int right){
  //找出基准位置与基准元素
  int mid = left + (right - left)/2;
  int pivot = vec[mid];

  //把基准元素移动到最右端并确定"小于区域"
  swap(vec[mid], vec[right]);
  int i = left;

  for(int j = left; j < right; j++){
    if(vec[j] < pivot){
      swap(vec[i], vec[j]);
      i++;
    }
  }

  swap(vec[i], vec[right]);
  return i;
}

void quickSort(vector<int> &vec, int low, int high){
  if(low < high){
    int pivotIndex = partition(vec, low, high);
    quickSort(vec, low, pivotIndex - 1);
    quickSort(vec, pivotIndex + 1, high);
  }

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();
  
  quickSort(arr, 0, n - 1);
  
  cout << "Sorted array: ";
  for (int num : arr) {
      cout << num << " ";
  }
  cout << endl;
  return 0;
}