```
[link](https://leetcode.com/problems/kth-largest-element-in-an-array/)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 1. O(nlogn) sort the array and find kth number
        // 2. O(nlogk) maintain a heap of size k containing the k largest elements
        // i.e minHeap (minimum element on top)
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

```