#include<iostream>
#include<vector>

using namespace std;

int lcs(std::vector<int> tests)
{
	int n = tests.size(), K[n+1][n+1], i, j;
	for (i = 0; i < n+1; i++)
	{
		K[i][0] = 0;
		K[0][i] = 0;
	}
	for (i = 1; i < n+1; ++i)
	{
		for (j = 1; j < n+1; j++)
		{
			if (tests.at(i-1) > tests.at(j-1))
				K[i][j] = 1 + K[i-1][j-1];
			else 
				K[i][j] = max(K[i-1][j], K[i][j-1]);
		}
	}
	return K[n][n];
}

int main(int argc, char const *argv[])
{
	std::vector<int> tests = {389, 207, 155, 300, 299, 170, 158, 65};
	cout<<lcs(tests)<<endl;
	return 0;
}