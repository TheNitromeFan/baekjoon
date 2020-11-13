#include <cstdio>
#include <map>

using namespace std;

int pth_power(int n, int p){
	int ret = 1;
	for(int i = 0; i < p; ++i){
		ret *= n;
	}
	return ret;
}

int sum_of_pth(int n, int p){
	int ret = 0;
	while(n){
		ret += pth_power(n % 10, p);
		n /= 10;
	}
	return ret;
}

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	map<int, int> visited;
	visited[n] = 0;
	while(true){
		int m = sum_of_pth(n, p);
		if(visited.find(m) == visited.end()){
			visited[m] = visited[n] + 1;
		}else{
			printf("%d", visited[m]);
			break;
		}
		n = m;
	}
	return 0;
}
