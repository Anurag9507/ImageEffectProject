#include "HueSaturation.h"
#include "../Pixel.h"
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<float> RGBtoHSV(float r, float g, float b) { 
    r /= 255.0; g /= 255.0; b /= 255.0;
    float cmax=max({r,g,b}), cmin=min({r,g,b}), diff=cmax-cmin, h=-1, s=-1, v=cmax*100;
    if (cmax==cmin) h=0;
    else if (cmax==r) h=fmod(60 *((g-b) / diff) + 360, 360); 
    else if (cmax == g) h = fmod(60 * ((b - r) / diff) + 120, 360); 
    else if (cmax == b) h = fmod(60 * ((r - g) / diff) + 240, 360); 
    if (cmax == 0) s = 0; 
    else s = (diff / cmax) * 100;
    return {h,s,v};
}

vector<float> HSVtoRGB(float h,float s,float v){
    float c=v*s, H=h/60, x=c*(1-abs(fmod(H,2)-1));
    if (H<1){
        vector<float> HSV = {c,x,0};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    else if (H<2){
        vector<float> HSV = {x,c,0};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    else if (H<3){
        vector<float> HSV = {0,c,x};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    else if (H<4){
        vector<float> HSV = {0,x,c};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    else if (H<5){
        vector<float> HSV = {x,0,c};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    else if (H<6){
        vector<float> HSV = {c,0,x};
        int m = v-c; HSV[0] += m; HSV[1] += m; HSV[2] += m;
        return HSV;
    }
    return {0,0,0};
}

vector<float> apply(vector<vector<float>> mat,float r,float g,float b){
    vector<float> result;
    float R = r * mat[0][0] + g * mat[0][1] + b * mat[0][2];
    float G = r * mat[1][0] + g * mat[1][1] + b * mat[1][2];
    float B = r * mat[2][0] + g * mat[2][1] + b * mat[2][2];
    result.push_back(R);
    result.push_back(G);
    result.push_back(B);
    return result;
}

void applyHueSaturation(vector<vector<Pixel>> &image,float hv,float sv){
    vector<vector<float>> mat;
    for(int i=0; i<3; i++){
        vector<float> temp;
        for (int j=0; j<3; j++) temp.push_back(0);
        mat.push_back(temp);
    }

    float cosA = cos(hv*M_PI*M_PI/180), sinA = sin(hv*M_PI*M_PI/180);
    mat[0][0] = cosA + (1.0-cosA) / 3.0;
    mat[0][1] = 1./3. * (1.0-cosA)-sqrt(1./3.) * sinA;
    mat[0][2] = 1./3. * (1.0-cosA)+sqrt(1./3.) * sinA;
    mat[1][0] = 1./3. * (1.0-cosA)+sqrt(1./3.) * sinA;
    mat[1][1] = cosA + 1./3. * (1.0-cosA);
    mat[1][2] = 1./3. * (1.0-cosA)-sqrt(1./3.) * sinA;
    mat[2][0] = 1./3. * (1.0-cosA)-sqrt(1./3.) * sinA;
    mat[2][1] = 1./3. * (1.0-cosA)+sqrt(1./3.) * sinA;
    mat[2][2] = cosA + 1./3. * (1.0-cosA);

    for (int i=0; i<image.size(); i++){
        for (int j=0; j<image[0].size(); j++){
            vector<float> vals = apply(mat,image[i][j].r,image[i][j].g,image[i][j].b);
            image[i][j].r = max(0,min(255,(int)(vals[0])));
            image[i][j].g = max(0,min(255,(int)(vals[1])));
            image[i][j].b = max(0,min(255,(int)(vals[2])));
        }
    }
    for (int i=0; i<image.size(); i++)
        for (int j=0; j<image[0].size(); j++){
            vector<float> hsv = RGBtoHSV(image[i][j].r,image[i][j].g,image[i][j].b);
            vector<float> rgb = HSVtoRGB(hsv[0],sv/50,hsv[2]);
            image[i][j].r = max(0,min(255,(int)(hsv[2] + rgb[0])));
            image[i][j].g = max(0,min(255,(int)(hsv[2] + rgb[1])));
            image[i][j].b = max(0,min(255,(int)(hsv[2] + rgb[2])));
        }
}


