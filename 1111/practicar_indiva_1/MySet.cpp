#include "MySet.h"
#include <iterator>


MySet::MySet(const MySet& other)
{
	body = other.body;
}

bool MySet::isEmpty()
{
	return body.empty();
}

size_t MySet::cardinality()
{
	return body.size();
}

bool MySet::is_in(string x)
{
	return (find(body.begin(), body.end(), x) != body.end());;
}

void MySet::addLast(string val)
{
	if (!is_in(val))
		body.push_back(val);
}

void MySet::del_el(string val)
{
	body.remove(val);
}

MySet& MySet::operator|=(string x)
{
	addLast(x);
	return *this;
}

MySet& MySet::operator/=(string x)
{
	del_el(x);
	return *this;
}

MySet MySet::operator||(const MySet & other)
{
	MySet res(*this);

	auto p = other.body.begin();
	while (p != other.body.end())
	{
		res |= *p;
		++p;
	}
	return res;
}

MySet MySet::operator&&(const MySet & other)
{
	MySet res;

	auto other_it = other.body.begin();
	auto this_it = body.begin();
	while (other_it != other.body.end())
	{
		if (this->is_in(*other_it)) {
			res |= *other_it;
		}
		++other_it;
	}
	return res;
}

MySet& MySet::operator=(const MySet & other)
{
	body = other.body;
	return *this;
}

string& MySet::operator[](int i)
{
	if (i < 0 || i >= body.size()) throw - 1;
	auto it = body.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}
	return *it;
}

string MySet::operator[](int i) const
{
	if (i < 0 || i >= body.size()) throw - 1;
	auto it = body.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}
	return *it;
}

ostream& operator<<(ostream & os, const MySet & l)
{
	os << "{ ";
	copy(l.body.begin(), l.body.end(), ostream_iterator<string>(os, " "));
	os << '}' << endl;
	return os;
}

istream& operator>>(istream & is, MySet & l)
{
	int n;
	string a;
	cout << "Введите количество элементов множества: " << endl;
	is >> n;
	cout << "Введите элементы множества: " << endl;
	for (int i = 0; i < n; ++i) {
		is >> a;
		l |= a;
	}

	return is;
}

bool MySet::operator == (const MySet & other) const {
	if (body.size() != other.body.size()) return false;
	auto other_it = other.body.begin();
	auto this_it = body.begin();
	while ((other_it != other.body.end()) && (this_it != body.end()))
	{
		if (*other_it != *this_it)
			return false;

		++other_it;
		++this_it;
	}
	return true;
}

bool MySet::operator != (const MySet & other) const {
	return !(*this == other);
}