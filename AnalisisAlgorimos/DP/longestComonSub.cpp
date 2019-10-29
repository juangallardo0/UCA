#include<iostream>
#include<vector>

using namespace std;

int longestComonSeq(string seq1, string seq2, int n)
{
	int L[n+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		L[i][0] = 0;
		L[0][i] = 0;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if (seq1[i-1] == seq2[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			cout<<L[i][j]<<endl;
		}
	}
	return L[n][n];
}

int main(int argc, char const *argv[])
{
	string seq1 = "abcdgh";
	string seq2 = "aedfhr";
	int n = 6;
	cout<<longestComonSeq(seq1, seq2, n)<<endl;
	return 0;
}