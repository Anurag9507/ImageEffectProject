#include "Flip.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
using namespace std;
void applyFlip(vector<vector<Pixel>>& image,int hf,int vf){
    if (hf !=0) for (auto& row:image) reverse(row.begin(),row.end());
    if (vf !=0) reverse(image.begin(),image.end());
}