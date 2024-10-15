
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include<algorithm>
#define fastio         \
    cout.tie(nullptr); \
    cin.tie(nullptr);  \
    ios_base::sync_with_stdio(false)
using namespace std;


long double scanline(double l, double r, double st, vector<double>&a){
    double mid = (l+r)/2;
    vector<pair<double, int> > ans;
    for(int i = 0; i < 2; i++){
        if(mid > a[2*i] - 100 && mid < a[2*i] + 100){
            ans.push_back({(sqrt(10000 - (a[2*i] - mid)*(a[2*i] - mid)) + a[2*i + 1])*st, 1});
            ans.push_back({(- sqrt(10000 - (a[2*i] - mid)*(a[2*i] - mid)) + a[2*i + 1])*st, -1});
        }
        if(mid > a[2*i] - 70 && mid < a[2*i] - 10){
            ans.push_back({(sqrt(900 - (a[2*i] - 40 - mid)*(a[2*i] - 40 - mid)) + a[2*i + 1] + 30)*st, -1});
            ans.push_back({(- sqrt(900- (a[2*i] - 40 - mid)*(a[2*i] - 40 - mid)) + a[2*i + 1] + 30)*st, 1});
        }
        if(mid > a[2*i] - 60 && mid < a[2*i] + 60){
            ans.push_back({(- sqrt(3600 - (a[2*i]- mid)*(a[2*i]- mid)) + a[2*i + 1] - 20)*st, 1 });
            ans.push_back({(a[2*i + 1] - 20)*st, -1});
        }
        if(mid > a[2*i] + 10 && mid < a[2*i] + 70){
            ans.push_back({(sqrt(900 - (-a[2*i] - 40 + mid)*(-a[2*i] - 40 + mid)) + a[2*i + 1] + 30)*st, -1});
            ans.push_back({(-sqrt(900 - (-a[2*i] - 40 + mid)*(-a[2*i] - 40 + mid)) + a[2*i + 1] + 30)*st, 1});
        }
    }
    sort(ans.begin(), ans.end());
    int cnt = 0;
    double res = 0;
    int ind = 0;
    for(int i = 0; i < ans.size(); i++){
        if(cnt == 0){
            ind = i;
        }
        cnt += ans[i].second;
        if(cnt == 0) res += ans[i].first - ans[ind].first;
    }
    return res;
}



int main() {
    fastio;
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    vector<double> a = {ax, ay, bx, by};
    double iter = 0.0001;
    double res = 0;
    for (double it = -1100.0; it <  1100.0; it+=iter) {
        res += scanline(it, it + iter, iter, a);
    }
    cout << fixed << setprecision(6) << res;
}


/* Wed Nov 08 2023 23:45:41 GMT+0300 (Moscow Standard Time) */
