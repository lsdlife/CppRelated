#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include"printVector.h"
#include"printArr.h"
//输入密文，计算明文
string returnStr(string s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>=92&&s[i]<=122) {
            if (s[i] - '0' <= 51) {
                s[i] = s[i] + 23;       //c->z;b->y;a->x;
            } else {
                s[i] = s[i] - 3;        //d->a;e->b;f->c;
            }
        }else{
            if (s[i] - '0' <=19 ) {
                s[i] = s[i]+55;       //C->z;b->y;a->x;
                //cout<<s[i]<<endl;
            } else {
                s[i] = s[i]-3+32;        //d->a;e->b;f->c;
            }
        }
    }
    return s;
}
int main(){
    string s="DABC";
    string s2= returnStr(s);
    cout<<s2<<endl;
    //int  a='D'-'d';
    //cout<<a<<endl;
    return 0;
}


