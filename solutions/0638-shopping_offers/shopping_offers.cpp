//
// Created by 赵丹 on 2023/12/31.
//
#include "utils.h"
namespace ShoppingOffers {
class Solution {
public:
    int shoppingOffers(std::vector<int>& price,
                       std::vector<std::vector<int>>& special,
                       std::vector<int>& needs) {
        std::vector<std::vector<int>> new_special;
        for (const std::vector<int>& v: special) {
            int cost = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                cost += v[i] * price[i];
            }
            if (cost > v.back()) {
                new_special.push_back(v);
            }
        }

        backtrack(price, new_special, needs, 0);
        return min_cost;
    }

    void backtrack(std::vector<int>& price,
                   std::vector<std::vector<int>>& special,
                   std::vector<int>& needs,
                   int start) {
        if (track_cost >= min_cost) {
            return;
        }

        bool use_special = false;
        for (int i = start; i < special.size(); i++) {
            if (!canUseSpecial(special[i], needs)) {
                continue;
            }
            use_special = true;

            for (int j = 0; j < needs.size(); j++) {
                needs[j] -= special[i][j];
            }
            track_cost += special[i].back();
            backtrack(price, special, needs, i);

            for (int j = 0; j < needs.size(); j++) {
                needs[j] += special[i][j];
            }
            track_cost -= special[i].back();
        }

        if (!use_special) {
            int sum = 0;
            for (int i = 0; i < needs.size(); i++) {
                sum += needs[i] * price[i];
            }
            min_cost = std::min(min_cost, sum + track_cost);
        }
    }

    static bool canUseSpecial(std::vector<int>& special, std::vector<int>& need) {
        for (int i = 0; i < need.size(); i++) {
            if (special[i] > need[i]) {
                return false;
            }
        }
        return true;
    }

private:
    int track_cost{0};
    int min_cost{INT32_MAX};
};
}// namespace ShoppingOffers

TEST(Solution, shoppingOffers) {
    ShoppingOffers::Solution sln;
    // case1
    std::vector<int> price1 = {2, 5};
    std::vector<std::vector<int>> special1 = {{3, 0, 5}, {1, 2, 10}};
    std::vector<int> needs1 = {3, 2};
    EXPECT_EQ(sln.shoppingOffers(price1, special1, needs1), 14);
}