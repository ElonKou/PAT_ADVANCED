/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 1006_Sign_In_and_Sign_Out.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 17 Mar 2021 10:18:08 PM CST
================================================================*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TimeItem {
    int hour;
    int mins;
    int secs;
} TimeItem;

typedef struct PersonItem {
    string   ID;
    TimeItem unlock;
    TimeItem lock;
} PersonItem;

int main(int argc, char* argv[]) {
    int                cnt;
    vector<PersonItem> pers;
    cin >> cnt;
    for (size_t i = 0; i < cnt; i++) {
        PersonItem temp;
        cin >> temp.ID;
        scanf("%d:%d:%d %d:%d:%d", &temp.unlock.hour, &temp.unlock.mins, &temp.unlock.secs,
              &temp.lock.hour, &temp.lock.mins, &temp.lock.secs);
        pers.push_back(temp);
        cin.get();
    }
    string   st_ID = pers[0].ID;
    string   ed_ID = pers[0].ID;
    TimeItem st    = pers[0].unlock;
    TimeItem ed    = pers[0].lock;
    for (size_t i = 0; i < cnt; i++) {
        TimeItem& x = pers[i].unlock;
        if (x.hour < st.hour || x.mins < st.mins || x.secs < st.secs) {
            st    = x;
            st_ID = pers[i].ID;
        }
        TimeItem& y = pers[i].lock;
        if (y.hour > ed.hour || y.mins > ed.mins || y.secs > ed.secs) {
            ed    = y;
            ed_ID = pers[i].ID;
        }
    }
    cout << st_ID << " " << ed_ID << endl;
    return 0;
}
