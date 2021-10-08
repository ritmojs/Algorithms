#include <iostream>
#include <algorithm>
using namespace std;
void reverseArray(int arr[], int n){
   for (int low = 0, high = n - 1; low < high; low++, high--){
      swap(arr[low], arr[high]);
   }
   for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
   }
}
int main(){
   int arrInput[] = { 11, 12, 13, 14, 15 };
   cout<<endl<<"Array::";
   for (int i = 0; i < 5; i++){
      cout << arrInput[i] << " ";
   }
   int n = sizeof(arrInput)/sizeof(arrInput[0]);
   cout<<endl<<"Reversed::";
   reverseArray(arrInput, n);
   return 0;
}