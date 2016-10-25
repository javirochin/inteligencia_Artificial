#include <iostream>

using namespace std;

int matriz[3][3]; //declarando matriz

int fila, columna, esquinas;

int vacio_f(int c);
int vacio_c(int f);

bool casi(int mat[3][3]);
bool ganar(int mat[3][3]);
bool completo(int mat[3][3]);

char checar(void); //declarando funciones
void i_matriz(void);
void obtener_movimientos(void);
void obtener_movimientos_pc(void);
void mostrar_matriz(void);

void reset();

int main(void)
{
    char hecho; char c;
    bool CONTINUAR = true;
    while (CONTINUAR)
    {
        hecho =  ' ';
        i_matriz();

        do
        {
            mostrar_matriz();
            obtener_movimientos();
            hecho = checar();//checar ganador
            if(hecho!= ' ') break;//si se encontro ganador
                obtener_movimientos_pc();
                hecho = checar();//checar si hay nuevo ganador
                if(hecho!= ' ') break;//si se encontro ganador
                    if (completo(matriz))//no hay ganador y se lleno la matriz
                    {
                        mostrar_matriz();
                        cout << endl;
                        break;
                        cout<<"Empate\n";
                        break;
                    }
                    reset();
            }
            while(hecho== ' ');

            if(hecho=='X')
                cout<<"Ganaste\n";
            else
                cout<<"Perdiste\n"<<endl;
            mostrar_matriz(); //mostrar posiciones finales
            cout << "otra vez? S/N" << endl; cin >> c;
            if ( c=='N' || c=='n')
                CONTINUAR = false;
            reset();
        }
        return 0;
}

void i_matriz(void) //iniciar matriz
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matriz[i][j] =  ' ';
}


void obtener_movimientos(void) //funcion de llamada para tirada de jugador
{
    int x, y;

    cout<<"Coordenadas para tirar: ";
    cin >> x >> y;

    x--; y--;

    if(matriz[x][y]!= ' '){
        cout<<"Tiraste mal.\n";
        obtener_movimientos();
       }
    else matriz[x][y] = 'X';
}

