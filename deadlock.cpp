#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("input.txt");

    if(!file)
    {
        cout << "Error opening file" << endl;
        return 0;
    }

    int n, m;
    file >> n >> m;

    int E[10];
    int C[10][10];
    int R[10][10];

    for(int i = 0; i < m; i++)
        file >> E[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            file >> C[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            file >> R[i][j];

    return 0;
}