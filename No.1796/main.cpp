#include <string>
#include <stdio.h>
#include <ctype.h>

int SecondHigh(std::string& str) {
    int first = -1, second = -1;
    for (char n : str) {
        if (isdigit(n)) {
            int tmp = n - '0';
            if (tmp > first) {
                second = first;
                first = tmp;
            } else if (tmp > second && tmp < first) {
                second = tmp;
            }
        }
    }
    return second;
}

int main() {
    std::string ss = "abc12345";
    auto res = SecondHigh(ss);
    printf("%d\n", res);
    return 0;
}
