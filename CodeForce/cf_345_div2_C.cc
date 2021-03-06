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
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x) cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)         cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n"
typedef  long long int LL;
const int INF = ~0U>>1;



const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
	if (fabs(x) < eps)return 0;
	if (x < 0)return -1;
	else return 1;
}

//1.1 Point 定义

struct Point
{
	LL x,y;
	Point() {}
	Point(LL x,LL y):x(x),y(y){}


	bool operator ==(const Point & b)const
	{
		return x==b.x && y==b.y;
	}


//*输入
    void in()
    {
        scanf("%I64d%I64d",&x,&y);
    }
//*输出
    void out()
    {
        printf("Point:(%I64d,%I64d)\n",x,y);
    }
};

bool cmp1(Point a,Point b) {return a.x < b.x;};
bool cmp2(Point a,Point b) {return a.y < b.y;};
bool cmp3(Point a,Point b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

LL Comb(LL x , LL y)
{
    LL u=1,v=1,len;
    if(y==0||x==y) return 1;
    if(y==1)  return x;
    if(x < y ) return 0;

    if(y > x/2) y=len = x-y;
    else len = y;

    while(len--)
    {
        u*= x--;
        v*= y--;
    }
    return  (LL)(u/v);
}


vector<Point> p;
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    while(1 == scanf("%d",&n))
    {
        p.clear();
        LL cnt = 0;
        LL res = 0;
        for(int i = 0 ; i < n ; i++)
        {
            LL x,y;
            scanf("%I64d%I64d",&x,&y);
            p.push_back(Point(x,y));
        }
        sort(p.begin(),p.end(),cmp1);
        for(int i = 0 ; i < n-1 ; i++)
            if(p[i].x == p[i+1].x)  cnt++;
            else if(p[i].x == p[i-1].x)
            {
                cnt++;
                res += Comb(cnt,2);
                cnt = 0;
            }
        if(p[n-1].x == p[n-2].x)    cnt++;
        res += Comb(cnt,2);

        cnt = 0;
        //Whats(res);
        sort(p.begin(),p.end(),cmp2);
        for(int i = 0 ; i < n-1; i++)
            if(p[i].y == p[i+1].y)  cnt++;
            else if(p[i].y == p[i-1].y)
            {
                cnt++;
                res += Comb(cnt,2);
                cnt = 0;
            }

        if(p[n-1].y == p[n-2].y)    cnt++;
        res += Comb(cnt,2);

        cnt = 0;
        //Whats(res);
        sort(p.begin(),p.end(),cmp3);
        LL tt = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if((p[i].x == p[i+1].x )&&( p[i].y == p[i+1].y))
                cnt++;
            else if((p[i].x == p[i-1].x )&&( p[i].y == p[i-1].y))
            {
                cnt++;
                tt += Comb(cnt,2);
                cnt = 0;
            }
        }

        if((p[n-2].x == p[n-1].x )&&( p[n-2].y == p[n-2].y))
            cnt++;
        tt += Comb(cnt,2);

        //Whats(tt);
        res -= tt;
        printf("%I64d\n",res);
    }
    return 0;
}
