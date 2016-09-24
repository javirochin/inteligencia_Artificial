#include <iostream>
#include <iomanip>//LIBRERIA PARA PODER USAR SETW

#define T 100//DEFINO UNA VARIABLE T DE TAMAÑO 100

using namespace std;

int main()
{
    //DEFINICIO DE VARIABLES Y ARREGLO, EL ARREGLO TOMA EL VALOR DE T(100)
    int A[T],j,piv,tem,i,k,n;
    cout<<"Tamaño del array:";
    cin>>n;//TOMA EL VALOR A INGRESAR
    cout<<"\nIngresa un numero: "<<endl;

    //CICLO PARA INGRESAR NUMEROS AL ARRAY
    for(i=1;i<=n;i++)
    {
        cout<<"Numero "<<i<<" :";
        cin>>A[i];
    }
    cout<<"\nNumeros ingresados:"<<endl;
    //CICLO PARA MOSTRAR LOS NUMEROS DEL ARRAY A COMO SE INGRESARON
    for(i=1;i<=n;i++)
    {
        cout<<A[i]<<setw(5);//SETW GENERA UN ESPACIO ENTRE LOS NUM DEL ARRAY
    }

    //METODO HEAPSORT
    for(k=n;k>0;k--)
    {
        for(i=1;i<=k;i++)
        {
            piv=A[i];
            j=i/2;
            while(j>0 && A[j]<piv)
            {
                A[i]=A[j];
                i=j;
                j=j/2;
            }
            A[i]=piv;
        }
        tem=A[1];
        A[1]=A[k];
        A[k]=tem;
    }
    cout<<"\nNumeros ordenados:"<<endl;
    for(i=1;i<=n;i++)
    {
    cout<<A[i] <<setw(5);
    }
    cout<<endl;
    return 0;
}
