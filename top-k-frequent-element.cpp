#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
      
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &entry : frequency) {
            int num = entry.first;
            int freq = entry.second;
            buckets[freq].push_back(num);
        }
        
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result1 = sol.topKFrequent(nums, k);
    cout << "Output for Example: ";
    for (int num : result1)
        cout << num << " ";
    cout << endl;
    return 0;
}

