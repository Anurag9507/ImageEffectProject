#include "DominantColour.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void applyDominantColour(vector<vector<Pixel>>& image){
    int nr = image.size(), nc = image[0].size(), s = 255<<16|255<<8|255;
    vector<int> frequencies(s,0);
    for (int i=0; i<nr; i++){
        for (int j=0; j<nc; j++){
            int k = (image[i][j].r<<16)|(image[i][j].g<<8)|(image[i][j].b);
            frequencies[k]++;
        }
    }
    int m = max_element(frequencies.begin(),frequencies.end())-frequencies.begin();
    Pixel dc;
    dc.r = (m>>16) & 0xFF; dc.g = (m>>8) & 0xFF; dc.b = m & 0xFF;
    for (int i=0; i<nr; i++) for (int j=0; j<nc; j++) image[i][j] = dc;

}