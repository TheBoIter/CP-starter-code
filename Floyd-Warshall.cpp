// All pairs shortest paths (Floyd-Warshall algorithm)
// O(V^3+E) time, O(V^2) memory
// POSITIVE EDGE WEIGHTS ONLY!
ll n, m, q; cin >> n >> m >> q;
vector<pair<ll,pair<ll,ll> > > edges;
for(ll i = 0; i < m; i++){
  ll a, b, c; cin >> a >> b >> c;
  edges.push_back({c, {a, b}});
}
ll dist[n+1][n+1];
for(ll i = 1; i <= n; i++){
  for(ll j = 1; j <= n; j++){
    dist[i][j] = inf;
  }
  dist[i][i] = 0;
}
for(ll i = 0; i < m; i++){
  dist[edges[i].second.first][edges[i].second.second] = min(dist[edges[i].second.first][edges[i].second.second], edges[i].first);
  dist[edges[i].second.second][edges[i].second.first] = min(dist[edges[i].second.second][edges[i].second.first], edges[i].first);
}

for(ll k = 1; k <= n; k++){
  for(ll i = 1; i <= n; i++){
    for(ll j = 1; j <= n; j++){
      if(dist[k][i] != inf && dist[k][j] != inf) dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);
    }
  }
}
