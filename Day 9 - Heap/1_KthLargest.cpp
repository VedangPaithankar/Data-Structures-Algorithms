/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (const int& num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); // Remove the smallest element if the size exceeds k
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop(); // Remove the smallest element if the size exceeds k
        }
        return pq.top(); // The top element is the kth largest
    }
};