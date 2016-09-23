#include<iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int A[10],n,i,j,aux;

	cout<<"Tamaño del array: "<<endl;
	cin>>n;

	cout<<endl<<"Introduce un numero: "<<endl;
	for(i=1;i<=n;i++)
    {
		cout<<"Numero "<<i<<": ";
		cin>>A[i];
	}

	for(i=2;i<=n;i++)
	{
		aux=A[i];
		j=i-1;

        while((j>=1) && (aux<A[j]))
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=aux;
	}
	/*
	for(i=2;i<=n;i++)
    {
		aux=a[i];
		k=i-1;
		while((k>=1)&&(aux<a[k]))
		{
			a[k+1]=a[k];
			k=k-1;
		}
		a[k+1]=aux;
	}
	*/
	cout<<endl;
	cout<<"elementos ordenados: "<<endl;

	for(i=1;i<=n;i++)
	{
		cout<<"  "<<A[i];
	}
	return 0;
}
