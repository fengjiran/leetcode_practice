//
// Created by richard on 12/23/23.
//

#ifndef LEETCODE_PRACTICE_UTILS_H
#define LEETCODE_PRACTICE_UTILS_H

#include "gtest/gtest.h"

bool Compare2DVector(std::vector<std::vector<int>> &nums1, std::vector<std::vector<int>> &nums2) {
    std::stable_sort(nums1.begin(), nums1.end());
    std::stable_sort(nums2.begin(), nums2.end());
    if (nums1.size() != nums2.size()) {
        return false;
    }

    for (int i = 0; i < nums1.size(); i++) {
        bool isEqual = std::equal(nums1[i].begin(), nums1[i].end(),
                                  nums2[i].begin(), nums2[i].end());
        if (!isEqual) {
            return false;
        }
    }
    return true;
}

#endif //LEETCODE_PRACTICE_UTILS_H
