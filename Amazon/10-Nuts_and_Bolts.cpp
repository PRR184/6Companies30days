// Problem:-https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
//Time:O(nlogn)
class Solution{
    int partition(char arr[], int low,int high, char pivot)
    {
        int i = low-1;
        for(int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i],arr[j]);
            }
            else if(arr[j]==pivot){
                swap(arr[j],arr[high]);
                j--;
            }

        }
        i++;
        swap(arr[i],arr[high]);
        return i;
    }
    void quicksort(char nuts[], char bolts[], int low,int high){
        if(low<high){
             int pivot = partition(nuts, low, high, bolts[high]);
             //we used the pivot of nuts as pivot of bolts because,we will get same arrays for both 
             //at each and every step so one quicksort operation enough for both arrays.
             partition(bolts, low, high, nuts[pivot]);
             
             
             quicksort(nuts, bolts, low, pivot - 1);
             quicksort(nuts, bolts, pivot + 1, high);
        }
    }
public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	   quicksort(nuts,bolts,0,n-1);
	}

};