void obtener_movimientos_pc(void) //Entrada de movimientos de pc
{
    char temp;
    int prueba[3][3], temporal[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            prueba[i][j] = matriz[i][j]; temporal[i][j] = matriz[i][j];
        }
        int i, j;
        for (i = 0; i < 3; i++)
        {
        for (j = 0; j < 3; j++)
            if (matriz[i][j] == ' ')
            {
                temp = matriz[i][j];
                if (ganar(prueba))
                {
                    if (fila > 0)
                    {
                        if (matriz[fila-1][vacio_c(fila-1)] != 'X')
                        matriz[fila-1][vacio_c(fila-1)] = 'O';
                        return;
                    }
                    if (columna > 0)
                    {
                        if (matriz[vacio_f(columna-1)][columna-1] != 'X')
                        matriz[vacio_f(columna-1)][columna-1] = 'O';
                        return;
                    }
                    if (esquinas == 1)
                    {
                        if ( matriz[0][0] !='X' && matriz[1][1] != 'X' && matriz[2][2] != 'X')
                        {
                            matriz[0][0] = 'O'; matriz[1][1] = 'O'; matriz[2][2] = 'O';
                        }
                        return;
                    }
                    else
                    {
                        if (matriz[0][2] != 'X' && matriz[1][1] != 'X' && matriz[2][0] != 'X')
                        {
                            matriz[0][2] = 'O'; matriz[1][1] = 'O'; matriz[2][0] ='O';
                        }
                        return;
                    }
                    return;
                    //break;
                }
                prueba[i][j] = temp;
            }
            if (matriz[i][j]==' ')
            {
                temp = matriz[i][j];
                if (ganar(prueba))
                {
                    if (fila > 0)
                    {
                        if (matriz[fila-1][vacio_c(fila-1)] != 'X')
                        matriz[fila-1][vacio_c(fila-1)] = 'O';
                        return;
                    }
                    if (columna > 0)
                    {
                        if (matriz[vacio_f(columna-1)][columna-1] != 'X')
                            matriz[vacio_f(columna-1)][columna-1] = 'O';
                        return;
                    }
                    if (esquinas == 1)
                    {
                        if ( matriz[0][0] !='X' && matriz[1][1] != 'X' && matriz[2][2] != 'X')
                        {
                            matriz[0][0] = 'O'; matriz[1][1] = 'O'; matriz[2][2] = 'O';
                        }
                        return;
                    }
                    else
                    {
                        if (matriz[0][2] != 'X' && matriz[1][1] != 'X' && matriz[2][0] != 'X')
                        {
                            matriz[0][2] = 'O'; matriz[1][1] = 'O'; matriz[2][0] = 'O';
                        }
                        return;
                    }
                    return;
                }
                prueba[i][j] = temp;
            }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (matriz[i][j]==' ')
            {
                temp = matriz[i][j];
                prueba[i][j] = 'O';
                if (!casi(prueba))
                break;
                prueba[i][j] = temp;
            }
            if (matriz[i][j]==' ')
            {
                temp = matriz[i][j];
                prueba[i][j] = 'O';
                if (!casi(prueba))
                    break;
                prueba[i][j] = temp;
            }
    }
    if (columna > 0)
    {
        if (matriz[vacio_f(columna-1)][columna-1] !='X')
            matriz[vacio_f(columna-1)][columna-1] = 'O';
            return;
    }
    if (fila > 0)
    {
        if (matriz[fila-1][vacio_c(fila-1)] !='X')
            matriz[fila-1][vacio_c(fila-1)] = 'O';
            return;
    }
    if (esquinas == 1 )
    {
        if (matriz[0][0] != 'X')
            matriz[0][0] = 'O';
        if (matriz[1][1] != 'X')
            matriz[1][1] = 'O';
        if (matriz[2][2] != 'X')
            matriz[2][2] = 'O';
        return;
    }
    if (esquinas == 2 )
    {
        if (matriz[0][2] != 'X')
            matriz[0][2] = 'O';
        if (matriz[1][1] != 'X')
            matriz[1][1] = 'O';
        if (matriz[2][0] != 'X')
            matriz[2][0] = 'O';
        return;
    }
    if (matriz[i][j] != 'X')
        matriz[i][j] = 'O';
}

void mostrar_matriz(void)
{
    int t;

    for(t=0; t<3; t++)
    {
        cout << " " << char(matriz[t][0]) << "  |  " << char(matriz[t][1]) << " | " << char(matriz[t][2]);

        if(t!=2)
            cout << "\n----|----|----\n";
    }
    cout << endl;
}

char checar(void) //identificar ganador
{
    int i;

    for(i=0; i<3; i++)  //checar filas
        if(matriz[i][0]==matriz[i][1] &&
           matriz[i][0]==matriz[i][2]) return matriz[i][0];

    for(i=0; i<3; i++)  //checar columnas
        if(matriz[0][i]==matriz[1][i] &&
           matriz[0][i]==matriz[2][i]) return matriz[0][i];

  //cecar esquinass
    if(matriz[0][0]==matriz[1][1] &&
       matriz[1][1]==matriz[2][2]) return matriz[0][0];

    if(matriz[0][2]==matriz[1][1] &&
       matriz[1][1]==matriz[2][0]) return matriz[0][2];

    return ' ';
}

