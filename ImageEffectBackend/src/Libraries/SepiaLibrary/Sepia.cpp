#include "Sepia.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
void applySepia(vector<vector<Pixel>> &image){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            float tr = 0.393*image[i][j].r + 0.769*image[i][j].g + 0.189*image[i][j].b;
            float tg = 0.349*image[i][j].r + 0.686*image[i][j].g + 0.168*image[i][j].b;
            float tb = 0.272*image[i][j].r + 0.534*image[i][j].g + 0.131*image[i][j].b;

            image[i][j].r = max(0,min(255,(int)(tr+0.5)));
            image[i][j].g = max(0,min(255,(int)(tg+0.5)));
            image[i][j].b = max(0,min(255,(int)(tb+0.5)));
        }
    }
}