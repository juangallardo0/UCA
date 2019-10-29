#include<iostream>
#include<vector>

using namespace std;

int minimumCoinChange(std::vector<int> coins, int n, int V)
{
	std::vector<int> c;
	int change;
	c.assign(12, INT8_MAX);	
	c[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < V+1; ++j)
		{
			if (coins[i] <= j)
			{
				change = 1 + c[j - coins[i]];
				if (change < c[j])
				{
					c[j] = change;
				}
			}
		}
	}
	return c[V];
}

int main(int argc, char const *argv[])
{
	std::vector<int> coins = {1, 5, 6 ,9};
	int n = 4;
	int V = 11;
	cout<<minimumCoinChange(coins, n, V)<<endl;
	return 0;
}