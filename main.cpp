//A lo que lei este metodo es una mejora de insercion directa
#include <iostream>
#include <iomanip>

using namespace std;

//DECLARANDO METODOS, RECIBEN COMO PARAMETROS EL ARREGLO Y LA VARIABLE
void imprimir(int [], int n);
void shellSort(int [], int n);

int main()
{
    int n;
    cout<<"Tamaño del arreglo:"<<endl;
    cin>>n;
    cout<<"\nIngresa los numeros: "<<endl;

    int num[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Numero "<<(i+1)<<":"<<endl;
        cin>>num[i];
    }

    shellSort(num,n);
    imprimir(num, n);
}

//METODO SHELLSORT, RECIBE EL ARREGLO a[] Y LA VARIABLE n QUE ALMACENA LOS NUMEROS DEL ARRAY
void shellSort(int a[], int n)
{
    //DECLARACION DE VARIABLES
    //ints GUARDA LAS PARTICIONES, aux EL ELEMENTO MAS PEQUEÑO
    int ints, i, aux;
    bool band;

    ints=n;//INICIALIZADO ints CON LO QUE TENGA n

    //METODO SHELLSORT
    while(ints>1)
    {
        ints=(ints/2);
        band=true;

        while(band==true)
        {
            band=false;
            i=0;

            while((i+ints)<=n)
            {
                if(a[i]>a[i+ints])
                {
                    aux=a[i];
                    a[i]=a[i+ints];
                    a[i+ints]=aux;
                    band=true;
                }
                i++;
            }
        }
    }
}

//METODO PARA IMPRIMIR LOS NUMEROS DEL ARRAY ORDENADOS
void imprimir(int a[], int n)
{
    cout<<"\nNumeros ordenados:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<setw(5);
    }
}
