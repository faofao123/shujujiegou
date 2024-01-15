//
// Created by fyz on 2023/12/1.
//网上搜的食物链的改的把d=1/2去掉剩下的就对了？离谱完全不知道自己写的哪里不对
//知道自己哪里出问题了，不能随意的确定两个未初使化的出拳状态；但是还是看不懂解析
#include <iostream>
using namespace std;
const int N = 50010;
int n, m;
int p[N], d[N];
int find(int x)
{
    if (p[x] != x)
    {
        int t=find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    int res = 0;
    while (m -- )
    {
        int  x, y;
        scanf("%d%d",  &x, &y);
        if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y);

            if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
            else if (px != py)
            {
                p[px] = py;
                d[px] = d[y] + 1 - d[x];
            }
        }
    }

    printf("%d\n", res);
    return 0;
}


/*#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, int> f;


int main() {
    int n,k,count=0;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        if(a>n||b>n)count++;
        else if(a==b)count++;
        else if(!f.count(a)&&!f.count(b)){
            f[a]=2;
            f[b]=1;
        }
        else if(f.count(a)&&f.count(b)){
            if(f[a]==3&&f[b]==1)count++;
            else if(f[a]==f[b])count++;
            else if(f[a]<f[b])count++;
        }
        else if(f.count(a)&&!f.count(b)){
            if(f[a]==1)f[b]=3;
            else if(f[a]==2)f[b]=1;
            else f[b]=2;
        }
        else {
            if(f[b]==1)f[a]=2;
            else if(f[b]==2)f[a]=3;
            else f[a]=1;
        }
    }
    cout << count <<endl;
    return 0;
}
*/