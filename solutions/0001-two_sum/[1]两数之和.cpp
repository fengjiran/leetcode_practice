#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> val2idx;
        for (int i = 0; i < nums.size(); i++) {
            if (val2idx.count(target - nums[i])) {
                return {i, val2idx[target - nums[i]]};
            } else {
                val2idx[nums[i]] = i;
            }
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
