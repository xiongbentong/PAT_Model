//计算n!中有多少个质因子p
int cal(int n, int p) {
	int ans = 0;
	for (int i = 2; i<=n; i++) {
		int temp = i;
		while (temp%p == 0) {
			ans++;
			temp /= p;
		}
	}
	return ans;
}
