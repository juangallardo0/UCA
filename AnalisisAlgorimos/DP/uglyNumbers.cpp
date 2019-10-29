#include<iostream>

using namespace std;

int uglyNumbers()
{
	int ugly[150];
	ugly[0] = 1;
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	int mult2 = 2, mult3 = 3, mult5 = 5, nextmult;
	for (int i = 1; i < 150; ++i)
	{
		nextmult = min(min(mult2, mult3), mult5);
		ugly[i] = nextmult;
		if (nextmult == mult2)
		{
			i2++;
			mult2 = ugly[i2] * 2;
		}
		if (nextmult == mult3)
		{
			i3++;
			mult3 = ugly[i3] * 3;
		}
		if (nextmult == mult5)
		{
			i5++;
			mult5 = ugly[i5] * 5;
		}
	}
	return nextmult;
}

int main()
{
	cout<<uglyNumbers()<<endl;
	return 0;
}