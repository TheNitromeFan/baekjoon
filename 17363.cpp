#include <cstdio>
#include <map>
#define MAX (100 + 1)

int main(){
	std::map<char, char> rot = {{'.', '.'}, {'O', 'O'}, {'-', '|'}, {'|', '-'}, {'/', '\\'}, {'\\', '/'}, 
	{'^', '<'}, {'<', 'v'}, {'v', '>'}, {'>', '^'}};
	char milk[MAX][MAX];
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", milk[i]);
	}
	for(int j = m - 1; j >= 0; --j){
		for(int i = 0; i < n; ++i){
			printf("%c", rot[milk[i][j]]);
		}
		printf("\n");
	}
	return 0;
}
