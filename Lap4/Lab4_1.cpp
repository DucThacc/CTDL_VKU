#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

void input( int a[100] ){
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		a[i] = rand() % (1000-1+1) + 1;
	}
}
void output( int a[100] ){
	for(int i = 0; i < 100; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void selection_sort(int a[100]){
	int min = 0;
	for(int i = 0; i < 100; i++){
		for(int j = i; j < 100; j++){
			if( a[j] < a[min] )
				min = j;
		}
		swap(a[min],a[i]);
	}
}
void insertion_sort(int a[100]){
	for(int i = 1; i < 100; i++){
		int index = i;
		int j = i-1;
		while(j>= 0 && a[index] < a[j] ){
			swap(a[j],a[index]);
			index = j;
			j--;
		}
	}
}
void bubble_sort(int a[100]){
	for(int i = 0; i < 99; i++){
		for(int j = 0; j < 99-i; j++){
			if( a[j] > a[j+1] ) 
				swap(a[j],a[j+1]);
		}
	}
}
int linear_search(int n, int a[100]){
	for(int i = 0; i < 100; i++){
		if(n == a[i]) return i;
	}
	return -1;
}
int binary_search(int n,int a[100], int begin, int end){
	if(begin > end)
		return -1;
	int middle = (begin + end)/2;
	if(n == a[middle])
		return middle;
	else if(n > a[middle])
		return binary_search(n,a,middle+1,end);
	else if(n < a[middle]) 
		return binary_search(n,a,begin,middle-1);
}
int main(){
	int a[100];
	int n;
	do{
		cout<<	"------------------------";
		cout <<"1.input.\n";
		cout <<"2.output.\n";
		cout <<"3.selection sort\n";
		cout <<"4.insertion sort\n";
		cout <<"5.bubble sort\n";
		cout <<"6.compare\n";
		cout <<"7.linear search\n";
		cout <<"8.binary search(after sorted)\n";
		cout <<"9.exit\n";
		cout<<	"------------------------";
		cin >> n;
		switch (n) {
			case 1:
				input(a);
				break;
			case 2:
				output(a);
				break;
			case 3:
				selection_sort(a);
				break;
			case 4:
				insertion_sort(a);
				break;
			case 5:
				bubble_sort(a);
				break;
			case 6:
				break;
			case 7:
				cout << "value: ";
				int num; cin >> num;
				cout << "index: \n" << linear_search(num,a)+1 << endl;
				break;
			case 8:
				cout << "value: ";
				int numb; cin >> numb;
				cout << "index: \n" << binary_search(numb,a,0,99)+1 << endl;
				break;
		}
	}while(n!=9);
}
