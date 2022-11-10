#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include"printVector.h"
#include"printArr.h"

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int m=words1.size(),n=words2.size();
    vector<string> st;
    //统计每组单词中每个字母最大次数
    int arr2[26]={};
    for(string &s:words2){     //每组
        int temp2[26]={};
        for(char &c:s){
            temp2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(temp2[i]>arr2[i]){
                arr2[i]=temp2[i];
            }
        }
    }


    for(string &s:words1){
        int temp1[26]={};
        for(char &c:s){
            temp1[c-'a']++;
        }
        bool ret=true;
        for(int i=0;i<26;i++){
            if(temp1[i]<arr2[i]){
                ret=false;
                break;
            }
        }
        if(ret==true){
            st.push_back(s);
        }
    }
    return st;
}

int main(){
    vector<string> s1={"amazon","apple","facebook","google","leetcode"};
    vector<string> s2={"e","o"};
    vector<string> s3=wordSubsets(s1,s2);
    printVector(s3);
    //cout<<s2[0][0]<<endl;
    // string str="oeoo";
    //cout<<str[0]<<endl;

    return 0;
}