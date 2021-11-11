#pragma once
#include"iostream"
using namespace std;
template <class T>
class line
{
	T* _data;
	size_t _size;
public:
	line();
	line(const T* data, const size_t size);
	line(const size_t size);
	line(const line& s);
	~line();
	size_t len()const;
	bool operator==(const line& s)const;
	bool operator!=(const line& s)const;
	line& operator=(const line& s);
	T& operator [](const size_t index);
	T operator [](const size_t index)const;
	line operator+(const line& s)const;
	line operator* (const size_t power);
	line substring(const size_t index, const size_t length)const;
	line operator() (const size_t start, const size_t stop) const;
	line operator() (const size_t start) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const line<T>& s);

template <typename T>
line<T> operator* (const size_t power, const line<T>& s);