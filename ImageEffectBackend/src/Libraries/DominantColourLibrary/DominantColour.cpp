#include "DominantColour.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
void applyDominantColour(vector<vector<Pixel>>& image){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){
            image[i][j].r = 255;
            image[i][j].g = 0;
            image[i][j].b = 0;
        }
    }
}