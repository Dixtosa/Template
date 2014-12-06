class LongBitmask
{
	int N, size;
	vector<int> A;
public:
	void init(int N)
	{
		this->N=N;
		size = (N+30)/30;
		A.assign(size, 0);
	}
	LongBitmask(){}
	LongBitmask(int N)
	{
		init(N);
	}
	LongBitmask(const LongBitmask &LBM)
	{
		init(LBM.N);
		forn(size) A[i] = LBM.A[i];
	}
	LongBitmask operator|(LongBitmask b)
	{
		LongBitmask ans(b.N);
		forn(size)
			ans.A[i] = b.A[i] | A[i];
		return ans;
	}
	void operator|=(LongBitmask b)
	{
		forn(size)
			A[i] |= b.A[i];
	}
	LongBitmask operator&(LongBitmask b)
	{
		LongBitmask ans(b.N);
		forn(size)
			ans.A[i] = b.A[i] & A[i];
		return ans;
	}
	void operator&=(LongBitmask b)
	{
		forn(size)
			A[i] &= b.A[i];
	}
	void set(int pos)
	{
		A[pos/30] |= 1<<(pos%30);
	}
	void unset(int pos)
	{
		A[pos/30] &= ~(1<<(pos%30));
	}
	bool get(int pos)
	{
		return (A[pos/30] & (1<<(pos%30))) > 0;
	}
};