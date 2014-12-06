#define MOD 10007

long long binpowMOD(long long a, long long n, long long mod)
{
	long long res = 1;
	a %= mod;
	while (n) {
		if (n & 1)
		{
			res *= a;
			res %= mod;
		}
		a *= a;
		a%=mod;
		n >>= 1;
	}
	return res;
}

struct Int {
	long long x;
	Int() :
			x(0) {
	}
	
	Int(long long _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(long long x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		long long t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		long long t = x - o.x;
		if (t < 0)
			t += MOD;
		return get(t);
	}
	Int operator/(const Int&o) const {
		return (*this) * o.inv();
	}
	Int&operator+=(const Int&o) {
		return (*this) = *this + o;
	}
	Int&operator-=(const Int&o) {
		return (*this) = *this - o;
	}
	Int&operator*=(const Int&o) {
		return (*this) = *this * o;
	}
	Int&operator/=(const Int&o) {
		return (*this) = *this / o;
	}

	Int power(long long n) const {
		if (!n)
			return get(1);
		const Int&a = *this;
		if (n & 1)
			return power(n - 1) * a;
		else
			return (a * a).power(n >> 1);
	}

	Int inv() const {
		return power(MOD - 2);
	}
};


int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

