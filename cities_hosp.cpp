//
// Created by Nikhil S. Nakhate on 2/28/18.
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<pair<int, int>>& nm, pair<int, int> ele) {
    int i = 0;
    int j = nm.size() - 1;

    int mid = (i + j) / 2;

    while(i < j) {
        if(double(double(nm[mid].first) / nm[mid].second) > double(double(ele.first) / ele.second)) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
        mid = (i + j) / 2;
    }
    return mid;
}

void reduce_key (vector<pair<int, int>>& nm) {
    if(nm[0].first / nm[0].second > nm[1].first / nm[1].second) {
        return;
    }
    pair<int, int> ele = nm[0];
    nm.erase(nm.begin());
    int idx = bin_search(nm, ele);
    nm.insert(nm.begin() + idx + 1, ele);
}


bool comp(pair<int, int> i, pair<int, int> j) {
    return i.first / i.second > j.first / j.second;
}

int main() {

    int N = 7;
    int M = 5;

    vector<pair<int, int>> n_m = {make_pair(40, 1), make_pair(53,1), make_pair(72,1), make_pair(84,1), make_pair(10,1), make_pair(64,1)};
    sort(n_m.begin(), n_m.end(), comp);

    for (int i = 0; i < N - M; i++) {

        n_m[0].second++;
        reduce_key(n_m);
        cout<<n_m[0].first<<'\n';
    }
}
