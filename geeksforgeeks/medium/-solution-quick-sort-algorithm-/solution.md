# ???? Solution: Quick Sort Algorithm ????

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Medium
- **URL:** https://www.geeksforgeeks.org/problems/quick-sort/1
- **Date:** 2026-04-29

## Solution

```cpp
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
     if(low<high)
     {
         int part = partition(arr, low, high);
         quickSort(arr,low, part-1 );
          quickSort(arr,part, high );
     }
    }
  public:
    int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high-1; j++ ){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
        return i+1;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
