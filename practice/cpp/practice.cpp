#include <iostream>
#include <utility>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {

        for(int j = 0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
cout <<endl;}

int main() {

    int bb[] = {9,8,7,6,5,4,3,2,1};


    cout << "Before Sorting: "; 
    for(int i = 0; i<9; i++){
            cout << bb[i] <<" ";}

    bubbleSort(bb, 9);

    cout << "Before Sorting: "; 
    for(int i = 0; i<9; i++){
            cout << bb[i] <<" ";}


    return 0;
}