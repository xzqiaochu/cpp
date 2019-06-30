#include <iostream>

using namespace std;

int m, n, ans, val[102][102], dp1[102][102], dp2[102][102];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> val[i][j];
    for (int i = m; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            int temp = 0;
            bool flag = false;
            if (val[i - 1][j] > val[i][j]) {
                flag = true;
                temp = max(temp, dp1[i + 1][j]);
            }
            if (val[i][j - 1] > val[i][j]) {
                flag = true;
                temp = max(temp, dp1[i][j + 1]);
            }
            if (flag)
                temp++;
            dp1[i][j] = temp;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp1[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int temp = 0;
            bool flag = false;
            if (val[i - 1][j] < val[i][j]) {
                flag = true;
                temp = max(temp, dp2[i - 1][j]);
            }
            if (val[i][j - 1] < val[i][j]) {
                flag = true;
                temp = max(temp, dp2[i][j - 1]);
            }
            if (val[i + 1][j] < val[i][j]) {
                flag = true;
                temp = max(temp, dp1[i + 1][j]);
            }
            if (val[i][j + 1] < val[i][j]) {
                flag = true;
                temp = max(temp, dp1[i][j + 1]);
            }
            if (flag)
                temp++;
            ans = max(temp, ans);
            dp2[i][j] = temp;
        }
    }
    cout << ans;
    return 0;
}