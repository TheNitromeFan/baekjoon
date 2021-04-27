#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tgmath.h>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int modinv(int x, int p) {
    int r = 1;
    for (int b = p - 2; b; b >>= 1) {
        if (b & 1) r = 1LL * r * x % p;
        x = 1LL * x * x % p;
    }
    return r;
}

int range_mul(int a, int b, int p) {
    int r = 1;
    __int128 pinv = 1;
    ++((pinv <<= 64) /= p);
    for (; a<=b; ++a) {
        long long v = 1LL * r * a;
        r = v - p * (v * pinv >> 64);
    }
    return r;
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    if (p == 2) puts("1");
    else if (n < p / 2) {
        printf("%d\n", range_mul(1, n, p));
    } else {
        printf("%d\n", modinv(p - range_mul(n + 1, p - 1, p), p));
    }
    return 0;
}

