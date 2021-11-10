#include "line.h"
#include"stdio.h"
#include"iostream"
using namespace std;
template <typename T>
line<T>::line() : _data(nullptr), _size(0) {}

template <class T>
line<T>::line(const T* data, const size_t size)
{
	_size = size;
	_data = new T[_size + 1];
	for (size_t i = 0; i < _size; i++)
		_data[i] = data[i];
}

template <class T>
line<T>::line(const size_t size)
{
	_size = size;
	_data = new T[_size + 1];
}

template <class T>
line<T>::line(const line& s)
{
	_size = s._size;
	_data = new T[_size + 1];
	for (size_t i = 0; i < _size + 1; i++)
		_data[i] = s._data[i];
}

template <class T>
line<T>::~line()
{
	delete[]_data;
}

template <class T>
size_t line<T>::len()const
{
	return _size;
}

template <class T>
bool line<T>::operator==(const line& s)const
{
	if (_data && s._data)
		if (typeid(_data) == typeid(s._data) && _size == s._size)
		{
			size_t i = 0;
			while (_data[i] == s._data[i])
			{
				i++;
				if (i == _size)
					return 1;
			}
		}
		else
			return 0;
	else
		if (_data == s._data)
			return 1;
		else
			return 0;
}
template <class T>
bool line<T>::operator!=(const line<T>& s)const
{
	return !(*this == s);
}

template <class T>
line<T>& line<T>::operator=(const line& s)
{
	if (this->_data == s._data) return *this;
	line <T> tmp(s);
	std::swap(this->_data, tmp._data);
	std::swap(this->_size, tmp._size);
	return *this;
}

template <class T>
T& line<T>::operator[](const size_t index)
{
	if (index >= _size)
		throw"Invalid index\n";
	return _data[index];
}

template <class T>
T line<T>::operator[](const size_t index)const
{
	if (index >= _size)
		throw"Invalid index\n";
	return _data[index];
}

template <class T>
line<T> line<T>::operator+(const line& s)const
{
	if (!_size)
		return s;
	if (!s._size)
		return *this;
	line res(_size + s._size);
	for (size_t i = 0; i < _size; i++)
		res._data[i] = _data[i];
	for (size_t j = 0; j < s._size + 1; j++)
		res._data[j + _size] = s._data[j];
	return res;
}

template <class T>
line<T> line<T>::operator*(const size_t pow)
{
	if (!_size)
		return *this;
	if (pow <= 0)
		throw"Invalid ratio\n";
	line res(_size * pow);
	for (size_t i = 0; i < pow; i++)
		for (size_t j = 0; j < (i == pow - 1 ? _size + 1 : _size); j++)
			res._data[j + i * _size] = _data[j];
	return res;
}

template <class T>
line<T> line<T>::substring(const size_t index, const size_t length)const
{
	if (!_size)
		return *this;
	if (index < 0 || index >= _size)
		throw"Invalid index\n";
	if (length <= 0)
		throw"Invalid length\n";
	line res(length);
	for (int i = 0; i < length + 1; i++)
		if (_data)
			res._data[i] = _data[index + i];
	res._data[length] = 0;
	return res;
}
template <typename T>
line<T> line<T>::operator() (const size_t start, const size_t stop) const 
{
	if (!_size)
		return *this;
	if (start >= _size)
		throw"Invalid index(start)\n";
	if (stop >= _size)
		throw"Invalid index(stop)\n";
	if (stop <= start)
		throw"Conflict index\n";
	return substring(start, stop - start + 1);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const line<T>& s)
{
	for (size_t i = 0; i < s.len(); ++i)
	{
		out << s[i];
	}
	return out;
}

template<typename T>
line<T> operator*(const size_t power, const line<T>& s)
{
	return s * pow;
}

