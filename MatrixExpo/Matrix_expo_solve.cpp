#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
//const int N = 2e5+6;


const int N = 2;

const long long M = 1000000007;

// Multiplies two matrices A and B and stores the result in A.
void multiply (long long A[N][N], long long B[N][N])
{
    long long R[N][N];

    // Multiply A and B and store result in R.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            R[i][j] = 0;

            for (int k = 0; k < N; k++)
            {
                R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }

    // Copy contents of R in A.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = R[i][j];
        }
    }
}

// Raise matrix A to the power of n in O(log n).
void power_matrix (long long A[N][N], ll n)
{
    long long B[N][N];

    // B = Identity Matrix.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = A[i][j];
        }
    }

    // A = A * A ^ (n - 1).
    n = n - 1;
    while (n > 0)
    {
        // If n is odd, A = A * B.
        if (n & 1)
            multiply (A, B);

        // B = B * B.
        multiply (B, B);

        // n = n / 2.
        n = n >> 1;
    }
}

// A = Coefficient Matrix, B = Base Matrix.
// It returns the nth term of the recurrence relation formed from A and B in O(log n).
long long solve_recurrence (long long A[N][N], long long B[N][1], ll n)
{
    //Base Cases.
    if (n < N)
        return B[N - 1 - n][0];

    // A = A ^ (n - N + 1).
    power_matrix (A, n - N + 1);

    long long result = 0;

    for (int i = 0; i < N; i++)
        result = (result + A[0][i] * B[i][0]) % M;

    return result;
}


void Solve()
{

    long long A[N][N] = {{1, 2}, {1, 0}};

    //Forming the Base Matrix
    long long B[N][1] = {{3}, {1}};

    long long n;
    cin>>n;
    long long R_n = solve_recurrence (A, B, n-1);
    cout<<R_n<<endl;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    cin >> tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}

// https://toph.co/arena?practice=63e263771cdc42c5a8103381#!/p/63cb929a33df094f35564ab8