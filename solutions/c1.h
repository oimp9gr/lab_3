#pragma once

#include <vector>

using namespace std;

vector<int> MergeSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
    size_t m = nums1.size();
    size_t n = nums2.size();
    vector<int> result(n + m);
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

vector<int> MergeSortRecursive(vector<int> &v, size_t left, size_t right) {
    if (right == left + 1) {
        return {v[left]};
    } else {
        auto left_array = MergeSortRecursive(v, left, left + (right - left) / 2);
        auto right_array = MergeSortRecursive(v, left + (right - left) / 2, right);
        return MergeSortedArrays1(left_array, right_array);
    }
}

void MergeSort(vector<int> &v) {
    if (v.empty()) return;
    v = MergeSortRecursive(v, 0, v.size());
}