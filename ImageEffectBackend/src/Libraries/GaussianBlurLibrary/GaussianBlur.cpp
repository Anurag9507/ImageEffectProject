#include "../Pixel.h"
#include "GaussianBlur.h"
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void applyGaussianBlur(vector<vector<Pixel>>& image, float radius){
    radius /= 4;
    int nr = image.size();
    int nc = image[0].size();                                                          
    vector<vector<Pixel>> blurredImage(nr, vector<Pixel>(nc,Pixel{0,0,0}));
    int kernelSize = int(2 * radius + 1);                                                
    vector<vector<float>> kernel(kernelSize, vector<float>(kernelSize, 0.0));
    float s = radius / 3.0;
    float tsSquare = 2.0 * s * s;
    float root = 1.0 / (tsSquare * M_PI);
    for (int i=-radius;i<=radius;i++) {
        for (int j=-radius;j<=radius; j++) {
            float distance = float(i*i + j*j);
            kernel[i+radius][j+radius] = exp(-distance/tsSquare)*root;
        }
    }
    for (int i=0;i<nr;i++) {
        for (int j=0;j<nc;j++) {
            float rA = 0.0, gA = 0.0, bA = 0.0;
            for (int ki=0;ki<kernelSize;ki++) {
                for (int kj=0;kj<kernelSize;kj++) {
                    int ri = i + ki - radius;
                    int ci = j + kj - radius;
                    if (ri>=0 && ri<nr && ci>=0 && ci<nc) {
                        rA += kernel[ki][kj] * image[ri][ci].r;
                        gA += kernel[ki][kj] * image[ri][ci].g;
                        bA += kernel[ki][kj] * image[ri][ci].b;
                    }
                }
            }
            blurredImage[i][j].r = clamp(int(rA),0,255);
            blurredImage[i][j].g = clamp(int(gA),0,255);
            blurredImage[i][j].b = clamp(int(bA),0,255);
        }
    }
    image = blurredImage;
}
