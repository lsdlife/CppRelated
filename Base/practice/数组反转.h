//
// Created by Administrator on 2021/12/29.
//

#ifndef UNTITLED3_REVERSE_H
#define UNTITLED3_REVERSE_H
class Reverse {
public:
    void reverse(int arr[],int n) {
        for (int i = 0; i < n; i++) {
            if (i < n - 1 - i) {
                int temp = arr[i];
                arr[i] = arr[n - 1 - i];
                arr[n - 1 - i] = temp;
            }
        }
    }
};

#endif //UNTITLED3_REVERSE_H
