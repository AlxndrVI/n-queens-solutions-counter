#include <algorithm>
#include <chrono>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

class NQueensSolutionsCounter
{
    size_t count = 0;
    const int n;
    const int diagSize;
    const int shift;
    char diag[82] = {};
    char row[20] = {};

    void solve(int x)
    {
        if (x < n)
        {
            for (int y = 0; y < n; ++y)
            {
                int mainDiag = x + y;
                int subDiag = x - y + shift;
                if ((row[y] | diag[mainDiag] | diag[subDiag]) == 0)
                {
                    row[y] = 1;
                    diag[mainDiag] = 1;
                    diag[subDiag] = 1;
                    solve(x + 1);
                    row[y] = 0;
                    diag[mainDiag] = 0;
                    diag[subDiag] = 0;
                }
            }
        }
        else
        {
            ++count;
        }
    }

  public:
    NQueensSolutionsCounter(int n)
        : n{n}, diagSize{(n << 1) - 1}, shift{diagSize + (diagSize >> 1)}
    {
        if (n < 1 || n > 20)
            return;
        solve(0);
    }

    int getCount() { return count; }
};

int main()
{
    int n;
    cout << "Enter number of Queens:";
    cin >> n;
    high_resolution_clock::time_point ts;
    ts = high_resolution_clock::now();
    NQueensSolutionsCounter nqsc(n);
    cout << endl
         << nqsc.getCount() << "  ";
    cout << duration_cast<duration<double>>(high_resolution_clock::now() - ts)
                .count();

    return 0;
}