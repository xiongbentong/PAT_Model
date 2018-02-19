//N个只有小写字母的字符串，求其中不同的字符串个数
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;//模数:1e9+7
const int P = 10000019;//进制:1e7+19
vector<int> ans;
//字符串hash
long long hashFunc(string str) {
	long long H = 0;//使用long long避免溢出
	for (int i = 0; i < str.length(); i++) {
		H = (H*P + str[i] - 'a') % MOD;
	}
	return H;
}
int main() {
	string str;
	while (getline(cin, str), str != "#") {//输入str直到#时停止
		long long id = hashFunc(str);//将字符串str转换为整数
		ans.push_back(id);
	}
	sort(ans.begin(), ans.end());//排序
	int count = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0 || ans[i] != ans[i - 1])
			count++;
	}
	cout << count << endl;
	return 0;
}
