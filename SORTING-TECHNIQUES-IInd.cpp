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
