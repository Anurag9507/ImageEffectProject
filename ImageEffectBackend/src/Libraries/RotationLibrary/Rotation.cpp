#include "Rotation.h"
#include "../Pixel.h"
#include <vector>
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
    if(value==1) {
        rotateBy90(image);  
    }
    else if(value==2) {
        rotateBy90(image);
        rotateBy90(image);
    }
    else if(value==3){
        rotateBy90(image);
        rotateBy90(image);
        rotateBy90(image);
    }
}
