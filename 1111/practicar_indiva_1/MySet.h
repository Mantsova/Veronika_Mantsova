#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;

class MySet {
private:
	list<string> body;
public:
	MySet() {};
	MySet& operator= (const MySet& other);

	string& operator[] (int i);
	string operator[] (int i) const;

	MySet(const MySet& other);

	bool isEmpty();
	size_t cardinality();
	bool is_in(string x);

	void addLast(string val);
	void del_el(string val);

	MySet& operator |=(string x);
	MySet& operator /=(string x);

	MySet operator||(const MySet& other);
	MySet operator&&(const MySet& other);

	friend ostream& operator<<(ostream& os, const MySet& l);
	friend istream& operator>>(istream& os, MySet& l);

	bool operator == (const MySet& other) const;
	bool operator != (const MySet& other) const;
};