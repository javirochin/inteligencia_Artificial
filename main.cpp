#include<iostream>

using namespace std;

int a[50];
void merge(int,int,int);

void mergeSort(int izq,int der)
{
	int med;
	if(izq<der)
	{
		med=(izq+der)/2;
		mergeSort(izq,med);
		mergeSort(med+1,der);
		merge(izq,med,der);
	}
}

void merge(int izq,int med,int der)
{
	int h,i,j,b[50],k;
	h=izq;
	i=izq;
	j=med+1;

	while((h<=med)&&(j<=der))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>med)
	{
		for(k=j;k<=der;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=med;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=izq;k<=der;k++)
	{
		a[k]=b[k];
	}
}

int main()
{
	int num,i;
	cout<<"Tamaño del array:"<<endl;
	cin>>num;
	cout<<endl;
	cout<<"Ingresa un numero:"<<endl;

	for(i=1;i<=num;i++)
	{
		cin>>a[i] ;
	}

	mergeSort(1,num);
	cout<<endl;
	cout<<endl<<endl;
	cout<<"Numeros ordenados:"<<endl;

	for(i=1;i<=num;i++)
	{
		cout<<a[i]<<"	";
	}
	return 0;
}
