#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         500002
typedef long long ll;
using namespace std;


int n, m;
vector<pair<ll, ll> > v[MAX];
int take[MAX];

void Solve()
{

    cin >> n >> m;

    for (int i = 0 ; i < m ; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({w, y});
        v[y].push_back({w, x});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll > >, greater<pair<ll, ll > > > pq;
    ll ans = 0;
    pq.push({0, 1});

    while (pq.size())
    {

        pair<ll, ll>p = pq.top();
        pq.pop();

        if (take[p.s])
            continue;

        ans += p.f;
        take[p.s] = 1;

        for (auto i : v[p.s])
        {
            if (!take[i.s])
                pq.push({i});
        }

    }

    cout << ans << endl;



}

int main()
{



    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    //   cin>>tt;
    while (tt--)
    {
        Solve();
    }

    return 0;

}
