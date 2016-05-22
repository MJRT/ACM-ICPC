//MJRT
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//////////////////////
#include<iostream>
#include<algorithm>
#include<string>
#include <iterator>
#include<sstream>
#include<functional>
#include<numeric>
///////////////////////
#include<vector>
#include<map>
#include <stack>
#include<queue>
#include<set>
#include <bitset>
#include <list>
///////////////////////
//#include<ext/pb_ds/priority_queue.hpp> //pd_bs库,hdu&&poj不支持
using namespace std;
#define lowbit(x) ((x)&(-x))
static int INDEX = 0,BUGs = 0;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x)           cout << "{ "<< (#x) << " }" << " is " << "*** "<< (x) << " ***" << "  index:" << INDEX++ <<endl
#define Whats2(x,y)        cout << "{ "<< "("<< #x << "," << #y << ")" << " }" << " is " << "*** "<< "("<< (x) << "," << (y) << ")" << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)       {cout << #x << ": "; for(int i = (s) ; i < (s)+(l) ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)    {cout << #x << ": " << (l)-(s) << "*" <<(h)-(s) <<"\n"; for(int j = (s) ; j < (s)+(h) ; j++){for(int i = (s) ; i < (s)+(l) ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}

typedef  long long int LL;
const int INF = 0x3f3f3f3f;

const int  N = 5 + 10000;

int ans[N],tmp1[N*2],tmp2[N*2],a[N],b[N];
//bool vis[N];

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int n;
    while(1 == scanf("%d",&n))
    {
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i= 0 ; i < n ; i++)
        {
            memset(tmp1,0,sizeof(tmp1));
            memset(tmp2,0,sizeof(tmp2));
            ans[i] = 0;
            int rr = 0;
            for(int j = i ; j < n ; j++)
            {
                if(a[j] > a[i])                rr++;
                else if(a[j] < a[i])           rr--;

                if((j-i)&1) tmp1[rr+10000]++;
                else        tmp2[rr+10000]++;
            }

            int ll = 0;
            for(int j = i ; j >= 0; j--)
            {
                if(a[j] > a[i])                 ll++;
                else if(a[j] < a[i])            ll--;

                if((j-i)&1) ans[i] += tmp1[10000-ll];
                else        ans[i] += tmp2[10000-ll];
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        puts("");

    }

    return 0;
}

