#include <iostream>
#include <vector>
using namespace std;

void simpleMerge(int low, int mid, int high, vector<int>& arr) {
    int i = low;       // Pointer for left part
    int j = mid + 1;   // Pointer for right part
    vector<int> temp;  // Temporary array for merged result

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements from left part
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from right part
    while (j <= high) {
        temp.push_back(arr[j++]);
    }

    // Copy sorted temp back to original array
    for (int k = 0; k < temp.size(); ++k) {
        arr[low + k] = temp[k];
    }
}


void mergeSort(int low, int high, vector<int>& arr){
    if(low >= high) return;   // base case
 
    int mid = (high+low)/2;
 
    mergeSort(low, mid, arr);
    mergeSort(mid+1, high, arr);
    simpleMerge(low,mid, high, arr);
 }

 
int main(){
    vector<int> vec = {2,6,1,9,75,6,21,47,6,15,1};
    mergeSort(0, vec.size()-1, vec);
    for(int i = 0;i<vec.size();i++) 
       cout<<vec[i]<<" ";
    return 0;
}





// with arrays 

void simpleMerge(int low, int mid, int high, int arr[]) {
    int n = high - low + 1;
    int* temp = new int[n];  // temporary array
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) 
          temp[k++] = arr[i++];
        else 
          temp[k++] = arr[j++];
    }

    while (i <= mid) 
      temp[k++] = arr[i++];
    while (j <= high) 
      temp[k++] = arr[j++];

      // copy the temp array backs to original array
    for (int x = 0; x < n; ++x) 
       arr[low + x] = temp[x];

    delete[] temp;  // free memory
}

void mergeSort(int low, int high, int arr[]) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    simpleMerge(low, mid, high, arr);
}

int main() {
    int arr[] = {2, 6, 1, 9, 75, 6, 21, 47, 6, 15, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(0, n - 1, arr);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
