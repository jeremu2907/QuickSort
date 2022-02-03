#include <iostream>
#include <vector>

using std::cout;
using std::cin;

void sort(std::vector<int>& toSort, int idxLow, int idxHigh){
  /*
    Implementing quick sort
    right: subarray right most idx
    left:  subarray left most idx
    idx: idx used fpr swapping
  */
  int right = idxHigh;
  int left = idxLow;
  if(right - left < 1)
    return;

  //Pick pivot point
  int Pivot = toSort[idxHigh];

  //Partitioning
  while(idxLow < idxHigh){
    while(toSort[idxLow] <= Pivot && idxLow < idxHigh){
      ++idxLow;
    }

    while(toSort[idxHigh] >= Pivot && idxLow < idxHigh){
      --idxHigh;
    }

    //Swapping elem
    int temp = toSort[idxLow];
    toSort[idxLow] = toSort[idxHigh];
    toSort[idxHigh] = temp;
  }

  //Swapping pivot and larger elem
  int temp = toSort[idxLow];
  toSort[idxLow] = Pivot;
  toSort[right] = temp;

  //Sort left side of array
  sort(toSort, left, idxLow - 1);
  sort(toSort, idxLow +1, right);
}

int main(){
  std::vector<int> n = {3,5,2,5,7,6,8,9,0,5,3,56,7,8,8,7,4,555,55,5,3,3,2,999};

  for(auto m:n)
    cout << m << ' ';

  sort(n,0,n.size()-1);
  cout << std::endl;

   for(auto m:n)
    cout << m << ' ';
}