#include<iostream>

using namespace std;

int maxSqareSubMatrix(int m, int n, int F[6][7])
{
	int M[m][n], i, j, max = 0, i1, j1;
	for (i = 0; i < m; ++i)
		M[i][0] = F[i][0];
	for (i = 0; i < n; i++)
		M[0][i] = F[0][i];
	for (i = 1; i < m; ++i)
	{
		for (j = 1; j < n; ++j)
		{
			if (F[i][j] == 1)
				M[i][j] = 0;
			else
			{
				M[i][j] = min(M[i-1][j], min(M[i][j-1], M[i-1][j-1])) + 1;
				if (M[i][j] > max)
				{
					max = M[i][j];
					i1 = i; j1 = j;
				}
			}
		}
	}
	return M[i1][j1];
}

int main(void)
{
	int m = 6, n = 7;
	int F[6][7] = 
	{{0,1,1,0,1,1,0},
	 {0,0,0,0,0,1,0},
	 {1,0,0,0,0,0,1},
	 {0,1,0,0,0,0,1},
	 {1,1,0,0,0,0,0},
	 {1,1,0,1,1,0,0}};
	cout<<maxSqareSubMatrix(m, n, F)<<endl;
	return 0;
}