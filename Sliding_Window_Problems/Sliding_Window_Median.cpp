#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
class Solution {
public:
    vector<int> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums; // Special case: each element itself is the median
        }
        
        vector<int> res;
        
        if (k == 2) {
            for (int i = 0; i <= nums.size() - 2; ++i) {
                res.push_back(min(nums[i], nums[i + 1]));
            }
            return res;
        }
        
        multiset<int> low, high;
        
        auto balance = [&]() {
            if (low.size() > high.size() + 1) {
                high.insert(*low.rbegin());
                low.erase(low.find(*low.rbegin()));
            }
            if (low.size() < high.size()) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (nums[i - k] <= *low.rbegin()) {
                    low.erase(low.find(nums[i - k]));
                } else {
                    high.erase(high.find(nums[i - k]));
                }
            }
            
            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
            } else {
                high.insert(nums[i]);
            }
            
            balance();
            
            if (i >= k - 1) {
                res.push_back(*low.rbegin());
            }
        }
        
        return res;
    }
};
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    Solution sol;
    vector<int> result = sol.medianSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
