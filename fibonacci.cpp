#include <iostream>

typedef long long int ll;

struct matrix2by2 {
  ll _a, _b, _c, _d;

  matrix2by2() {
  }

  matrix2by2(ll a, ll b, ll c, ll d) {
    _a = a;
    _b = b;
    _c = c;
    _d = d;
  }

};

matrix2by2 multiply(matrix2by2 m1, matrix2by2 m2) {
  ll a = m1._a * m2._a + m1._b * m2._c,
     b = m1._a * m2._b + m1._b * m2._d,
     c = m1._c * m2._a + m1._d * m2._c,
     d = m1._c * m2._b + m1._d * m2._d;
  return matrix2by2(a, b, c, d);
}

matrix2by2 power(matrix2by2 m, int n) {
  matrix2by2 result(1, 0, 0, 1); // identity matrix
  while(n) {
    if(n & 1) {
      result = multiply(result, m);
    }
    n >>= 1;
    m = multiply(m, m);
  }
  return result;
}

int main() {
  matrix2by2 m1(1, 1, 1, 0), m2;
  int n;
  std::cin >> n;
  m2 = power(m1, n);
  std::cout << m2._b << '\n';
}
