#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    
    ifstream in("in.txt");
    ofstream out("out.txt");

    int n;
    in >> n;
    vector<int> v;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int a;
        in >> a;
        v.push_back(a);
        res.push_back(100);
    }
    res[0] = 0;
    for (int i = 1; i < n; ++i) {
        res[i] = min(res[i - 1] + abs(v[i] - v[i - 1]), res[i]);
        if (i != n - 1) {
            res[i + 1] = min(res[i - 1] + 3 * abs(v[i + 1] - v[i - 1]), res[i + 1]);
        }
    }
    out << res[n-1];

}
