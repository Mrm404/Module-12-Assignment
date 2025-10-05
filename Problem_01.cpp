#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int find_kth_largest(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num); 
        if (minHeap.size() > k) {
            minHeap.pop(); 
        }
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "th largest element is: " << find_kth_largest(nums, k) << endl;
    return 0;
}

/*
Time Complexity: O(n log k), because each insertion/pop in the heap is log k and we do it n times.
Space Complexity: O(k), since heap stores at most k elements.
*/
