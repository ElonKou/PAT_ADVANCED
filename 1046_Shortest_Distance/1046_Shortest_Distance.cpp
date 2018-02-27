//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1046_Shortest_Distance.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 27 Feb 2018 12:11:35 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <algorithm>

using namespace std;

inline long checkShortest(int *dist,long *sumArr,int start,int end,int cnt,int sum){
	long distance = sumArr[max(start,end)] - sumArr[min(start,end)];
	return min(distance,sum - distance);
}

int main(){
	int cnt,num;
	cin >> cnt;
	int dist[cnt] = {0};
	long sumArr[cnt] = {0};
	int sum = 0;
	for(int i = 0 ;i < cnt;i++){
		cin >> dist[i];
		sumArr[i] = sum;
		sum += dist[i];
	}
	cin >> num;
	long result[num] = {0};
	int start,end;
	for(int i = 0;i < num;i++){
		cin >> start >> end;
		result [i] = checkShortest(dist,sumArr,start-1,end-1,cnt,sum);
	}
	for(int i  = 0;i < num;i++){
		cout << result[i];
		if(i != num - 1){
			cout << endl;
		}
	}
    return 0;
}

