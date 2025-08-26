#include <iostream>

int main()
{
    using namespace std;

    double x = 3;
    double y = 7;
    double z;
    double w;

    z = min(x,y);
    w = max(x,y);

    cout << "max: " << w << ", min: " << z << endl;

    return 0;
}