#include "Flip.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
// Function to apply horizontal and vertical flips to a 2D vector of pixels
void applyFlip(vector<vector<Pixel>>& image,int hf,int vf){
    if (hf !=0) for (auto& row:image) reverse(row.begin(),row.end());  // Check if horizontal flip is requested and than Iterate through each row in the image and reverse the order of pixels
    if (vf !=0) reverse(image.begin(),image.end()); // Check if vertical flip is requested and than Reverse the order of rows in the entire image
}