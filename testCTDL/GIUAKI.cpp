#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct HD{
	int maKH, Sdt;
	String tenKH, diaChi;
	float KW, DonGia, ThanhTien, TongTien, GTGT;
	HD *next;
};

void AddKH(HD *&L){
	HD *P = new HD;
	cout<<"MaKH: ";		cin>>P->maKH;
	cout<<"HoTen: ";	cin.ignore(); getline(cin, P->tenKH);
	cout<<"DiaChi: ";	cin.ignore(); getline(cin, P->diaChi);
	cout<<"SDT:	";		cin>>P->Sdt;
	cout<<"KW, DonGia, ThanhTien, TongTien, GTGT, ThanhToan: ";
	cin>> P->KW >> P->DonGia >> P->ThanhTien >> P->TongTien >>P->GTGT;
	P->next=L;
	L=P;
}

void InsertKH(HD *&L;int k, String maK )
{
	int dem=0;
	HD *P, *Q;
	P=new HD;
	
}

main(){
	HD *L= NULL;
	int maKH1, Sdt1,k;
	String tenKH1, diaChi1;
	float KW1, DonGia1, ThanhTien1, TongTien1, GTGT1;
	
	cin>>k;
	cout<<"MaKH: ";		cin>>maKH1;
	cout<<"HoTen: ";	cin>>tenKH1;
	cout<<"DiaChi: ";	cin>>diaChi1;
	cout<<"SDT:	";		cin>>Sdt;
	cout<<"KW, DonGia, ThanhTien, TongTien, GTGT, ThanhToan: ";
	cin>>KW >>DonGia >>ThanhTien >>TongTien >>GTGT;
	
} 
