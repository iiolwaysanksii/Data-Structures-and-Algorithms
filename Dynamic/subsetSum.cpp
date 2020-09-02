#include <iostream>
using namespace std;

bool SubsetSum(int, int[], int);

int main()
{
    int S, n;

    cout << "Subset Sum Problem" << endl;

    S = 10;
    int subset[] = {5, 1, 4};
    n = 3;

    if (SubsetSum(S, subset, n))
        cout << "Yes, there exists a subset in array whose Sum is equal to " << S << endl;
    else
        cout << "No, there does not exists a subset in array whose Sum is equal to " << S << endl;
}

bool SubsetSum(int S, int subset[], int n)
{
    if (S == 0)
        return true;
    if (n == 0 && S != 0)
        return false;

    if (subset[n-1] > S)
        return SubsetSum(S, subset, n-1);
    else
        return max(SubsetSum(S, subset, n-1), SubsetSum(S-subset[n-1], subset, n-1));
}
