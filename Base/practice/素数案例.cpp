#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include"printVector.h"
#include"printArr.h"
//输出1~n中的素数个数和打印出区间内所有素数
int  returnNumber(int n){
    int arr[]={0};
    int count=1,j=0;        //包括2
    while(n>2){
        int ret=0;
        for(int i=2;i<=n;i++){
            if(n%i==0) {
                ret++;  //ret为1的才是素数
            }
        }
        if(ret==1){
            count++;
            arr[j++]=n;
            cout<<n<<",";
        }
        n--;
    }
    return count;
}

int main(){
    int ret= returnNumber(101);
    cout<<"总数为："<<ret<<endl;
    return 0;
}


