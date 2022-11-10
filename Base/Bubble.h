//
// Created by Administrator on 2021/12/29.
//

#ifndef UNTITLED3_BUBBLE_H
#define UNTITLED3_BUBBLE_H


class Bubble {
public:
    void bubble (int arr[],int n){
        //外层循环控制全部元素排好序，趟数
        for(int i=0;i<n;i++){
            //内层循环每一次找到一个最小的
            for(int j=1;j<n;j++)
                if(arr[j-1]<arr[j]){
                    int temp=arr[j-1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                }

        }
    }

};


#endif //UNTITLED3_BUBBLE_H
