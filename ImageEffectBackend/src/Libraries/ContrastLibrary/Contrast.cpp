#include "Contrast.h"
#include "../Pixel.h"
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
void applyContrast(vector<vector<Pixel>>& image,float amount)
{
    for(int i=0;i<image.size();i++)
    {
        for(int j=0;j<image[i].size();j++)
        {
            image[i][j].r = min(255,(int)(image[i][j].r*amount));
            image[i][j].g = min(255,(int)(image[i][j].g*amount));
            image[i][j].b = min(255,(int)(image[i][j].b*amount));
        }
    }
}