#include "../Pixel.h"
#include "GaussianBlur.h"
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*This function blurs an image by convoluting all pixels with a Gaussian kernel which gives more weight to
nearby pixels, and less weight to distant ones. The kernel values are calculated using the gaussian function and depend on 
the radius given. The reultant image is a blurred, smoothed-out version of the original*/

void applyGaussianBlur(vector<vector<Pixel>>& image,float radius){                                                        
    vector<vector<Pixel>> blurredImage(image.size(),vector<Pixel>(image[0].size(),Pixel{0,0,0})); //empty temporary image
    int kernelSize = int(2*radius + 1);                                                
    vector<vector<float>> kernel(kernelSize, vector<float>(kernelSize,0.0));
    float s = 2.0 * radius * radius / 9.0;
    float root = 1.0 / (s*M_PI);
    for (int i= -radius; i<=radius; i++){ //computing Gaussian kernel weights, and normalising the kernel
        for (int j=-radius; j<=radius; j++){
            float distance = float(i*i + j*j);
            kernel[i+radius][j+radius] = exp(-distance/s)*root;
        }
    }
    for (int i=0; i<image.size(); i++){ //convoluting each pixel with the Gaussian kernel
        for (int j=0; j<image[0].size(); j++){
            float R = 0.0, G = 0.0, B = 0.0;
            for (int x=0; x<kernelSize; x++){
                for (int y=0; y<kernelSize; y++){
                    int ri = i + x - radius;
                    int ci = j + y - radius;
                    if (ri>=0 && ri<image.size() && ci>=0 && ci<image[0].size()){
                        R += kernel[x][y] * image[ri][ci].r;
                        G += kernel[x][y] * image[ri][ci].g;
                        B += kernel[x][y] * image[ri][ci].b;
                    }
                }
            }
            blurredImage[i][j].r = clamp(int(R),0,255); //clamping values to 0,255
            blurredImage[i][j].g = clamp(int(G),0,255);
            blurredImage[i][j].b = clamp(int(B),0,255);
        }
    }
    if(radius!=0) image = blurredImage; //replacing original image with blurred image
}
