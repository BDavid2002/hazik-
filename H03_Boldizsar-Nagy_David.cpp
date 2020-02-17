#include <iostream>

using namespace std;

int atablamerete;

int szamlalo = 0;

int xmove[] = {1, 2, 2, 1, -1, -2, -2, -1};
int ymove[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool lehet(int i, int j,  short egynegyzetestabla[20][20])
{
    if (egynegyzetestabla[i][j] > 0) {
        return false;
    }

    if (i<0 || i >= atablamerete || j < 0 || j>= atablamerete) {
        return false;
    }

    return true;
}
void uresit( short egynegyzetestabla[20][20])
{
    for(int i = 0; i < atablamerete; i++)
    {
        for(int j = 0; j < atablamerete; j++)
        {
            egynegyzetestabla[i][j] = 0;
        }
    }
}
void kiir( short egynegyzetestabla[20][20])
{
    int f = 1;
    while(f <= atablamerete*atablamerete){
        for(int i = 0; i < atablamerete; i++)
        for(int j = 0; j < atablamerete; j++)
            if(f == egynegyzetestabla[i][j])
                cout << "(" << i << "," << j << ") ";
        f++;
    }
}
bool backtracking(int row, int column, short egynegyzetestabla[20][20], int lepes )
{
    if(lepes == atablamerete*atablamerete)
    {
        szamlalo++;
        kiir(egynegyzetestabla);
        cout << endl;
        return true;
    }
    for(int i = 0; i < 8; i++)
    {
        if(lehet(row+xmove[i], column+ymove[i],  egynegyzetestabla))
        {
            short ideiglenesnegyzetestabla[20][20];
            for(int i = 0; i< atablamerete; i++){
                for(int j = 0; j < atablamerete; j++){
                    ideiglenesnegyzetestabla[i][j] = egynegyzetestabla[i][j];
                }
            }
            int ideigleneslepes = lepes + 1;
            ideiglenesnegyzetestabla[row+xmove[i]][column+ymove[i]] = ideigleneslepes;
            if(backtracking(row+xmove[i], column+ymove[i],  ideiglenesnegyzetestabla,ideigleneslepes) == true )return true;
        }

    }
}
int main()
{
    cout << "A sakktabla merete:";
    cin >> atablamerete;
    short egynegyzetestabla[20][20];
    uresit(egynegyzetestabla);
    for(int i=0; i<atablamerete; i++){
        for(int j=0; j<atablamerete; j++){
            uresit(egynegyzetestabla);
            egynegyzetestabla[i][j] = 1;
            if(backtracking(i,j, egynegyzetestabla, 1) == 1)return true;
            else cout << "No path found!" << endl;
        }
    }
    cout << szamlalo << endl;

    return 0;
}
