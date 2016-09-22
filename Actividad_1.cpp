#include <iostream>

using namespace std;

int main()
{
    int f=4,c=4,mayor=0;
    int matriz[f][c];
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
             cout<<"introduce datos:";
             cin>>matriz[i][j];
        }
    }
    cout<<"\nlos datos introducidos son:"<<endl;
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            for(int x=0; x<f;x++)
            {
                for(int y=0; y<c; y++)
                {
                    if(matriz[i][j]>matriz[x][y])
                    {
                        mayor=matriz[i][j];
                        matriz[i][j]=matriz[x][y];
                        matriz[x][y]=mayor;
                    }
                }
            }
        }
    }

    cout<<"\ndatos ordenados:"<<endl;
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
