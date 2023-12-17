#include "Rotation.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyRotation(vector<vector<Pixel>>& image,int value){
    while(value--){
        vector<vector<Pixel>> temp;
        for(int i=image[0].size()-1; i>=0; i--){
            vector<Pixel> row;
            for(int j=0; j<image.size(); j++) row.push_back(image[j][i]);
            temp.push_back(row);
        }
        image = temp;
    }
}
