#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, ans, h, m;
    cin >> a >> b >> c >> d;
    ans = 60 * c + d - 60 * a - b;
    h = ans / 60;
    m = ans % 60;
    cout << h << ' ' << m;
    return 0;
}
