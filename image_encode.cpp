//
// Created by Nikhil S. Nakhate on 1/18/18.
//

// {7,5,0,0,4,8,6,2}      {}
// {6,0,6,4}              {{-2,0,4,-4}}
// {3,5}                  {{-6,-2},{-2,0,4,-4}}
// {4}                    {{2},{-6,-2},{-2,0,4,-4}}
//

// {4,2,-6,-2,-2,0,4,-4}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

std::vector<float> decode(vector<vector<float>> sep, vector<float>& orig) {
    float sec = 0;
    float fir = 0;

    if(sep.empty())
        return orig;

    vector<float> sw;
    for(int i = 0; i < sep[0].size(); i++) {
        fir = (orig[i] * 2 - sep[0][i]) / 2;
        sec = (orig[i] * 2 + sep[0][i]) / 2;
        sw.push_back(fir);
        sw.push_back(sec);
    }
    orig.swap(sw);
    sep.erase(sep.begin());
    return decode(sep, orig);
}

std::vector<float> call_decode(vector<float> enc) {
    vector<vector<float>> sep;
    vector<float> orig;
    orig.push_back(enc[0]);

    int i = 0;
    while(pow(2, i+1) <= enc.size()) {
        vector<float> temp;
        temp.insert(temp.begin(), enc.begin() + pow(2, i), enc.begin() + pow(2,i+1));
        sep.push_back(temp);
        i++;
    }

    decode(sep, orig);

    return orig;

}


void encode(vector<float> orig, vector<vector<float>>& res) {
    vector<float> avg_res;
    vector<float> fwd_diff_res;
    int sz = orig.size();

    if(orig.size() == 2) {
        res.push_back(vector<float> (1, orig[1] - orig[0]));
        res.push_back(vector<float> (1, (orig[0] + orig[1]) / 2));
        return;
    }
    for(int i = 0; i < orig.size(); i=i+2) {
        avg_res.push_back((orig[i] + orig[i+1]) / 2);
        fwd_diff_res.push_back((orig[i+1] - orig[i]));
    }

    res.push_back(fwd_diff_res);

    return encode(avg_res, res);
}


vector<float> call_encode(vector<float> orig) {

    vector<vector<float>> res;
    vector<float> final_res;

    encode(orig, res);

    reverse(res.begin(), res.end());

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            final_res.push_back(res[i][j]);
        }
    }

    return final_res;

}

int main()
{
    std::vector<float> orig = {7,5,0,0,4,8,6,2};
    vector<float> enc;

    enc = call_encode(orig);

    vector<float> orig_back;
    orig_back = call_decode(enc);

    for(int i = 0; i < orig_back.size(); i++) {
        cout<<orig_back[i]<<"\n";
    }
}