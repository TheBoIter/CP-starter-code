// Binary Search; here because off-by-one errors are too common
// O(lg n) time
ll lo = 1;
ll hi = 1e12+7;
while(lo < hi){
  ll mid = (lo+hi+1)/2;
  if(check(n, k, m, mid)){
    lo = mid;
  }
  else hi = mid-1;
}
