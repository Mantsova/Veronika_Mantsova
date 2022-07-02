#include "pch.h"
#include "CppUnitTest.h"
#include "../practicar_indiva_1/MySet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestAddLast) {
			MySet A;

			Assert::IsFalse(A.is_in("a"));

			A.addLast("a");

			Assert::IsTrue(A.is_in("a"));
			Assert::IsFalse(A.is_in("b"));

		}

		TEST_METHOD(TestDel_el) {
			MySet A;
			A |= "a";
			A.del_el("a");

			Assert::IsFalse(A.is_in("a"));
			Assert::IsTrue(A.isEmpty());

			A.del_el("a");
			Assert::IsFalse(A.is_in("a"));
			Assert::IsTrue(A.isEmpty());
		}

		TEST_METHOD(TestIsEmpty) {
			MySet A;
			Assert::IsTrue(A.isEmpty());

			A |= "a";
			Assert::IsFalse(A.isEmpty());
		}

		TEST_METHOD(TestCardinality) {
			MySet A;
			Assert::AreEqual(size_t(0), A.cardinality());

			A |= "a";
			Assert::AreEqual(size_t(1), A.cardinality());

			A /= "a";
			Assert::AreEqual(size_t(0), A.cardinality());

			A |= "a";
			A |= "b";
			A |= "c";
			A |= "d";
			A |= "e";

			A |= "a";
			Assert::AreEqual(size_t(5), A.cardinality());
		}

		TEST_METHOD(TestIs_In) {
			MySet A;
			A |= "a";
			A |= "b";
			A |= "c";
			A |= "d";
			A |= "e";

			Assert::IsTrue(A.is_in("a"));
			Assert::IsTrue(A.is_in("c"));
			Assert::IsTrue(A.is_in("e"));
			Assert::IsFalse(A.is_in("0"));
		}

		TEST_METHOD(TestAdd) {
			MySet A;
			Assert::IsTrue(A.isEmpty());

			A |= "a";
			Assert::IsTrue(A.is_in("a"));
			Assert::AreEqual(size_t(1), A.cardinality());

			A |= "a";
			Assert::AreEqual(size_t(1), A.cardinality());
		}

		TEST_METHOD(TestDel) {
			MySet A;
			A |= "a";
			Assert::IsTrue(A.is_in("a"));

			A /= "a";
			Assert::IsTrue(A.isEmpty());

			A /= "a";
			Assert::IsTrue(A.isEmpty());
		}

		TEST_METHOD(TestUnion) {
			MySet A;
			A |= "1";
			A |= "2";
			A |= "3";
			A |= "4";
			A |= "5";

			MySet B;
			B |= "3";
			B |= "4";
			B |= "5";
			B |= "6";
			B |= "7";
			B |= "8";

			MySet C = A || B;

			Assert::IsTrue(C.is_in("1"));
			Assert::IsTrue(C.is_in("2"));
			Assert::IsTrue(C.is_in("3"));
			Assert::IsTrue(C.is_in("4"));
			Assert::IsTrue(C.is_in("5"));
			Assert::IsTrue(C.is_in("6"));
			Assert::IsTrue(C.is_in("7"));
			Assert::IsTrue(C.is_in("8"));

			Assert::AreEqual(size_t(8), C.cardinality());

			MySet D = B || A;

			Assert::IsTrue(D.is_in("1"));
			Assert::IsTrue(D.is_in("2"));
			Assert::IsTrue(D.is_in("3"));
			Assert::IsTrue(D.is_in("4"));
			Assert::IsTrue(D.is_in("5"));
			Assert::IsTrue(D.is_in("6"));
			Assert::IsTrue(D.is_in("7"));
			Assert::IsTrue(D.is_in("8"));

			Assert::AreEqual(size_t(8), D.cardinality());

			MySet G = A || A;

			Assert::IsTrue(G.is_in("1"));
			Assert::IsTrue(G.is_in("2"));
			Assert::IsTrue(G.is_in("3"));
			Assert::IsTrue(G.is_in("4"));
			Assert::IsTrue(G.is_in("5"));

			Assert::AreEqual(size_t(5), G.cardinality());

			MySet H;
			MySet K = H || A;

			Assert::IsTrue(K.is_in("1"));
			Assert::IsTrue(K.is_in("2"));
			Assert::IsTrue(K.is_in("3"));
			Assert::IsTrue(K.is_in("4"));
			Assert::IsTrue(K.is_in("5"));

			Assert::AreEqual(size_t(5), K.cardinality());
		}

		TEST_METHOD(TestIntersection) {
			MySet A;
			A |= "1";
			A |= "2";
			A |= "3";
			A |= "4";
			A |= "5";

			MySet B;
			B |= "3";
			B |= "4";
			B |= "5";
			B |= "6";
			B |= "7";
			B |= "8";

			MySet C = A && B;

			Assert::IsTrue(C.is_in("3"));
			Assert::IsTrue(C.is_in("4"));
			Assert::IsTrue(C.is_in("5"));

			Assert::AreEqual(size_t(3), C.cardinality());

			MySet D = B && A;

			Assert::IsTrue(D.is_in("3"));
			Assert::IsTrue(D.is_in("4"));
			Assert::IsTrue(D.is_in("5"));

			Assert::AreEqual(size_t(3), D.cardinality());

			MySet G = A && A;

			Assert::IsTrue(G.is_in("1"));
			Assert::IsTrue(G.is_in("2"));
			Assert::IsTrue(G.is_in("3"));
			Assert::IsTrue(G.is_in("4"));
			Assert::IsTrue(G.is_in("5"));

			Assert::AreEqual(size_t(5), G.cardinality());

			MySet H;
			MySet K = H && A;

			Assert::IsTrue(H.isEmpty());
		}

		TEST_METHOD(TestIsEqual) {
			MySet A;
			A |= "1";
			A |= "2";
			A |= "3";

			MySet B;
			B |= "1";
			B |= "2";
			B |= "3";

			Assert::IsTrue(A == B);
			Assert::IsTrue(B == A);

			MySet C;
			MySet D;

			Assert::IsTrue(C == D);
			Assert::IsTrue(D == C);

			C |= "1";
			D |= "1";

			Assert::IsTrue(C == D);
			Assert::IsTrue(D == C);
		}

		TEST_METHOD(TestIsNotEqual) {
			MySet A;
			A |= "1";
			A |= "2";
			A |= "3";
			
			MySet B;
			B |= "3";
			B |= "4";
			B |= "5";
			B |= "6";

			Assert::IsTrue(A != B);
			Assert::IsTrue(B != A);

			MySet C;
			C |= "1";
			C |= "2";
			C |= "3";
			C |= "4";

			Assert::IsTrue(A != C);

			Assert::IsTrue(C != A);

			MySet D;
			D |= "1";

			MySet E;
			E |= "3";

			Assert::IsTrue(D != E);
			Assert::IsTrue(E != D);
		}

		TEST_METHOD(TestEqual) {
			MySet A;
			A |= "1";
			A |= "2";
			A |= "3";

			MySet B;
			Assert::IsTrue(B.isEmpty());

			B = A;
			Assert::IsTrue(A == B); 

			MySet C;
			C = B;
			Assert::IsTrue(C == B);
		}
	};
}
