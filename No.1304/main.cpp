#include <vector>
#include <stdio.h>


std::vector<int> SumZero(int n) {
    std::vector<int> vec;
    int bound = n / 2;
    for (int i = 1; i <= bound; ++i) {
        vec.emplace_back(i);
        vec.emplace_back(-i);
    }
    if (n % 2 == 1) vec.emplace_back(0);
    return vec;
}


int main() {
    auto res = SumZero(2);
    for (auto num : res) {
        printf("%d\n", num);
    }
    return 0;
}
