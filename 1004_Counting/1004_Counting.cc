/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 1004_Counting.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 17 Mar 2021 09:58:47 PM CST
================================================================*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct Item {
    vector<int> childs;
} Item;

void coutChilds(vector<Item>& data, vector<int>& lays, vector<int>& RESULTS) {
    vector<int> temp;
    int         sum = 0;

    for (size_t i = 0; i < lays.size(); i++) {
        if (data[lays[i]].childs.size() == 0) {
            sum++;
        } else {
            for (size_t j = 0; j < data[lays[i]].childs.size(); j++) {
                temp.push_back(data[lays[i]].childs[j]);
            }
        }
    }
    results.push_back(sum);
    if (temp.size() == 0) {
        return;
    }
    coutChilds(data, temp, results);
}

int main(int argc, char* argv[]) {
    int N, M;
    cin >> N >> M;
    vector<Item> data;
    data.resize(N + 1);
    for (size_t i = 0; i < M; i++) {
        int id, cnt;
        cin >> id >> cnt;
        for (size_t j = 0; j < cnt; j++) {
            int x;
            cin >> x;
            data[id].childs.push_back(x);
        }
    }
    vector<int> lays = {1};
    vector<int> results;
    coutChilds(data, lays, results);
    for (size_t i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
