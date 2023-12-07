#include "Grayscale.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
void applyGrayscale(vector<vector<Pixel>> &image){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            float f = 0.299*image[i][j].r + 0.587*image[i][j].g + 0.114*image[i][j].b;
            image[i][j].r = (int)(f+0.5);
            image[i][j].g = (int)(f+0.5);
            image[i][j].b = (int)(f+0.5);
        }
    }
}