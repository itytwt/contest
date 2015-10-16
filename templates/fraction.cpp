// fraction

struct frac {
	ll a, b;

	frac() {
		a = 0, b = 1;
	}

	frac(ll _a, ll _b = ll(1)) {
		if (_b) {
			ll g = __gcd(_a, _b);
			a = _a / g, b = _b / g;
			if (b < 0) b = -b, a = -a;
		}
		else
			a = (_a > 0 ? 1 : -1), b = 0;
	}

	frac operator - () const {
		return frac(-(this->a), this->b);
	}

	frac operator + (const frac &that) const {
		return frac(this->a * that.b + this->b * that.a, this->b * that.b);
	}

	frac & operator += (const frac &that) {
		frac tmp = (*this) + that;
		tmp.swap(*this);
		return *this;
	}

	frac operator - (const frac &that) const {
		return (*this) + (-that);
	}

	frac & operator -= (const frac &that) {
		frac tmp = (*this) - that;
		tmp.swap(*this);
		return *this;
	}

	frac operator * (const frac &that) const {
		return frac(this->a * that.a, this->b * that.b);
	}

	frac & operator *= (const frac &that) {
		frac tmp = (*this) * that;
		tmp.swap(*this);
		return *this;
	}

	frac operator / (const frac &that) const {
		return frac(this->a * that.b, this->b * that.a);
	}

	frac & operator /= (const frac &that) {
		frac tmp = (*this) / that;
		tmp.swap(*this);
		return *this;
	}

	bool operator < (const frac &that) const {
		if ((this->a ^ that.a) < 0)
			return this->a < 0;
		else
			return this->a * that.b < this->b * that.a;
	}

	bool operator == (const frac &that) const {
		return !(*this < that) && !(that < *this);
	}

	void swap(frac &that) {
		std::swap(this->a, that.a);
		std::swap(this->b, that.b);
	}

	friend ostream & operator << (ostream &os, const frac &k) {
		os << k.a;
		if (k.b > 1) os << "/" << k.b;
		return os;
	}
};
