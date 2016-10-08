#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int aristas,a,b;
    vector<int>nodos[1000];
    cout<<"Introduce el numero de aristas."<<endl;
    cout<<"Posteriormente las conexiones de cada una de ellas con su siguiente."<<endl;
	cin>>aristas;
	for(int i=0;i<aristas;i++)
    {
		cin>>a>>b;
		nodos[a].push_back(b);
		nodos[b].push_back(a);
	}
	cout<<endl;
	//Lista de adyacencia
    for(int i=0;i<1000;i++)
    {
        if(!nodos[i].empty())
        {
            cout<<"[ "<<i<<" ]"<<"-->";
            for(vector<int>::iterator it=nodos[i].begin();
            it!=nodos[i].end();++it)
            {
                cout<<*it<<"-->";
            }
            cout<<"NULL"<<endl;
        }
    }

queue<int> que;
//inicialmente que esta vacio
bool visitado[1000];
//marca todos los vertices como no visitados
for(int i=0;i<1000;i++)
visitado[i]=false;

int inicio;
cout<<"\nIntroduce el nodo inicial:"<<endl;
cin>>inicio;

//inserta el nodo de inicio en la cola
que.push(inicio);
//marca el nodo inicial como visitado
visitado[inicio]=true;

cout<<"\nRecorrido:\n";

while(!que.empty())
{
    //quita de la cola un vertice para imprimirlo
    int frente = que.front();
    cout<<frente<<" ";
    que.pop();
    //obtiene todos los vértices adyacentes del vértice quitado de la cola s
    //si un vértice adyacente no ha sido visitado,
    //entonces se marca como visitado
    //y lo pongo en la cola
	for(vector<int>::iterator it=nodos[frente].begin();
		it!=nodos[frente].end();++it)
		{
			if(visitado[*it]==false)
			{
				visitado[*it]=true;
				que.push(*it);
			}
		}
}
	cout<<endl;
	return 0;
}
