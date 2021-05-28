
#ifndef LCS_H
#define LCS_H


size_t getLinearPosition(const size_t& i, const size_t& j, const size_t& r, const size_t& c) {
	if(i >= r || j >= c) throw;
	return i*c + j;
}

void strReverse(std::string& str) {
	size_t l = 0, r = str.size()-1;
	while(l < r) std::swap(str[l++],str[r--]);
	return;
}

#define P(x,y,r,c) getLinearPosition(x,y,r,c)

std::string lcs(const std::string& v1, const std::string& v2) {
	const size_t r{v1.size() + 1};
	const size_t c{v2.size() + 1};
	std::string res = "";
	size_t i = 0, j = 0;
	size_t* mat = new size_t[r*c];

	while(i < r) mat[P(i++,j,r,c)] = 0;
	i = 0;
	while(j < c) mat[P(i,j++,r,c)] = 0;
	j = 0;

	while(i < r-1) {
		j = 0;
		while(j < c-1) {
			if(v1[i] == v2[j]) mat[P(i+1,j+1,r,c)] = mat[P(i,j,r,c)]+1;
			else mat[P(i+1,j+1,r,c)] = std::max(mat[P(i+1,j,r,c)], mat[P(i,j+1,r,c)]);
			++j %= c;
		}
		++i %= r;
	}

	// std::cout << "- -";
	// for(size_t k = 0; k < c; ++k) std::cout << ' ' << v2[k];
	// std::cout << '\n';
	// std::cout << "- ";
	// for(size_t k = 0; k < r*c; ++k) {
	// 	std::cout << mat[k] << ' ';
	// 	if((k+1) % c == 0) std::cout << '\n' << v1[((k+1)/c)-1] << ' ';
	// }

	while(i > 0 && j > 0) {
		if(mat[P(i,j,r,c)] > mat[P(i-1,j-1,r,c)]) {
			--i,--j;
			res += v1[i];
		} else {
			--i;
		}
	}
	strReverse(res);
	return res;
}


#endif






//
