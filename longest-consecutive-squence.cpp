#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> seqMap;
        int longest = 0;
        
        for (int num : nums) {
            
            if (seqMap.find(num) != seqMap.end())
                continue;
            
            int left = (seqMap.find(num - 1) != seqMap.end()) ? seqMap[num - 1] : 0;
        
            int right = (seqMap.find(num + 1) != seqMap.end()) ? seqMap[num + 1] : 0;
            
            int currLength = left + right + 1;
            seqMap[num] = currLength;
            
            seqMap[num - left] = currLength;
            seqMap[num + right] = currLength;
            
            longest = max(longest, currLength);
        }
        return longest;
    }
};
//implementation of class using example
int main() {
    
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    Solution solution;
    
    cout << "Longest consecutive sequence length : " 
         << solution.longestConsecutive(nums) << endl;
    
    
    return 0;
}
