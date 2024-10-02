/*
#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
//#define mod      10000007
#define pi       acos(-1.0)
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
int x,y;
int egcd(int a,int b,int *x,int *y)
{
	 if (b==0) {
      *x = 1;
      *y = 0;
      return a;
   }
   int x1, y1;
   int gcd = egcd(b,a%b,&x1,&y1);
   *x =y1;
   *y =x1-y1*(a/b);
   return gcd;
}
int man()
{
	  int a,b;
	  cin>>a>>b;

	  cout<<x<<" "<<y<<" "<<egcd(a,b,&x,&y);

       return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int x, y;
int gcdExtended(int a, int b, int *x, int *y) {
   if (b==0) {
      *x = 1;
      *y = 0;
      return a;
   }
   int x1, y1;
   int gcd = gcdExtended(b,a%b,&x1,&y1);
   *x =y1;
   *y =x1-y1*(a/b);
   return gcd;
}
int main() {
   
   int a = 50, b = 10;
   cout<<"gcd "<<gcdExtended(a, b, &x, &y)<<endl;;
   cout<<x<<" " <<y<<endl;
   return 0;
}
