#include <cctype>
#include <iostream>
#include <iterator>
#include <cstring>

#include "Str.h"

using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}

// �Է� ������ 
istream& operator>>(istream& is, Str& s) {
	// ������ �� ���� 
	if (s.value != 0)
		delete[] s.value;
	char c;

	// ������ �Ǻ��ϴ� �� ���� ������ ���� 
	while (is.get(c) && std::isspace(c)); 

	// ���� ���ڰ� ���� �ִٸ� ���� ���� ���ڿ� 
	// ������ ������ ���ڸ� ����.
	if (is) {
		do s += c; //������ ����! data�� private��.
		while (is.get(c) && !isspace(c));

		// ������ �о��ٸ� �ٽ� ��Ʈ���� ���ܵ�.
		if (is)
			is.unget();
	}
	return is;
}

istream& getline( istream& is, Str& s) {
	// ������ ���� �ϱ� 
	char c; 
	while (is.get(c) && c != '\n')
		s += c;

	return is;
}

// �Է� ������ 


Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}
// Q5
Str operator+(const Str& s, const char* t){
	Str r = s;
	r += t;
	return r;
}
// Q11
Str operator+(const char* t, const Str& s){
	Str r(t);
	r += s;
	return r;
}

// �� ������ �߰�
bool operator<(const Str& lhs, const Str& rhs) { //Q3
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}//Q3
bool operator>(const Str& lhs, const Str& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;

} //Q3
bool operator<=(const Str& lhs, const Str& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
} //Q3
bool operator>=(const Str& lhs, const Str& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
} //Q3
bool operator==(const Str& lhs, const Str& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
} //Q4
bool operator!=(const Str& lhs, const Str& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
} //Q4