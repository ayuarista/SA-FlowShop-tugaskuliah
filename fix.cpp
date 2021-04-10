#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <fstream.h>

void main()
{
	ofstream file("SA.txt");
	int job,mesin,i,j,waktu[100][100],waktu1[100][100],waktu2[100][100],sol[100],acak,acak1,acak2,temp,tawal1=0;
   int pilihan,pilihan1,pilihan2,benar;

//tampilan awal

   cout<<endl;
	cout<<"\t\t\t\t\t\t                AIRLANGGA UNIVERSITY"<<endl;
	cout<<"\t\t\t\t\t\t======================================================="<<endl;
	cout<<"\t\t\t\t\t\t   Solusi Optimal Permasalahan Permutation Job Shop"<<endl;
	cout<<"\t\t\t\t\t\t      Menggunakan Algoritma Simulated Annealing"<<endl;
	cout<<"\t\t\t\t\t\t              (kriteria 5 sukses)"<<endl;
	cout<<"\t\t\t\t\t\t======================================================="<<endl;
	cout<<endl;

   file<<endl;
	file<<"\t\t\t\t\t\t                AIRLANGGA UNIVERSITY"<<endl;
	file<<"\t\t\t\t\t\t======================================================="<<endl;
	file<<"\t\t\t\t\t\t   Solusi Optimal Permasalahan Permutation Job Shop"<<endl;
	file<<"\t\t\t\t\t\t      Menggunakan Algoritma Simulated Annealing"<<endl;
	file<<"\t\t\t\t\t\t              (kriteria 5 sukses)"<<endl;
	file<<"\t\t\t\t\t\t======================================================="<<endl;
	file<<endl;


//input job dan mesin

	ifstream buka;
	cout<<"\tPilih:"<<endl;
	cout<<"\t1. Data Kecil"<<endl;
	cout<<"\t2. Data Sedang"<<endl;
	cout<<"\t3. Data Besar"<<endl;
	do
   {
		cout<<"\tPilihan: ";
		cin>>pilihan1;
		pilihan=pilihan1;
		pilihan2=pilihan1-pilihan;
		switch(pilihan)
		{
			case 1:
   		buka.open("DataD1.txt");
   		job=4;
   		mesin=3;
   		benar=1;
   		break;

			case 2:
   		buka.open("DataD2.txt");
   		job=10;
   		mesin=9;
   		benar=1;
   		break;

   		case 3:
   		buka.open("DataD3.txt");
   		job=100;
   		mesin=10;
   		benar=1;
   		break;

   		default:
   		cout<<endl<<"Pilihan yang anda masukkan salah"<<endl;
   		benar=0;
			}
		}

//data waktu

	while(benar!=1 || pilihan2!=0);
   cout<<endl;
   cout<<"\t=========================================="<<endl;
   file<<"\t=========================================="<<endl;
	cout<<"\t              Data Awal"<<endl;
   file<<"\t              Data Awal"<<endl;
	cout<<"\t=========================================="<<endl;
   file<<"\t=========================================="<<endl;
	cout<<endl;
   file<<endl;
  	cout<<"\t|   Job/Mesin";
   file<<"\t|   Job/Mesin";
   for(i=0;i<mesin;i++)
   {
   	cout<<"\t|  M "<<(i+1)<<"\t";
      file<<"\t|  M "<<(i+1)<<"\t";
      }
   cout<<"\t|";
   file<<"\t|";
   cout<<endl;
   file<<endl;
   cout<<"\t|";
   file<<"\t|";
   for(i=0;i<mesin+1;i++)
   {
   	cout<<"--------------\t|";
      file<<"--------------\t|";
      }
   cout<<endl;
   file<<endl;
   for(i=0;i<job;i++)
   {
   	{
      	cout<<"\t|J "<<(i+1);
         file<<"\t|J "<<(i+1);
         }
      for(j=0;j<mesin;j++)
      {
      	buka>>waktu[i][j];
      	cout<<"\t\t|  "<<waktu[i][j];
         file<<"\t\t|  "<<waktu[i][j];
         }
      cout<<"\t\t|";
      file<<"\t\t|";
      cout<<endl;
      file<<endl;
      }

//membangkitkan solusi awal

	cout<<endl<<endl;
   file<<endl<<endl;
	for(i=0;i<job;i++)
   {
   	sol[i]=i+1;
      }
   srand(time(0));
   for(i=0;i<job;i++)
   {
   	acak=random(job);
      temp=sol[acak];
      sol[acak]=sol[i];
      sol[i]=temp;
      }
   cout<<"[-] solusi awal :\t";
   file<<"[-] solusi awal :\t";
   for(i=0;i<job;i++)
   {
   	cout<<sol[i]<<" - ";
   	file<<sol[i]<<" - ";
      }


//menghitung makespan solusi awal

	cout<<endl<<endl;
   file<<endl<<endl;
  	cout<<"\t|  Job/mesin";
   file<<"\t|  Job/mesin";
   for(i=0;i<mesin;i++)
   {
   	cout<<"\t|  M "<<(i+1)<<"\t";
      file<<"\t|  M "<<(i+1)<<"\t";
      }
   cout<<"\t|";
   file<<"\t|";
   cout<<endl;
   file<<endl;
   cout<<"\t|";
   file<<"\t|";
   for(i=0;i<mesin+1;i++)
   {
   	cout<<"--------------\t|";
      file<<"--------------\t|";
      }
   cout<<endl;
   file<<endl;
	for(i=0;i<job;i++)
   {
   	{
      	cout<<"\t|J "<<sol[i];
         file<<"\t|J "<<sol[i];
         }

      {
      for(j=0;j<mesin;j++)
      	{
         if(i==0)
         	{
         		waktu1[i][j]=waktu[(sol[i]-1)][j]+tawal1;
            	cout<<"\t\t|  "<<waktu1[i][j];
               file<<"\t\t|  "<<waktu1[i][j];
            	tawal1=waktu1[i][j];
            	}
            if(i>0 && j==0)
            {
            	waktu1[i][j]=waktu1[i-1][j]+waktu[(sol[i]-1)][j];
            	cout<<"\t\t|  "<<waktu1[i][j];
               file<<"\t\t|  "<<waktu1[i][j];
               }
				if(i>0 && j>0)
            {
            	if(waktu1[i][j-1]>=waktu1[i-1][j])
             	{
						waktu1[i][j]=waktu1[i][j-1]+waktu[(sol[i]-1)][j];
            		cout<<"\t\t|  "<<waktu1[i][j];
                  file<<"\t\t|  "<<waktu1[i][j];
            		}
             	if(waktu1[i][j-1]<waktu1[i-1][j])
               {
               	waktu1[i][j]=waktu1[i-1][j]+waktu[(sol[i]-1)][j];
                  cout<<"\t\t|  "<<waktu1[i][j];
                  file<<"\t\t|  "<<waktu1[i][j];
                  }
               }
            }
         }
      cout<<"\t\t|";
      file<<"\t\t|";
      cout<<endl;
      file<<endl;
      }
   cout<<endl;
   file<<endl;
   cout<<"\tMakespan solusi awal :"<<"\t"<<waktu1[job-1][mesin-1];
   file<<"\tMakespan solusi awal :"<<"\t"<<waktu1[job-1][mesin-1];

//proses algoritma

   int sukses,suhu,akhir;
   double p,q,r,delta,alfa;
   cout<<endl<<endl;
   file<<endl<<endl;
	cout<<"\t======================================================="<<endl;
   file<<"\t======================================================="<<endl;
	cout<<"\t              Proses Simulated Annealing"<<endl;
   file<<"\t              Proses Simulated Annealing"<<endl;
	cout<<"\t======================================================="<<endl;
   file<<"\t======================================================="<<endl;
   cout<<endl;
   file<<endl;
   cout<<"\tMasukkan suhu awal:\t\t";
   cin>>suhu;
   file<<"\tMasukkan suhu awal:\t\t"<<suhu<<endl;
   cout<<"\tMasukkan suhu akhir:\t\t";
   cin>>akhir;
   file<<"\tMasukkan suhu akhir:\t\t"<<akhir<<endl;
   cout<<"\tMasukkan alfa(bilangan 0-1):\t";
   cin>>alfa;
   file<<"\tMasukkan alfa(bilangan 0-1):\t"<<alfa<<endl;
   cout<<endl;
   file<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<endl;
   file<<endl;
   srand(time(0));
   while(suhu>akhir)
   {
   	sukses=0;
      while(sukses<5)
      {

//solusi baru

			acak1=rand()%(job);
   		acak2=rand()%(job);
			temp=sol[acak1];
   		sol[acak1]=sol[acak2];
   		sol[acak2]=temp;
   		cout<<endl;
			cout<<"[-] solusi baru :\t";
         file<<"[-] solusi baru :\t";
   		for(i=0;i<job;i++)
   		{
   			cout<<sol[i]<<"\-";
            file<<sol[i]<<"\-";
      		}
   		//for(i=0;i<job;i++)
   		//{
   			//for(j=0;j<mesin;j++)
      		//{
      			//waktu2[i][j]=0;
         		//}
      		//}

//menghitung makespan

			cout<<endl<<endl;
         file<<endl<<endl;
   		int tawal2=0;
  			//cout<<"\t|   Job/Mesin";
   		for(i=0;i<mesin;i++)
   		{
   			//cout<<"\t|  M "<<(i+1)<<"\t";
      		}
   		//cout<<"\t|";
   		//cout<<endl;
   		//cout<<"\t|";
   		for(i=0;i<mesin+1;i++)
   		{
   			//cout<<"--------------\t|";
      		}
   		//cout<<endl;
			for(i=0;i<job;i++)
   		{
   			{
      			//cout<<"\t|J "<<sol[i];
         		}
				{
      			for(j=0;j<mesin;j++)
      			{
         			if(i==0)
         			{
         				waktu2[i][j]=waktu[(sol[i]-1)][j]+tawal2;
            			//cout<<"\t\t|  "<<waktu2[i][j];
            			tawal2=waktu2[i][j];
            			}
            		if(i>0 && j==0)
            		{
            			waktu2[i][j]=waktu2[i-1][j]+waktu[(sol[i]-1)][j];
            			//cout<<"\t\t|  "<<waktu2[i][j];
               		}
						if(i>0 && j>0)
            		{
            			if(waktu2[i][j-1]>=waktu2[i-1][j])
             			{
								waktu2[i][j]=waktu2[i][j-1]+waktu[(sol[i]-1)][j];
            				//cout<<"\t\t|  "<<waktu2[i][j];
            				}
             			if(waktu2[i][j-1]<waktu2[i-1][j])
               		{
               			waktu2[i][j]=waktu2[i-1][j]+waktu[(sol[i]-1)][j];
                  		//cout<<"\t\t|  "<<waktu2[i][j];
                  		}
               		}
            		}
         		}
      		//cout<<"\t\t|";
      		//cout<<endl;
      		}
   		cout<<endl;
         file<<endl;
   		cout<<"\tMakespan solusi baru :"<<"\t"<<waktu2[job-1][mesin-1];
         file<<"\tMakespan solusi baru :"<<"\t"<<waktu2[job-1][mesin-1];
   		delta=waktu2[job-1][mesin-1]-waktu1[job-1][mesin-1];
   		r=rand()%1000;
   		r=r/1000;
   		q=-delta/suhu;
   		p=exp(q);
			cout<<endl<<endl;
         file<<endl<<endl;
   		if(delta<0)
   		{
   			sukses=sukses+1;
   			cout<<"\tDelta:\t"<<delta<<endl<<endl;
            file<<"\tDelta:\t"<<delta<<endl<<endl;
      		cout<<"  [V]\tSukses"<<endl<<endl;
            file<<"  [V]\tSukses"<<endl<<endl;
      		waktu1[job-1][mesin-1]=waktu2[job-1][mesin-1];
   			}
   		if(delta>=0)
   		{
   			if(r<=p)
      		{
      			sukses=sukses+1;
   				cout<<"\tDelta:\t"<<delta<<endl<<endl;
               file<<"\tDelta:\t"<<delta<<endl<<endl;
      			cout<<"\tr:\t"<<r<<endl<<endl;
               file<<"\tr:\t"<<r<<endl<<endl;
      			cout<<"\tp:\t"<<p<<endl<<endl;
               file<<"\tp:\t"<<p<<endl<<endl;
         		cout<<"  [V]\tSukses"<<endl<<endl;
               file<<"  [V]\tSukses"<<endl<<endl;
      			waktu1[job-1][mesin-1]=waktu2[job-1][mesin-1];
      			}
      		if(r>p)
      		{
      			cout<<"\tDelta:\t"<<delta<<endl<<endl;
               file<<"\tDelta:\t"<<delta<<endl<<endl;
      			cout<<"\tr:\t"<<r<<endl<<endl;
               file<<"\tr:\t"<<r<<endl<<endl;
      			cout<<"\tp:\t"<<p<<endl<<endl;
               file<<"\tp:\t"<<p<<endl<<endl;
         		cout<<"  [X]\tGagal"<<endl<<endl;
               file<<"  [X]\tGagal"<<endl<<endl;
      			waktu1[job-1][mesin-1]=waktu1[job-1][mesin-1];
         		}
      		}
   		cout<<"\tJumlah sukses:\t"<<sukses;
         file<<"\tJumlah sukses:\t"<<sukses;
   		cout<<endl<<endl;
         file<<endl<<endl;
   		cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
         file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   		cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
         file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   		}
   	suhu=suhu-suhu*alfa;
   	cout<<endl;
      file<<endl;
   	cout<<"============================================================================================================================================================"<<endl;
      file<<"============================================================================================================================================================"<<endl;
   	cout<<endl;
      file<<endl;
   	cout<<"\tKarena looping dalam terpenuhi sebanyak 5 sukses, maka dilakukan penurunan suhu";
   	cout<<endl<<endl;
      file<<endl<<endl;
   	suhu=suhu-(suhu*alfa);
   	cout<<"\tSuhu baru :\t"<<suhu<<endl<<endl;
      file<<"\tSuhu baru :\t"<<suhu<<endl<<endl;
   	cout<<"============================================================================================================================================================"<<endl;
      file<<"============================================================================================================================================================"<<endl;
   	}
   cout<<endl;
   file<<endl;
   cout<<"\tKarena suhu baru kurang dari suhu akhir maka iterasi berhenti";
   file<<"\tKarena suhu baru kurang dari suhu akhir maka iterasi berhenti";
   cout<<endl<<endl;
   file<<endl<<endl;
   cout<<"============================================================================================================================================================"<<endl;
   file<<"============================================================================================================================================================"<<endl;
   cout<<endl;
   file<<endl;
   cout<<"\tKesimpulan:"<<endl;
   file<<"\tKesimpulan:"<<endl;
   cout<<"\tsolusi optimalnya adalah:\t";
   file<<"\tsolusi optimalnya adalah:\t";
   for(i=0;i<job;i++)
   {
   	cout<<sol[i]<<"-";
      file<<sol[i]<<"-";
      }
   cout<<endl<<endl;
   file<<endl<<endl;
   cout<<"\tDengan makespan:\t"<<waktu1[job-1][mesin-1];
   file<<"\tDengan makespan:\t"<<waktu1[job-1][mesin-1];
   cout<<endl<<endl;
   file<<endl<<endl;
   cout<<"\tArtinya:";
   file<<"\tArtinya:";
   cout<<endl;
   file<<endl;
   cout<<"\tYang harus dikerjakan terlebih dahulu adalah:\t"<<endl;
   file<<"\tYang harus dikerjakan terlebih dahulu adalah:\t"<<endl;
   for(i=0;i<job;i++)
   {
   	cout<<"\t|"<<(i+1)<<".\t|\tJob "<<sol[i]<<"\t\tpada Mesin "<<(i+1)<<"\t\t|"<<endl;
      file<<"\t|"<<(i+1)<<".\t|\tJob "<<sol[i]<<"\t\tpada Mesin "<<(i+1)<<"\t\t|"<<endl;
      }
   cout<<endl;
   file<<endl;
   cout<<"\tDengan waktu:\t"<<waktu1[job-1][mesin-1]<<" Menit";
   file<<"\tDengan waktu:\t"<<waktu1[job-1][mesin-1]<<" Menit";

   file.close();

	getch();
	}












