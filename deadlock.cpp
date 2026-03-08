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
    int A[10];
    bool finish[10];

    // read total resources 
    for(int i = 0; i < m; i++)
        file >> E[i];

    // read allocation matrix 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            file >> C[i][j];

    // read request matrix        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            file >> R[i][j];

    //calculate available resources 
    for(int j = 0; j < m; j++)
    {
        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += C[i][j];

        A[j] = E[j] - sum;
    }

    // mark all processes as unfinished 
    for(int i = 0; i < n; i++)
        finish[i] = false;

    bool change = true;

    // deadlock detection algorithm 
    while(change)
    {
        change = false;

        for(int i = 0; i < n; i++)
        {
            if(!finish[i])
            {
                bool possible = true;

                // check if process can execute 
                for(int j = 0; j < m; j++)
                {
                    if(R[i][j] > A[j])
                        possible = false;
                }

                // if process can execute, release its resources 
                if(possible)
                {
                    for(int j = 0; j < m; j++)
                        A[j] += C[i][j];

                    finish[i] = true;
                    change = true;
                }
            }
        }
    }

    bool deadlock = false;

    cout << "Deadlock Detection Result:" << endl;
    cout << "Deadlocked Processes: ";

    for(int i = 0; i < n; i++)
    {
        if(!finish[i])
        {
            cout << "P" << i << " ";
            deadlock = true;
        }
    }

    if(!deadlock)
        cout << "None";

    cout << endl;

    return 0;
}