#include "Brightness.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
void applyBrightness(vector<vector<Pixel>>& image,float amount){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){
            image[i][j].r = max(0,min(255,(int)(image[i][j].r + amount - 100)));
            image[i][j].g = max(0,min(255,(int)(image[i][j].g + amount - 100)));
            image[i][j].b = max(0,min(255,(int)(image[i][j].b + amount - 100)));
        }
    }
}