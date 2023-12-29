#include "Brightness.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
/*
    This function modifies the red, green, and blue components of each pixel
    in the image to adjust brightness based on the specified amount.
*/
void applyBrightness(vector<vector<Pixel>>& image,float amount){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){//Changing brightness by modifiying r, g, b values for every pixel in the image
            image[i][j].r = max(0,min(255,(int)(image[i][j].r + amount - 100)));// Update the red component of the pixel
            image[i][j].g = max(0,min(255,(int)(image[i][j].g + amount - 100)));// Update the green component of the pixel
            image[i][j].b = max(0,min(255,(int)(image[i][j].b + amount - 100)));// Update the blue component of the pixel
        }
    }
}