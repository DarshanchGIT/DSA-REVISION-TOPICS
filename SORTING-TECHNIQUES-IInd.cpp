//MERGE SORT => T.C: Average/Best/worst = 0(N*log(N)) & S.C: 0(1) + 0(N) auxiliary stack space.

#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}


//QUICK SORT => T.C: Average/Best = 0(N*log(N)), worst => 0(N^2) & S.C: 0(1) + 0(N) auxiliary stack space.


class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {   
        // helper(arr, low, high);
        if (low < high){
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int i = low, j = high;
       int pivotEl = arr[low];
       
       //first swap will be done for saare chote ko left me laane k liye
       //second swap will be done for saare bade ko right me laane k liye
        while(i < j){
            //finding bada in the left
            while( i < high && pivotEl >= arr[i]) i+=1;
            //finding bada in the right
            while( j > low && pivotEl < arr[j]) j-=1;
            
            //ab i left of pivot m pivotEl se bade par hai and 
            // j right of pivot m pivotEl se chote par hai
            if(i < j) swap(arr[i], arr[j]);
        }
        //now this next shift will be for pivotEl ko uski jagah par 
        swap(arr[low], arr[j]);
        return j;
    }
};
