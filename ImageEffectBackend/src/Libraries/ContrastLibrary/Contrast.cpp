#include "Contrast.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
void applyContrast(vector<vector<Pixel>>& image,float amount){
    amount /= 100
    for (int i=0; i<image.size(); i++) {
        for (int j=0; j<image[0].size(); j++){
            image[i][j].r = (int)((image[i][j].r - 128) * amount + 128);
            image[i][j].g = (int)((image[i][j].g - 128) * amount + 128);
            image[i][j].b = (int)((image[i][j].b - 128) * amount + 128);

            image[i][j].r = max(0,min(255,image[i][j].r));
            image[i][j].g = max(0,min(255,image[i][j].g));
            image[i][j].b = max(0,min(255,image[i][j].b));
        }
    }
}