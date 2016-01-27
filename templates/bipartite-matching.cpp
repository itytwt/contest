// bipartite matching
//  - augmenting path algorithm
//  * kV = size of the graph
//  * n = # of vertices in X
//  * m = # of vertices in Y

vector< int > X[kV], Y[kV];
int mx[kV], my[kV];
bool vy[kV];

void bipartite_matching() {
	int res = 0;

	fill(&mx[0], &mx[n], -1);
	fill(&my[0], &my[m], -1);
	for (int i = 0; i < n; ++i) {
		fill(&vy[0], &vy[m], false);
		if (dfs(i))
			++res;
	}
}

bool dfs(int u) {
	for (int v: X[u])
		if (!vy[v]) {
			vy[v] = true;
			if (my[v] == -1 || dfs(my[v])) {
				mx[u] = v, my[v] = u;
				return true;
			}
		}

	return false;
}
