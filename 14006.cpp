#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int nplayers = 1 << n;
	vector<int> v(nplayers);
	for(int &x : v){
		scanf("%d", &x);
	}
	int dudu = v[0];
	sort(v.begin(), v.end());
	if(n == 0 || v[0] != dudu || v[1] == dudu){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}
