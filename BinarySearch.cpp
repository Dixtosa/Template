#include<iostream>
using namespace std;


//true true true true true true true | false false false false
long long MAX_TRUE(bool check(int), long long left, long long right)
{
	long long i = left, j = right, mid;
	
	while (i<j)
	{
		mid  = (i + j)/2;
		if (check (mid))
			i = mid+1;
		else
			j = mid;
	}
	if (check(i))
		return i;  //all true
	else if (i==left)
		return -1; //all false
	else
		return i-1;
}