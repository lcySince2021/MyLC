#include <string>
#include <vector>
#include <stdio.h>

int test(std::vector<std::string>& vec) {
    int res = 0;
    for (auto str : vec) {
        if (str == "X++" || str == "++X") {
            res++;
        } else {
            res--;
        }
    }
    return res;
}


int main() {
    std::vector<std::string> vec{"X++", "--X", "--X", "++X"};
    auto res = test(vec);
    printf("%d\n", res);
    return 0;
}
