/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 1008_Elevator.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Thu 18 Mar 2021 12:25:41 AM CST
================================================================*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int cnt   = 0;
    int total = 0;
    int bf    = 0;
    cin >> cnt;
    for (size_t i = 0; i < cnt; i++) {
        int x;
        cin >> x;
        if (x > bf) {
            total += (x - bf) * 6 + 5;
        } else {
            total += (bf - x) * 4 + 5;
        }
        bf = x;
    }
    cout << total << endl;

    return 0;
}
