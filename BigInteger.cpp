#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

#define ll long long
#define forn(N)          for(ll i = 0; i<N; i++)
#define fornj(N)         for(ll j = 0; j<N; j++)
#define fornk(N)         for(ll k = 0; k<N; k++)

using namespace std;

int base = 10;

class BigInteger
{
	vector<int> NUMBER;
public:
	BigInteger(unsigned int integer)
	{
		while(integer!=0)
		{
			NUMBER.push_back (integer%10);
			integer /= 10;
		}
	}
	BigInteger(string str)
	{
		for(int i=str.size()-1; i>=0; i--)
			NUMBER.push_back (str[i]-'0');
	}
	BigInteger(vector<int> number)
	{
		int N = number.size();
		NUMBER.resize(N);
		forn(number.size())
			NUMBER[i] = number[i];
	}
	BigInteger add(BigInteger arg)
	{
		BigInteger ans(0);
		int carry = 0;
		for(int i = 0; i<(int)max(NUMBER.size(), arg.NUMBER.size()); i++)
		{
			ans.NUMBER[i] += carry + (arg.NUMBER[i] + NUMBER[i])%10;
			carry = (arg.NUMBER[i] + NUMBER[i])/10;
		}
		return ans;
	}
	BigInteger subtract(BigInteger arg)
	{
		BigInteger *first, *second, ans(0);
		first = this;
		second = &arg;
		bool sign = true;
		if (!isBigger(arg))
		{
			first = &arg;
			second = this;
			sign=false;
		}
		int carry = 0;
		for(int i = first->NUMBER.size(); i>=0; i--)
		{
			int dif = ((*first)[i]-carry)-(*second)[i];
			if (dif<0) 
			{
				dif+=10;
				carry++;
			}
			ans.change(i, dif);
		}
		return ans;
	}
	bool isBigger(BigInteger bi)
	{
		if (size()>bi.size()) return true;
		int N = size();
		forn(N)
		{
			if (NUMBER[i]>bi[i]) return true;
		}
		return false;
	}
	BigInteger divide(BigInteger div)
	{
		int N = div.NUMBER.size();
		BigInteger ans(0);
		for(int i = 0; i+N<size(); i++)
		{
			bool flag = false;
			BigInteger tmpnum(0);
			for(int j = 0; j<N; j++)
			{
				tmpnum.NUMBER.push_back(NUMBER[i+j]);
			}
			BigInteger tmp (tmpnum);
			int cnt = 0;
			do
			{
				if(tmp.isBigger(div))
				{
					tmp = tmp.subtract(div);
					cnt++;
				}
				else
				{
					flag=true;
					break;
				}
			}while(true);
			if(flag) continue;
			ans.change(i, cnt);
		}
		return ans;
	}
	void change(int index, int val){ NUMBER[index] = val;}
	int BigInteger::operator[] (int index)
	{
		return this->NUMBER[index];
	}
	int size(){return NUMBER.size();}
	string toString()
	{
		string ans;
		forn(size())
			ans+=NUMBER[size()-1- i];
		return ans;
	}
};

ostream& operator<<(ostream& in, BigInteger& integer)
{
	in<<integer.toString();
	return in;
}
