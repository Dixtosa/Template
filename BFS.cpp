#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int BFS()
{    
    vector<int> color(n, 0); // 0 = tetri, 1= ruxi, 2=shavi
    vector<int> d(n, -1);
    vector<int> p(n, -1);
    
    for (int k=0; k<n; ++k) 
        if (color[k] == 0)
		{
           cout << "New Tree\n";
        
            queue<int> q;
            q.push(k);            
            color[k] = 1;
            d[k] = 0;
            p[k] = -1;
            
            while (!q.empty()) {
                  int v = q.front();
                  q.pop();          
                  
                  cout << v << " " << d[v] << " " << p[v] << "\n";
                  
                  for (int i=0; i<n; ++i)
                      if (a[v][i] == true && color[i] == 0) {
                         color[i] = 1;
                         d[i] = d[v] + 1;
                         p[i] = v;
                         q.push(i);
                      }
                  
                  color[v] = 2;
            }
            
        }    
    return 0;
}



int BFS()
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(xx0, xy0));

	MAP[xx0][xy0]=-1;
	
	while (!Q.empty())
	{
		pair<int, int> XY = Q.front();
		Q.pop();
		MAP[XY.first][XY.second]=-1;

		if (XY.first==xx1 && XY.second==xy1)
		{
			return MAP2[XY.first][XY.second];
		}

		for (int yyy=0; yyy<8; yyy++)
		{
			if (XY.first + way[yyy][0]>=0 && (XY.second + way[yyy][1]>=0))
			{
				if (MAP[XY.first + way[yyy][0]] [XY.second + way[yyy][1]]==1)
				{
					MAP2[XY.first + way[yyy][0]] [XY.second + way[yyy][1] ] = MAP2[XY.first] [XY.second]+1;
					Q.push(make_pair(XY.first + way[yyy][0], XY.second + way[yyy][1]));
					MAP[XY.first + way[yyy][0]][XY.second + way[yyy][1]]=-1;
				}
			}
		}
	}
	return -1;
}
