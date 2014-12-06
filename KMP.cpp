#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define forn(N)         for(int i = 0; i<N; i++)



/*
void FailureFunction(string P, int F[])
{
	int i,j;
	F[0]=0;	//  assignment is important!
	j=0;
	i=1;
	while(i<P.size())
	{ // that i is less than the length of pattern
		if(P[i]==P[j]){
			F[i]=j+1;
			i++;
			j++;
		}

		else if(j>0){
			j=F[j-1];
		}
		
		else {
			F[i]=0;
			i++;
		}
	}
	F[0]=-1;
}




int KMP(string base, string pattern)
{
	int * T = new int[pattern.size()];

	FailureFunction(pattern, T);
	int m = 0, i = 0, ans=-1;
	for( ; m+i<base.size(); )
	{
		if (pattern[i] != base[m+i])
		{
			m += i-T[i];
			i = max(0, T[i]);
		}
		else
		{
			i++;
			if (i == pattern.size())
				return m;
		}
	}
	return -1;
}*/



void FailureFunction(char P[], int F[],int m){
	int i,j;
	F[0]=0;	//  assignment is important!
	j=0;
	i=1;
	while(i<m){ // that i is less than the length of pattern
		if(P[i]==P[j]){
			F[i]=j+1;
			i++;
			j++;
		}else if(j>0){
			j=F[j-1];
		}else {
			F[i]=0;
			i++;
		}
	}
}

int KMP(char T[], char P[]){
	int i,j,F[100];	// the maximum size of Pattern String
	int m=strlen(P);
	int n=strlen(T);
	FailureFunction(P,F,m);
	i=0;
	j=0;
	while(i<n){
		if(T[i]==P[j]){
			if(j==m-1)
				return i-j; // means, in (i-j)th position, there is a match occur
			else{
				i++;
				j++;
			}
		}else if(j>0){
			j=F[j-1];
		}else{
			i++;
		}
	}
	return -1; // No match found
}

