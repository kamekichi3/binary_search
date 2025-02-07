#include <stdio.h>

int n;
int k;
int A[100000];

int bag(int m){
    int j, bag_count=0;
    for (j = 0; j < n; j++) {
        bag_count = bag_count + (A[j] + m - 1) / m; //切り上げ
    }
    return (long long int) bag_count <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;               //x:取りうる最小1 = 返り値0
  ub = 1000000000;      //x:取りうる最大10^9 = 返り値1

  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (bag(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);       //上から抑える
  return 0;
}
