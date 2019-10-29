#include<iostream>
#include<vector>

using namespace std;

bool sumSubset(std::vector<int> set, int sum)
{
	int n = set.size(), i;
	bool M[n+1][sum+1];
	for (i = 0; i < n+1; i++)
		M[i][0] = true;
	for (i = 1; i < sum+1; i++)
		M[0][i] = false;
	for (i = 1; i < n+1; i++)
	{
		for (int j = 1; j < sum+1; j++)
		{
			if (set.at(i-1) > j)
				M[i][j] = M[i-1][j];
			else 
				M[i][j] = M[i-1][j] or M[i-1][j-set.at(i-1)];
		}
	}
	return M[n][sum];
}

int main(int argc, char const *argv[])
{
	std::vector<int> set = {3,34,4,12,5,2};
	int sum = 1;
	cout<<sumSubset(set, sum)<<endl;
	return 0;
}