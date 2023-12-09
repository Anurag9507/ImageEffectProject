#include "Flip.h"
#include "../Pixel.h"
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
void applyFlip(vector<vector<Pixel>>& image, int horizontalFlipValue, int verticalFlipValue) {
    if (horizontalFlipValue != 0) {
        for (auto& row : image) {
            reverse(row.begin(), row.end());
        }
    }
    if (verticalFlipValue != 0) {
        int N = int(image.size());
        int L = int(image[0].size());
        for (int i=0;i < N / 2;i++) {
            for (int j=0;j<L;j++) {
                swap(image[i][j], image[N - i - 1][j]);
            }
        }
    }
}
