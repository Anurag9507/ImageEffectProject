#include "Sepia.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
// Function to apply sepia effect to an image represented by a 2D vector of Pixels
void applySepia(vector<vector<Pixel>> &image){
    // Loop through each row of the image
    for(int i=0;i<image.size();i++){
        // Loop through each pixel in the current row
        for(int j=0;j<image[0].size();j++){
            // Calculate sepia values for each color channel of the current pixel        
            float tr = 0.393*image[i][j].r + 0.769*image[i][j].g + 0.189*image[i][j].b;
            float tg = 0.349*image[i][j].r + 0.686*image[i][j].g + 0.168*image[i][j].b;
            float tb = 0.272*image[i][j].r + 0.534*image[i][j].g + 0.131*image[i][j].b;
            // Update the red channel of the current pixel with the sepia value, clamping it to the range [0, 255]            
            image[i][j].r = max(0,min(255,(int)(tr+0.5)));
            // Update the green channel of the current pixel with the sepia value, clamping it to the range [0, 255]            
            image[i][j].g = max(0,min(255,(int)(tg+0.5)));
            // Update the blue channel of the current pixel with the sepia value, clamping it to the range [0, 255]            
            image[i][j].b = max(0,min(255,(int)(tb+0.5)));
        }
    }
}