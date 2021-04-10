#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main()
{
    ifstream arus, jrk;
    int jarak[100][100],frek[100][100],x[100][100],j,i,n,b,k,l,slh,bnr,pilih,iya,it,s1,s2,tukar,solusi[100];
    float awal[100],sem[100],tuk,ha[100],z,T,alpha,takhir,zbar,p,r;
    cout<<endl;
    /*cout<<"  Masukkan Jumlah Data : ";cin>>n;*/
    cout<<" *----------------------------------------------------------*"<<endl;
    cout<<" | PROGRAM UNTUK MENYELESAIKAN QUADRATIC ASSIGNMENT PROBLEM |"<<endl;
    cout<<" |               DENGAN SIMULATED ANNEALING                 |"<<endl;
    cout<<" *----------------------------------------------------------*"<<endl<<endl;
    cout<<"  Pilihan Data : "<<endl;
    cout<<"  1. Data 4 fasilitas 4 lokasi"<<endl;
    cout<<"  2. Data 12 fasilitas 12 lokasi"<<endl;
    cout<<"  3. Data 14 fasilitas 14 lokasi"<<endl;
    cout<<"  4. Data 16 fasilitas 16 lokasi"<<endl;
    cout<<"  5. Data 18 fasilitas 18 lokasi"<<endl;
    cout<<"  6. Data 20 fasilitas 20 lokasi"<<endl;
    do{
       cout<<endl<<"  Data yang anda pilih : ";cin>>pilih;
       switch(pilih)
             {
              case 1:
              arus.open("arus1.txt");
              jrk.open("jarak1.txt");
              n=4;
              iya=1;
              break;

              case 2:
              arus.open("arus2.txt");
              jrk.open("jarak2.txt");
              n=12;
              iya=1;
              break;

              case 3:
              arus.open("arus3.txt");
              jrk.open("jarak3.txt");
              n=14;
              iya=1;
              break;

              case 4:
              arus.open("arus4.txt");
              jrk.open("jarak4.txt");
              n=16;
              iya=1;
              break;

              case 5:
              arus.open("arus5.txt");
              jrk.open("jarak5.txt");
              n=18;
              iya=1;
              break;

              case 6:
              arus.open("arus6.txt");
              jrk.open("jarak6.txt");
              n=20;
              iya=1;
              break;

              default:
              cout<<"  input yang anda pilih salah, coba ulangi lagi"<<endl;
              iya=0;
             }
       }while(iya==0);
    for(i=0;i<n;i++)
     	 {
        for(j=0;j<n;j++)
      	  {
            arus>>frek[i][j];
            jrk>>jarak[i][j];
           }
       }
    /*for (i=0;i<n;i++)
    { for (j=0;j<n;j++)
      { cout<<"Masukkan jarak antara lokasi ke "<<i<<" dan "<<j<<" : ";cin>>jarak[i][j];
       }
    }
    cout<<endl;
    for (i=0;i<n;i++)
    { for (j=0;j<n;j++)
      { cout<<"Masukkan frekuensi perpindahan dari fasilitas ke "<<i<<" ke fasilitas ke "<<j<<" : ";cin>>frek[i][j];
       }
    }*/
    cout<<endl;
    cout<<"  INPUT PARAMETER SIMULATED ANNEALING"<<endl;
    cout<<"  ==================================="<<endl;
    do{
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
    cout<<"       Untuk menyelesaikan QAP"<<endl;
    cout<<"======================================"<<endl;
    cout<<"-------parameter yang digunakan-------"<<endl;
    cout<<"  Suhu Awal                : "<<T<<endl;
    cout<<"  Koefisien penurunan suhu : "<<alpha<<endl;
    cout<<"  Suhu Akhir               : "<<takhir<<endl<<endl;
    cout<<endl<<"  Matriks arus : "<<endl;
    for (i=0;i<n;i++)
        {
         cout<<" ";
         for (j=0;j<n;j++)
             {
              cout<<" "<<frek[i][j];
             }
         cout<<endl;
        }
    cout<<endl<<"  Matriks jarak : "<<endl;
    for (i=0;i<n;i++)
        {
         cout<<" ";
         for (j=0;j<n;j++)
             {
              cout<<" "<<jarak[i][j];
             }
         cout<<endl;
        }
    //Membangkitkan solusi awal secara acak
     for(i=0;i<n;i++)
    	  {
         sem[i]=rand()%1000;
         ha[i]=sem[i];}
         for(i=0;i<n;i++)
    	       {
              for(j=0;j<n;j++)
                 {
                  if(sem[i]<sem[j])
                     {
                      tuk=sem[i];
                      sem[i]=sem[j];
                      sem[j]=tuk;
                     }
                 }
             }
    for(i=0;i<n;i++)
    	 {
        for(j=0;j<n;j++)
           {
            if(sem[i]==ha[j])
          	  {
               awal[i]=j;
              }
           }
       }
      /* manual
      for(i=0;i<n;i++)
      {cout<<" nilai : ";cin>>awal[i];}*/
//matriks penempatan
    for(j=0;j<n;j++)
       {
        for (i=0;i<n;i++)
      	   {
             x[j][i]=0;
             b=awal[i];
             x[i][b]=1;
            }
       }
    cout<<endl<<"  Solusi Awal : ";
    for(i=0;i<n;i++)
    	 {
        cout<<awal[i]+1<<" ";
       }
    cout<<endl;
    z=0;
    for(i=0;i<n;i++)
    	 {
        for (j=0;j<n;j++)
      	   {
             for (k=0;k<n;k++)
         	      {
                   for (l=0;l<n;l++)
                        {
                         z=z+(frek[i][k]*jarak[j][l]*x[i][j]*x[k][l]);
                        }
                  }
             }
       }
    cout<<endl<<"  Nilai z= "<<z;
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
             s1=rand()%n;
             s2=rand()%n;
            }while(s1==s2);
          tukar=awal[s1];
          awal[s1]=awal[s2];
          awal[s2]=tukar;
          //matriks penempatan baru
          for (j=0;j<n;j++)
    	        {
               for (i=0;i<n;i++)
      	           {
                     x[j][i]=0;
                     b=awal[i];
         	         x[i][b]=1;
                    }
              }
          //hitung fungsi tujuan baru
          zbar=0;
          for(i=0;i<n;i++)
    	        {
               for (j=0;j<n;j++)
      	          {
                    for (k=0;k<n;k++)
         	            {
                         for (l=0;l<n;l++)
            	              {
                              zbar=zbar+(frek[i][k]*jarak[j][l]*x[i][j]*x[k][l]);
                             }
                        }
                   }
              }
          if(zbar<=z)
          	{
             bnr=bnr+1;
             z=zbar;
             for(i=0;i<n;i++)
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
                  for(i=0;i<n;i++)
                     {
                      solusi[i]=awal[i];
                     }
                 }
              if(r>p)
                 {
                  slh=slh+1;
                 }
              }
       cout<<"  Urutan penempatan sekarang : ";
       for(i=0;i<n;i++)
           {
            cout<<awal[i]+1<<" ";
           }
       cout<<endl;
       cout<<"  Nilai Penempatan Sekarang : "<<zbar<<endl;
       if(zbar>z)
          {
           cout<<"  Nilai peluang diterima : "<<p<<endl;
           cout<<"  Nilai random : "<<r<<endl;
          }
       cout<<"  Nilai Z terbaik : "<<z<<endl;
       cout<<"  Benar = "<<bnr<<endl;
       cout<<"  Salah = "<<slh<<endl<<endl;
      }while(slh<3 && bnr<3);
      T=alpha*T;
      cout<<"  Kriteria Looping dalam sudah terpenuhi."<<endl;
      cout<<"  Suhu turun menjadi : "<<T<<endl;
    }while(T>takhir);
    cout<<endl<<"  Karena suhu turun menjadi : "<<T<<" lebih kecil dari suhu akhir : "<<takhir<<endl;
    cout<<"  Iterasi Berhenti!"<<endl<<endl;
    cout<<"  Maka Solusi penyelesaiannya : "<<endl;
    for(i=0;i<n;i++)
       {
        cout<<"  Lokasi ke "<<i+1<<" di tempati fasilitas ke "<<solusi[i]+1<<endl;
       }
    cout<<endl<<"  Dengan Nilai Z : "<<z;
getch();
}