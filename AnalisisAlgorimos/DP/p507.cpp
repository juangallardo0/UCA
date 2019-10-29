#include<iostream>
#include<vector>

using namespace std;

void largestContiguousSum(std::vector<int> roads)
{
	int max_here = 0, max_so_far = 0, n = roads.size(), a, b;
	for (int i = 0; i < n; ++i)
	{
		max_here += roads.at(i);
		if (max_here < 0)
		{
			max_here = 0;
			a = i+2;
		}
		if (max_so_far <= max_here)
		{
			max_so_far = max_here;
			b = i+1+1;
		}
	}
	cout<<max_so_far<<endl<<a<<endl<<b<<endl;
}

int main(int argc, char const *argv[])
{
	std::vector<int> roads = {-2,-3,-4};
	largestContiguousSum(roads);
	return 0;
}