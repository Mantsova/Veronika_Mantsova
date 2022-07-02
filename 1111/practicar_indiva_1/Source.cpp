#include "MySet.h"
#include <fstream>

int main() {

	setlocale(LC_ALL, "");

	MySet K;
	cout << "�������� �����" << endl;
	cin >> K;
	cout << "K: " << K << endl;

	MySet A;
	cout << "A - ������? " << boolalpha << A.isEmpty() << endl;
	A |= "a";
	cout << "����� ���������� �������� 'a' � ������� |=. ������? " << boolalpha << A.isEmpty() << endl;
	cout << "������ ���������: " << A.cardinality() << endl;

	cout << "�������� �� 'a' ��������� ��������� �? " << boolalpha << A.is_in("a") << endl;
	cout << "�������� �� 'b' ��������� ��������� �? " << boolalpha << A.is_in("b") << endl;

	A /= "a";
	cout << "����� �������� �������� 'a' � ������� /=. �������� �� 'a' ��������� ��������� �? " << boolalpha << A.is_in("a") << endl;
	cout << "������? " << boolalpha << A.isEmpty() << endl;

	MySet A_copy;
	A_copy = A;
	cout << "A_copy: " << A_copy << endl;

	MySet B;
	B |= "1";
	B |= "2";
	B |= "3";
	B |= "4";
	B |= "5";

	A |= "3";
	A |= "4";
	A |= "5";
	A |= "6";
	A |= "7";
	A |= "8";

	cout << "A: " << A;
	cout << "B: " << B;

	A.addLast("0");
	cout << "��������� '0' � ����� ��������� A: " << A;
	A.del_el("1");
	cout << "������� '1' �� ��������� A: " << A;

	MySet D = (B || A);
	cout << "A || B: " << D;

	MySet E = (B && A);
	cout << "A && B: " << E;

	cout << "A1 == A2 ? : " << boolalpha << (A == B) << endl;
	cout << "A1 != A2 ? : " << boolalpha << (A != B) << endl << endl;

	cout << "-------------------------������------------------------- " << endl;

	ifstream f1;
	f1.open("f1.txt");

	ifstream f2;
	f2.open("f2.txt");

	if (!f1.is_open()) {
		cerr << "���������� ������� ���� f1" << endl;
		return -1;
	}
	if (!f2.is_open()) {
		cerr << "���������� ������� ���� f2" << endl;
		return -1;
	}

	MySet A1;
	MySet A2;

	string ch;
	while (!f1.eof()) {
		f1 >> ch;
		A1 |= ch;
	}
	f1.close();

	while (!f2.eof()) {
		f2 >> ch;
		A2 |= ch;
	}
	f2.close();

	cout << "����� �� f1: " << A1 << endl;
	cout << "����� �� f2: " << A2 << endl;

	MySet result = (A1 && A2);
	cout << "����������� f1 � f2:" << result;

	/*
	ofstream f_res;
	f_res.open("f_res.txt");

	if (!f_res.is_open()) {
		cerr << "������ �������� ��������� �����" << endl;
		return -1;
	}
	for (int i = 0; i < result.cardinality()-1; i++) {
		f_res << result[i] << ", ";
	}
	f_res << result[result.cardinality() - 1];

	f_res.close();
	*/
	return 0;
}