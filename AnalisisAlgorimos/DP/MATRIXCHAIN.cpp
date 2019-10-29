#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,d;
    vector<int> dims;
    
    //Se lee la cantidad de matrices
    cin >> n;
    //Se leen las dimensiones
    //Hay n+1 dimensiones, de forma que la matrix n, tiene dimensiones (n)x(n+1)
    for(int i=0;i<n+1;i++){
        cin >> d;
        dims.push_back(d);
    }
    
    //Se prepara la estructura para DP
    int M[n][n];
    //Se llena la diagonal con ceros por caso trivial
    for(int i=0;i<n;i++)
        M[i][i] = 0;
    
    //Se llena el resto de la matriz
    //El primer for es para controlar la diferencia entre i e j,
    //esto se debe a la necesidad del recorrido diagonal
    for(int k=1;k<n;k++)
        //En cada diagonal se llega hasta una fila menos
        for(int i=0;i<n-k;i++){
            //Se calcula j en base a i y la diferencia actual
            int j = i + k;
            //Cada celda es el mínimo entre multiplicar sin agrupar la matriz
            //de la columna actual y agrupandola.
            //Se calcula la multiplicacion adicional acorde a la formula
            // p x q x r
            M[i][j] = min(dims.at(i)*dims.at(j)*dims.at(j+1) + M[i][j-1],
                          dims.at(i)*dims.at(i+1)*dims.at(j+1) + M[i+1][j]);
        }
    
    //La respuesta queda en la esquina superior derecha
    cout << M[0][n-1] << "\n";

    return 0;
}