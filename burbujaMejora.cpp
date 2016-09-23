#include <iostream>
#include <iomanip>//PARA PODER USAR setw

using namespace std;

int main()
{
    //DECLARACIONES DE VARIABLES.
    const int tAr = 6;//tAr, tamaño del array
    int A[6] = {5,19,4,0,21,2};
    //NO FUNCIONA SI SE PONE UNA CONSTANTE COMO TAMAÑO DEL ARRAY
    int i, j, temp, ord;
    //TERMINA DEFINICION

    cout << "Datos ingresados:" << endl;
    //FOR PARA IMPRIMIR DATOS DEL ARREGLO A[].
    for ( i = 0; i < tAr; i++ )
    {
        cout << setw(4) << A[i];
    }
    //TERMINA EL CICLO FOR

    //CICLOS PARA ORDENAR ARRAY
    for ( ord = 0; ord < tAr - 1; ord++ )
    {
        //CICLO ANIDADO
        //for ( i = 0, j = tAr -1; i < j; i++, j--)
        for ( i = 0, j = tAr -1; i < j; i++)
        {
            //PARTE PARA EL ALGORITMO BURBUJA MEJORA
            if ( A[i] > A[i+1])
            {
                temp = A[i];
                A[i] = A[i +1];
                A[i + 1] = temp;
            }
        }
    }
    //TERMINA ORDENAMIENTO DE ARRAY

    //PARA IMPRIMIR DATOS ORDENADOS
    cout << "\nDatos ordenados: " <<endl;
    for ( i = 0; i < tAr; i++ )
    {
        cout << setw(4) << A[i];
    }
    return 0;
}
