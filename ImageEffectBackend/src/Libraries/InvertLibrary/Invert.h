// The following code is a header file guard to prevent multiple inclusions of the 'Invert.h' header.
#ifndef INVERT_H
#define INVERT_H

// Include necessary headers for the code
#include <vector>
#include "../Pixel.h"
using namespace std;
// Declaration of the function 'applyInvert'
// This function takes a 2D vector representing an image, where each element is a Pixel object.
// The function inverts the colors of the image by subtracting each color channel value from 255.
void applyInvert(std::vector<std::vector<Pixel>>& image);

// End of the header file guard
#endif
