#include "Invert.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
// Function to invert the image (done by inversing the colors of RGB in each pixel)
void applyInvert(vector<vector<Pixel>>& image){
    for(int i=0; i<image.size(); i++){// Iterate through each row of the image
        for(int j=0;j<image[0].size();j++){// Iterate through each pixel in the current row
        // Invert each color channel in the pixel
            image[i][j].r = 255 - image[i][j].r;// Invert the red channel
            image[i][j].g = 255 - image[i][j].g;// Invert the green channel
            image[i][j].b = 255 - image[i][j].b;// Invert the blue channel
        }
    }
}