//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1065_A+B_and_C.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 27 Feb 2018 07:04:06 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cnt;
	long double a, b, c;
	cin >> cnt;
	bool flag[cnt] = {false};
	for (int i = 0; i < cnt; i++)
	{
		cin >> a >> b >> c;
		if (a + b > c)
		{
			flag[i] = true;
		}
		else
		{
			flag[i] = false;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (flag[i] == true)
		{
			cout << "Case #" << i + 1 << ": true" << endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": false" << endl;
		}
	}
	return 0;
}
