//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1042_Shuffling_Machine.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Mon 26 Feb 2018 02:21:48 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void changeOrder(int origin[],int order[],int cnt){
	int temp[54];
	for(int i = 0;i < cnt;i++){
		for(int j = 0;j < 54;j++){
			temp[order[j]] = origin[j];
		}
		for(int j = 0;j < 54;j++){
			origin[j] = temp[j];
		}
	}
}

void print(int origin[]){
	for(int i = 0;i < 54;i++){
		int type = origin[i] / 13;
		int num = origin[i] % 13;
		char c = ' ';
		switch(type){
			case 0:
				c = 'S';
				break;
			case 1:
				c = 'H';
				break;
			case 2:
				c = 'C';
				break;
			case 3:
				c = 'D';
				break;
			case 4:
				c = 'J';
				break;
		}
		cout << c << num + 1;
		if(i != 53){
			cout << " ";
		}
	}
}

int main(){
	int origin[54] = {0};
	int order[54]  = {0};
	int cnt;
	cin >> cnt;
	for(int i = 0;i < 54;i++){
		origin[i] = i;
		cin >> order[i];
		order[i] --;
	}
	changeOrder(origin,order,cnt);
	print(origin);
    return 0;
}

