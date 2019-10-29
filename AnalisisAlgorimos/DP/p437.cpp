#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct dims
{
	int x, y, z;

	dims(int a, int b, int c)
	{
		x = a; y = b; z = c;
	}

	bool operator < (const dims& area) const
    {
        return (x * y > area.x * area.y);
    }
}dims;

int boxStack(std::vector<dims> bricks)
{
	std::vector<int> ht;
	int n = bricks.size();
	ht.push_back(bricks.at(0).z);
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if ((bricks.at(i).x < bricks.at(j).x and bricks.at(i).y < bricks.at(j).y) 
				or (bricks.at(i).x < bricks.at(j).y and bricks.at(i).y < bricks.at(j).x))
			{
				ht.push_back(bricks.at(i).z + ht.at(i-1));
			}
			else 
			{
				ht.push_back(ht.at(i-1));
			}
		}
	}
	return ht.at(n);
}

int main(int argc, char const *argv[])
{
	int n, a, b, c;
	cin>>n;
	std::vector<dims> bricks;
	bricks.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b>>c;
		bricks.push_back(dims(a, b, c));
		if (b != c)
		{
			bricks.push_back(dims(a, c, b));
		}
		if (a != c and a != b)
		{
			bricks.push_back(dims(b, c, a));
		}
	}
	sort(bricks.begin(), bricks.end());
	cout<<boxStack(bricks)<<endl;
	return 0;
}