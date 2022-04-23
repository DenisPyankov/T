#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int N, M;
    in >> N >> M;
    vector < vector <int> > v(N, vector <int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int a;
            in >> a;
            v[i][j] = a;
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < M - 1; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[j][i] < v[j][i + 1]) {
                for (int j = 0; j < N; j++) {
                    swap(v[j][i], v[j][i + 1]);
                }
            }
        }
    }


    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] < v[i + 1][j]) {
                for (int j = 0; j < M; j++) {
                    swap(v[i][j], v[i + 1][j]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    out << v[N - 1][M - 1];

}
