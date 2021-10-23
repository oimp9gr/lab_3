#pragma once

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Stats {
    size_t size;
    int64_t range;
    double mean;
    double median;
    int32_t mode;
};

double GetMedian(const vector<int> &sorted_array) {
    if (sorted_array.size() % 2) {
        return sorted_array[sorted_array.size() / 2];
    } else {
        return (sorted_array[(sorted_array.size() / 2) - 1] + sorted_array[sorted_array.size() / 2]) / 2.;
    }
}

double GetMean(const vector<int> array) {
    int64_t sum = 0;
    vector<int> numbers(1000);
    for (auto elem: array) {
        numbers[elem]++;
        sum += elem;
    }
    return static_cast<double>(sum) / array.size();
}

int GetMode(vector<int> sorted_array) {
    int cur_mode;
    size_t max_mode_occurrences = 0;
    long long prev_num = -INT_MAX - 1;
    size_t cur_mode_occurrences = 0;
    for (int num: sorted_array) {
        if (num != prev_num) {
            if (cur_mode_occurrences > max_mode_occurrences) {
                cur_mode = prev_num;
                max_mode_occurrences = cur_mode_occurrences;
            }
            prev_num = num;
            cur_mode_occurrences = 0;
        }
        cur_mode_occurrences++;
    }
    return cur_mode;
}

Stats GetStats(vector<int> sample) {
    sort(sample.begin(), sample.end());
    Stats stats;
    stats.size = sample.size();
    stats.median = GetMedian(sample);
    stats.range = sample[stats.size - 1] - sample[0];
    stats.mean = GetMean(sample);
    stats.mode = GetMode(sample);
    return stats;
}