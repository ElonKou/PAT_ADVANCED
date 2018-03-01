//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1065_A+B_and_C.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 27 Feb 2018 07:04:06 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int cnt;
	long a,b,c;
	cin >> cnt;
	bool flag[cnt] = {false};
	bool minus = false;
	for(int i = 0;i < cnt;i ++){
		cin >> a >> b >> c;
		// ...
		if(a < 0 && b < 0){
			minus = true;
		}else if(a > 0 && b > 0){
			minus = false;
		}else if((abs(a) > abs(b) && (a > 0 && b < 0)) || (abs(a) < abs(b) && (b > 0 && (a < 0)))){
			minus = false;
		}else{
			minus = true;
		}
		// ...
		if(a + b > c && minus == false){
			flag[i] = true;
		}else{
			flag[i] = false;
		}
	}
	for(int i =0 ;i < cnt;i ++){
		
		if(flag[i] == true){
			cout << "Case #" << i+1 << ": true";
		}else{
			cout << "Case #" << i+1 << ": false";
		}
		if(i != cnt-1){
			cout << endl;
		}
    }
	return 0;
}

