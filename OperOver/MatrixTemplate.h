#pragma once

#include <iostream>

using namespace std;

/**
* define a generic matrix class
*/

class ComplexNumber {
public:
	ComplexNumber(int realIn = defaultReal, int imagIn = defaultImag);
	ComplexNumber(const ComplexNumber& src);
	~ComplexNumber();

	//getters/setters
	int getReal() const;
	int getImag() const;
	void setReal(int in);
	void setImag(int in);

	//operator overloads
	ComplexNumber& operator=(const ComplexNumber& rhs);
	friend ostream& operator<<(ostream& ostr, const ComplexNumber& mtx);
	friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
	friend ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b);
	friend bool operator==(const ComplexNumber& a, const ComplexNumber& b);
	friend bool operator!=(const ComplexNumber& a, const ComplexNumber& b);

	//default statics
	static const int defaultReal = 1;
	static const int defaultImag = 0;

private:
	//data members
	int realNum;
	int imagNum;
};

//constructor/deconstructor
ComplexNumber::ComplexNumber(int realIn, int imagIn) :
	realNum(realIn), imagNum(imagIn) { ; }
ComplexNumber::ComplexNumber(const ComplexNumber& src) :
	realNum(src.realNum), imagNum(src.imagNum) { ; }
ComplexNumber::~ComplexNumber() { ; }

//basic methods
int ComplexNumber::getReal() const {
	return realNum;
}
int ComplexNumber::getImag() const {
	return imagNum;
}
void ComplexNumber::setReal(int in) {
	realNum = in;
}
void ComplexNumber::setImag(int in) {
	imagNum = in;
}

//operator overloads
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs) {
	realNum = rhs.realNum;
	imagNum = rhs.imagNum;
	return *this;
}
ostream& operator<<(ostream& ostr, const ComplexNumber& compNum) {
	ostr << compNum.realNum << " + " << compNum.imagNum << "i";
	return ostr;
}
ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result(a.realNum + b.realNum, a.imagNum + b.imagNum);
	return result;
}
ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result(a.realNum - b.realNum, a.imagNum - b.imagNum);
	return result;
}
bool operator==(const ComplexNumber& a, const ComplexNumber& b) {
	if (a.realNum != b.realNum || a.imagNum != b.imagNum) {
		return false;
	}
	return true;
}
bool operator!=(const ComplexNumber& a, const ComplexNumber& b) {
	return !(a==b);
}


template <typename T>
class Matrix
{
public:
	Matrix(int x = default_x, int y = default_y);
	Matrix(const Matrix<T>& src);
	~Matrix();
	// overloaded operators on class
	Matrix<T>& operator=(const Matrix<T>& rhs);
	template <typename E>
	friend ostream& operator<<(ostream& ostr, const Matrix<E>& mtx);
	template <typename E>
	friend Matrix<E> operator*(const Matrix<E>& a, const Matrix<E>& b);
	template <typename E>
	friend Matrix<E> operator+(const Matrix<E>& a, const Matrix<E>& b);
	template <typename E>
	friend Matrix<E> operator-(const Matrix<E>& a, const Matrix<E>& b);
	template <typename E>
	friend bool operator==(const Matrix<E>& a, const Matrix<E>& b);
	
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	T get_element(int x, int y) const;
	void set_element(int x, int y, T elem);
	// constant elements
	static const int default_x = 3;
	static const int default_y = 3;
protected:
	T** cells;
	int x_size;
	int y_size;
};

template <typename T>
Matrix<T>::Matrix(int x, int y) :
	x_size(x), y_size(y) {
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i) {
		cells[i] = new T[y_size];
		memset(cells[i], 0, (y_size * sizeof(T)));
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& src) :
	x_size(src.x_size), y_size(src.y_size)
{
	cells = new T*[x_size];
	for (int i = 0; i < x_size; ++i)
	{
		cells[i] = new T[y_size];
		memcpy_s(cells[i], (y_size * sizeof(T)), src.cells[i], (y_size * sizeof(T)));
		//memcpy(cells[i], src.cells[i], y_size * sizeof(T)); // same but less safe than memcpy_s
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	if (this == &rhs) return (*this);

	// release old memory
	for (int i = 0; i < x_size; ++i) {
		delete[] cells[i];
	}
	delete[] cells;

	// allocate new memory
	cells = new T*[rhs.x_size];
	for (int i = 0; i < rhs.x_size; ++i) {
		cells[i] = new T[rhs.y_size];
		memset(cells[i], 0, (rhs.y_size * sizeof(T)));
	}

	// copy values
	for (int i = 0; i < rhs.x_size; ++i) {
		for (int j = 0; j < rhs.y_size; ++j) {
			cells[i][j] = rhs.cells[i][j];
		}
	}
	return *this;
}

// friend functions

template <typename E>
ostream& operator<<(ostream& ostr, const Matrix<E>& mtx) {
	for (int i = 0; i < mtx.x_size; ++i) {
		for (int j = 0; j < mtx.y_size; ++j) {
			ostr << mtx.cells[j][i] << ", ";
		}
		ostr << "\n";
	}
	ostr << "\n";
	return ostr;
}

template <typename E>
Matrix<E> operator*(const Matrix<E>& a, const Matrix<E>& b) {
	Matrix<E> result(a.x_size, b.y_size);
	for (int i = 0; i < a.x_size; ++i) {
		for (int j = 0; j < a.x_size; ++j) {
			for (int k = 0; k < a.x_size; ++k) {
				result.cells[i][j] += (a.cells[k][j] * b.cells[i][k]);
			}
		}
	}
	return result;
}

template <typename E>
Matrix<E> operator+(const Matrix<E>& a, const Matrix<E>& b) {
	Matrix<E> result(a.x_size, b.y_size);
	for (int i = 0; i < a.x_size; ++i) {
		for (int j = 0; j < a.y_size; ++j) {
			result.cells[i][j] = a.cells[i][j] + b.cells[i][j];
		}
	}
	return result;
}

template <typename E>
Matrix<E> operator-(const Matrix<E>& a, const Matrix<E>& b) {
	Matrix<E> result(a.x_size, b.y_size);
	for (int i = 0; i < a.x_size; ++i) {
		for (int j = 0; j < a.y_size; ++j) {
			result.cells[i][j] = a.cells[i][j] - b.cells[i][j];
		}
	}
	return result;
}

template <typename E>
bool operator==(const Matrix<E>& a, const Matrix<E>& b) {
	for (int i = 0; i < a.x_size; ++i) {
		for (int j = 0; j < a.y_size; ++j) {
			if (a.cells[i][j] != b.cells[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template <typename T>
T Matrix<T>::get_element(int x, int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::set_element(int x, int y, T elem) {
	cells[x][y] = elem;
}


