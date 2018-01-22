//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1001_A+B_format.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Mon 22 Jan 2018 02:23:01 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>

using namespace std;

int main(){
    long numa = 0;
    long numb = 0;
    cin >> numa;
    cin >> numb;
    string result = to_string(numa + numb);
    int len = result.length();
    for(int i = 0;i<len;i++){
        cout << result[i];
        if(result[i] == '-'){
            continue;
        }
        if((len-1-i)%3 == 0 && i!=len-1){
            cout << ",";
        }
    }
    return 0;
}
