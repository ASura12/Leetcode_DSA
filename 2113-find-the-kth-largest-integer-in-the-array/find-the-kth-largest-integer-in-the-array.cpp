struct Compare {
    bool operator()(string a, string b) {
        if (a.size() != b.size())
            return a.size() > b.size();   // smaller length = smaller number

        return a > b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> minHeap;

        for (string s : nums) {
            minHeap.push(s);

            if (minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};