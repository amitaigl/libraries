#include "../../../code/templates/containers/Array.hpp"
#include "../../../tests_engine/macros.hpp"

using namespace AG;

void TestAssignmentOperator();
void TestIsEmpty();
void TestGetSize();
void TestGetCapacity();
void TestParenthesesOperator();
void TestParenthesesOperatorConst();
void TestAt();
void TestAtConst();
void TestAdd();
void TestInsert();
void TestRemove();
void TestReserve();
void TestTruncate();
void TestShrink();
void TestClean();
void TestReset();

int main()
{
    try
    {
        TestAssignmentOperator();
        TestIsEmpty();
        TestGetSize();
        TestGetCapacity();
        TestParenthesesOperator();
        TestParenthesesOperatorConst();
        TestAt();
        TestAtConst();
        TestAdd();
        TestInsert();
        TestRemove();
        TestReserve();
        TestTruncate();
        TestShrink();
        TestClean();
        TestReset();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(char const* e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}

void TestAssignmentOperator()
{
    Array<int> a1(11);

    int i1 = 1;
    a1.Add(i1);
    a1.Add(257);
    a1.Add(3000);
    TEST(i1 == a1[0]);
    TEST(257 == a1[1]);
    TEST(3000 == a1[2]);

    Array<int> a2;

    a2.Reset();
    TEST(10 == a2.GetCapacity());

    a2 = a1;
    TEST(i1 == a2[0]);
    TEST(257 == a2[1]);
    TEST(3000 == a2[2]);
    TEST(3 == a2.GetSize());
    TEST(11 == a2.GetCapacity());

    a2.Reserve(12);
    TEST(12 == a2.GetCapacity());

    a2.Reset();
    TEST(11 == a2.GetCapacity());
}

void TestIsEmpty()
{
    Array<int> a1;

    TEST(1 == a1.IsEmpty());
    int i1 = 1;
    a1.Add(i1);
    TEST(0 == a1.IsEmpty());
}

void TestGetSize()
{
    Array<int> a1;

    TEST(0 == a1.GetSize());
    int i1 = 1;
    a1.Add(i1);
    a1.Add(i1);
    a1.Add(i1);
    a1.Add(i1);
    TEST(4 == a1.GetSize());
    a1.Remove(3);
    TEST(3 == a1.GetSize());
}

void TestGetCapacity()
{
    Array<int> a1;

    TEST(10 == a1.GetCapacity());

    Array<int> a2(20);

    TEST(20 == a2.GetCapacity());
}

void TestParenthesesOperator()
{
    Array<int> a1;
    int i1 = 1;

    a1.Add(i1);
    TEST(i1 == a1[0]);

    int i2 = 2;
    a1[0] = i2;
    TEST(i2 == a1[0]);

    TRY(a1[22] = i2);
}

void TestParenthesesOperatorConst()
{
    Array<int> a1;
    int i1 = 1;

    a1.Add(i1);
    TEST(i1 == a1[0]);

    const Array<int> a2(a1);
    TEST(i1 == a2[0]);
}

void TestAt()
{
    Array<int> a1;

    int i1 = 1;
    a1.Add(i1);
    TEST(i1 == a1.At(0));

    int i2 = 2;
    a1.At(0) = i2;
    TEST(i2 == a1.At(0));

    TRY((a1.At(22) = i2));
}

void TestAtConst()
{
    Array<int> a1;
    int i1 = 1;

    a1.Add(i1);
    TEST(i1 == a1.At(0));
    
    const Array<int> a2(a1);
    TEST(i1 == a2.At(0));
}

void TestAdd()
{
    Array<int> a1;
    int i1 = 1;
    
    a1.Add(i1);
    TEST(i1 == a1[0]);

    int i2 = 2;
    a1.Add(i2);
    TEST(i1 == a1[0]);
    TEST(i2 == a1[1]);

    a1.Add(98);
    TEST(i1 == a1[0]);
    TEST(i2 == a1[1]);
    TEST(98 == a1[2]);
}

void TestInsert()
{
    Array<int> a1;
    int i1 = 1111, i2 = 22, i3 = 333, i4 = 4;

    TRY(a1.Insert(1, i1));
    TRY(a1.Insert(12, i1));

    a1.Insert(0, i1);
    TEST(i1 == a1[0]);

    a1.Insert(1, i2);
    TEST(i1 == a1[0]);
    TEST(i2 == a1[1]);

    a1.Insert(1, i3);
    TEST(i1 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i2 == a1[2]);

    a1.Insert(0, i2);
    TEST(i2 == a1[0]);
    TEST(i1 == a1[1]);
    TEST(i3 == a1[2]);
    TEST(i2 == a1[3]);

    a1.Insert(0, i4);
    TEST(i4 == a1[0]);
    TEST(i2 == a1[1]);
    TEST(i1 == a1[2]);
    TEST(i3 == a1[3]);
    TEST(i2 == a1[4]);

    a1.Insert(a1.GetSize(), 99);
    TEST(i4 == a1[0]);
    TEST(i2 == a1[1]);
    TEST(i1 == a1[2]);
    TEST(i3 == a1[3]);
    TEST(i2 == a1[4]);
    TEST(99 == a1[5]);
}

void TestRemove()
{
    Array<int> a1;

    int i1 = 1;
    a1.Add(i1);
    TEST(i1 == a1[0]);

    int i2 = 258;
    a1.Add(i2);
    TEST(i1 == a1[0]);
    TEST(i2 == a1[1]);

    int i3 = 3;
    a1.At(0) = i3;
    TEST(i3 == a1[0]);
    TEST(i2 == a1[1]);

    a1.Remove(0);
    TEST(i2 == a1[0]);

    a1.Add(i3);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);

    int i4 = 4;
    a1.Add(i4);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i4 == a1[2]);

    int i5 = 5;
    a1.Add(i5);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i4 == a1[2]);
    TEST(i5 == a1[3]);

    a1.Remove(2);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i5 == a1[2]);

    TRY(a1.Remove(22));
}

