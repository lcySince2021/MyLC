#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>



int MiniMumSize(std::vector<int>& nums, int max_operations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int ans = 0;   
    while (left <= right) {
        int y  = (left + right) / 2;
        int ops = 0;
        for (int x : nums) {
            ops += (x - 1) / y;
        }
        if (ops <= max_operations) {
            ans = y;
            right = y - 1;
        } else {
            left = y + 1;
        }
    }
    return ans;
}


int main() {
    std::vector<int> nums{9};
    int max_operations = 2;
    auto res = MiniMumSize(nums, max_operations);
    printf("%d\n", res);
    for (auto num : nums) {
        printf("%d\n", num);
    }

    return 0;
}
