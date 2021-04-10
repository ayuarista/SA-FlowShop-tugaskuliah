#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main()
{
    ifstream data;
    ifstream random;
    int jarak[100][100],frek[100][100],frek2[100][100],x[100][100],j,i,n,m,q,b,k,l,slh,bnr,pilih,iya,it,s1,s2,tukar,solusi[100],awal[100];
    int a[4]={1,2,3,4},bb[4]={1,2,3,4}, c[4]={1,2,3,4},d[4]={1,2,3,4},e[4]={1,2,3,4},o;
int a1[10]={1,2,3,4,5,6,7,8,9,10};
int a2[10]={1,2,3,4,5,6,7,8,9,10};
int a3[10]={1,2,3,4,5,6,7,8,9,10};
int a4[10]={1,2,3,4,5,6,7,8,9,10};
int a5[10]={1,2,3,4,5,6,7,8,9,10};
int a6[10]={1,2,3,4,5,6,7,8,9,10};
int a7[10]={1,2,3,4,5,6,7,8,9,10};
int a8[10]={1,2,3,4,5,6,7,8,9,10};
int a9[10]={1,2,3,4,5,6,7,8,9,10};
int a10[10]={1,2,3,4,5,6,7,8,9,10};
int a11[10]={1,2,3,4,5,6,7,8,9,10};
int a12[10]={1,2,3,4,5,6,7,8,9,10};
int a13[10]={1,2,3,4,5,6,7,8,9,10};
int a14[10]={1,2,3,4,5,6,7,8,9,10};
int a15[10]={1,2,3,4,5,6,7,8,9,10};
int a16[10]={1,2,3,4,5,6,7,8,9,10};
int a17[10]={1,2,3,4,5,6,7,8,9,10};
int a18[10]={1,2,3,4,5,6,7,8,9,10};
int a19[10]={1,2,3,4,5,6,7,8,9,10};
int a20[10]={1,2,3,4,5,6,7,8,9,10};
    float sem[100],tuk,ha[100],z,T,alpha,takhir,zbar,p,r;
    cout<<endl;
    /*cout<<"  Masukkan Jumlah Data : ";cin>>n;*/
    cout<<" *----------------------------------------------------------*"<<endl;
    cout<<" |        SOLUSI OPTIMAL PERMASALAHAN FLOW SHOP              |"<<endl;
    cout<<" |      MENGGUNAKAN ALGORITMA SIMULATED ANNEALING            |"<<endl;
    cout<<" *----------------------------------------------------------*"<<endl<<endl;
    cout<<"  Pilihan Data : "<<endl;
    cout<<"  1. Data 5 mesin 4 job "<<endl;
    cout<<"  2. Data 20 mesin 10job "<<endl;
    do{
       cout<<endl<<"  Data yang anda pilih : ";cin>>pilih;
       switch(pilih)
             {
              case 1:
              data.open("data1.txt");
              random.open("random5-4.txt");
              n=4;
              m=5;

              iya=1;

              //Membangkitkan solusi awal secara acak
       q=n*m   ;
       cout<<endl<<"  Solusi Awal : ";
       for (i=4;i>0;i--)
{
	o=rand()%i  ;
	cout<<a[o]<<" ";
	while(o<i-1)
	{
		a[o]=a[o+1];
		o++;
   }
}
cout<<" ";
for (i=4;i>0;i--)
{
	o=rand()%i  ;
	cout<<bb[o]<<" ";
	while(o<i-1)
	{
		bb[o]=bb[o+1];
		o++;
   }
}
cout<<" ";
for (i=4;i>0;i--)
{
	o=rand()%i  ;
	cout<<c[o]<<" ";
	while(o<i-1)
	{
		c[o]=c[o+1];
		o++;
   }
}
cout<<" ";
for (i=4;i>0;i--)
{
	o=rand()%i  ;
	cout<<d[o]<<" ";
	while(o<i-1)
	{
		d[o]=d[o+1];
		o++;
   }
}
cout<<" ";
for (i=4;i>0;i--)
{
	o=rand()%i  ;
	cout<<e[o]<<" ";
	while(o<i-1)
	{
		e[o]=e[o+1];
		o++;
   }
}

              break;

              case 2:
              data.open("data2.txt");

              random.open("random2010.txt");
              n=10;
              m=20;
              iya=1;
              //Membangkitkan solusi awal secara acak
       q=n*m   ;
     /* cout<<endl<<"  Solusi Awal : ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a1[o]<<" ";
	while(o<i-1)
	{
		a1[o]=a1[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a2[o]<<" ";
	while(o<i-1)
	{
		a2[o]=a2[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a3[o]<<" ";
	while(o<i-1)
	{
		a3[o]=a3[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a4[o]<<" ";
	while(o<i-1)
	{
		a4[o]=a4[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a5[o]<<" ";
	while(o<i-1)
	{
		a5[o]=a5[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a6[o]<<" ";
	while(o<i-1)
	{
		a6[o]=a6[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a7[o]<<" ";
	while(r<i-1)
	{
		a7[o]=a7[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a8[o]<<" ";
	while(o<i-1)
	{
		a8[o]=a8[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a9[o]<<" ";
	while(o<i-1)
	{
		a9[o]=a9[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a10[o]<<" ";
	while(o<i-1)
	{
		a10[o]=a10[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a11[o]<<" ";
	while(o<i-1)
	{
		a11[o]=a11[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a12[o]<<" ";
	while(o<i-1)
	{
		a12[o]=a12[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a13[o]<<" ";
	while(o<i-1)
	{
		a13[o]=a13[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a14[o]<<" ";
	while(o<i-1)
	{
		a14[o]=a14[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a15[o]<<" ";
	while(o<i-1)
	{
		a15[o]=a15[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a16[o]<<" ";
	while(o<i-1)
	{
		a16[o]=a16[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a17[o]<<" ";
	while(o<i-1)
	{
		a17[o]=a17[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a18[o]<<" ";
	while(o<i-1)
	{
		a18[o]=a18[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a19[o]<<" ";
	while(o<i-1)
	{
		a19[o]=a19[o+1];
		o++;
   }
}
cout<<" ";
for (i=10;i>0;i--)
{
	r=rand()%i  ;
	cout<<a20[o]<<" ";
	while(o<i-1)
	{
		a20[o]=a20[o+1];
		o++;
   }
}
cout<<" ";  */
              break;

              default:
              cout<<"  input yang anda pilih salah, coba ulangi lagi"<<endl;
              iya=0;
             }
       }while(iya==0);
    for(i=0;i<n;i++)
     	 {
        for(j=0;j<m;j++)
      	  {
            data>>frek[i][j];
           }
       }
       for(i=0;i<q;i++)
       {
       random>>awal[i];
       }
       cout<<endl<<"  Matriks data : "<<endl;
    for (i=0;i<n;i++)
        {
         cout<<" ";
         for (j=0;j<m;j++)
             {
              cout<<" "<<frek[i][j];
             }
         cout<<endl;
        }
        cout<<endl;
    cout<<endl;
    cout<<"  INPUT PARAMETER SIMULATED ANNEALING"<<endl;
    cout<<"  ==================================="<<endl;
    do{
    cout<<"  Solusi Awal : ";
       for(i=0;i<q;i++)
       {
       cout<<" "<<awal[i];
       }
       cout<<endl;
       cout<<"  Masukkan Suhu Awal : ";cin>>T;
       cout<<"  Masukkan Suhu Akhir : ";cin>>takhir;
       if(T<takhir)
         {
          cout<<endl<<"  Suhu Awal lebih rendah daripada Suhu Akhir"<<endl;
          cout<<"  Mohon ulangi lagi"<<endl<<endl;
         }
       }while(T<=takhir);
    do{
       cout<<"  Masukkan Koefisien Penurunan Suhu (0,1): ";cin>>alpha;
       if(alpha<=0 || alpha>=1)
         {
          cout<<endl<<"  koefisien penurunan suhu salah"<<endl;
          cout<<"  Mohon ulangi lagi"<<endl<<endl;
         }
       }while(alpha<=0 || alpha>=1);



    cout<<endl<<endl;
    cout<<"         Simulated Annealing"<<endl;
    cout<<"       Untuk menyelesaikan FSP"<<endl;
    cout<<"======================================"<<endl;
    cout<<"-------parameter yang digunakan-------"<<endl;
    cout<<"  Suhu Awal                : "<<T<<endl;
    cout<<"  Koefisien penurunan suhu : "<<alpha<<endl;
    cout<<"  Suhu Akhir               : "<<takhir<<endl<<endl;

    //matriks solusi
    for(j=0;j<m;j++)
       {
        for (i=0;i<n;i++)
      	   {
             x[j][i]=0;
             b=awal[i];
             x[i][b]=1;
            }
       }
       //nilai makespan
    z=0;
   		//cout<<endl;
			for(i=0;i<n;i++)
   		{
   			{
      			//cout<<"\t|J "<<sol[i];
         		}
				{
      			for(j=0;j<m;j++)
      			{
         			if(i==0)
         			{
         				frek2[i][j]=frek[(awal[i]-1)][j]+z;
            			//cout<<"\t\t|  "<<waktu2[i][j];
            			z=frek2[i][j];
            			}
            		if(i>0 && j==0)
            		{
            			frek2[i][j]=frek2[i-1][j]+frek[(awal[i]-1)][j];
            			//cout<<"\t\t|  "<<waktu2[i][j];
               		}
						if(i>0 && j>0)
            		{
            			if(frek2[i][j-1]>=frek2[i-1][j])
             			{
								frek2[i][j]=frek2[i][j-1]+frek[(awal[i]-1)][j];
            				//cout<<"\t\t|  "<<waktu2[i][j];
            				}
             			if(frek2[i][j-1]<frek2[i-1][j])
               		{
               			frek2[i][j]=frek2[i-1][j]+frek[(awal[i]-1)][j];
                  		//cout<<"\t\t|  "<<waktu2[i][j];
                  		}
               		}
            		}
         		}
      		}
   		cout<<endl;
   		cout<<"\tMakespan solusi baru :"<<"\t"<<frek2[n-1][m-1];
    it=0;
    do{
       cout<<endl;
    	 it=it+1;
       cout<<"-------------------------------------------"<<endl;
       cout<<" Iterasi KE "<<it<<endl;
       cout<<"-------------------------------------------"<<endl;
       bnr=0;
       slh=0;
       do{
          do{
             s1=rand()%q;
             s2=rand()%q;
            }while(s1==s2);
          tukar=awal[s1];
          awal[s1]=awal[s2];
          awal[s2]=tukar;
          //matriks penempatan baru
          for (j=0;j<q;j++)
    	        {
               for (i=0;i<q;i++)
      	           {
                     x[j][i]=0;
                     b=awal[i];
         	         x[i][b]=1;
                    }
              }
          //hitung fungsi tujuan baru
          zbar=0;
   		//cout<<endl;
			for(i=0;i<n;i++)
   		{
   			{
      			//cout<<"\t|J "<<sol[i];
         		}
				{
      			for(j=0;j<m;j++)
      			{
         			if(i==0)
         			{
         				frek2[i][j]=frek[(awal[i]-1)][j]+zbar;
            			//cout<<"\t\t|  "<<waktu2[i][j];
            			zbar=frek2[i][j];
            			}
            		if(i>0 && j==0)
            		{
            			frek2[i][j]=frek2[i-1][j]+frek[(awal[i]-1)][j];
            			//cout<<"\t\t|  "<<waktu2[i][j];
               		}
						if(i>0 && j>0)
            		{
            			if(frek2[i][j-1]>=frek2[i-1][j])
             			{
								frek2[i][j]=frek2[i][j-1]+frek[(awal[i]-1)][j];
            				//cout<<"\t\t|  "<<waktu2[i][j];
            				}
             			if(frek2[i][j-1]<frek2[i-1][j])
               		{
               			frek2[i][j]=frek2[i-1][j]+frek[(awal[i]-1)][j];
                  		//cout<<"\t\t|  "<<waktu2[i][j];
                  		}
               		}
            		}
         		}
      		}
    //cek kebnaran
          if(zbar<=z)
          	{
             bnr=bnr+1;
             z=zbar;
             for(i=0;i<q;i++)
                {
                 solusi[i]=awal[i];
                }
            };
          if(zbar>z)
             {
              p=exp(-(zbar-z)/T);
              r=((double)rand()/(RAND_MAX + 1));
              if(r<p)
                 {
                  bnr=bnr+1;
                  z=zbar;
                  for(i=0;i<q;i++)
                     {
                      solusi[i]=awal[i];
                     }
                 }
              if(r>p)
                 {
                  slh=slh+1;
                 }
              }
       cout<<"  Urutan Solusi sekarang : ";
       for(i=0;i<q;i++)
           {
            cout<<awal[i]<<" ";
           }
       cout<<endl;
       cout<<"  Nilai Solusi Sekarang : "<<zbar<<endl;
       if(zbar>z)
          {
           cout<<"  Nilai peluang diterima : "<<p<<endl;
           cout<<"  Nilai random : "<<r<<endl;
          }
       cout<<"  Nilai makespan terbaik : "<<z<<endl;
       cout<<"  Benar = "<<bnr<<endl;
       cout<<"  Salah = "<<slh<<endl<<endl;
      }while(slh<5);
      T=alpha*T;
      cout<<"  Kriteria Looping dalam sudah terpenuhi."<<endl;
      cout<<"  Suhu turun menjadi : "<<T<<endl;
    }while(T>takhir);
    cout<<endl<<"  Karena suhu turun menjadi : "<<T<<" lebih kecil dari suhu akhir : "<<takhir<<endl;
    cout<<"  Iterasi Berhenti!"<<endl<<endl;
    cout<<"  Maka Solusi penyelesaiannya : "<<endl;
    for(i=0;i<q;i++)
     	 {
        cout<<"  Mesin ke "<<i+1<<" mengerjakan job ke "<<awal[i]<<endl;
       }
    cout<<endl<<"  Dengan Nilai Z : "<<z;
getch();
}
