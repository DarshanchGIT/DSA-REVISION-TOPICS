#include <bits/stdc++.h>

using namespace std;

// SELECTION SORTING - best=> 0(N^2), avg=> 0(N^2), worst=> 0(N^2)
// minimum el ka ind find kara, then usse swap karna is the goal
// In selection Sort after first pass, min el will be at the first index

void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
                // Find the minimum element in the unsorted part
                int minIdx = i;
                for (int j = i + 1; j < n; j++) {
                        if (arr[j] < arr[minIdx]) {
                                minIdx = j;
                        }
                }
                // swap minIndex with arr[j]
                swap(arr[i], arr[minIdx]);
        }
}

//BUBBLE SORTING - best=> 0(N), avg=> 0(N^2), worst=> 0(N^2)
// adjacent se swap karna is the goal
// In bubble sort, after first pass, max el will be the last index

void bubbleSort(int arr[], int n){
        for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - i - 1; j++){
                        if(arr[j] > arr[j + 1]){
                          swap(arr[j], arr[j + 1]);      
                        } 
                }
        }
        
}


//INSERTION SORTING
// goal is to put element in it's correct position 
// swap adjacent peeche jaate jaate if arr[index - 1] > arr[index]
// INSERTION SORTING - best=> 0(N), avg=> 0(N^2), worst=> 0(N^2)


void insertionSort(int arr[], int n){
        for (int i = 0; i < n; i++){
                int index = i;
                while(index > 0 && arr[index - 1] > arr[index]){
                        swap(arr[index - 1], arr[index]);
                        index--;
                }
        }
}





int main() {
        // sample test cases
        // Input: 6
        // 13 46 24 52 20 9
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }

        // Before sorting
        cout << "Before sorting" << endl;
        for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
        }

        // Sorting algo
        insertionSort(arr, n);

        // After sorting
        cout << "\nAfter sorting" << endl;
        for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
        }

        return 0;
}