bool casi(int mat[3][3])
{
    char a,b,c,d,e,f,g,h,i;
    a = mat[0][0], b = mat[0][1], c = mat[0][2];
    d = mat[1][0], e = mat[1][1], f = mat[1][2];
    g = mat[2][0], h = mat[2][1], i = mat[2][2];
    if((a=='X' && b=='X' && c!='O')||(b=='X' && c=='X' && a!='O')||(a=='X' && c=='X' && b!='O'))
    {
        fila = 1; return true;
    }
    if((d=='X' && e=='X' && f!='O')||(e=='X' && f=='X' && d!='O')||(d=='X' && f=='X' && e!='O'))
    {
        fila = 2; return true;
    }
    if((g=='X' && h=='X' && i!='O')||(h=='X' && i=='X' && g!='O')||(g=='X' && i=='X' && h!='O'))
    {
        fila = 3; return true;
    }
    if((a=='X' && d=='X' && g!='O')||(d=='X' && g=='X' && a!='O')||(a=='X' && g=='X' && d!='O'))
    {
        columna = 1; return true;
    }
    if((b=='X' && e=='X' && h!='O')||(e=='X' && h=='X' && b!='O')||(b=='X' && h=='X' && e!='O'))
    {
        columna = 2; return true;
    }
    if((c=='X' && f=='X' && i!='O')||(f=='X' && i=='X' && c!='O')||(c=='X' && i=='X' && f!='O'))
    {
        columna = 3; return true;
    }
    if((a=='X' && e=='X' && i!='O')||(e=='X' && i=='X' && a!='O')||(a=='X' && i=='X' && e!='O'))
    {
        esquinas = 1; return true;
    }
    if((g=='X' && e=='X' && c!='O')||(e=='X' && c=='X' && g!='O')||(g=='X' && c=='X' && e!='O'))
    {
        esquinas = 2; return true;
    }
    return false;
}

bool ganar(int mat[3][3])
{
    char a,b,c,d,e,f,g,h,i;
    a = mat[0][0], b = mat[0][1], c = mat[0][2];
    d = mat[1][0], e = mat[1][1], f = mat[1][2];
    g = mat[2][0], h = mat[2][1], i = mat[2][2];
    if((a=='O' && b=='O' && c!='X')||(b=='O' && c=='O' && a!='X')||(a=='O' && c=='O' && b!='X'))
    {
        fila = 1;
        return true;
    }
    if((d=='O' && e=='O' && f!='X')||(e=='O' && f=='O' && d!='X')||(d=='O' && f=='O' && e!='X'))
    {
        fila = 2;
        return true;
    }
    if((g=='O' && h=='O' && i!='X')||(h=='O' && i=='O' && g!='X')||(g=='O' && i=='O' && h!='X'))
    {
        fila = 3;
        return true;
    }
    if((a=='O' && d=='O' && g!='X')||(d=='O' && g=='O' && a!='X')||(a=='O' && g=='O' && d!='X'))
    {
        columna = 1;
        return true;
    }
    if((b=='O' && e=='O' && h!='X')||(e=='O' && h=='O' && b!='X')||(b=='O' && h=='O' && e!='X'))
    {
        columna = 2;
        return true;
    }
    if((c=='O' && f=='O' && i!='X')||(f=='O' && i=='O' && c!='X')||(c=='O' && i=='O' && f!='X'))
    {
        columna = 3;
        return true;
    }
    if((a=='O' && e=='O' && i!='X')||(e=='O' && i=='O' && a!='X')||(a=='O' && i=='O' && e!='X'))
    {
        esquinas = 1;
        return true;
    }
    if((g=='O' && e=='O' && c!='X')||(e=='O' && c=='O' && g!='X')||(g=='O' && c=='O' && e!='X'))
    {
        esquinas = 2;
        return true;
    }
    return false;
}

bool completo(int mat[3][3])
{
    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            if (mat[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int vacio_c(int r)
{
    for (int i = 0; i<3; ++i)
    {
        if (matriz[r][i] == ' ')
            return i;
    }
}

int vacio_f(int c)
{
    for (int i=0; i<3; ++i)
    {
        if (matriz[i][c] == ' ')
            return i;
    }
}

void reset()
{
    fila = 0;
    columna = 0;
    esquinas = 0;
}
