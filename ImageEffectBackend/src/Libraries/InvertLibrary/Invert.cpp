#include "Invert.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyInvert(vector<vector<Pixel>>& image){
    for(int i=0; i<image.size(); i++){
        for(int j=0;j<image[0].size();j++){
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }
}
