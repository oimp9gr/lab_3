#pragma once

#include <vector>

using namespace std;

vector<int> MergeSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    size_t m = nums1.size();
    size_t n = nums2.size();
    vector<int>result(n+m);
    size_t nums1_i = 0, result_i = 0, nums2_i = 0;
    for (; nums1_i < m && nums2_i < n; ++result_i) {
        if (nums1[nums1_i] <= nums2[nums2_i]) {
            result[result_i] = nums1[nums1_i++];
        } else {
            result[result_i] = nums2[nums2_i++];
        }
    }
    for (; nums1_i < m; nums1_i++, result_i++) {
        result[result_i] = nums1[nums1_i];
    }
    for (; nums2_i < n; nums2_i++, result_i++) {
        result[result_i] = nums2[nums2_i];
    }
    return result;
}