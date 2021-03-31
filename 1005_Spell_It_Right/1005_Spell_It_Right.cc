/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 1005_Spell_It_Right.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 17 Mar 2021 10:07:08 PM CST
================================================================*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, string> names = {
    {'0', "zero"},
    {'1', "one"},
    {'2', "two"},
    {'3', "three"},
    {'4', "four"},
    {'5', "five"},
    {'6', "six"},
    {'7', "seven"},
    {'8', "eight"},
    {'9', "nine"}};

int main(int argc, char* argv[]) {
    string x;
    cin >> x;
    int sum = 0;
    for (size_t i = 0; i < x.size(); i++) {
        sum += x[i] - '0';
    }

    string y = to_string(sum);
    for (size_t i = 0; i < y.size(); i++) {
        cout << names[y[i]];
        if (i != y.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
