// Binary Exponentiation; computes a^b (mod m) quickly 
// Common mods: 998244353 on CF, 1e9+7 everywhere else
// O(lg b) time, O(1) memory
ll binexp(ll b, ll e){
  ll res = 1;
  while(e > 0){
    if(e % 2 == 1){
      res = res * b % mod;
    }
    b = b * b % mod;
    e /= 2;
  }
  return res;
}
