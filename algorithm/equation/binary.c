// バイナリサーチで方程式を解くプログラム
// この方法じゃ不連続な数やリニア変化じゃないようなデータには対応できない

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 解析したい関数
double func(double x) {
  return x*x*x*x*x
  - 10.0 *x*x*x*x
  + 25.0 *x*x*x
  + 40.0 *x*x
  + 200.0 *x - 500.0;
}

// バイナリサーチで与えられた関数を解く
double BinarySearch() {
  double left, mid, right;
  double epsilon; //double型で発声する誤差を許容するための値

  epsilon = 0.001;

  //解が確実に存在する領域を指定
  left = -50.0;
  right = 100.0;

  // 範囲を絞りこむ
  while(fabs(right - left) > epsilon && fabs(func(left)) > epsilon) {

    //fabs()　中身の絶対値を取得する

    mid = (left + right) / 2.0;

    // func(left)とfunc(mid)が同符号なら
    if(func(left) * func(mid) >= 0.0) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return left;
}

int main() {
  double b;
  b = BinarySearch();
  printf("方程式の解は%lf\n その時のfunc(x)は%lfです", d, func(d));
  return 0;
}
