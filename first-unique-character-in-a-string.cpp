#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    
    int firstUniqChar(string s) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
  
    string s = "leetcode";
    cout << "Output for " << s << " : " << sol.firstUniqChar(s)<< endl;
    
    return 0;
}
