#include "iostream"
#include "iomanip"

using namespace std;
long double a_1,b_1,c,d,e;
const long double eps = 1e-16;

long double f(long double x){
    return (1/(a_1*x*x*x*x + b_1*x*x*x + c*x*x + d*x + e));
}
long double simpsonIntegral(long double a, long double b) {
    long double simpson_integral = (b-a)/6.0*(f(a) + 4.0*f(0.5*(a+b)) + f(b));
    return simpson_integral;
}
long double binpoisk(long double l, long double r){
    long double m = (l+r)/2;
    long double ans = simpsonIntegral(l,r);
    long double left = simpsonIntegral(l, m);
    long double right = simpsonIntegral(m, r);
    if(abs(left+right - ans) < eps) return ans;
    else {
       return  binpoisk(l,m) + binpoisk(m,r);
    }
}
int main(){
    cin >> e >> d >> c >> b_1 >> a_1;
    cout << fixed << setprecision(10) << binpoisk(-1e4, 1e4);
}
