#include <iostream>
using namespace std;
//desc:利用函数模板封装一个排序的函数，可以对不同的数据类型数组进行排序，从大到小(即小的往后排)
//采用简单选择排序，分别利用char数组和int数组进行测试

//交换模板
template <typename  T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}
//排序模板
template <typename T>
void sortArr(T arr[], int n) {    //参数为数组名(数组元素首地址),和数组元素个数
	for (int i = 0; i < n; i++) {       //要求使用简单选择排序：每趟之前前面的元素已经排好序
		int max = i;  //  每次都要更新默认下标，
		//简单选择排序的具体实现
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {   //如果前面这个元素的值小于后面这个元素的值
				//这里采用模板进行交换两个元素的值
				Swap(arr[i], arr[j]);
				max = j;  // 更新最大值的下标
			}
			else {
				continue;
			};
		}
	}
}
//打印模板
template <typename  T>
void printArr(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	char ch[] = { 'a','f','d','e','r','o' };
	int n = sizeof(ch) / sizeof(ch[0]);
	cout << "原先的数组序列为：" << endl;
	printArr(ch, n);
	sortArr(ch, n);
	cout << "排序后的数组序列为：" << endl;
	printArr(ch, n);
}

void test02() {
	int arr[] = { 12,43,23,45,67,3,57,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "原先的数组序列为：" << endl;
	printArr(arr, n);
	sortArr(arr, n);
	cout << "排序后的数组序列为：" << endl;
	printArr(arr, n);
}
int main() {
	//test01();
	test02();
	return 0;
}
