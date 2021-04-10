#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <fstream.h>

void main()
{ofstream catat("JSP-SA.txt");
int awal,j,i,kgen,acak,turun,akhir,sol[16],sol_new[16],wkt1[16],suhu,k;
int isi[36]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
int wkt[6][6]={{3,6,1,7,6,3},{10,8,5,4,10,10},{9,1,5,4,7,8},{5,5,5,3,8,9},{3,3,9,1,5,4},{10,3,1,3,4,9}};
int makespan[6][6],makespan1[6][6],mak_col[6],mak_brs[6],maxi;
int simpan[100][100],msp[100];
double alfa1[100],alfa,n;

/*
Keterangan variabel:
awal		: suhu awal
akhir		: suhu akhir
turun		: penurunan suhu
suhu		: suhu iterasi
acak		: random bilangan acak untuk menyusun random solusi awal
kgen		: menyimpan random solusi awal
i,j,k		: variabel counter
isi		: array notasi 0-15
sol		: array untuk urutan solusi
sol_new	: array urutan solusi baru
wkt		: matriks waktu pengerjaan untuk solusi lama
wkt1		: matriks waktu pengerjaan untuk solusi baru
makespan	: matriks untuk menghitung fitness solusi lama
makespan1: matriks untuk menghitung fitness solusi baru
mak_brs	: matriks berisi maksimum baris
mak_col	: matriks berisi maksimum kolom
alfa		: tingkat perubahan suhu
alfa1		: array untuk menyimpan perubahan suhu
n			: banyaknya perubahan suhu
simpan	: menyimpan solusi akhir untuk suatu alfa tertentu
msp		: menyimpan makespan solusi akhir untuk alfa tertentu

*/

//catat.open("D:/JSP.txt");//Untuk menyimpan hasil running dlm Notepad

cout<<"======================================================="<<endl;
cout<<"         Solusi Optimal Permasalahan Job Shop"<<endl;
cout<<"      Menggunakan Algoritma Simulated Annealing"<<endl;
cout<<"        (kriteria dua atatu sukses dua gagal)"<<endl;
cout<<"======================================================="<<endl;
cout<<endl;
cout<<"Matriks job dan mesin"<<endl<<endl;

catat<<"======================================================"<<endl;
catat<<"         Solusi Optimal Permasalahan Job Shop"<<endl;
catat<<"      Menggunakan Algoritma Simulated Annealing"<<endl;
catat<<"        (kriteria dua atatu sukses dua gagal)"<<endl;
catat<<"======================================================"<<endl;
catat<<endl;
catat<<"Matriks job dan mesin"<<endl<<endl;

for (i=0;i<6;i++)
{	for(j=0;j<6;j++)
		{cout<<wkt[i][j]<<" ";
      catat<<wkt[i][j]<<" ";}
	cout<<endl<<endl;
   catat<<endl<<endl;
}
cout<<endl;
catat<<endl;
cout<<"(sumber:orlib(files.nyu.edu))"<<endl<<endl;
catat<<"(sumber:orlib(files.nyu.edu))"<<endl<<endl;

//Melinierkan bentuk matriks di atas
for(i=0;i<6;i++)
{
	for(j=0;j<6;j++)
		{if (i==0)
      	{wkt1[j]=wkt[i][j];}
      else if (i==1)
      	{wkt1[6+j]=wkt[i][j];}
		else if (i==2)
      	{wkt1[12+j]=wkt[i][j];}
      else if (i==3)
      	{wkt1[18+j]=wkt[i][j];}
      else if (i==4)
      	{wkt1[24+j]=wkt[i][j];}
      else
      	{wkt1[30+j]=wkt[i][j];}
      }
}
//menampilkan hasil manipulasi
	cout<<"Bentuk Linier:"<<endl;
   catat<<"Bentuk Linier:"<<endl;
	for(i=0;i<36;i++)
		{cout<<wkt1[i]<<" ";
      catat<<wkt1[i]<<" ";}
	cout<<endl;
   catat<<endl;
//urutan
	cout<<"Notasi 0-35"<<endl;
   catat<<"Notasi 0-35"<<endl;
   for(i=0;i<=35;i++)
   	{	sol[i]=isi[i];
      	cout<<sol[i]<<" ";
         catat<<sol[i]<<" ";
      }
   cout<<endl<<endl;
   catat<<endl<<endl;

cout<<endl;

//Mulai proses Simulated annealing
cout<<"======================================================="<<endl;
cout<<"              Proses Simulated Annealing"<<endl;
cout<<"======================================================="<<endl;

catat<<"======================================================="<<endl;
catat<<"              Proses Simulated Annealing"<<endl;
catat<<"======================================================="<<endl;

awal=100;akhir=10;

cout<<"Suhu awal:		"<<awal<<endl;
cout<<"Suhu akhir:	"<<akhir<<endl;
cout<<endl;

catat<<"Suhu awal:		"<<awal<<endl;
catat<<"Suhu akhir:	"<<akhir<<endl;
catat<<endl;
//Menginputkan beberapa nilai alfa yang berbeda
cout<<"Berapa kali perubahan alfa:	";
cin>>n;
catat<<"Berapa kali perubahan alfa:	"<<n<<endl;
int asli=n;
if(n<1 || n!=asli)
{
   cout<<"Input salah...minimal 1 dan atau harus bilangan bulat"<<endl;
   cout<<"ulangi: ";
   cin>>n;

   catat<<"Input salah...minimal 1 dan atau harus bilangan bulat"<<endl;
   catat<<"ulangi: ";
}
cout<<endl;
catat<<endl;

for(k=0;k<n;k++)
{
//clrscr();
cout<<"Tingkat Penurunan Suhu (alfa) ke-"<<k+1<<":	";
cin>>alfa;

catat<<"Tingkat Penurunan Suhu (alfa) ke-"<<k+1<<":	"<<alfa<<endl;
if (alfa<=0 || alfa>1)
{
	cout<<"Maaf input salah...alfa dalam himp (0,1]"<<endl;
   cout<<"Silahkan mengulangi:	";
   cin>>alfa;

   catat<<"Maaf input salah...alfa dalam himp (0,1]"<<endl;
   catat<<"Silahkan mengulangi:	";

}


suhu=awal;

//Random Solusi Awal
srand((unsigned)time(NULL));

for(i=0;i<=35;i++)
  	{
		acak=random(35-i);
      kgen=sol[acak+1];
      sol[acak+1]=sol[35-i];
      sol[35-i]=kgen;
  	}
cout<<endl;
catat<<endl;
cout<<"Solusi awal secara acak:"<<endl;
catat<<"Solusi acak:"<<endl;
for(i=0;i<=35;i++)
	{	cout<<sol[i]<<" ";
      catat<<sol[i]<<" ";
   }
cout<<endl;
catat<<endl;

/*int z[2][100];
for(j=0;j<36;j++)
	{	z[0][j]=sol[j];
   	z[1][j]=wkt1[sol[j]];
   }
for(i=0;i<2;i++)
{	for(j=0;j<36;j++)
		cout<<z[i][j]<<" ";
	cout<<endl;
}
*/
//Proses menghitung Makespan solusi awal/lama
   for (i=0;i<6;i++)
   {	for(j=0;j<6;j++)
   	{	makespan[i][j]=0;}
   }
   for(i=0;i<6;i++)
   {mak_col[i]=mak_brs[i]=0;}

   for(i=0;i<36;i++)
   {
   	if (sol[i]<6)
      {
         for(j=0;j<6;j++)
         {
            mak_brs[0]=max(mak_brs[0],makespan[0][j]);//maks baris
            mak_col[sol[i]]=max(mak_col[sol[i]],makespan[j][sol[i]]);//mak kolom
         }//tutup for j

         makespan[0][sol[i]]=max(mak_brs[0],mak_col[sol[i]])+wkt1[sol[i]];
         }//tutup if 6

      else if (sol[i]>=6 && sol[i]<12)
      	{
         for(j=0;j<6;j++)
         	{
            mak_brs[1]=max(mak_brs[1],makespan[1][j]);
            mak_col[sol[i]-6]=max(mak_col[sol[i]-6],makespan[j][sol[i]-6]);

         	}//tutup for j
         makespan[1][sol[i]-6]=max(mak_brs[1],mak_col[sol[i]-6])+wkt1[sol[i]];
         }//tutup else if 6

      else if (sol[i]>=12 && sol[i]<18)
      	{
         for(j=0;j<6;j++)
         	{
            mak_brs[2]=max(mak_brs[2],makespan[2][j]);
            mak_col[sol[i]-12]=max(mak_col[sol[i]-12],makespan[j][sol[i]-12]);

         	}//tutup for j
         makespan[2][sol[i]-12]=max(mak_brs[2],mak_col[sol[i]-12])+wkt1[sol[i]];
         }//tutup else if 6


      else if (sol[i]>=18 && sol[i]<24)
      	{
         for(j=0;j<6;j++)
         	{
            mak_brs[3]=max(mak_brs[3],makespan[3][j]);
            mak_col[sol[i]-18]=max(mak_col[sol[i]-18],makespan[j][sol[i]-18]);

         	}//tutup for j
         makespan[3][sol[i]-18]=max(mak_brs[3],mak_col[sol[i]-18])+wkt1[sol[i]];
         }//tutup else if 6

      else if (sol[i]>=24 && sol[i]<30)
      	{
         for(j=0;j<6;j++)
         	{
            mak_brs[4]=max(mak_brs[4],makespan[4][j]);
            mak_col[sol[i]-24]=max(mak_col[sol[i]-24],makespan[j][sol[i]-24]);

         	}//tutup for j
         makespan[4][sol[i]-24]=max(mak_brs[4],mak_col[sol[i]-24])+wkt1[sol[i]];
         }//tutup else if 6

      else
      	{
         for(j=0;j<6;j++)
         	{
            mak_brs[5]=max(mak_brs[5],makespan[5][j]);
            mak_col[sol[i]-30]=max(mak_col[sol[i]-30],makespan[j][sol[i]-30]);

         	}//tutup for j
         makespan[5][sol[i]-30]=max(mak_brs[5],mak_col[sol[i]-30])+wkt1[sol[i]];
         }//tutup else if 6
   }//tutup for 36

//menampilkan makespan semua
	cout<<endl;catat<<endl;
	cout<<"Matriks Pencarian Makespan:"<<endl;
   catat<<"Matriks Pencarian Makespan:"<<endl;
   for(i=0;i<6;i++)
   {	for (j=0;j<6;j++)
   		{cout<<makespan[i][j]<<" ";
         catat<<makespan[i][j]<<" ";}
   	cout<<endl;
      catat<<endl;
   }

//Mengambil nilai makespan solusi awal/lama
//dgn cara mengambil nilai tertinggi dlm matrik makespan
maxi=0;
int sukses,gagal,a,b,maxi1=0,delta;
// maxi	: nilai makespan solusi lama
// maxi1	: nilai makespan solusi baru
for (i=0;i<6;i++)
{	for(j=0;j<6;j++)
	{maxi=max(maxi,makespan[i][j]);}
}
cout<<"Makespan solusi awal = "<<maxi<<endl;
cout<<"======================================================="<<endl<<endl;
//untuk notepad
catat<<"Makespan solusi awal = "<<maxi<<endl;
catat<<"======================================================"<<endl<<endl;


//Iterasi
while(suhu>akhir)
{
	maxi1=0;
	sukses=gagal=1;
	cout<<"ITERASI SUHU KE-"<<suhu<<endl<<endl;
   catat<<"ITERASI SUHU KE-"<<suhu<<endl<<endl;
//Looping dalam (2 sukses atau 2 gagl)
	while(sukses<=2 || gagal<=2)
   {
//Menampilkan solusi lama
   cout<<"Solusi Lama:"<<endl;
   catat<<"Solusi Lama:"<<endl;
   for(i=0;i<36;i++)
   	{cout<<sol[i]<<" ";
      catat<<sol[i]<<" ";}
   cout<<endl;
   catat<<endl;
   cout<<"MAKESPAN: "<<maxi;
   catat<<"MAKESPAN: "<<maxi;
   cout<<endl<<endl;
   catat<<endl<<endl;


//Proses Gangguan
//random 2 tempat untuk saling ditukar
   a=rand()%36;
   b=rand()%36;
   acak=sol[b];
   sol[b]=sol[a];
   sol[a]=acak;
//menampilkan hasil gangguan
   cout<<endl;
   cout<<"MUTASI"<<endl<<endl;

   catat<<endl;
   catat<<"MUTASI"<<endl<<endl;

   cout<<"Solusi Baru :"<<endl;
   catat<<"Solusi Baru :"<<endl;
   for (i=0;i<36;i++)
   	{sol_new[i]=sol[i];
      cout<<sol_new[i]<<" ";
      catat<<sol_new[i]<<" ";}
   cout<<endl<<endl;
   catat<<endl<<endl;

//Pencarian makespan solusi baru
   for(i=0;i<6;i++)
   	{mak_col[i]=mak_brs[i]=0;}
   for (i=0;i<6;i++)
	{	for(j=0;j<6;j++)
		{makespan1[i][j]=0;}
	}
	for(i=0;i<36;i++)
   	{
   		if (sol_new[i]<6)
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[0]=max(mak_brs[0],makespan1[0][j]);//maks baris
            	mak_col[sol_new[i]]=max(mak_col[sol_new[i]],makespan1[j][sol_new[i]]);
               //maks kolom
         		}//tutup for j

         	makespan1[0][sol_new[i]]=max(mak_brs[0],mak_col[sol_new[i]])+wkt1[sol_new[i]];

         	}//tutup if 6

      	else if (sol_new[i]>=6 && sol_new[i]<12)
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[1]=max(mak_brs[1],makespan1[1][j]);
            	mak_col[sol_new[i]-6]=max(mak_col[sol_new[i]-6],makespan1[j][sol_new[i]-6]);

         		}//tutup for j
         	makespan1[1][sol_new[i]-6]=max(mak_brs[1],mak_col[sol_new[i]-6])+wkt1[sol_new[i]];
         	}//tutup else if 6

      	else if (sol_new[i]>=12 && sol_new[i]<18)
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[2]=max(mak_brs[2],makespan1[2][j]);
            	mak_col[sol_new[i]-12]=max(mak_col[sol_new[i]-12],makespan1[j][sol_new[i]-12]);

         		}//tutup for j
         	makespan1[2][sol_new[i]-12]=max(mak_brs[2],mak_col[sol_new[i]-12])+wkt1[sol_new[i]];
         	}//tutup else if 6

         else if (sol_new[i]>=18 && sol_new[i]<24)
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[3]=max(mak_brs[3],makespan1[3][j]);
            	mak_col[sol_new[i]-18]=max(mak_col[sol_new[i]-18],makespan1[j][sol_new[i]-18]);

         		}//tutup for j
         	makespan1[3][sol_new[i]-18]=max(mak_brs[3],mak_col[sol_new[i]-18])+wkt1[sol_new[i]];
         	}//tutup else if 6

         else if (sol_new[i]>=24 && sol_new[i]<30)
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[4]=max(mak_brs[4],makespan1[4][j]);
            	mak_col[sol_new[i]-24]=max(mak_col[sol_new[i]-24],makespan1[j][sol_new[i]-24]);

         		}//tutup for j
         	makespan1[4][sol_new[i]-24]=max(mak_brs[4],mak_col[sol_new[i]-24])+wkt1[sol_new[i]];
         	}//tutup else if 6

      	else
      		{
         	for(j=0;j<6;j++)
         		{
            	mak_brs[5]=max(mak_brs[5],makespan1[5][j]);
            	mak_col[sol_new[i]-30]=max(mak_col[sol_new[i]-30],makespan1[j][sol_new[i]-30]);

         		}//tutup for j
         	makespan1[5][sol_new[i]-30]=max(mak_brs[5],mak_col[sol_new[i]-30])+wkt1[sol_new[i]];
         	}//tutup else if 6
   	}//tutup for 36

