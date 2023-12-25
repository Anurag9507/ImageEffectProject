#include "Contrast.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
void applyContrast(vector<vector<Pixel>>& image,float amount){//Method to apply contrast
    float f = (259.0*(amount + 155.0))/(255.0*(359.0 - amount));//Constant to apply contrast more effectively
    for (int i=0; i<image.size(); i++) {
        for (int j=0; j<image[0].size(); j++){//Changing contrast by modifiying r,g,b values for every pixel in the image
            image[i][j].r = max(0,min(255,(int)(f*(image[i][j].r - 128) + 128)));
            image[i][j].g = max(0,min(255,(int)(f*(image[i][j].g - 128) + 128)));
            image[i][j].b = max(0,min(255,(int)(f*(image[i][j].b - 128) + 128)));
        }
    }
}