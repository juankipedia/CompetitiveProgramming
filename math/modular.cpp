struct mint {
	static ll& mod(){
		static ll MOD = 0;
		return MOD;
	}
	static void set_mod(const ll p){ mod() = p; }
	ll value;
	mint(ll v = 0) { value = v % mod(); if (value < 0) value += mod();}
	mint(ll a, ll b) : value(0){ *this += a; *this /= b;}
	mint& operator+=(mint const& b) {value += b.value; if (value >= mod()) value -= mod(); return *this;}
	mint& operator-=(mint const& b) {value -= b.value; if (value < 0) value += mod();return *this;}
	mint& operator*=(mint const& b) {value = (ll)value * b.value % mod();return *this;}
	friend mint powmod(mint a, ll e) {
		mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
	}
	friend mint inv(mint a) { return powmod(a, mod() - 2); }
	mint& operator/=(mint const& b) { return *this *= inv(b); }
	friend mint operator+(mint a, mint const b) { return a += b; }
	friend mint operator-(mint a, mint const b) { return a -= b; }
	friend mint operator-(mint const a) { return 0 - a; }
	friend mint operator*(mint a, mint const b) { return a *= b; }
	friend mint operator/(mint a, mint const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.value;}
	friend bool operator==(mint const& a, mint const& b) {return a.value == b.value;}
	friend bool operator!=(mint const& a, mint const& b) {return a.value != b.value;}
};


const ll mod = 1e9 + 7;
template <ll MOD=mod> struct Modular {
	ll value;
	static const ll MOD_value = MOD;
	Modular(ll v = 0) { value = v % MOD; if (value < 0) value += MOD;}
	Modular(ll a, ll b) : value(0){ *this += a; *this /= b;}
	Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
	Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
	Modular& operator*=(Modular const& b) {value = (ll)value * b.value % MOD;return *this;}
	friend Modular powmod(Modular a, ll e) {
		Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
	}
	friend Modular inv(Modular a) { return powmod(a, MOD - 2); }
	Modular& operator/=(Modular const& b) { return *this *= inv(b); }
	friend Modular operator+(Modular a, Modular const b) { return a += b; }
	friend Modular operator-(Modular a, Modular const b) { return a -= b; }
	friend Modular operator-(Modular const a) { return 0 - a; }
	friend Modular operator*(Modular a, Modular const b) { return a *= b; }
	friend Modular operator/(Modular a, Modular const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
	friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
	friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
}; typedef Modular<> mi;
