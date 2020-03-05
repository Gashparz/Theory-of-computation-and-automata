#include <iostream>
#include <string.h>
#include <fstream>
#include <map>

using namespace std;



int main()
{
    ifstream f("input.txt");
    ofstream g("output.txt");
    int numarStari;
    map<int, int> stari;
    f>>numarStari;
    cout<<"Numar stari: "<<numarStari<<endl;
    for(int i=0;i<numarStari;i++)
    {
        int x;
        f>>x;
        stari.insert(make_pair(x,i));
        cout<<"Starea "<<i<<": "<<x<<endl;
    }
    cout<<endl;
    int numarLitere;
    char litere[100];
    f>>numarLitere;
    cout<<"Numar litere: "<<numarLitere<<endl;
    for(int i=0;i<numarLitere;i++)
    {
        f>>litere[i];
        cout<<"Litera "<<i<<": "<<litere[i]<<endl;
    }
    cout<<endl;

    int stareInit;
    f>>stareInit;
    cout<<"Stare initiala: "<<stareInit<<endl;
    cout<<endl;

    int numarFinale;
    int stariFin[100];
    f>>numarFinale;
    cout<<"Numar stari finale: "<<numarFinale<<endl;
    for(int i=0;i<numarFinale;i++)
    {
        f>>stariFin[i];
        cout<<"Starea finala "<<i<<": "<<stariFin[i]<<endl;
    }
    cout<<endl;

    int numarTranzitii;
    int delta[100][26];
    f>>numarTranzitii;
    cout<<"Numar tranzitii: "<<numarTranzitii<<endl;
    for(int i=0;i<numarTranzitii;i++)
    {
        int s1;
        char t;
        f>>s1;
        f>>t;
        f>>delta[stari[s1]][t-'a'];
        cout<<"Tranzitia: "<<i<<": "<<s1<<" "<<t<<" "<<delta[stari[s1]][t-'a']<<endl;
    }

    for(int i=0;i<numarStari;i++)
        for(int j=0;j<26;j++)
            if(delta[i][j] == 0)
                delta[i][j] = -1;
    cout<<endl;

    int numarCuvinte;
    char cuvinte[100][100];
    f>>numarCuvinte;
    cout<<"Numar cuvinte: "<<numarCuvinte<<endl;
    for(int i=0;i<numarCuvinte;i++)
    {
        f>>cuvinte[i];
        cout<<"Cuvantul "<<i<<": "<<cuvinte[i]<<endl;

    }
    cout<<endl;

    for(int i=0;i<numarCuvinte;i++)
    {
        int ok = 0;
        int q = stareInit;
        char cuv[100];
        strcpy(cuv,cuvinte[i]);
        for(int j=0;j<strlen(cuv);j++)
        {
            q = delta[stari[q]][cuv[j]-'a'];
            if(q == -1)
                break;
        }
        for(int j=0;j<numarFinale;j++)
            if(q == stariFin[j])
                ok = 1;
        if(ok == 1)
            g<<"DA\n";
        else
            g<<"NU\n";
    }

    g.close();
    f.close();
}
