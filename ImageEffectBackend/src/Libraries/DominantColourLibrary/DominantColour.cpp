#include "DominantColour.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*This function iterates over all pixels of the image, and converts their r,g,b values to a single value k by left-shifting
the red colour by 16 and the green colour by 8. This ensures that similar colours map to the similar values of k, and a single
value of k does not have vastly different colours mapped to it. We then use a hash table to store frequencies of all values of k,
and finally we convert the most frequent value of k back to rgb to get the dominant colour*/

void applyDominantColour(vector<vector<Pixel>>& image){
    int nr = image.size(), nc = image[0].size(), s = 255<<16|255<<8|255;
    vector<int> frequencies(s,0);
    for (int i=0; i<nr; i++){
        for (int j=0; j<nc; j++){
            int k = (image[i][j].r<<16)|(image[i][j].g<<8)|(image[i][j].b); //mapping r,g,b to k
            frequencies[k]++;
        }
    }
    int m = max_element(frequencies.begin(),frequencies.end())-frequencies.begin(); //most frequent k
    Pixel dc;
    dc.r = (m>>16) & 0xFF; dc.g = (m>>8) & 0xFF; dc.b = m & 0xFF; //converting k back to rgb
    for (int i=0; i<nr; i++) for (int j=0; j<nc; j++) image[i][j] = dc; //colouring entire image with dominant colour

}