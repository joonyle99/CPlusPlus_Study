#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    float a = 1.1f;
    float b = 0.1f;

    printf("%f\n", a);
    printf("%f\n", b);

    double c = 1.1;
    double d = 0.1;

    printf("%lf\n", c);
    printf("%lf\n", d);

    cout << (0.125f + 0.125f == 0.25f) << endl;

    return 0;
}
