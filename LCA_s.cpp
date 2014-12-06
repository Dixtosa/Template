vector<bool> visited;

vector<list<pair<int, int> > > G;

vector<int> EULER;
vector<int> LEVEL;
vector<int> FirstOcurrence;

int Depth = 0;
int mandzili = 0;
unsigned short DP[2*50000+1][18];
unsigned short DP_ind[2*50000+1][18];
int len[50000+1];

void DFS(int u)
{
	visited[u] = true;
	len[u] = mandzili;

	EULER.push_back(u);
	LEVEL.push_back(Depth);
	FirstOcurrence[u] = EULER.size()-1;
	for(list<pair<int, int> >::iterator it = G[u].begin(); it!=G[u].end(); it++)
	{
		if (!visited[it->first])
		{

			Depth++;
			mandzili += it->second;

			DFS(it->first);

			mandzili -= it->second;
			Depth--;

			EULER.push_back(u);
			LEVEL.push_back(Depth);
		}
	}
}


int my_log(int K)
{
	int tmp = 1,ans=0;

	while(2*tmp<K)
	{
		ans++;
		tmp *= 2;
	}
	return ans;
}

int get(int l, int r)
{
 	int length = my_log(r-l+1);
	if (DP[l][length] < DP[r+1-(int)pow(2.0, length)][length])
		return DP_ind[l][length];
	else
		return DP_ind[r+1-(int)pow(2.0, length)][length];
}


DFS(0);
for(int i = 0; i<2*N-1; i++)
{
	DP[i][0] = LEVEL[i];
	DP_ind[i][0] = i;
}

for(int j = 1; j<=17; j++)
{
	for(int i = 2*N-2; i>=0; i--)
	{
		if (i+pow(2.0, j)>=2*N-1) continue;

		if (DP[i][j-1] < DP[i + (int)pow(2.0, j-1)][j-1])
		{
			DP[i][j] = DP[i][j-1];
			DP_ind[i][j] = DP_ind[i][j-1];
		}
		else
		{
			DP[i][j] = DP[i + (int)pow(2.0, j-1)][j-1];
			DP_ind[i][j] = DP_ind[i + (int)pow(2.0, j-1)][j-1];
		}
	}
}