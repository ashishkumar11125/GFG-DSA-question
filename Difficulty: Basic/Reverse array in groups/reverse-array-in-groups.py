#User function template for Python

class Solution:
    # Function to reverse every sub-array group of size k.
    def reverseInGroups(self, arr, k):
        for i in range(0,len(arr),k):
            arr[i:i+k] = reversed(arr[i:i+k])