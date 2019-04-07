#include <iostream>

using namespace std;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {

    for (int i = 0; i < 1023; i++)
    {
        auto res = map(i, 0, 1023, 0, 3);

        cout << "i = " << i << " level = " << res << endl;
    }
    return 0;
}