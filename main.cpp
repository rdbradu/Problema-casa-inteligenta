#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
using namespace std;
int cnp_valid(char c[14], char cnp[648][14])
{
    for(int i=0;i<648;i++)
        if(strcmp(c,cnp[i])==0)
            return 1;
    return 0;
}
int cnp_existent(char c[14], char cnpfol[648][14], int nr)
{
    for(int i=0;i<nr;i++)
        if(strcmp(c,cnpfol[i])==0)
           return 1;
    return 0;
}
int minor(char c[14])
{
    int a=c[0]-'0';
    int b=c[1]-'0';
    b=(b*10)+(c[2]-'0');
    int d=c[3]-'0';
    d=(d*10)+(c[4]-'0');

    if(a==1 || a==2)
        return 1;
    else if(b==0 && d<=5)
            return 1;

    return 0;
}
int apare_nume(char s[100], char nume[300][40], int j)
{
    for(int i=0;i<j;i++)
        if(strcmp(nume[i],s)==0)
            return 1;
    return 0;
}
void voteaza(char s[100],char nume[300][40],int j,int nr_aparitii[300])
{
    for(int i=0;i<j;i++)
        if(strcmp(nume[i],s)==0)
            nr_aparitii[i]++;
}
void ordonare(char nume[300][40],int k,int nr_aparitii[300])
{
    for(int i=0;i<k-1;i++)
        for(int j=i+1;j<k;j++)
            if(nr_aparitii[i]<nr_aparitii[j])
            {
                swap(nr_aparitii[i],nr_aparitii[j]);
                swap(nume[i],nume[j]);
            }

}
void afisare(char nume[300][40],int k,int nr_aparitii[300],int nr_voturi)
{
    for(int i=0;i<k;i++)
    {
        cout<<nume[i]<<": "<<nr_aparitii[i]<<" voturi (";
        float pr;
        pr=((float)nr_aparitii[i]/nr_voturi)*100;
        printf("%.2f",pr);
        cout<<"%)"<<endl;
    }

}
int main()
{
   ifstream f("evidenta.csv");
   int incercare_de_frauda=0,nr_voturi=0;
   char cnp[648][14];
   char cnpfol[648][14];
   char s[100],semn,nume[300][40];
   int i,nr=0,j=0,nr_aparitii[300]={0};
   for(i=0;i<648;i++)
   {
        f.getline(s, 300, ',');
        f.getline(s, 300, ',');
        f.getline(s, 300, ',');
        strcpy(cnp[i], s);
        f.getline(s, 300);
   }
  
   while(true)
   {
       cin>>semn;
       if(semn=='+')
       {
            char c[14];
            cin>>c;
            scanf("%[^\n]",s);
            if(cnp_valid(c,cnp)==1)
            {
                if(cnp_existent(c,cnpfol,nr)==0)
                {
                    if(minor(c)==1)
                    {
                        strcpy(cnpfol[nr++],c);
                        if(apare_nume(s,nume,j)==1)
                        {
                            voteaza(s,nume,j,nr_aparitii);
                            nr_voturi++;
                        }
                        else
                        {
                            strcpy(nume[j++],s);
                            voteaza(s,nume,j,nr_aparitii);
                            nr_voturi++;
                        }
                    }
                    else
                    {
                        cout<<"Persoana minora"<<endl;
                    }
                }
                else
                {
                    cout<<"Vot deja inregistrat"<<endl;
                    incercare_de_frauda++;
                }
            }
            else
            {
                cout<<"CNP invalid"<<endl;
                incercare_de_frauda++;
            }


       }
       if(semn=='?')
       {
           cout<<"Statistici"<<endl<<"=========="<<endl;
           ordonare(nume,j,nr_aparitii);
           afisare(nume,j,nr_aparitii,nr_voturi);
           cout<<"Incercari de frauda: "<<incercare_de_frauda<<endl;
       }
       if(semn=='*')
       {
           cout<<"Statistici"<<endl<<"=========="<<endl;
           ordonare(nume,j,nr_aparitii);
           afisare(nume,j,nr_aparitii,nr_voturi);
           cout<<"Incercari de frauda: "<<incercare_de_frauda<<endl;
           return 0;
       }
   }

}
