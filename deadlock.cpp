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

    for(int i = 0; i < m; i++)
        file >> E[i];

    return 0;
}