//fungsi tujuan gangguan

/*   for(i=0;i<6;i++)
   {	for(j=0;j<6;j++)
   		{cout<<makespan1[i][j]<<" ";
         catat<<makespan1[i][j]<<" ";}
   	cout<<endl;
      catat<<endl;
   }
   cout<<endl;
   catat<<endl;*/
   for (i=0;i<6;i++)
   {	for(j=0;j<6;j++)
   	{maxi1=max(maxi1,makespan1[i][j]);}
   }
   cout<<"MAKESPAN: "<<maxi1<<endl;
   catat<<"MAKESPAN: "<<maxi1<<endl;
   delta=maxi1-maxi;
   double r,p,q;
   r=rand()%1000;// bil.random r
	r=r/1000;
   q=-delta/suhu;
  	p=exp(q);//probabilitas penerimaan

//Syarat SUKSES atau GAGAL-nya solusi baru
   if (delta<0)
   	{for (i=0;i<36;i++)
   		{	sol[i]=sol_new[i];
         	maxi=maxi1;}
         	gagal=gagal+1;
		      sukses=sukses+1;
			   cout<<"DELTA C: "<<delta<<endl;
            cout<<"<SUKSES>"<<endl<<endl;

            catat<<"DELTA C: "<<delta<<endl;
            catat<<"<SUKSES>"<<endl<<endl;
      }
   else if (r<p)
      {for (i=0;i<36;i++)
   		{	sol[i]=sol_new[i];
         	maxi=maxi1;}
         	gagal=gagal+1;
            sukses=sukses+1;
            cout<<"DELTA C: "<<delta<<endl;
            cout<<"BIL.RANDOM(r): "<<r<<"	PROBABILITAS(p): "<<p<<endl;
            cout<<"<SUKSES>"<<endl<<endl;

            catat<<"DELTA C: "<<delta<<endl;
            catat<<"BIL.RANDOM(r): "<<r<<"	PROBABILITAS(p): "<<p<<endl;
            catat<<"<SUKSES>"<<endl<<endl;
      }
   else
   	{for(i=0;i<36;i++)
      	sukses=sukses+1;
         gagal=gagal+1;
         cout<<"DELTA C: "<<delta<<endl;
         cout<<"BIL>RANDOM(r): "<<r<<"	PROBABILITAS(p): "<<p<<endl;
       	cout<<"<GAGAL>"<<endl<<endl;

         catat<<"DELTA C: "<<delta<<endl;
         catat<<"BIL.RANDOM(r): "<<r<<"	PROBABILITAS(p): "<<p<<endl;
         catat<<"<GAGAL>"<<endl<<endl;
      }
   }//while sukses or gagal
   suhu=suhu-suhu*alfa;
}//while suhu
cout<<endl<<endl<<endl;
catat<<endl<<endl<<endl;
cout<<"========================================================"<<endl;
//Solusi terakhir ketika mencapai suhu akhir
cout<<endl;
cout<<"Solusi Optimal yang diperoleh ketika mencapai suhu akhir"<<endl<<endl;

