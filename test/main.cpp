#include <iostream>

using namespace std;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;

    return 0;
}
int analogRead(int pin) {
    return rand() % 100;
}


int analogRead() {
    int sum = 0;

    constexpr int iter_count = 28;

    int values[iter_count];

    for (int i = 0; i < iter_count; i++) {
        //sum += ::analogRead(m_analog_pin);
        values[i] = ::analogRead(1);
    }

    qsort(values, iter_count, sizeof(int), compare);

    for (int i = 0; i < iter_count / 28; i++) {
        sum += values[i];
    }

    return sum / (iter_count / 28);
}

int main() {

    cout << analogRead();

//    for (int i = 0; i < 1023; i++)
//    {
//        auto res = map(i, 0, 1023, 0, 3);
//
//        cout << "i = " << i << " level = " << res << endl;
//    }
    return 0;
}