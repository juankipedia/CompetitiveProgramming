const lli mod = 1e9 + 7;
template <lli MOD=mod> struct Modular {
	lli value;
	static const lli MOD_value = MOD;
	Modular(lli v = 0) { value = v % MOD; if (value < 0) value += MOD;}
	Modular(lli a, lli b) : value(0){ *this += a; *this /= b;}
	Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
	Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
	Modular& operator*=(Modular const& b) {value = (lli)value * b.value % MOD;return *this;}
	friend Modular powmod(Modular a, lli e) {
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