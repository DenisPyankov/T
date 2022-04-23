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
    vector < vector <char> > v(N, vector <char>(N));
    for (int i=0; i<N; i++)
        for (int j = 0; j < N; j++) {
            char a;
            in >> a;
            v[i][j] = a;
        }

    vector < vector <char> > res(N, vector <char>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            res[i][j] = '.';
        }

    res[0][0] = '#';
    int x = 0, y = 0;
    while (x != N - 1 || y != N - 1) {
        if (x == N - 1) {
            res[x][y + 1] = '#';
            y += 1;

        }else 
            if (y == N - 1) {
            res[x + 1][y] = '#';
            x += 1;

            }
            else {
                int a, b, c;
                a = v[x + 1][y] - '0';
                b = v[x][y + 1] - '0';
                c = v[x + 1][y + 1] - '0';
                if (a < b && c < b && x != N - 1 && y != N - 1) {
                    res[x + 1][y] = '#';
                    x += 1;
                }
                else {
                    res[x][y + 1] = '#';
                    y += 1;
                }
                
            }


    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out << res[i][j] << " ";
        }
        out << endl;
    }

}
