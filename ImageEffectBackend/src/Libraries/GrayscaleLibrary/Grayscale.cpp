#include "Grayscale.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
// Function to apply grayscale effect to an image represented by a 2D vector of Pixels
void applyGrayscale(vector<vector<Pixel>> &image){
    // Loop through each row of the image    
    for(int i=0;i<image.size();i++){
        // Loop through each pixel in the current row        
        for(int j=0;j<image[0].size();j++){
            // Calculate grayscale value using the luminosity method
            float f = 0.299*image[i][j].r + 0.587*image[i][j].g + 0.114*image[i][j].b;
            // Update the red channel of the current pixel with the grayscale value, rounding to the nearest integer            
            image[i][j].r = (int)(f+0.5);
            // Update the green channel of the current pixel with the grayscale value, rounding to the nearest integer            
            image[i][j].g = (int)(f+0.5);
            // Update the blue channel of the current pixel with the grayscale value, rounding to the nearest integer            
            image[i][j].b = (int)(f+0.5);
        }
    }
}