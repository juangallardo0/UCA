#include<iostream>

using namespace std;

typedef struct job
{
	int start;
	int finish;
}jobs;

int main(int argc, char const *argv[])
{
	int L[11];
	for (int i = 0; i < 11; ++i)
		L[i] = 0;

	job jobs[11] = {
		{0,6},{1,4},{2,13},{3,5},{3,8},{5,7},{5,9},{6,10},{8,11},{8,12},{12,14}
	};

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (jobs[j].finish < jobs[i].start and L[i] < L[j])
				L[i] = L[j];
		}
		L[i]++;
	}
	
	cout<<L[10]<<endl;
	return 0;
}