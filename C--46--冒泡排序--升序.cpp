#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	//1. 按照”升序“排列
	// . 找最小的
	int min = 10000;
	// .        n为arr[]的小标最高值
	int n = sizeof(arr) / sizeof(arr[0])-1;
	int p[9];
	for(int j=0;j<n+1;j++){
		for (int i = 0; i < n + 1; i++) {
			if (j == 0) {
				if (min > arr[i]) {
					min = arr[i];
				}
			}
			else {
				if (min > arr[i] && arr[i] > p[j - 1]) {
					min = arr[i];
				}
			}
		}
		p[j] = min;
		min = 10000;
	}
	// .
	cout << "重新排序（升序）：" << endl;
	for (int j = 0; j < n + 1; j++) {
		if (j == n) {
			cout << p[j] << endl;
		}
		else {
			cout << p[j] <<',';
		}
	}

	system("pause");
	return 0;
}
/*
   该说不说，这特么对我来说，真的是有点难思考，但好歹是 0.5h 之内想出来，并且完成了程序的编写及修饰，以下是“思路”
   1. 找出最小值min
   2. 然后找最小值上面的第一个（这也是这道题最难搞的地方）
    .a 将上一个min给目标数列 p[]
	.b 然后将满足条件的 arr[i] 赋给 p[j],但是“条件”----min>arr[i],这是最基本的，因为你要遍历所有的数字，包括已经在p[]
	               里面的，但是又要“去除”这一部分，怎么办？--加“条件”-----arr[i]>p[j-1] ,只需要arr[i]大于
				       上一个 p[j-1] 就好了，因为 p[j-1] 是升序过程中最大的，这样前几个arr[]里面的已经被排序入p[]里面的
					   将会被“条件”所排除
   3. 打印输出
   可以在过程里面每一次都打印一个 p[j]
   也可以 在最后，遍历打印 p[] 的每一个元素
   4. 那么降序也就是改 max 和 < 号而已！！！
*/