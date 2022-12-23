#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>


int Test(int x, int y, std::vector<std::vector<int>>& points) {
    int index = -1;
    int dis = INT_MAX;
    for (int i = 0; i < points.size(); ++i) {
        if (points[i][0] == x) {
            int tmp = std::abs(points[i][1] - y);
            if (tmp < dis) {
                index = i;
                dis = tmp;
            }
        } else (points[i][1] == y) {
            int tmp = std::abs(points[i][0] - x);
            if (tmp < dis) {
                index = i;
                dis = tmp;
            }
        }
    }
    return index;
}



int main() {
    return 0;
}
