#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void tao(int n, int *a)
{
	srand(time(NULL));
	for (int i=0; i<n; i++)
	{
		a[i]=rand()%100+1;
	}

}

void xuat(int n, int *a)
{
	for (int i=0; i<n; i++)
	{
		cout<<*(a+i)<<" ";
	}

}
void removeOdd(int &n, int* &a) {
    int* temp = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++)
	{
        if (*(a + i) % 2 == 0)
		{ 
            *(temp + count) = *(a + i);
            count++;
        }
    }
    delete[] a;
    a = temp;
    n = count;
}


int main()
{
	int n;
	cin>>n;
	int *a = new int [n];
	tao(n,a);
	xuat(n,a);	
	cout<<endl;
	removeOdd(n,a);
	xuat(n,a);	
	return 0;
	
}
