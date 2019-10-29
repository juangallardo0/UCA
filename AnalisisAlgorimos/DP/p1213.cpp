#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int primeSum(int n, int k)
{
	std::vector<int> primes;
	int i, K[k+1][n+1];
	for (i = 2; i < 1120; ++i)
	{
		if (isPrime(i))
			primes.push_back(i);
	}
	for (i = 0; i < k+1; i++)
	{
		K[i][0] = 0;
		K[i][1] = 1;
	}
	for (i = 0; i < n+1; i++)
		K[0][i] = 0;
	for (i = 1; i < k+1; ++i)
	{
		for (int j = 2; j < n+1; j++)
		{
			if (j < primes.at(i-1))
				K[i][j] = 0;
			else 
				K[i][j] = 1 + K[i-1][j-primes.at(i-1)];
		}
	}
	return K[k][n];
}

int main(int argc, char const *argv[])
{
	int n, k;
	do
	{
		cin>>n>>k;
		cout<<primeSum(n, k)<<endl;
	} 
	while (n > 0);
	return 0;
}