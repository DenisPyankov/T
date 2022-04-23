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
    int max = 0, k = 1;
    
    for (int i = 0; i < N - 1; i++) {
        if (v[i] <= v[i + 1])
            k++;
        else {
            if (k > max)
                max = k;
            k = 1;
 
        }
    }


    out << max;


}