void TestReserve()
{
    Array<int> a1;

    a1.Reserve(8);
    TEST(10 == a1.GetCapacity());
    a1.Reserve(11);
    TEST(11 == a1.GetCapacity());

    a1.Add(123);
    a1.Add(456);
    a1.Add(789);
    TEST(123 == a1.At(0));
    TEST(456 == a1.At(1));
    TEST(789 == a1.At(2));
    TEST(3 == a1.GetSize());

    a1.Reserve(12);
    TEST(123 == a1.At(0));
    TEST(456 == a1.At(1));
    TEST(789 == a1.At(2));
    TEST(3 == a1.GetSize());
    TEST(12 == a1.GetCapacity());
}

void TestTruncate()
{
    Array<int> a1(12);

    a1.Add(111);
    TEST(111 == a1.At(0));
    TEST(0 == a1.IsEmpty());
    TEST(1 == a1.GetSize());
    TEST(12 == a1.GetCapacity());

    a1.Truncate(4);
    TEST(111 == a1.At(0));
    TEST(0 == a1.IsEmpty());
    TEST(1 == a1.GetSize());
    TEST(12 == a1.GetCapacity());

    a1.Truncate(0);
    TRY(a1.At(0) = 4);
    TEST(1 == a1.IsEmpty());
    TEST(0 == a1.GetSize());
    TEST(12 == a1.GetCapacity());

    a1.Add(111);
    a1.Add(222);
    a1.Add(333);
    a1.Add(444);
    a1.Add(555);
    TEST(111 == a1.At(0));
    TEST(222 == a1.At(1));
    TEST(333 == a1.At(2));
    TEST(444 == a1.At(3));
    TEST(555 == a1.At(4));
    TEST(0 == a1.IsEmpty());
    TEST(5 == a1.GetSize());
    TEST(12 == a1.GetCapacity());

    a1.Truncate(3);
    TEST(111 == a1.At(0));
    TEST(222 == a1.At(1));
    TEST(333 == a1.At(2));
    TRY(a1.At(3) = 4);
    TRY(a1.At(4) = 4);
    TEST(0 == a1.IsEmpty());
    TEST(3 == a1.GetSize());
    TEST(12 == a1.GetCapacity());
}

void TestShrink()
{
    Array<int> a1;

    TEST(10 == a1.GetCapacity());
    a1.Add(111);
    a1.Add(222);
    a1.Add(333);
    a1.Add(444);
    a1.Add(555);
    TEST(111 == a1.At(0));
    TEST(222 == a1.At(1));
    TEST(333 == a1.At(2));
    TEST(444 == a1.At(3));
    TEST(555 == a1.At(4));
    TEST(5 == a1.GetSize());

    a1.Shrink();
    TEST(5 == a1.GetCapacity());
    TEST(111 == a1.At(0));
    TEST(222 == a1.At(1));
    TEST(333 == a1.At(2));
    TEST(444 == a1.At(3));
    TEST(555 == a1.At(4));
}

void TestClean()
{
    Array<char> a1(15);
    
    TEST(0 == a1.GetSize());
    TEST(15 == a1.GetCapacity());
    a1.Add('a');
    a1.Add('m');
    a1.Add('i');
    a1.Add('t');
    a1.Add('a');
    a1.Add('i');
    TEST('a' == a1.At(0));
    TEST('m' == a1.At(1));
    TEST('i' == a1.At(2));
    TEST('t' == a1.At(3));
    TEST('a' == a1.At(4));
    TEST('i' == a1.At(5));
    TEST(6 == a1.GetSize());

    a1.Clean();
    TEST(0 == a1.GetSize());
}

void TestReset()
{
    Array<double> a1(5);
    
    TEST(1 == a1.IsEmpty());
    TEST(0 == a1.GetSize());
    TEST(5 == a1.GetCapacity());

    a1.Add(1.0);
    a1.Add(1.1);
    a1.Add(1.2);
    a1.Add(1.3);
    a1.Add(1.4);
    TEST(1.0 == a1.At(0));
    TEST(1.1 == a1.At(1));
    TEST(1.2 == a1.At(2));
    TEST(1.3 == a1.At(3));
    TEST(1.4 == a1.At(4));
    TEST(0 == a1.IsEmpty());
    TEST(5 == a1.GetSize());
    TEST(5 == a1.GetCapacity());

    a1.Reset();
    TRY(a1.At(0) = 1.0);
    TEST(1 == a1.IsEmpty());
    TEST(0 == a1.GetSize());
    TEST(5 == a1.GetCapacity());

    a1.Add(1.0);
    a1.Add(1.1);
    a1.Add(1.2);
    a1.Add(1.3);
    a1.Add(1.4);
    a1.Add(1.5);
    TEST(1.0 == a1.At(0));
    TEST(1.1 == a1.At(1));
    TEST(1.2 == a1.At(2));
    TEST(1.3 == a1.At(3));
    TEST(1.4 == a1.At(4));
    TEST(1.5 == a1.At(5));
    TRY(a1.At(6) = 5);
    TEST(0 == a1.IsEmpty());
    TEST(6 == a1.GetSize());
    TEST(15 == a1.GetCapacity());

    a1.Reset();
    TRY(a1.At(0) = 8);
    TEST(1 == a1.IsEmpty());
    TEST(0 == a1.GetSize());
    TEST(5 == a1.GetCapacity());
}
