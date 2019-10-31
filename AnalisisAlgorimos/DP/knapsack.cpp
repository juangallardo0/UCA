#include<iostream>

using namespace std;

int knapsack(int val[], int wt[], int w, int n)
{
	int k[n+1][w+1], res;
	for (int i = 0; i < n + 1; ++i)
		k[i][0] = 0;	
	for (int i = 0; i < w + 1; i++)
		k[0][i] = 0; 
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < w + 1; ++j)
		{
			if (wt[i-1] > j)
				k[i][j] = k[i-1][j];
			else
				k[i][j] = max(k[i-1][j], val[i-1] + k[i][w-wt[i-1]]);
		}
	}
	res = k[n][w]; int j = w, i;
	for (i = n; i > 0 and res > 0; i--)
	{
		if (res == k[i-1][j])
			continue;
		else {
			cout<<wt[i-1]<<endl;
			res -= val[i-1];
			j -= wt[i-1];
		}
	}
	return k[n][w];
}

int main(int argc, char const *argv[])
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int w = 50;
	cout<<knapsack(val, wt, w, 3)<<endl;
	return 0;
}