#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> a(3);
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a.begin(), a.end());
	if(a[2] * a[2] == a[0] * a[0] + a[1] * a[1]){
		printf("1");
	}else if(a[0] == a[1] && a[1] == a[2]){
		printf("2");
	}else{
		printf("0");
	}
	return 0;
}
