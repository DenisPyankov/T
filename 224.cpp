#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int N;
    in >> N;
    vector <int> v;
    for (int i = 0; i < N; i++) {
        int a;
        in >> a;
        v.push_back(a);
    }
    int i, j, temp;
    for (i = 1; i < N; i++){
        temp = v[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] < temp)
                break;

            v[j + 1] = v[j];
            v[j] = temp;
        }
    }
    out << v[N - 1] * v[N - 2] * v[N - 3];

}
