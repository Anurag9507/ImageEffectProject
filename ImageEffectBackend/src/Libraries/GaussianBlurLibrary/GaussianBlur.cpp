#include "../Pixel.h"
#include "GaussianBlur.h"
#include<bits/stdc++.h>
using namespace std;
void applyGaussianBlur(vector<vector<Pixel>>& image, float radius) {
    int numRows = image.size();
    int numCols = image[0].size();                                                          
    vector<vector<Pixel>> blurredImage(numRows, vector<Pixel>(numCols, Pixel{0, 0, 0}));  // Create a temporary vector to store the blurred values
    int kernelSize = int(2 * radius + 1);                                                // Gaussian kernel generation
    vector<vector<float>> kernel(kernelSize, vector<float>(kernelSize, 0.0));
    float s = radius / 3.0;
    float tsSquare = 2.0 * s * s;
    float root = 1.0 / (tsSquare * M_PI);
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            float distance = float(i * i + j * j);
            kernel[i + radius][j + radius] = exp(-distance / tsSquare) * root;
        }
    }
    // Apply Gaussian blur
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            float rAccumulator = 0.0, gAccumulator = 0.0, bAccumulator = 0.0;
            for (int ki = 0; ki < kernelSize; ++ki) {
                for (int kj = 0; kj < kernelSize; ++kj) {
                    int ri = i + ki - radius;
                    int ci = j + kj - radius;
                    if (ri >= 0 && ri < numRows && ci >= 0 && ci < numCols) {
                        rAccumulator += kernel[ki][kj] * image[ri][ci].r;
                        gAccumulator += kernel[ki][kj] * image[ri][ci].g;
                        bAccumulator += kernel[ki][kj] * image[ri][ci].b;
                    }
                }
            }
            blurredImage[i][j].r = int(rAccumulator);
            blurredImage[i][j].g = int(gAccumulator);
            blurredImage[i][j].b = int(bAccumulator);
        }
    }
    image = blurredImage;
}
