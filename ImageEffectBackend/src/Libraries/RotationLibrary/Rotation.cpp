#include "Rotation.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>

#include<bits/stdc++.h>
using namespace std;

void rotateBy90(vector<vector<Pixel>>& image) {
    
    int numRows= int(image.size());
    int numColumns = int(image[0].size());

    vector<vector<Pixel>> image1;
    
    for(int i=numColumns-1; i>=0; i--) {
        
        vector<Pixel> temp;
        for(int j=0; j<numRows; j++) {

            temp.push_back(image[j][i]);
        }

        image1.push_back(temp);
    }

    image = image1;
}


void applyRotation(vector<vector<Pixel>>& image, int value) {

    int numRows= int(image.size());
    int numColumns = int(image[0].size());
    // cout<<value;

    for(int i=0; i<image.size(); i++) {
        for(int j=0; j<image[0].size(); j++) {
            cout<<image[i][j].r<<" ";
        }
        cout<<endl;
    }

    if(value==90) {
        rotateBy90(image);
        
    }
    else if(value==180) {
        rotateBy90(image);
        rotateBy90(image);
    }
    else if(value==270) {
        rotateBy90(image);
        rotateBy90(image);
        rotateBy90(image);
    }

    for(int i=0; i<image.size(); i++) {
        for(int j=0; j<image[0].size(); j++) {
            cout<<image[i][j].r<<" ";
        }
        cout<<endl;
    }

    //ig image is definitely updated but still its not going to the native, lets try return
    // return image;

}
