#include "Invert.h"
#include "../Pixel.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Function to invert the image (done by inversing the colors of RGB in each pixel)
void applyInvert(vector<vector<Pixel>>& image) {
    // Iterate through each row of the image
    for (auto& row : image) {
        // Iterate through each pixel in the current row
        for (auto& pixel : row) {
            // Invert each color channel in the pixel
            pixel.r = 255 - pixel.r;  // Invert the red channel
            pixel.g = 255 - pixel.g;  // Invert the green channel
            pixel.b = 255 - pixel.b;  // Invert the blue channel
        }
    }
}

// Comments for the entire code file:
// This file defines the function 'applyInvert', which inverts the colors of an image
// represented as a 2D vector of Pixel objects. The inversion is achieved by subtracting
// each color channel value from 255. The file includes necessary headers and uses the
// 'std' namespace for convenience.
