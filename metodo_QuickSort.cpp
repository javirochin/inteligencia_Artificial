#include <iostream>
#include <iomanip>//LIBRERIA PARA PODER USAR SETW

#define T 100//DEFINO UNA VARIABLE T DE TAMAÑO 100

using namespace std;

//DEFINIR FUNCIONES CON LOS PARAMETROS QUE SE ENVIAN
void ordenar(int [T], int);
void quickSort(int [T], int, int);

int main()
{
    //DEFINICIO DE VARIABLES Y ARREGLO, EL ARREGLO TOMA EL VALOR DE T(100)
    int n, A[T];
    cout <<"Tamaño del array: ";
    cin>>n;//TOMA EL VALOR A INGRESAR
    cout<<"Ingresa un numero: "<<endl;

    //CICLO PARA INGRESAR NUMEROS AL ARRAY
    for(int i=0; i<n;i++)
    {
        cout<<"Numero "<<i<<" :";
        cin>>A[i];
    }
    cout<<"\nNumeros ingresados:"<<endl;
    //CICLO PARA MOSTRAR LOS NUMEROS DEL ARRAY A COMO SE INGRESARON
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<setw(5);//SETW GENERA UN ESPACIO ENTRE LOS NUM DEL ARRAY
    }
    //LLAMANDO LAS FUNCIONES
    //A nombre del array
    //0 primera posicion del array
    //n-1 ultima posicion
    quickSort(A, 0, n-1);
    ordenar(A, n);

    return 0;
}

//FUNCION PARA DESPLEGAR NUMEROS ORDENADS EN BASE AL METODO
//SE ENVIAN LOS PARAMETROS DEL ARREGLO
void ordenar(int A[T], int n)
{
    cout<<"\nNumeros ordenados:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<setw(5);
    }
    cout<<endl;
}

//FUNCION PARA ORDENAR LA LISTA DE NUMEROS
//DENTRO DE LOS PARAMETROS ESTA LA PRIMERA Y SEGUNDA POSICION DEL ARRAY
//PIV O PIVOTE ES EL VALOR CENTRAL DEL ARRAY
void quickSort(int A[T], int pri, int ult)
{
    int cen, i, j, piv;
    cen = (pri + ult)/2; //SE CAPTURA POS. CENTAL DEL ARRAY
    //PARA CAPTURAR EL VALOR MEDIO DEL ARRAY
    piv = A[cen];
    //SEPARAR LOS SEGMENTOS DEL ARRAY
    i = pri;
    j = ult;

    do
    {
        //SEPARANDO EN DOS PARTES EL ARRAY
        while(A[i] < piv)
        {
            i++;//PARA SEPARAR LOS MENORES DEL PIV
        }
        while(A[j] > piv)
        {
            j--;//PARA SEPARAR LOS MAYORES DEL PIV
        }
        //EMPIEZA EL INTERCAMBIO
        if(i<=j)
        {
            int tem;
            //AQUI INICIA EL INTERCAMBIO
            tem = A[i];
            A[i] = A[j];
            A[j] = tem;
            i++;
            j--;
        }
    }
    //EL RECORRIDO TERMINA SI SE CUMPLE ESTA FUNCION
    while(i<=j);
    {
        //SI EL PRIMERO DE LA POSICION ES MENOR QUE J
        if(pri<j)
        {
            //LA PIMERA POSICION ASUME EL VALOR DE pri Y LA ULTIMA DE j
            quickSort(A, pri, j);
        }
        //SI LA POSICION i ES MENOR QUE EL ULTIMO
        if(i<ult)
        {
            //LA PRIMER POSICION AHORA ES i Y LA ULTIMA POSICION ult
            quickSort(A, i, ult);
        }
    }
}
