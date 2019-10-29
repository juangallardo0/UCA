#include<iostream>

using namespace std;

int fibo(int n)
{
	int fibo[n];
	fibo[0] = 0; 
	fibo[1] = 1;
	for (int i = 2; i < n + 1; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return fibo[n];
}

int main(int argc, char const *argv[])
{
	cout<<fibo(9)<<endl;
	return 0;
}