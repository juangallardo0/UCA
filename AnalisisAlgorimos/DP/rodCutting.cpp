#include<iostream>

using namespace std;

int rodCutting(int precio[], int n)
{
	int r[n + 1];
	r[0] = 1;
	int maxR, k;
	for (int i = 1; i < n; ++i)
	{
		maxR = precio[i];
		k = i - 1 ;
		for (int j = 0; j < i; j++)
		{
			maxR = max(maxR, r[j] + r[k]);
			k--;
		}
		r[i] = maxR;
	}
	return r[n - 1];
}

int main(int argc, char const *argv[])
{
	int precio[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n = 8;
	cout<<rodCutting(precio, n)<<endl;
	return 0;
}