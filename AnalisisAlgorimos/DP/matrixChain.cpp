#include<iostream>
#include<vector>

using namespace std;

int matrixChain(std::vector<int> dims, int n)
{
	int m[n][n];
	for (int i = 0; i < n; i++)
		m[i][i] = 0;
	int j, k, o1, o2;
	for (int i = 1; i < n; ++i)
	{
		j = 0;
		for (k = i; k < n; ++k)
		{
			o1 = m[j][k-1] + dims[j]*dims[k]*dims[k+1];
			cout<<o1<<endl;
			o2 = m[j+1][k] + dims[j]*dims[k+1]*dims[j+1];
			cout<<o2<<endl;
			m[j][k] = min(o1, o2);
			j++;
		}		
	}
	return m[0][n-1];
}

int main(int argc, char const *argv[])
{
	int n = 4;
	vector <int> dims = {40,20,30,10,30}; 
	cout<<matrixChain(dims, n)<<endl;
	return 0;
}