#include "Rotation.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyRotation(vector<vector<Pixel>>& image,int value){
    //value =1 represents 90 degree, 2 represents 180 degree, 3 represents 270 degree 
    while(value--){
        vector<vector<Pixel>> temp; //we created a temporary 2d vector of pixels

        //we are iterating over the number of rows of our original image
        for(int i=image[0].size()-1; i>=0; i--){

            //we created a temporary row where we push an entire column starting from the last till the first
            /*
            for ex: 1 2 3 
                    4 5 6
                    7 8 9

                    say above thing is our img and then initially we push the column 3 6 9 into our "row" vector 
            */
            vector<Pixel> row;
            for(int j=0; j<image.size(); j++) row.push_back(image[j][i]);
            temp.push_back(row);
            //now we push this row to the temp image and hence 9

            /* 
                so for value =1 finally our image becomes 
                3 6 9
                2 5 8
                7 8 9
            */
        }
        image = temp;
    }
}
