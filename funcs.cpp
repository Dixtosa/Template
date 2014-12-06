#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template<class input>
void SHOW(input y)
{
	for (input::iterator l=y.begin (); l!=y.end(); l++)
	{
		cout<<*l<<", ";
	}
	cout<<";";
}

template<class type1, class type2>
void SHOW(vector<pair<type1, type2> >  y)
{
	if (y.size() == 0) return; 
	int iii=0;
	for (; iii<y.size()-1; iii++)
	{
		cout<<"("<<y[iii].first<<", "<<y[iii].second<<"), ";
	}
	cout<<"("<<y[iii].first<<", "<<y[iii].second<<");\n";
}