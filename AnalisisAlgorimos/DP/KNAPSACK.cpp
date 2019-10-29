#include <iostream>
#include <vector>

using namespace std;

/*Probar este código inicialmente con:
    K = 50
    n = 3
    values = {60,100,120}
    weights = {10,20,30}               */

int main()
{
    int n,v,w,K;
    vector<int> values;
    vector<int> weights;
    
    //Capacidad del Knapsack
    cin >> K;
    //Cantidad de items
    cin >> n;
    for(int i=0;i<n;i++){
        //Se lee el valor
        cin >> v;
        values.push_back(v);
        //Se lee el peso
        cin >> w;
        weights.push_back(w);
    }
    
    //Estructura para el DP
    int M[n+1][K+1];
    //Primera columna en cero por caso trivial
    for(int i=0;i<n+1;i++)
        M[i][0] = 0;
    //Primera fila en cero como fila auxiliar
    for(int i=1;i<K+1;i++)
        M[0][i] = 0;
    //Se llena el resto de la matriz
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<K+1;j++)
        {
            //Se verifica que el item actual no sobrepasa el peso libre actual
            if(weights.at(i-1) > j)
                //Si se pasa, se toma en cuenta solo los items anteriores
                M[i][j] = M[i-1][j];
            else
                //Si no se pasa, se estima el máximo entre usar el item actual y no
                M[i][j] = max(values.at(i-1)+M[i-1][j-weights.at(i-1)],M[i-1][j]);
            cout<<M[i][j];
        }
    }
    
    //La respuesta queda en la esquina inferior derecha
    cout << M[n][K] << "\n";

    return 0;
}