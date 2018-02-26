//计算n!中有多少个质因子p，O(nlogn)
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
//计算n!中有多少个质因子p,O(logn)
int cal(int n, int p) {
	int ans = 0;
	while (n) {
		ans += n / p;
		n /= p;
	}
	return ans;
}
//可快速计算出n!的末尾有多少个0,：由于末尾0的个数等于n!中因子10的个数，而这又等于n!中质因子5的个数，cal(n,5)即可得到结果。
