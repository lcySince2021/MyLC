#include <iostream>
#include <algorithm>
int MaxSouce(int a, int b, int c) {
    int max_num = std::max({a, b, c});
    int sum = a + b + c;
    if (sum - max_num < max_num) {
        return sum - max_num;
    } else {
        return sum / 2;
    }
}

int main() {
    return 0;
}
