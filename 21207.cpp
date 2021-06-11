#include <iostream>
#define MAX 100

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len, p;
	cin >> n >> len >> p;
	int boarded[MAX] = {};
	int longest_dist = 0;
	int max_boarded = 0;
	for(int i = 0; i < p; ++i){
		int x;
		cin >> x;
		int q = x / len, r = x % len;
		int dist = 0;
		if(q >= n){
			dist = x - ((n - 1) * len + len / 2);
			q = n - 1;
		}else if(r == 0){
			dist = len / 2;
		}else if(r >= len / 2){
			dist = r - len / 2;
		}else{
			dist = len / 2 - r;
		}
		++boarded[q];
		if(dist > longest_dist){
			longest_dist = dist;
		}
		if(boarded[q] > max_boarded){
			max_boarded = boarded[q];
		}
	}
	cout << longest_dist << '\n' << max_boarded;
	return 0;
}
