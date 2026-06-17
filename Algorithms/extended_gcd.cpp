#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// naive
inline ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
inline ll gcd_iter(ll a, ll b) {
    while (b != 0) {
        tie(a, b) = pair{b, a % b};
    }
    return a;
}
// recursive, returns r, s, t  where r = sa + tb = gcd(a,b)
inline tuple<ll, ll, ll> ext_gcd(ll a, ll b) {
    if (b == 0) return {a, 1, 0};
    auto [r, s0, t0] = ext_gcd(b, a % b);
    ll s = t0;
    ll t = s0 - (a/b) * t0;
    return {r, s, t};
}
// iterative, returns r, s, t  where r = sa + tb = gcd(a,b)
inline tuple<ll,ll,ll> ext_gcd_iter(ll a, ll b) {
    ll s = 1, t = 0;
    ll s1 = 0, t1 = 1;
    while (b != 0) {
        ll q = a/b;
        tie(s1,s) = pair{s, s1 - s * q};
        tie(t1,t) = pair{t, t1 - t * q};
        tie(a, b) = pair{b, a % b};
    }
    ll r = a;
    return {r, s, t};
}
