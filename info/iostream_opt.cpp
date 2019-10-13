// iostream输入输出优化
#include <iostream>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // 这两行代码取消了与stdio的关联，所以接下来只能用iostream
}