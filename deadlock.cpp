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

    cout << "Processes: " << n << endl;
    cout << "Resources: " << m << endl;

    return 0;
}