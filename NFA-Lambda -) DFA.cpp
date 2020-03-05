#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

int stari[30][2];
int finale[30];
int nr_stari=0;
int nr_fin=0;
void citire()
{
    cout<<"Cate stari doriti sa fie?\n";
    cin>>nr_stari;
    cout<<endl;
    cout<<"Dati starile:\n";
    for(int i=0; i<nr_stari; i++)
        for(int j=0; j<2; j++)
        {
            cout<<"("<<i<<","<<j<<")"<<"->_";
            cin>>stari[i][j];
        }
    cout<<endl;
    cout<<"Cate stari finale doriti?\n";
    cin>>nr_fin;
    cout<<endl;
    cout<<"Ce stari finale doriti?\n";
    for(int i=0; i<nr_fin; i++)
        cin>>finale[i];
}
bool apartine(int m[30], int x)
{
    bool gasit = false;
    for(int i = 0; i < nr_fin; i++)
        if(m[i] == x)
            gasit = true;
    return gasit;
}
int main()
{
    citire();
    bool gasit = false;
    int n = nr_stari;
    char a[30][30];
    int h[30];
    for (int i=0; i<n; i++)
        h[i]=0;
    h[0]=1;
    for (int i=0; i<n; i++)
    {
        if(stari[i][0]!=-1)
            h[stari[i][0]]=1;
        if(stari[i][1]!=-1)
            h[stari[i][1]]=1;
    }
    for(int i=0; i<n; i++)
        if(h[i]==0)
        {
            stari[i][0]=-1;
            stari[i][1]=-1;
        }
    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j]='-';
    for(int x=0; x<nr_fin; x++)
    {
        for(int i=0; i<finale[x]; i++)
        {
            if(apartine(finale,i)==false)
                a[finale[x]][i]='*';
        }
    }
    int a1,a2,b1,b2;
    gasit=true;
    while(gasit == true)
    {
        gasit = false;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(a[j][i]!='*')
                {
                    a1=stari[i][0];
                    a2=stari[j][0];
                    b1=stari[i][1];
                    b2=stari[j][1];
                    if(a[a2][a1]=='*')
                    {
                        a[j][i]='*';
                        gasit=true;
                    }
                    if(a[b2][b1]=='*')
                    {
                        a[j][i]='*';
                        gasit=true;
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            if(a[i][j]=='-')
                h[i]=0;
    }
    cout<<endl;
    cout<<"S-au eliminat starile:\n";
    for(int i=0; i<n; i++)
        if(h[i]==0)
            cout<<i<<endl;
    for (int i=0; i<n; i++)
        if (h[i]==1)
        {
            cout<<"("<<i<<",0)->";
            if(h[stari[i][0]]==0)
                cout<<stari[i][0]-1<<endl;
            else
                cout <<stari[i][0]<<endl;
            cout<<"("<<i<<",1)->";
            if(h[stari[i][1]]==0)
                cout<<stari[i][1]-1<<endl;
            else
                cout<<stari[i][1]<<endl;
        }
}
