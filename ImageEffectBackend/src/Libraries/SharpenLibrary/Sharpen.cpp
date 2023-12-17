#include "Sharpen.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
void applySharpen(vector<vector<Pixel>> &image,float amount){
    float kernel[3][3] = {{-1,-1,-1},{-1,9,-1},{-1,-1,-1}};
    for (int i=1 ; i<image.size()-1 ; i++) {
        for (int j=1 ; j<image[0].size()-1 ; j++){
            float R = 0.0, G = 0.0, B = 0.0;
            for (int k = -1; k <= 1; k++){
                for (int l = -1; l <= 1; ++l) {
                    R += kernel[k + 1][l + 1] * image[i + k][j + l].r;
                    G += kernel[k + 1][l + 1] * image[i + k][j + l].g;
                    B += kernel[k + 1][l + 1] * image[i + k][j + l].b;
                }
            }
            R = (1 - amount) * image[i][j].r + amount * R;
            G = (1 - amount) * image[i][j].g + amount * G;
            B = (1 - amount) * image[i][j].b + amount * B;
            image[i][j].r = max(0,min(255,(int)(image[i][j].r + amount * R + 0.5)));
            image[i][j].g = max(0,min(255,(int)(image[i][j].g + amount * G + 0.5)));
            image[i][j].b = max(0,min(255,(int)(image[i][j].b + amount * B + 0.5)));
        }
    }
}