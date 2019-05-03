#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<float>> rotate(vector<vector<float>> result_step2, float theta) {

    for(int i=0; i<cols; i++)
    {
        for(int j=1; j<=rows; j++)
        {
            datOut[i][j]= datIn[rows-j][i];
        }
    }

}


vector<vector<float>> convolve(vector<vector<int>> &input, vector<vector<float>> &kernel)
{
    int inRows = input.size();

    int inCols = input[0].size();


    int kRows = kernel.size();
    int kCols = kernel[0].size();

    int rows = inRows - kRows + 1;
    int cols = inCols - kCols + 1;

    std::vector <std::vector<float> > output(rows, std::vector<float>(cols, 1));

    int convolve = 0; // This holds the convolution results for an index.
    int x, y; // Used for input matrix index

    // Fill output matrix: rows and columns are i and j respectively
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            x = i;
            y = j;

            // Kernel rows and columns are k and l respectively
            for (int k = 0; k < kRows; k++)
            {
                for (int l = 0; l < kCols; l++)
                {
                    // convolve here.
                    //cout<<convolve<<"\n";
                    convolve += kernel[k][l] * input[x][y];
                    y++; // Move right.
                }
                x++; // Move down.
                y = j; // Restart column position
            }

            output[i][j] = convolve; // Add result to output matrix.
            cout<<output[i][j]<<"\n";
            convolve = 0; // Needed before we move on to the next index.
        }
    }
    return output;

}
//
//
vector<vector<float>> setRandomZero(vector<vector<float>> result_step1, int k) {
    int numOfRows = result_step1.size();
    int numOfCols = result_step1.at(0).size();
    int rangeOfIdx = numOfRows*numOfCols;

    vector<int> chosen;
    for(int i=0; i < rangeOfIdx; i++) {
        chosen.push_back(i);
        //cout<<"chosen="<<i<<endl;
    }

    srand(time(NULL));
    int c = 0;
    while(chosen.size() > 0 && c < k) {
        int randomIdx =  rand() % chosen.size();

        int idx = chosen.at(randomIdx);
        //cout<<"size="<<chosen.size()<<" Random="<<randomIdx<<" Idx="<<idx<<endl;
        chosen.erase(chosen.begin() + randomIdx);

        int x = idx / numOfCols;
        int y = idx % numOfCols;
        result_step1.at(x).at(y) = 0;
        c++;
    }

    return result_step1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Simple template as follows, you may also use 2D array to store an image

    vector<vector<int> > input = {{1, 1, 5, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1}};
    vector<vector<float> > kernel = {{0, 1, 0},
                                     {0, 1, 0},
                                     {0, 0, 0}};

    const int k = 7;

    const float theta = 90;

    cout<<input[0][0]<<"\n";

    vector<vector<float> > result_step1 = convolve(input, kernel);




    /*
      acceptable output:
      {{ 2, 6, 2},
        {2, 2, 2},
        {2, 2, 2}};
    */




    /*
      acceptable output:
      {{ 0, 2, 0},
        {0, 0, 0},
        {2, 0, 0}};
    */
    vector<vector<float> > result_step2 = setRandomZero(result_step1, k);

    /*
      acceptable output:
      {{ 0, 0, 0},
        {2, 0, 0},
        {0, 0, 2}};
    */
    //vector<vector<float> > result_step3 = rotate(result_step2, theta);

    /*
      acceptable output: 2
    */
    //int connected_areas = connectedComponent(result_step3);
    return 0;
}