catat<<endl;
catat<<"Solusi Optimal yang diperoleh ketika mencapai suhu akhir"<<endl<<endl;
for(i=0;i<36;i++)
  	{cout<<sol[i]<<" ";catat<<sol[i]<<" ";
   }
cout<<endl<<endl;
catat<<endl<<endl;
cout<<"Urutan pengerjaan setiap job pada setiap mesin"<<endl;
catat<<"Urutan pengerjaan setiap job pada setiap mesin"<<endl;

for (i=0;i<36;i++)
	{if (sol[i]<6)
   	{cout<<"job ke-1 "<<"mesin ke-"<<sol[i]+1<<endl;
      catat<<"job ke-1 "<<"mesin ke-"<<sol[i]+1<<endl;}
   else if(sol[i]>=6 && sol[i]<12)
   	{cout<<"job ke-2 "<<"mesin ke-"<<sol[i]-5<<endl;
      catat<<"job ke-2 "<<"mesin ke-"<<sol[i]-5<<endl;}
   else if(sol[i]>=12 && sol[i]<18)
   	{cout<<"job ke-3 "<<"mesin ke-"<<sol[i]-11<<endl;
      catat<<"job ke-3 "<<"mesin ke-"<<sol[i]-11<<endl;}
   else if(sol[i]>=18 && sol[i]<24)
   	{cout<<"job ke-4 "<<"mesin ke-"<<sol[i]-17<<endl;
      catat<<"job ke-4 "<<"mesin ke-"<<sol[i]-17<<endl;}
   else if(sol[i]>=24 && sol[i]<30)
   	{cout<<"job ke-5 "<<"mesin ke-"<<sol[i]-23<<endl;
      catat<<"job ke-5 "<<"mesin ke-"<<sol[i]-23<<endl;}
   else if(sol[i]>=30 && sol[i]<36)
   	{cout<<"job ke-6 "<<"mesin ke-"<<sol[i]-29<<endl;
      catat<<"job ke-6 "<<"mesin ke-"<<sol[i]-29<<endl;}
   }
   cout<<endl;
   catat<<endl;
