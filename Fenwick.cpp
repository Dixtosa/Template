#include <iostream>
#include <vector>

#define forn(N)         for(long long i = 0; i<N; i++)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Fenwick_SUM
{
	vector<int> T;
	int N;
public:
	Fenwick_SUM(int N)
	{
		this->N=N;
		T.resize(N);
	}
	Fenwick_SUM(vector<int> arg)
	{
		T.resize(arg.size());
		forn(arg.size())
		{
			inc(i, arg[i]);
		}
	}
	void inc (int ind, int delta)
	{
		for(int i = ind; i<N; i|=i+1)
		{
			T[i] += delta;
		}
	}
	int getsum(int l, int r)
	{
		return sum(r) - sum(l-1);
	}
	int sum(int i)
	{
		long long sum = 0;
		for(; i>=0; i&=(i+1), i--)
		{
			sum+=T[i];
		}
		return sum;
	}
};