#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size() / 2)];
    }
};
int main() {
    vector<int> vec = { 2, 2, 1, 1, 1, 2, 2 };
    Solution s1;
    cout << s1.majorityElement(vec);
}