cout<<"Dengan makespan: "<<maxi<<endl<<endl;
cout<<"=================================================="<<endl;
catat<<"Dengan makespan: "<<maxi<<endl<<endl;
catat<<"=================================================="<<endl;

for(i=0;i<n;i++)
{	if (i==k)
	{	msp[i]=maxi;
      for(j=0;j<36;j++)
      	simpan[i][j]=sol[j];
      alfa1[i]=alfa;
   }
}

}//for k

//Menampilkan perbandingan untuk beberapa nilai alfa yang berbeda
cout<<"========================================================"<<endl;
cout<<"Alfa	Solusi akhir				Makespan"<<endl;
cout<<"========================================================"<<endl;

catat<<"========================================================"<<endl;
catat<<"Alfa	Solusi akhir				Makespan"<<endl;
catat<<"========================================================"<<endl;

for(i=0;i<n;i++)
{  cout<<alfa1[i]<<"	";
	catat<<alfa1[i]<<"	";
	for(j=0;j<36;j++)
   {	cout<<simpan[i][j]<<" ";
		catat<<simpan[i][j]<<" ";
   }
   cout<<"	"<<msp[i]<<endl<<endl;
   catat<<"	"<<msp[i]<<endl<<endl;
}
cout<<endl;
catat<<endl;
catat.close();

getch();
}