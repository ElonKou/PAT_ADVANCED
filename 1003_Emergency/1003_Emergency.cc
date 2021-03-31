/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 1003_Emergency.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Thu 18 Mar 2021 05:37:24 PM CST
================================================================*/

#include <iostream>
#include <unordered_map>
#include <vector>

#define INF 99

using namespace std;

void dijstra(vector<vector<int>>& data, vector<int>& aids, int st, int ed) {
    unordered_map<int, bool> flag; // distance between st and other points.
    vector<int> paths;             // selected points.
    vector<int> paths_cnts;        // numbers between st to other points.
    vector<int> aids_cnts;         // aids count between st to other points.
    flag[st] = true;

    for (size_t i = 0; i < data.size(); i++) {
        paths.push_back(data[st][i]);
        // if (data[st][i] > 0 && data[st][i] < INF) {
        //     paths_cnts.push_back(1);
        // } else {
        //     paths_cnts.push_back(0);
        // }
    }
    // aids_cnts.push_back();

    while (flag.size() != data.size()) {
        int minv = INF;
        int minx = -1;
        for (size_t i = 0; i < paths.size(); i++) {
            if (paths[i] < minv && flag.count(i) == 0) {
                minv = paths[i];
                minx = i;
            }
        }
        if (minx != -1) {
            for (size_t i = 0; i < paths.size(); i++) {
                if (flag.count(i) == 0 && paths[i] > paths[minx] + data[minx][i]) {
                    paths[i] = paths[minx] + data[minx][i];
                }
            }
            flag[minx] = true;
        }
    }
    for (size_t i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }
}


int main(int argc, char* argv[]) {
    vector<int>         aids;
    vector<vector<int>> data;
    int                 n  = 0;
    int                 m  = 0;
    int                 st = 0;
    int                 ed = 0;
    cin >> n >> m >> st >> ed;
    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        aids.push_back(x);
    }
    for (size_t i = 0; i < n; i++) {
        vector<int> temp;
        for (size_t j = 0; j < n; j++) {
            temp.push_back(INF);
        }
        data.push_back(temp);
    }

    for (size_t i = 0; i < m; i++) {
        int s = 0; // start
        int e = 0; // end
        int d = 0; // distance
        cin >> s >> e >> d;
        data[s][e] = d;
        data[e][s] = d;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    dijstra(data, aids, st, ed);

    return 0;
}
