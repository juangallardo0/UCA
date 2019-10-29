#include<iostream>
#include<vector>

using namespace std;

void treasureHunt(int t, int w, std::vector<int> depth, std::vector<int> worth)
{
	std::vector<int> T;
	int n = depth.size(), i, K[n+1][t+1], countT;
	for (i = 0; i < n; ++i)
		T.push_back(depth.at(i) * w + 2 * w * depth.at(i));
	for (i = 0; i < n+1; ++i)
		K[i][0] = 0;
	for (i = 0; i < t+1; i++)
		K[0][i]  = 0;
	for (i = 1; i < n+1; i++)
	{
		for (int j = 1; j < t+1; ++j)
		{
			if (j < T.at(i-1))
				K[i][j] = K[i-1][j];
			else
				K[i][j] = max(K[i-1][j], worth.at(i-1) + K[i][t-T.at(i-1)]);
		}
	}	
	cout<<K[n][t]<<endl;
}

int main(int argc, char const *argv[])
{
	int t = 210, w = 4;
	std::vector<int> depth = {7, 10, 10};
	std::vector<int> worth = {2, 1, 5};
	treasureHunt(t, w, depth, worth);
	return 0;
}