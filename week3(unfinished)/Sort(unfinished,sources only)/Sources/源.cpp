#include<stdio.h>
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>
using namespace std;
using std::setw;
void InserSort(int array[],int lenth ){
	int t;
	for (int i = 0; i < lenth - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				t = array[j - 1];
				array[j - 1] = array[j];
				array[j] = t;
			}
			else {
				break;
			}

		}
	}
}

void QuickSort(int a[], int l, int r) {
	if (l >= r)
		return;
	int i = l; int j = r; int key = a[0];
	while (i < j) {
		while (i < j && a[j] >= key)j--;
		if (i < j) {
			a[i] = a[j];
			i++;
		}
		while (i < j && a[i] < key) i++;
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = key;
	QuickSort(a, l, i - 1);
	QuickSort(a, i + 1, r);//递归调用

}

void MergeArray(int a[], int first, int middle, int end, int temp[]) {
	int i = first;
	int m = middle;
	int j = middle + 1;
	int n = end;
	int k = 0;
	while (i <= m && j <= n) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= m) {
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= n) {
		temp[k] = a[j];
		k++;
		j++;
	}

	for (int ii = 0; ii < k; ii++) {
		a[first + ii] = temp[ii];
	}
}

void MergeSort(int a[],int one,int last,int temp[]) {
	if (one < last) {
		int middle = (one + last) / 2;
		MergeSort(a, one, middle, temp);
		MergeSort(a, middle + 1, last, temp);
		MergeArray(a, one, middle, last, temp);
	}//递归调用
}

void CountSort(int* arr, int n)
{
	//找到序列中的最大值和最小值
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	
	int range = max - min + 1;//开辟空间的数量
	if (range < 1) {
		cerr << "序列过短" << endl;
		return;
	}
	int* countArr = (int*)malloc(sizeof(int) * range);//开辟空间
	
	memset(countArr, 0, sizeof(int) * range);

	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}


	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[j] = i + min;
			j++;
		}
	}

	free(countArr);
}

void RadixSort(int A[], int temp[], int n, int k, int r, int cnt[]) {
	for (int i = 0, rtok = 1; i < k; i++, rtok = rtok * r) {
	//A:原数组
	 //temp:临时数组
	 //n:序列的数字个数
	 //k:最大的位数2
	 //r:基数10
	 //cnt:存储bin[i]的个数
		
		for (int j = 0; j < r; j++) {
			cnt[j] = 0;
		}
	
		for (int j = 0; j < n; j++) {
			cnt[(A[j] / rtok) % r]++;
		}
		
		for (int j = 1; j < r; j++) {
			cnt[j] = cnt[j - 1] + cnt[j];
		}
		for (int j = n - 1; j >= 0; j--) {   
			cnt[(A[j] / rtok) % r]--;
			temp[cnt[(A[j] / rtok) % r]] = A[j];
		}
		for (int j = 0; j < n; j++) {
			A[j] = temp[j];
		}
	}
}
int arr[20000] = { 0 };
void Get_array(int arr[],int n) {
	
	
	for (int i = 0; i < n; i++) {
		cout << "请输入整型数组a[" << i << "]的数据" << endl;
		cin >> arr[i];
		while (cin.fail()) {
			cout << "data type error!enter again:" << endl;
			cin.clear();
			i--;
			while (cin.get() != '\n')
				continue;
		}
	}
}

void PrintArray(int arr[],int n) {
	cout << "Element" << setw(13) << "Value" << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(7) << i << setw(13) << arr[i] << endl;
	}
}

int menu_select(void);
int menu_out;		//定义一个返回上一级菜单 
int main()
{
	int temp[20000] = { 0 };
	while (1)
	{
		int n = 0;

		memset(arr, 0, 20000); 
		switch (menu_select())
		{
			
		case 1:
			system("cls");
			menu_out = 1;
			printf("这是二级菜单：插入排序\r\n");
			n = 0;
			cout << "请输入数组元素个数（整型）" << endl;
			cin >> n;
			while (cin.fail()) {
				cout << "data type error!enter again:" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			Get_array(arr,n); PrintArray(arr,n);
			InserSort(arr, sizeof(arr));
			PrintArray(arr,n);
			printf("输入0返回上一级菜单：\r\n");
			while (menu_out)			//只有当键盘输入为0时，才退出当前菜单 
				cin>>menu_out; //否则一直循环获取键盘输入 
			break;
		case 2:
			system("cls");
			menu_out = 1;
			printf("这是二级菜单：归并排序\r\n");
			n = 0;
			cout << "请输入数组元素个数（整型）" << endl;
			cin >> n;
			while (cin.fail()) {
				cout << "data type error!enter again:" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			Get_array(arr, n); PrintArray(arr,n);
			
			MergeSort(arr, arr[0],arr[n-1],temp);
			PrintArray(arr,n);
			printf("输入0返回上一级菜单：\r\n");
			while (menu_out)
				cin >> menu_out;
			break;
		case 3:
			system("cls");
			menu_out = 1;
			printf("这是二级菜单：快速排序\r\n");
			n = 0;
			cout << "请输入数组元素个数（整型）" << endl;
			cin >> n;
			while (cin.fail()) {
				cout << "data type error!enter again:" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			Get_array(arr, n); PrintArray(arr,n);
			QuickSort(arr, arr[0],arr[n-1]);
			PrintArray(arr,n);
			printf("输入0返回上一级菜单：\r\n");
			while (menu_out)
				cin >> menu_out;
			break;
		case 4:
			system("cls");
			menu_out = 1;
			printf("这是二级菜单：计数排序\r\n");
			n = 0;
			cout << "请输入数组元素个数（整型）" << endl;
			cin >> n;
			while (cin.fail()) {
				cout << "data type error!enter again:" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			Get_array(arr, n); PrintArray(arr,n);
			CountSort(arr, sizeof(arr));
			PrintArray(arr,n);
			printf("输入0返回上一级菜单：\r\n");
			while (menu_out)
				cin >> menu_out;
			break;
		case 5:
			system("cls");
			menu_out = 1;
			printf("这是二级菜单：基数排序(基数为10），\r\n");
			n = 0;
			cout << "请输入数组元素个数（整型）" << endl;
			cin >> n;
			while (cin.fail()) {
				cout << "data type error!enter again:" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			Get_array(arr, n); PrintArray(arr,n);
			int cnt[10];
			
			RadixSort(arr, temp,n,5,10, cnt);
			PrintArray(arr,n);
			printf("输入0返回上一级菜单：\r\n");
			while (menu_out)
				cin >> menu_out;
			break;
		default:break;
		}
	}
	return 0;
}
int menu_select(void)
{
	int select;
	//system("cls");
	cout<<"输入对应标号进入下一级功能：\r\n";
	printf("1、插入排序\r\n");
	printf("2、归并排序\r\n");
	printf("3、快速排序\r\n");
	printf("4、计数排序\r\n");
	printf("5、基数排序\r\n");
	cin>>select;
	return select;
}
