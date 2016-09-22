#include <iostream>

using namespace std;

void seleccion(int [],int);
void imprimir(int[],int);//Recorre elementos del arreglo y los imprime :v

int main()
{
    int n;//almacena lo que se ingresa
    cout<<"Numero de elementos a ingresar: "<<endl;
    cin>>n;
    int a[n];//arreglo
    for(int i=0;i<n;i++)//for para pedir los numeros
    {
        cout<<"Ingresa el valor "<<(i+1)<<" del array"<<endl;
        cin>>a[i];//almacenar en el arreglo a en cada una de sus posiciones, segun el tamaño que se indique
    }
    seleccion(a, n);
    imprimir(a, n);
}

void seleccion(int a[], int n)
{
    int k, menor, i, j;//menor almancena el numero menor para hacer intercambio

    for(i=0;i<n;i++)
    {
        menor=a[i];//se asigna lo que tenga el arreglo en posicion i
        k=i;//k se inicializa en el valor que tiene i

        for(j=i+1;j<n;j++)//para comparar si es el numero menor
        {
            if(a[j]<menor)//si se cumple que los elementos de a pos.J son menores a menor, se guarda
            {
                menor=a[j];//menor, valor mas pequeño
                k=j;//se guarda la posicion para hacer intercambio
            }
        }
        //se hace intercambio y se manda al for
        a[k]=a[i];
        a[i]=menor;
    }
}

void imprimir(int a[], int n)
{
    cout<<"Nnumeros ordenados: "<<endl;

    for(int i=0; i<n; i++)
        cout<<"[ "<<a[i]<<" ]";
}
