//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans = 0;
    // Merge function to merge two sorted halves and count inversions
    void merge(long long low, long long mid, long long high, long long arr[]) {
        vector<long long> temp;
        long long left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                // If arr[left] > arr[right], it forms inversion with all elements from left to mid
                ans += (mid - left + 1);
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high) temp.push_back(arr[right++]);

        // Copy elements from temp back to original array
        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Merge Sort function
    void mergeSort(long long low, long long high, long long arr[]) {
        if (low < high) {
            long long mid = (low + high) / 2;
            mergeSort(low, mid, arr);
            mergeSort(mid + 1, high, arr);
            merge(low, mid, high, arr);
        }
    }

    // Function to count inversions in the array
    long long int inversionCount(long long arr[], long long N) {
        long long start = 0, end = N - 1;
        mergeSort(start, end, arr);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends