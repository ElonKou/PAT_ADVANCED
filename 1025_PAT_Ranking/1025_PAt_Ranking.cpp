//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1025_PAt_Ranking.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 20 Feb 2018 04:52:12 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct stu{
	long long code;
	int room;
	int score;
	int rank;
	int allRank;
};

bool com(stu a,stu b){
	if(a.score != b.score){
		return a.score > b.score;
	}else{
		return a.code < b.code;
	}
}

stu stus[30001];

int main(){
	int cnt;
	int all = 0;
	int index = 0;
	
	int order;
	int rank = 1;
	int score = stus[0].score;
	
	cin >> cnt;
	for(int i = 0;i < cnt;i++){
		int num = 0;
		cin >> num;
		for(int j = 0 ;j < num;j++){
			cin >> stus[index].code;
			cin >> stus[index].score;
			stus[index].room = i + 1;
			index ++;
		}
		sort(stus+all,stus+all+num,com);
		rank = 1;
		score = stus[all].score;
		for(int k = 0;k < num;k++){
			if(score > stus[all+k].score){
				rank = k+1;
				score = stus[all+k].score;
			}
			stus[all+k].rank = rank;
		}
		all += num;
	}
	sort(stus,stus+all,com);
	rank = 1;
	score = stus[0].score;
	for(int k = 0;k < all;k++){
		if(score > stus[k].score){
			rank = k+1;
			score = stus[k].score;
		}
		stus[k].allRank = rank;
	}
	//输出
	if(all != 0){
		cout << all << endl;
	}
	for(int i = 0;i < all;i++){
		//cout << setw(5) << setfill('0') << checkList[i];
		cout << setw(13) << setfill('0')
			 << stus[i].code << " "
			 << stus[i].allRank << " "
			 << stus[i].room << " "
			 << stus[i].rank;
		if(i != all-1){
			cout << endl;
		}
	}
    return 0;
}

