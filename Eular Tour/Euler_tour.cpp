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

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=" << a << " ! ";
    err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.fr << ", " << p.sc << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class T> ostream& operator << (ostream& out, multiset<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{"; for (auto it = m.begin (); it != m.end (); ++it) { if (it != m.begin ())out << ", "; out << *it; } return out << "}"; }



const int mod = 1e9 + 7;
const int N = 2e5 + 6;

vector<int>node[N];
int Intime[N], Outtime[N], Level[N] , a[N];
int timer = 1;
int n, q;

void EulerTour(int p, int par, int d)
{
    Intime[p] = timer++;
    Level[p] = d;

    for (auto i : node[p])
    {
        if (i == par)
            continue;

        EulerTour(i, p, Level[p] + 1);
    }

    Outtime[p] = timer;
}

struct BIT {
    long long M[N], A[N];
    BIT() {
        memset(M, 0, sizeof M);
        memset(A, 0, sizeof A);
    }
    void update(int i, long long mul, long long add)
    {
        while (i < N)
        {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void upd(int l, int r, long long x)
    {
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    long long query(int i)
    {
        long long mul = 0, add = 0;
        int st = i;
        while (i >= 0)
        {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }
    long long query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
} T[2];


void Solve()
{

    cin >> n >> q;

    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];

    for (int i = 1 ; i < n ; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    EulerTour(1, 0, 0);


    for (int i = 1 ; i <= n ; i++)
    {
        T[Level[i] % 2].upd(Intime[i], Intime[i], a[i]);
        T[!(Level[i] % 2)].upd(Intime[i], Intime[i], 0);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            ll x, val;
            cin >> x >> val;

            T[Level[x] % 2].upd(Intime[x], Outtime[x]-1, val);
            T[!(Level[x] % 2)].upd(Intime[x], Outtime[x]-1, -val);
        }
        else
        {
            ll x;
            cin >> x;
            cout << T[Level[x] % 2].query(Intime[x], Intime[x]) << endl;
        }


    }


}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;

    //cin >> tt;

    while (tt--)
    {

        Solve();
    }

    return 0;

}


//https://codeforces.com/contest/383/problem/C