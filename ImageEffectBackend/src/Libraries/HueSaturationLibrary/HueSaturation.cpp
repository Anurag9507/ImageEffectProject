#include "HueSaturation.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void applyHueSaturation(vector<vector<Pixel>> &image,float hv,float sv){
    float s = max(0.0,min(1.0,sv/100.0));
    float h = hv*3.6;
    for (int i=0; i<image.size(); i++){
        for (int j=0; j<image[0].size();j++){
            float maxVal = max({image[i][j].r,image[i][j].g,image[i][j].b});
            float minVal = min({image[i][j].r,image[i][j].g,image[i][j].b});
            float l = (maxVal + minVal) / 200.0;
            float c = (1 - abs(2*l - 1)) * s;
            float x = c*(1-abs(fmod(h/60.0,2)-1));
            float m = (l-c)/2;
            float r,g,b;
            if (h<60){
                r = c; g = x; b = 0;
            } 
            else if (h<120){
                r = x; g = c; b = 0;
            }
            else if (h<180){
                r = 0; g = c; b = x;
            } 
            else if (h<240){
                r = 0; g = x; b = c;
            } 
            else if (h<300){
                r = x; g = 0; b = c;
            } 
            else{
                r = c; g = 0; b = x;
            }
            image[i][j].r = (min(255,(int)(abs(r + m)*255)));
            image[i][j].g = (min(255,(int)(abs(g + m)*255)));
            image[i][j].b = (min(255,(int)(abs(b + m)*255)));
        }
    }
}

