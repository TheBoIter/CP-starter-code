// Compute Bezout coefficients for CRT, solving system of modular equations
// O(lg(max(a,b))) time, O(1) memory
pair<ll,ll> bezout(ll a, ll b){
  vector<ll> r, s, t;
  r.push_back(a); s.push_back(1ll); t.push_back(0ll);
  r.push_back(b); s.push_back(0ll); t.push_back(1ll);
  while(r[r.size()-1] != 0){
    ll q = r[r.size()-2]/r[r.size()-1];
    r.push_back(r[r.size()-2]-q*r[r.size()-1]);
    s.push_back(s[s.size()-2]-q*s[s.size()-1]);
    t.push_back(t[t.size()-2]-q*t[t.size()-1]);
  }
  return {s[s.size()-2], t[t.size()-2]};
}
