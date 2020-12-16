#include <iostream>
#define MAX 31

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int streets, avenues;
		cin >> streets >> avenues;
		if(streets == 0 && avenues == 0){
			break;
		}
		++t;
		long long roads[MAX][MAX] = {};
		while(true){
			int s, a;
			cin >> s >> a;
			if(s == 0 && a == 0){
				break;
			}
			roads[s][a] = -1;
		}
		roads[0][0] = 1;
		for(int i = 0; i < streets; ++i){
			for(int j = 0; j < avenues; ++j){
				if(roads[i][j] == -1){
					continue;
				}
				if(i > 0 && roads[i - 1][j] != -1){
					roads[i][j] += roads[i - 1][j];
				}
				if(j > 0 && roads[i][j - 1] != -1){
					roads[i][j] += roads[i][j - 1];
				}
			}
		}
		cout << "Map " << t << ": " << roads[streets - 1][avenues - 1] << "\n";
	}
	return 0;
}
