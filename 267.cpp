#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int N, x, y;
    in >> N >> x >> y;
    int a = 0;
    a += x;
    N--;
    int x1 = 0;
    int x2 = y * N;
    while (x1 != x2) {
        int s = (x1 +x2) / 2;
        if (s / x + s / y < N) {
            x1 = s + 1;
        }
        else {
            x2 = s;
        }
    }
    a += x1;
    out << a;
}
