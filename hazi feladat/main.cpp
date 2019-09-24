#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream pr("prim.txt");
    ofstream pa("pallindrom.out");
    ofstream to("tokeletes.dat");
    int i,szam,z,a,o=0,k=0,l=0, prim,pallindrom,tokeletes,pall;
    while(in >> a)
    {
        for(i=1; i<=a/2; i++)
        {
            if(a%i==0)
            {
                k=k+1;
                l=l+i;
            }
        }
        pall=a;
        if(l==a)
        {
            to << a <<" ";
        }
        if(k==1)
        {
            pr << a << " ";
        }
        while(a>0)
        {
            z=a%10;
            o=o*10+z;
            a=a/10;
        }
        if(pall==o)
        {
            pa << pall << " ";
        }
        k=0;
        l=0;
        o=0;
    }
}
