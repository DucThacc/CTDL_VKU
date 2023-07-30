#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
//------khai bai CTDL----------------------------
struct CB{char macb[15];
           char ht[35];
           float hsl;
           char dt[15];
           }; 
CB A[50];
int n;
//----nhap---------------------------------------
void Nhap(int &n)
{char ma[15]; 
      for(int i=0;i<n;i++)
      {
           fflush(stdin);
           printf("\nCho biet ma can bo: ");
           gets(ma);
           strcpy(A[i].macb, ma);
           printf("\nCho biet ho ten: ");
           gets(A[i].ht);
           printf("\nCho biet he so luong: ");
           scanf("%f",&A[i].hsl);
           fflush(stdin);
           printf("\nCho biet so dien thoai: ");
           gets(A[i].dt);
      }    
}
//-----xuat-------------------------------
void Xuat(int n)
{     
     printf("\nMA CB      HO TEN      HSL      SDT:\n");
     for(int i=0;i<n;i++)
          printf("\n %s     %s       %5.2f      %s",A[i].macb,A[i].ht,A[i].hsl,A[i].dt);
     printf("\n");     
}
//---SX chon-----------------
void Select(CB A[50],int n)
{char ma[15],t[35],dt[15];
 float h;       
     for(int i=0;i<n-1;i++)
	 {int m=i;
		for(int j=i+1;j<n;j++)
			if(strcmp(A[j].macb,A[m].macb)<0)                 
                 m=j;                
            if(m!=i)
		    { 
                    strcpy(ma,A[i].macb);
                    strcpy(t,A[i].ht);
                    strcpy(dt,A[i].dt);
                    h=A[i].hsl;
                    
                    strcpy(A[i].macb,A[m].macb);
                    strcpy(A[i].ht,A[m].ht);
                    strcpy(A[i].dt,A[m].dt);
                    A[i].hsl=A[m].hsl;
                    
                    strcpy(A[m].macb,ma);
                    strcpy(A[m].ht,t);
                    strcpy(A[m].dt,dt);
                    A[m].hsl=h;                    
            }
	}
	Xuat(n);
}
//-----SX Chen---------------
void Insert(CB A[50],int n)
{char ma[15],t[35],dt[15];
 float h;
 int j;
	for(int i=1;i<n;i++)
	{    strcpy(ma,A[i].macb);
         strcpy(t,A[i].ht);
         strcpy(dt,A[i].dt);
         h=A[i].hsl;
         j=i-1;
    	 while((j>=0)&&(h>A[j].hsl))
		 {	
             strcpy(A[j+1].macb,A[j].macb);
             strcpy(A[j+1].ht,A[j].ht);
             strcpy(A[j+1].dt,A[j].dt);
             A[j+1].hsl=A[j].hsl;
			 j--;
         }
    	 strcpy(A[j+1].macb,ma);
         strcpy(A[j+1].ht,t);
         strcpy(A[j+1].dt,dt);
         A[j+1].hsl=h;
	}
    Xuat(n);	
}
//----SX noi bot----------------
void Bubble(CB A[50],int n)
{char ma[15],t[35],dt[15];
 float h;
     for(int i=0;i<n-1;i++)
	 for(int j=n-1;j>=i+1;j--)
		if(strcmp(A[j].ht,A[j-1].ht)<0)
        { 
             strcpy(ma,A[j].macb);
             strcpy(t,A[j].ht);
             strcpy(dt,A[j].dt);
             h=A[j].hsl;
              
             strcpy(A[j].macb,A[j-1].macb);
             strcpy(A[j].ht,A[j-1].ht);
             strcpy(A[j].dt,A[j-1].dt);
             A[j].hsl=A[j-1].hsl;
strcpy(A[j-1].macb,ma);
             strcpy(A[j-1].ht,t);
             strcpy(A[j-1].dt,dt);
             A[j-1].hsl=h;
        }		
	 Xuat(n);
}
//----SX Nhanh----------------
void QuickSort(CB A[50],int left,int right)
{char ma[15],t[35],dt[15];
 float h;    
     if(left<right)
     {int i=left;
      int j=right;      
      strcpy(ma,A[(left+right)/2].macb);
		  do{ while(strcmp(A[i].macb,ma)>0) 
                   i++;
              while(strcmp(A[j].macb,ma)<0) 
                   j--;
              if(i<=j)
              {
                      strcpy(ma,A[i].macb);
                      strcpy(t,A[i].ht);
                      strcpy(dt,A[i].dt);
                      h=A[i].hsl;
                       
                      strcpy(A[i].macb,A[j].macb);
                      strcpy(A[i].ht,A[j].ht);
                      strcpy(A[i].dt,A[j].dt);
                      A[i].hsl=A[j].hsl;
                       
                      strcpy(A[j].macb,ma);
                      strcpy(A[j].ht,t);
                      strcpy(A[j].dt,dt);
                      A[j].hsl=h;
                      
                      i++;
                      j--;
              }
	     }while(i<=j);
	   QuickSort(A,left,j);
	   QuickSort(A,i,right);
    }        
}
//-----------------------------
main()
{int n,x,k;      
      printf("\nn=");
      scanf("%d",&n);
      Nhap(n);  
      printf("\nDANH SACH:\n");
      Xuat(n);  
      printf("\nSap Xep Chon:\n");
      Select(A,n);
      printf("\nSap Xep Chen:\n");
      Insert(A,n);
      printf("\nSap Xep Noi bot:\n");
      Bubble(A,n);
      printf("\nSap Xep Nhanh:\n");
      QuickSort(A,0,n-1);
      Xuat(n);                                  
      getch();
}
