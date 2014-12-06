bool eq(double a, double b, double eps = 0.000000001)
{
	return abs(a-b) < eps;
}
	
//GRID
int way[8][2] =
{
	{-1, 1}, {0, 1},   {1, 1},
	{-1, 0},           {1, 0},
	{-1, -1}, {0, -1}, {1, -1}
};

int way[4][2] = 
{
			{0, 1},
	{-1, 0},		{1, 0},
			{0, -1}        
};

bool inGrid(int i, int j, int N, int M)
{
	return ((0<=i && i<N) && (0<=j && j<M));
}
//////////////////////////////////////////////////////////////


//MATRIX class
struct MATRIX
{
	int dim;
	long long MAT[100][100];
	
	
	MATRIX (int N, int x = -1)
	{
		dim = N;
		for (int i = 0; i<dim; i++)
			for (int j = 0; j<dim; j++)
			{
				if (x!=-1 && i==j)
					MAT[i][j] = x;
				else
					MAT[i][j] = 0;
			}
	}
	
	
	void operator+=(const MATRIX& a)
	{
		for (int i = 0; i<a.dim; i++)
		{
			for (int j = 0; j<a.dim; j++)
			{
				MAT[i][j] += a.MAT[i][j];
			}
		}
	}

	void show()
	{
		for (int i = 0; i<dim; i++)
		{
			for (int j = 0; j<dim; j++)
				cout<<MAT[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}

};
MATRIX operator*(MATRIX a, MATRIX b)
{
	MATRIX res(a.dim);
	for (int i = 0; i<a.dim; i++)
	{
		for (int j = 0; j<b.dim; j++)
		{
			long long sum=0;
			for (int z=0; z<a.dim; z++)
			{
				sum += a.MAT[i][z] * b.MAT[z][j];
			}
			sum %=MOD;
			res.MAT[i][j] = sum;
		}
	}
	return res;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//CONVEX HULL
struct point
{
	int x, y;
	bool operator<(point B)
	{
		return (x<B.x || x==B.x && y<B.y);
	}
};


bool upper_OK(
	int x1, int y1,
	int x2, int y2,
	int x3, int y3) {
	return ((x2*y3-y2*x3) + (x1*y2 - x2*y1) - (x1*y3-y1*x3))<0;
}

bool lower_OK(
	int x1, int y1,
	int x2, int y2,
	int x3, int y3) {
	return ((x2*y3-y2*x3) + (x1*y2 - x2*y1) - (x1*y3-y1*x3))>0;
}


vector<point> Convex_Hull(vector<point>& V)
{
	sort (all(V));
	vector<point> UP, DOWN;

	point A = V[0], B = V.back();
	
	UP.push_back(A);
	DOWN.push_back(A);
	
	int i = 1;

	for (; i<V.size()-1; i++)
	{
		if (upper_OK(A.x, A.y, V[i].x, V[i].y, B.x, B.y))
		{
			while (UP.size()>=2 && !upper_OK(
				UP[UP.size()-2].x, UP[UP.size()-2].y,
				UP[UP.size()-1].x, UP[UP.size()-1].y,
				V[i].x, V[i].y) ) UP.pop_back();
			UP.push_back(V[i]);
		}

		if (lower_OK(A.x, A.y, V[i].x, V[i].y, B.x, B.y))
		{
			while (DOWN.size()>=2 && !lower_OK(
				DOWN[DOWN.size()-2].x, DOWN[DOWN.size()-2].y,
				DOWN[DOWN.size()-1].x, DOWN[DOWN.size()-1].y,
				V[i].x, V[i].y) ) DOWN.pop_back();
			DOWN.push_back(V[i]);
		}
	}
	
	
			while (UP.size()>=2 && !upper_OK(
				UP[UP.size()-2].x, UP[UP.size()-2].y,
				UP[UP.size()-1].x, UP[UP.size()-1].y,
				V[i].x, V[i].y) ) UP.pop_back();
			UP.push_back(V[i]);

			while (DOWN.size()>=2 && !lower_OK(
				DOWN[DOWN.size()-2].x, DOWN[DOWN.size()-2].y,
				DOWN[DOWN.size()-1].x, DOWN[DOWN.size()-1].y,
				V[i].x, V[i].y) ) DOWN.pop_back();
			DOWN.push_back(V[i]);

	V.clear();
	forn(UP.size()) V.push_back(UP[i]);

	for(int i=DOWN.size()-2; i>0; i--) V.push_back(DOWN[i]);
	return V;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//C calcualation
void C_MAKE()
{
	for(int i=1; i<=22; i++)
	{
		C[i][1] = i;
		C[i][i] = 1;

		for(int j=2; j<i; j++)
		{
			C[i][j] = C[i][j-1] * (i-j+1)/j;
		}
	}
}

//OR
void Pascal_combination(int N)
{
	C[0][0] = 1;
	for(int i=1; i<N; i++)
	{
		C[i][0] = 1;
		for(int j=1; j<i; j++)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
			C[i][j]%=MOD;
		}
		C[i][i] = 1;
	}
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

vector<int> Factorization(int N){
	vector<int> ans(N + 1);
	for(int i = 2; i * i <= N; i++){
		while (N % i == 0){
			N /= i;
			ans[i]++;
		}
	}
	if (N > 1)
		ans[N]++;
	return ans;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


vector<bool> ERATOSTHENE_SIEVE(int N)
{
	vector<bool> prime (N+1, true);
	prime[0] = prime[1] = false;
	for (long long i = 2; i * i <= N; ++i)
		if (prime[i])
			for (long long j = i * i; j <= N; j += i)
				prime[j] = false;
	return prime;
}

vector<int> primesUpTo(int N)
{
	vector<bool> prime (N+1, true);
	vector<int> primes;
	prime[0] = prime[1] = false;
	for (long long i = 2; i <= N; ++i){
		if (prime[i]){
			for (long long j = i * i; j <= N; j += i)
				prime[j] = false;
			primes.push_back(i);
		}
	}
	return primes;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

ll FACT[100000+1];
void Factorial(int N, int MOD=-1)
{
	FACT[0]=1;
	for(long long f = 1; f < N; f++)
	{
		FACT[f] = FACT[f - 1] * f;
		if (MOD != -1) FACT[f] %= MOD;
	}
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
long long CombinationMOD(int N, int k, long long mod){
	ll ans = FACT[N] % mod;
	ans *= binpow(FACT[k] * FACT[N-k] % mod, mod - 2, mod) % mod;
	return ans % mod;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

long long GCD(ll a, ll b)
{
	if (a<b) swap (a,b);
	if (!b) return a;

	return GCD(b, a%b);
}


long long LCM(ll a, ll b)
{
	return a*b/GCD(a,b);
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


//Triple
struct Triple
{
	int a,b,c;
	bool operator<(const Triple &d) const
	{
		return a<d.a;
	}
};

int popcnt(int c)
{
	int res = 0;
	while(c)
	{
		c = c & (c - 1);res++;
	}
	return res;
}