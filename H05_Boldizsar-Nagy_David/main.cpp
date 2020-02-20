#include<iostream>
using namespace std;
struct lista {
   int ertek;
   string gyumolcsneve;
   lista * kov;
};
int main() {
   lista * mutato = NULL;
   int maximum=-INT_MAX;
   int i;
   int n;
   string kiiratodolog;
   cout << "N=";
   cin >> n;
   for(i=0;i<n;i++) {
      lista * ujelem = new lista;
      cin >> ujelem->ertek;
      cin >> ujelem->gyumolcsneve;
      if(ujelem->ertek > maximum)
      {
          maximum=ujelem->ertek;
          kiiratodolog=ujelem->gyumolcsneve;
      }
      ujelem->kov  = mutato;
      mutato = ujelem;

   }
   while(mutato) {
      if(mutato->ertek==maximum)
      {
          cout << mutato->gyumolcsneve;
      }
      mutato = mutato->kov ;

   }
   return 0;
}
