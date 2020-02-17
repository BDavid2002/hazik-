#include <iostream>
#include <fstream>

using namespace std;

int szamokossz(int number);
int A2SZAMLNKOJA(int a, int b);
int szamoklnkoja(int igen[], int n);


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n; in >> n;
    int vektor[n];
    int p = 1;
    for(int i = 0; i < n; i++)in >> vektor[i];

    out << szamoklnkoja(vektor, n) << endl;
    out << szamokossz(szamoklnkoja(vektor,n));


    return 0;
}
int A2SZAMLNKOJA(int a, int b){
    int p = a * b;
    while(a != b){
        if(a > b)a -= b;
        else     b -= a;
    }
    return p / a;
}


int szamoklnkoja(int igen[], int n){
   int answ = A2SZAMLNKOJA(igen[0], igen[1]);
   for(int i = 2; i < n; i++){
    answ = A2SZAMLNKOJA(answ, igen[i]);
   }
   return answ;
}

int szamokossz(int number){
    int osszeg = 0;
    while(number > 0){
        osszeg += number%10;
        number /= 10;
    }
    return osszeg;
}

