#include<iostream>
#include<cmath>
using namespace std;
int n,m,a,b;

struct pol
{
    int grad, coef;
    pol *urm;
};

pol *p , *u;

void afisare(pol *p)
{
    pol *aux=p;
    while(aux!=0)
    {
        cout<<aux->coef<<"x^"<<aux->grad<<" ";
        aux=aux->urm;
    }
    cout<<"\n";
}

void creare( pol *&p, pol *&u, int n, int m)
{
    pol *c;
    if(p==0)
    {
        p=new pol;
        p->coef=n;
        p->grad=m;
        p->urm=0;
        u=p;
    }
    else
    {
        pol *nou;
        nou= new pol;
        nou->coef=n;
        nou->grad=m;
        nou->urm=p;
        p=nou;
    }
}

int main()
{
    int x,y,n,k;
    cout<<"Cati termeni are polinomul? ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Coeficinetul termenului "<<i<<" este : ";
        cin>>x;
        cout<<"Gradul termenului "<<i<<" este : ";
        cin>>y;
        if(x!=0)
            creare(p,u,x,y);
    }
    cout<<"Care este valoarea de evaluat (x0) ?";
    cin>>k;




    afisare(p);
    cout<<"\n";
    pol *aux=p;
    //long long sum=0;
    long long sum=0;
    while(aux)
    {
        sum=sum +pow(k,aux->grad)*aux->coef;
        aux=aux->urm;
    }
    afisare(p);
    cout<<"\n";
    cout<<sum;
}
