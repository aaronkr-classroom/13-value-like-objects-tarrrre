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

// 입력 연산자 
istream& operator>>(istream& is, Str& s) {
	// 기존의 값 제거 
	if (s.value != 0)
		delete[] s.value;
	char c;

	// 조건을 판별하는 것 외의 동작은 없음 
	while (is.get(c) && std::isspace(c)); 

	// 읽을 문자가 남아 있다면 다음 공백 문자에 
	// 도달할 때까지 문자를 읽음.
	if (is) {
		do s += c; //컴파일 오류! data는 private임.
		while (is.get(c) && !isspace(c));

		// 공백을 읽었다면 다시 스트림에 남겨둠.
		if (is)
			is.unget();
	}
	return is;
}

istream& getline( istream& is, Str& s) {
	// 다음줄 까지 일기 
	char c; 
	while (is.get(c) && c != '\n')
		s += c;

	return is;
}

// 입력 연산자 


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

// 비교 연산자 추가
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