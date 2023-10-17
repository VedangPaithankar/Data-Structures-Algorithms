/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

https://leetcode.com/problems/k-closest-points-to-origin/description/
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> pts, int k) {
        multimap<int, int> mp;
        for (int i = 0; i < pts.size(); i++) {
            int x = pts[i][0], y = pts[i][1];
            mp.insert({(x * x) + (y * y), i});
        }

        vector<vector<int>> result;
        for (auto it = mp.begin(); it != mp.end() && k > 0; it++, k--) {
            result.push_back({pts[it->second][0], pts[it->second][1]});
        }

        return result;
    }
};
