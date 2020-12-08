#include <cstdio>
#include <string>
#include <set>

using std::string;
using std::set;

void paths(set<string> diag[444], char grid[][21], unsigned n, unsigned x, unsigned y, string s){
	s += grid[x][y];
	if(s.length() == n){
		diag[x * y + y].insert(s);
		return;
	}
	if(x < n - 1){
		paths(diag, grid, n, x + 1, y, s);
	}
	if(y < n - 1){
		paths(diag, grid, n, x, y + 1, s);
	}
}

void find_paths(set<string> diag[444], set<string> &pals, char grid[][21], unsigned n, unsigned x, unsigned y, string s){
	s += grid[x][y];
	if(s.length() == n){
		if(diag[x * y + y].find(s) != diag[x * y + y].end()){
			pals.insert(s);
		}
		return;
	}
	if(x > 0){
		find_paths(diag, pals, grid, n, x - 1, y, s);
	}
	if(y > 0){
		find_paths(diag, pals, grid, n, x, y - 1, s);
	}
}

int main(){
	unsigned n;
	scanf("%u", &n);
	char grid[21][21];
	for(unsigned i = 0; i < n; ++i){
		scanf("%s", grid[i]);
	}
	set<string> diag[444], pals;
	paths(diag, grid, n, 0, 0, "");
	find_paths(diag, pals, grid, n, n - 1, n - 1, "");
	printf("%llu", pals.size());
	return 0;
}
