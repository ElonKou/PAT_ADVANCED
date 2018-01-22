//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  1002_A+B_for_polynomails.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Mon 22 Jan 2018 03:33:02 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(){
    // 进行合并同类项
    int na = 0;
    cin >> na;
    int exp_a[na] = {0};
    float coe_a[na] = {0};
    for(int i =0;i < na;i++){
        cin >> exp_a[i];
        cin >> coe_a[i];
    }

    int nb = 0;
    cin >> nb;
    int exp_b[nb] = {0};
    float coe_b[nb] = {0};
    for(int i =0;i < nb;i++){
        cin >> exp_b[i];
        cin >> coe_b[i];
    }
    // 进行查找合并
    int num = 0;
    int exp[na+nb] = {1001};
    float coe[na+nb] = {0};
    for(int j = 0;j < na+nb;j++){
        int temp = 0;
        int tempexp = 0;
        int isModified = 0;
        // 找到最大值
        for(int index = 0;index < na ; index++){
            if(temp < exp_a[index] && exp_a[index] < exp[((num-1)>0)?(num-1):0]){
                temp = exp_a[index];
            }
        }
        for(int index = 0;index < nb ; index++){
            if(temp < exp_b[index] && exp_b[index] < exp[((num-1)>0)?(num-1):0]){
                temp = exp_b[index];
            }
        }
        // 对所有的最大值进行求和
        for(int index = 0;index < na ; index++){
            if(temp == exp_a[index] && temp != exp[((num-1)>0)?(num-1):0]){
                tempexp = temp;
                coe[num] += coe_a[index];
                // 
                isModified = 1;
            }
        }
        for(int index = 0;index < nb ; index++){
            if(temp == exp_b[index] && temp != exp[((num-1)>0)?(num-1):0]){
                tempexp = temp;
                coe[num] += coe_b[index];
                // 
                isModified = 1;
            }
        }
        if(isModified == 1){
            exp[num] = tempexp;
            num ++;
        }
        
    }

    // 打印信息
    cout << num;
    for(int i = 0;i<num;i++){
        cout << setiosflags(ios::fixed)
             << setprecision(1)
             << " " 
        //cout << " " 
             << exp[i]
             << " ";
             //<< coe[i];
             printf("%.1f",coe[i]);
    }
    return 0;
}

