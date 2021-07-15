#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int n[15],p[11],Q,F,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,ret[11][2],c[11]; //11Â÷¿ø
vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<ll>>>>>>>>>>> a;

ll Do() {
	ll rett = 0;
	do {
		F = 0;
		for(int i = 0;i < 11;i++) {
			if(!p[i]) c[i] = ret[i][1];
			else {
				c[i] = ret[i][0]-1;
				if(c[i] == -1) {
					F = 1; break;
				}
			}
		}
		if(!F) rett += a[c[0]][c[1]][c[2]][c[3]][c[4]][c[5]][c[6]][c[7]][c[8]][c[9]][c[10]];
	}while(prev_permutation(p,p+11));
	return rett;
}

ll f() {
	ll rett = 0;
	for(int i = 1;i <= 11;i++) {
		memset(p,0,sizeof(p));
		for(int j = 0;j < i;j++) p[j] = 1;
		if(i % 2) rett += Do();
		else rett -= Do();
	}
	return rett;
}

int main() {
	for(int i = 1;i <= 11;i++) scanf("%d",&n[i]);
	a.resize(n[1]);
	for(i1 = 0;i1 < n[1];i1++) { a[i1].resize(n[2]);
		for(i2 = 0;i2 < n[2];i2++) { a[i1][i2].resize(n[3]);
			for(i3 = 0;i3 < n[3];i3++) { a[i1][i2][i3].resize(n[4]);
				for(i4 = 0;i4 < n[4];i4++) { a[i1][i2][i3][i4].resize(n[5]);
					for(i5 = 0;i5 < n[5];i5++) { a[i1][i2][i3][i4][i5].resize(n[6]);
						for(i6 = 0;i6 < n[6];i6++) { a[i1][i2][i3][i4][i5][i6].resize(n[7]);
							for(i7 = 0;i7 < n[7];i7++) { a[i1][i2][i3][i4][i5][i6][i7].resize(n[8]);
								for(i8 = 0;i8 < n[8];i8++) { a[i1][i2][i3][i4][i5][i6][i7][i8].resize(n[9]);
									for(i9 = 0;i9 < n[9];i9++) { a[i1][i2][i3][i4][i5][i6][i7][i8][i9].resize(n[10]);
										for(i10 = 0;i10 < n[10];i10++) { a[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10].resize(n[11]);
											for(i11 = 0;i11 < n[11];i11++) {
												scanf("%lld",&a[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11]);

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int w = 0;w < 11;w++) {
		memset(c,0,sizeof(c));
		c[w] = 1;
		for(i1 = 0,ret[0][1] = ret[0][0] = 0;i1 < n[1];ret[0][0]++,ret[0][1]++,i1++)
		for(i2 = 0,ret[1][1] = ret[1][0] = 0;i2 < n[2];ret[1][0]++,ret[1][1]++,i2++)
		for(i3 = 0,ret[2][1] = ret[2][0] = 0;i3 < n[3];ret[2][0]++,ret[2][1]++,i3++)
		for(i4 = 0,ret[3][1] = ret[3][0] = 0;i4 < n[4];ret[3][0]++,ret[3][1]++,i4++)
		for(i5 = 0,ret[4][1] = ret[4][0] = 0;i5 < n[5];ret[4][0]++,ret[4][1]++,i5++)
		for(i6 = 0,ret[5][1] = ret[5][0] = 0;i6 < n[6];ret[5][0]++,ret[5][1]++,i6++)
		for(i7 = 0,ret[6][1] = ret[6][0] = 0;i7 < n[7];ret[6][0]++,ret[6][1]++,i7++)
		for(i8 = 0,ret[7][1] = ret[7][0] = 0;i8 < n[8];ret[7][0]++,ret[7][1]++,i8++)
		for(i9 = 0,ret[8][1] = ret[8][0] = 0;i9 < n[9];ret[8][0]++,ret[8][1]++,i9++)
		for(i10 = 0,ret[9][1] = ret[9][0] = 0;i10 < n[10];ret[9][0]++,ret[9][1]++,i10++)
		for(i11 = 0,ret[10][1] = ret[10][0] = 0;i11 < n[11];ret[10][0]++,ret[10][1]++,i11++)
		if(ret[w][1] != 0) a[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] += a[i1-c[0]][i2-c[1]][i3-c[2]][i4-c[3]][i5-c[4]][i6-c[5]][i7-c[6]][i8-c[7]][i9-c[8]][i10-c[9]][i11-c[10]];

	}
	scanf("%d",&Q);
	while(Q--) {
		for(int i = 0;i < 2;i++) {
			for(int j = 0;j < 11;j++) {
				scanf("%d",&ret[j][i]); ret[j][i]--;
			}
		}
		printf("%lld\n",a[ret[0][1]][ret[1][1]][ret[2][1]][ret[3][1]][ret[4][1]][ret[5][1]][ret[6][1]][ret[7][1]][ret[8][1]][ret[9][1]][ret[10][1]]-f());
	}
	return 0;
}
