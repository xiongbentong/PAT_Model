//参考
#include <cstdio>
const int maxn = 10010;
int a[maxn], dp[maxn];
int s[maxn] = {0};
int main() {
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] >= 0) flag = true;
    }
    if(flag == false) {
        printf("0 %d %d\n", a[0], a[n - 1]);
        return 0;
    }
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
    //状态转移方程
        if(dp[i - 1] + a[i] > a[i]) {
            dp[i] = dp[i - 1] + a[i];
		//s[i]表示以a[i]作为结尾的最大连续子列和从哪个元素开始，记录下标
            s[i] = s[i - 1];
        } else {
            dp[i] = a[i];
            s[i] = i;
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++) {
        if(dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
    return 0;
}
//自用
#include<cstdio>
int main() {
	int num[10010], K,flag=0;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num[i]);
		if (num[i] >=0)
			flag = 1;
	}
	int maxsum = -1, sum = 0,st,ed,temp;
	for (int i = 0; i < K; i++) {
		if (sum == 0) {
			temp = num[i];
		}
		sum += num[i];
		if (sum < 0) {
			sum = 0;
		}
		else if (sum > maxsum) {
			maxsum = sum;
			st = temp;
			ed = num[i];
		}
	}
	if (flag == 0) {
		printf("0 %d %d", num[0], num[K - 1]);
	}
	else {
		printf("%d %d %d", maxsum,st,ed);
	}
	return 0;
}
