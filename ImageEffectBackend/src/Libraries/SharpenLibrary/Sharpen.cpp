#include "Sharpen.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
void applySharpen(vector<vector<Pixel>>& image,float amount){//Method to sharpen an image
    vector<vector<int>> kernel = {{0,-1,0},{-1,4,-1},{0,-1,0}};
    vector<vector<Pixel>> temp(image);
    for (int i=1; i<image.size()-1; i++){
        for (int j=1; j<image[0].size()-1; j++){//Sharpen every pixel of an image
            float R=0.0, G=0.0, B=0.0;
            for (int x=-1; x<2; x++){
                for (int y=-1; y<2; y++){
                    R += kernel[x+1][y+1] * image[x+i][y+j].r;
                    G += kernel[x+1][y+1] * image[x+i][y+j].g;
                    B += kernel[x+1][y+1] * image[x+i][y+j].b;
                }
            }
            temp[i][j].r = max(0,min(255,(image[i][j].r + (int)(amount * R/16))));
            temp[i][j].g = max(0,min(255,(image[i][j].g + (int)(amount * G/16))));
            temp[i][j].b = max(0,min(255,(image[i][j].b + (int)(amount * B/16))));
        }
    }
    image = temp;
}