#include "Contrast.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
/*
    This function modifies the red, green, and blue components of each pixel
    in the image to enhance or reduce contrast based on the specified amount.
    It utilizes a constant 'f' to apply contrast more effectively.
*/
void applyContrast(vector<vector<Pixel>>& image,float amount){
    float f = (259.0*(amount + 155.0))/(255.0*(359.0 - amount));// Calculate a factor 'f' to apply contrast more effectively
    for (int i=0; i<image.size(); i++) {
        for (int j=0; j<image[0].size(); j++){// Changing contrast by modifying r, g, b values for every pixel in the image
            image[i][j].r = max(0,min(255,(int)(f*(image[i][j].r - 128) + 128)));// Update the red component of the pixel
            image[i][j].g = max(0,min(255,(int)(f*(image[i][j].g - 128) + 128)));// Update the green component of the pixel
            image[i][j].b = max(0,min(255,(int)(f*(image[i][j].b - 128) + 128)));// Update the blue component of the pixel
        }
    }
}