bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
#include<cstdio>//筛法求素数表，复杂度O(nloglogn)
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };
void Find_Prime() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + 1; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}
struct factor {
	int x, cnt;
}fac[10];
int main() {
	Find_Prime();
	int n, num = 0;
	scanf("%d", &n);
	if (n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0*n);
		for (int i = 0; i < pNum&&prime[i] <= sqr; i++) {
			if (n%prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n%prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1) {
			fac[num].x = n;
			fac[num].cnt = 1;
		}
		for (int i = 0; i < num; i++) {
			if (i > 0) printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1) {
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}
