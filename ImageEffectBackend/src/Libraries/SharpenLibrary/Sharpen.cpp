#include "Sharpen.h"
#include "../Pixel.h"
#include <vector>
using namespace std;

/*Sharpening is done by convoluting all pixels of the image with a 3x3 convolution matrix, which then creates a weighted sum of
that pixel and it's neighbours, but emphasizes the contribution of the central pixel. So the resultant image appears sharper
with enhanced edges and details*/

void applySharpen(vector<vector<Pixel>>& image,float amount){
    vector<vector<int>> kernel = {{0,-1,0},{-1,4,-1},{0,-1,0}}; //3x3 convolution kernel
    vector<vector<Pixel>> temp(image);
    for (int i=1; i<image.size()-1; i++){ //iterating over the entire image, excluding borders
        for (int j=1; j<image[0].size()-1; j++){
            float R=0.0, G=0.0, B=0.0;
            for (int x=-1; x<2; x++){
                for (int y=-1; y<2; y++){
                    R += kernel[x+1][y+1] * image[x+i][y+j].r; //convolution operation
                    G += kernel[x+1][y+1] * image[x+i][y+j].g;
                    B += kernel[x+1][y+1] * image[x+i][y+j].b;
                }
            }
            temp[i][j].r = max(0,min(255,(image[i][j].r + (int)(amount * R/16)))); //clamping to 0,255
            temp[i][j].g = max(0,min(255,(image[i][j].g + (int)(amount * G/16))));
            temp[i][j].b = max(0,min(255,(image[i][j].b + (int)(amount * B/16))));
        }
    }
    image = temp;
}