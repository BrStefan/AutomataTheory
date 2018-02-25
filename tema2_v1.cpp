#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct tranzitie
{
    int stare1,stare2;
    char alf;
};
//Se citesc n si n stari
void citire_stari(vector <int> &stari_initiale,int &n)
{
    int x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        stari_initiale.push_back(x);
    }
}

//se citesc n si n carectere (Ex: 4\n abcd)
void citire_alfabet(vector <char> &alfabet,int &n)
{
    char x;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&x);
        alfabet.push_back(x);
    }
}

//Se cinteste starea initiala
void citire_stare_initiala(int &n)
{
    scanf("%d",&n);
}

//Se citeste n si n functii (Ex:1\n 1b2)
void citire_functii(vector <tranzitie> &functii,int &n)
{
    tranzitie x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%c%d",&x.stare1,&x.alf,&x.stare2);
        functii.push_back(x);
    }
}

//Se citesc n si n stari finale
void citire_stari_finale(vector <int> &v, int &n)
{
    int x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
}

//Se verifica daca datele sunt valide
bool verificari_stari(vector <int> v1,int n1, vector <int> v2,int n2, vector <tranzitie> v3,int n3,vector <char> v4, int n4)
{
    bool e=0;
    for(int i=0;i<n2;i++)
    {
        e=0;
        for(int j=0;j<n1;j++)
            if(v1[j]==v2[i])
            {
                e=1;
                break;
            }
        if(e==0)
        {
            printf("Una din starile finale este invalida!");
            return false;
        }
    }
    for(int i=0;i<n3;i++)
    {
        e=0;
        for(int j=0;j<n1;j++)
            if(v1[j]==v3[i].stare1)
            {
                e=1;
                break;
            }
        if(e==0)
        {
            printf("Una din starile initiale ale functiei nu este valabila!");
            return false;
        }
    }
    for(int i=0;i<n3;i++)
    {
        e=0;
        for(int j=0;j<n1;j++)
            if(v1[j]==v3[i].stare2)
            {
                e=1;
                break;
            }
        if(e==0)
        {
            printf("Una din starile finale ale functiei nu este valabila!");
            return false;
        }
    }
    for(int i=0;i<n3;i++)
    {
        e=0;
        for(int j=0;j<n4;j++)
            if(v4[j]==v3[i].alf)
            {
                e=1;
                break;
            }
        if(e==0)
        {
            printf("Una din alfabetul functiei nu este valabila!");
            return false;
        }
    }
    return true;
}

//functie ce returneaza starea dupa parcurgerea cuvantului
int verifica_cuvant(vector <tranzitie> v,int n,int stare_initiala)
{
        char cuvant[100];
        int i,j,nr_litere,stare_curenta;
        bool e=0;
        scanf("%s",&cuvant);
        nr_litere=strlen(cuvant);
        stare_curenta=stare_initiala;
        for(i=0;i<nr_litere;i++)
        {
            e=0;
            for(int j=0;j<n && e==0;j++)
                if(v[j].alf==cuvant[i] && stare_curenta==v[j].stare1)
                {
                    e=1;
                    stare_curenta=v[j].stare2;
                }
            if(e==0)
            {
                printf("Cuvantul nu este acceptat");
                return -1;
            }
        }
        return stare_curenta;
}

//Functie ce verifica daca starea cuvantului e stare finala
bool verifica_stare_finala(int stare,vector <int> v,int n)
{
    for(int i=0;i<n;i++)if(v[i]==stare)
    {
        printf("Cuvant acceptat");
        return true;
    }
    printf("Cuvant neacceptat");
}
int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    int nr_stari_initiale,nr_alfabet,stare_initiala,nr_functii,nr_stari_finale,nr_litere,stare_cuvant;
    vector <int> stari,stari_finale;
    vector <char> alfabet;
    vector <tranzitie> functii;

    citire_stari(stari,nr_stari_initiale);
    citire_alfabet(alfabet,nr_alfabet);
    citire_stare_initiala(stare_initiala);
    citire_functii(functii,nr_functii);
    citire_stari_finale(stari_finale,nr_stari_finale);
    if(verificari_stari(
                        stari,nr_stari_initiale,
                        stari_finale,nr_stari_finale,
                        functii,nr_functii,
                        alfabet,nr_alfabet)==true)
    {
        stare_cuvant=verifica_cuvant(functii,nr_functii,stare_initiala);
        if(stare_cuvant!=-1)
        {
            verifica_stare_finala(stare_cuvant,stari_finale,nr_stari_finale);
        }
    }
    return 0;
}
