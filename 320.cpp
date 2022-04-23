#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int f(int m, int n) {
    int a = 0;
    if (n < m) {
        return 1;
    }
    for (int i = 0; i < n - m + 1; ++i) {
        a += f(m, n - m - i);
    }
    return a;
}


int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n, m;
    in >> m >> n;
    out << 1 + f(m, n);
}
