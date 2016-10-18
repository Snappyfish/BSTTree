#include <iostream>
#include "MatrixTemplate.h"

using namespace std;


int main() {
	Matrix<int> mtx1;
	mtx1.set_element(0, 0, 1);
	mtx1.set_element(1, 1, 4);
	mtx1.set_element(2, 2, 6);
	cout << "matrix 1:\n" << mtx1;

	Matrix<int> mtx2;
	mtx2.set_element(0, 0, 1);
	mtx2.set_element(1, 1, 4);
	mtx2.set_element(2, 2, 2);

	cout << "matrix 2:\n" << mtx2;

	Matrix<int> mtx3;
	mtx3 = mtx2;
	cout << "matrix 3 assigned from matrix 2:\n" << mtx3;

	Matrix<int> product = (mtx1 * mtx3);
	cout << "matrix product assigned from mtx1 * mtx3:\n" << product;

	Matrix<int> plusRes = (mtx1 + mtx3);
	cout << "matrix sum assigned from mtx1 + mtx3:\n" << plusRes;
	Matrix<int> minusRes = (mtx1 - mtx3);
	cout << "matrix subtraction assigned from mtx1 - mtx3:\n" << minusRes;

	cout << "matrix equivalence from plusRes and minusRes:" << (plusRes == minusRes) << endl;
	cout << "matrix equivalence from plusRes and plusRes:" << (plusRes == plusRes) << endl << endl;

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

	Matrix<ComplexNumber> compMtx1;
	compMtx1.set_element(0, 0, ComplexNumber(2,4));
	compMtx1.set_element(1, 1, ComplexNumber(1, 1));
	compMtx1.set_element(2, 2, ComplexNumber(9, -2));
	cout << "matrix 1:\n" << compMtx1;

	Matrix<ComplexNumber> compMtx2;
	compMtx2.set_element(0, 0, ComplexNumber(9, -2));
	compMtx2.set_element(1, 1, ComplexNumber(2, 4));
	compMtx2.set_element(2, 2, ComplexNumber(1, 1));

	cout << "matrix 2:\n" << compMtx2;

	Matrix<ComplexNumber> compMtx3;
	compMtx3 = compMtx2;
	cout << "matrix 3 assigned from matrix 2:\n" << compMtx3;

	Matrix<ComplexNumber> plusResC = (compMtx1 + compMtx3);
	cout << "matrix sum assigned from mtx1 + mtx3:\n" << plusResC;
	Matrix<ComplexNumber> minusResC = (compMtx1 - compMtx3);
	cout << "matrix subtraction assigned from mtx1 - mtx3:\n" << minusResC;

	cout << "matrix equivalence from plusRes and minusRes:" << (plusResC == minusResC) << endl;
	cout << "matrix equivalence from plusRes and plusRes:" << (plusResC == plusResC) << endl;


	int x;
	cin >> x;
	return 0;
}


