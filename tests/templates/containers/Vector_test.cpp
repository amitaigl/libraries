#include "../../../code/templates/containers/Vector.hpp"
#include "../../../tests_engine/macros.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace AG;

static void TestAssignmentOperator();
static void TestIsEmpty();
static void TestGetSize();
static void TestGetCapacity();
static void TestParenthesesOperator();
static void TestParenthesesOperatorConst();
static void TestAt();
static void TestAtConst();
static void TestAdd();
static void TestInsert();
static void TestRemoveAt();
static void TestRemoveObj();
static void TestDelete();
static void TestReserve();
static void TestTruncate();
static void TestShrink();
static void TestClean();
static void TestReset();
static void TestConstFind();
static void TestNonConstFind();
static void TestIsExisting();

struct newType
{
    bool operator==(const newType& other) const
    {
        return ((a == other.a) && (b == other.b) && (c == other.c));
    }

    int a;
    int b;
    char c;
};

int Vector_main()
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
        TestRemoveAt();
        TestRemoveObj();
        TestDelete();
        TestReserve();
        TestTruncate();
        TestShrink();
        TestClean();
        TestReset();
        TestConstFind();
        TestNonConstFind();
        TestIsExisting();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown exception" << '\n';
    }

    return 0;
}

static void TestAssignmentOperator()
{
    Vector<newType> v1(11);

    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    Vector<newType> v2;

    v2.Reset();
    TEST(10 == v2.GetCapacity());

    v2 = v1;
    TEST(i1.a == v2[0].a);
    TEST(i1.b == v2[0].b);
    TEST(i1.c == v2[0].c);
    TEST(1 == v2.GetSize());
    TEST(11 == v2.GetCapacity());

    v2.Reserve(12);
    TEST(12 == v2.GetCapacity());

    v2.Reset();
    TEST(11 == v2.GetCapacity());
}

static void TestIsEmpty()
{
    Vector<newType> v1;

    TEST(1 == v1.IsEmpty());
    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(0 == v1.IsEmpty());
}

static void TestGetSize()
{
    Vector<newType> v1;

    TEST(0 == v1.GetSize());
    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    TEST(4 == v1.GetSize());
    v1.Remove(3);
    TEST(3 == v1.GetSize());
}

static void TestGetCapacity()
{
    Vector<newType> v1;

    TEST(10 == v1.GetCapacity());

    Vector<newType> v2(20);

    TEST(20 == v2.GetCapacity());
}

static void TestParenthesesOperator()
{
    Vector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType i2 = {3, 4, 'a'};
    v1[0] = i2;
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);

    TRY(v1[22] = i2);
}

static void TestParenthesesOperatorConst()
{
    Vector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    const Vector<newType> v2(v1);
    TEST(i1.a == v2[0].a);
    TEST(i1.b == v2[0].b);
    TEST(i1.c == v2[0].c);
}

static void TestAt()
{
    Vector<newType> v1;

    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);

    newType i2 = {3, 4, 'a'};
    v1.At(0) = i2;
    TEST(i2.a == v1.At(0).a);
    TEST(i2.b == v1.At(0).b);
    TEST(i2.c == v1.At(0).c);
    TEST(i2.a == i1.a);
    TEST(i2.b == i1.b);
    TEST(i2.c == i1.c);

    TRY(v1.At(22) = i2);
}

static void TestAtConst()
{
    Vector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);

    const Vector<newType> v2(v1);
    TEST(i1.a == v2.At(0).a);
    TEST(i1.b == v2.At(0).b);
    TEST(i1.c == v2.At(0).c);
}

static void TestAdd()
{
    Vector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType i2 = {11, 12, '2'};
    v1.Add(i2);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
}

static void TestInsert()
{
    Vector<newType> v1;
    newType i1 = {1111, 1, 'a'},
            i2 = {22, 2, 'b'},
            i3 = {333, 3, 'c'},
            i4 = {44444, 4, 'd'};

    TRY(v1.Insert(1, i1));
    TRY(v1.Insert(12, i1));

    v1.Insert(0, i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    v1.Insert(1, i2);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);

    v1.Insert(1, i3);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    TEST(i3.a == v1[1].a);
    TEST(i3.b == v1[1].b);
    TEST(i3.c == v1[1].c);

    TEST(i2.a == v1[2].a);
    TEST(i2.b == v1[2].b);
    TEST(i2.c == v1[2].c);

    v1.Insert(0, i2);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);

    TEST(i1.a == v1[1].a);
    TEST(i1.b == v1[1].b);
    TEST(i1.c == v1[1].c);

    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);

    TEST(i2.a == v1[3].a);
    TEST(i2.b == v1[3].b);
    TEST(i2.c == v1[3].c);


    v1.Insert(0, i4);
    TEST(i4.a == v1[0].a);
    TEST(i4.b == v1[0].b);
    TEST(i4.c == v1[0].c);

    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);

    TEST(i1.a == v1[2].a);
    TEST(i1.b == v1[2].b);
    TEST(i1.c == v1[2].c);

    TEST(i3.a == v1[3].a);
    TEST(i3.b == v1[3].b);
    TEST(i3.c == v1[3].c);

    TEST(i2.a == v1[4].a);
    TEST(i2.b == v1[4].b);
    TEST(i2.c == v1[4].c);
}

static void TestRemoveAt()
{
    Vector<newType> v1;

    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType i2 = {11, 12, '2'};
    v1.Add(i2);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);

    newType i3 = {3, 4, 'a'};
    v1.At(0) = i3;
    TEST(i3.a == v1[0].a);
    TEST(i3.b == v1[0].b);
    TEST(i3.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);

    v1.Remove(0);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);

    v1.Add(i3);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);
    TEST(i3.a == v1[1].a);
    TEST(i3.b == v1[1].b);
    TEST(i3.c == v1[1].c);

    newType i4 = {4, 42, 'd'};
    v1.Add(i4);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);
    TEST(i3.a == v1[1].a);
    TEST(i3.b == v1[1].b);
    TEST(i3.c == v1[1].c);
    TEST(i4.a == v1[2].a);
    TEST(i4.b == v1[2].b);
    TEST(i4.c == v1[2].c);

    newType i5 = {5, 52, 'e'};
    v1.Add(i5);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);
    TEST(i3.a == v1[1].a);
    TEST(i3.b == v1[1].b);
    TEST(i3.c == v1[1].c);
    TEST(i4.a == v1[2].a);
    TEST(i4.b == v1[2].b);
    TEST(i4.c == v1[2].c);
    TEST(i5.a == v1[3].a);
    TEST(i5.b == v1[3].b);
    TEST(i5.c == v1[3].c);


    v1.Remove(2);
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);
    TEST(i3.a == v1[1].a);
    TEST(i3.b == v1[1].b);
    TEST(i3.c == v1[1].c);
    TEST(i5.a == v1[2].a);
    TEST(i5.b == v1[2].b);
    TEST(i5.c == v1[2].c);

    TRY(v1.Remove(22));
}

static void TestRemoveObj()
{
    Vector<newType> v1;

    newType i1 = { 1, 2, '1' };
    v1.Add(i1);
    TEST(&i1 == &v1[0]);

    newType i2 = { 11, 12, '2' };
    v1.Add(i2);
    TEST(&i1 == &v1[0]);
    TEST(&i2 == &v1[1]);

    newType i3 = { 3, 4, 'a' };
    v1.At(0) = i3;
    TEST(i1 == i3);
    TEST(&i1 == &v1[0]);
    TEST(&i2 == &v1[1]);

    v1.Add(i3);
    TEST(&i1 == &v1[0]);
    TEST(&i2 == &v1[1]);
    TEST(&i3 == &v1[2]);
    TEST(v1.Remove(i2));
    TEST(&i1 == &v1[0]);
    TEST(&i3 == &v1[1]);

    newType i4 = { 4, 42, 'd' };
    v1.Add(i4);
    TEST(&i1 == &v1[0]);
    TEST(&i3 == &v1[1]);
    TEST(&i4 == &v1[2]);

    newType i5 = { 5, 52, 'e' };
    v1.Add(i5);
    TEST(&i1 == &v1[0]);
    TEST(&i3 == &v1[1]);
    TEST(&i4 == &v1[2]);
    TEST(&i5 == &v1[3]);

    v1.Remove(i4);
    TEST(&i1 == &v1[0]);
    TEST(&i3 == &v1[1]);
    TEST(&i5 == &v1[2]);

    newType i6 = { 6, 66, 'g' };
    TEST(false == v1.Remove(i6));
    TEST(false == v1.Remove(i2));
    TEST(false == v1.Remove(i4));
}

static void TestDelete()
{
    Vector<newType> v1;

    newType* i1 = new newType;
    *i1 = { 1, 2, '1' };
    v1.Add(*i1);
    TEST(i1 == &v1[0]);

    newType* i2 = new newType;
    *i2 = { 11, 12, '2' };
    v1.Add(*i2);
    TEST(i1 == &v1[0]);
    TEST(i2 == &v1[1]);

    newType* i3 = new newType;
    *i3 = { 3, 4, 'a' };
    v1.Add(*i3);
    TEST(i1 == &v1[0]);
    TEST(i2 == &v1[1]);
    TEST(i3 == &v1[2]);

    TEST(v1.Delete(*i2));
    TEST(i1 == &v1[0]);
    TEST(i3 == &v1[1]);
}

static void TestReserve()
{
    Vector<newType> v1;

    v1.Reserve(8);
    TEST(10 == v1.GetCapacity());
    v1.Reserve(11);
    TEST(11 == v1.GetCapacity());

    newType i1 = {1, 11, 'a'};
    newType i2 = {2, 22, 'b'};
    newType i3 = {3, 33, 'c'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(3 == v1.GetSize());

    v1.Reserve(12);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);
    TEST(i2.a == v1.At(1).a);
    TEST(i2.b == v1.At(1).b);
    TEST(i2.c == v1.At(1).c);
    TEST(i3.a == v1.At(2).a);
    TEST(i3.b == v1.At(2).b);
    TEST(i3.c == v1.At(2).c);
    TEST(3 == v1.GetSize());
    TEST(12 == v1.GetCapacity());
}

static void TestTruncate()
{
    Vector<newType> v1(12);

    newType i1 = {1, 11, 'a'};
    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);
    TEST(0 == v1.IsEmpty());
    TEST(1 == v1.GetSize());
    TEST(12 == v1.GetCapacity());

    v1.Truncate(4);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);
    TEST(0 == v1.IsEmpty());
    TEST(1 == v1.GetSize());
    TEST(12 == v1.GetCapacity());

    v1.Truncate(0);
    TRY(v1.At(0) = i1);
    TEST(1 == v1.IsEmpty());
    TEST(0 == v1.GetSize());
    TEST(12 == v1.GetCapacity());

    newType i2 = {2, 22, 'b'};
    newType i3 = {3, 33, 'c'};
    newType i4 = {4, 44, 'd'};
    newType i5 = {5, 55, 'e'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    v1.Add(i4);
    v1.Add(i5);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(i4.a == v1[3].a);
    TEST(i4.b == v1[3].b);
    TEST(i4.c == v1[3].c);
    TEST(i5.a == v1[4].a);
    TEST(i5.b == v1[4].b);
    TEST(i5.c == v1[4].c);
    TEST(0 == v1.IsEmpty());
    TEST(5 == v1.GetSize());
    TEST(12 == v1.GetCapacity());

    v1.Truncate(3);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TRY(v1.At(3) = i1);
    TRY(v1.At(4) = i1);
    TEST(0 == v1.IsEmpty());
    TEST(3 == v1.GetSize());
    TEST(12 == v1.GetCapacity());
}

static void TestShrink()
{
    Vector<newType> v1;

    TEST(10 == v1.GetCapacity());

    newType i1 = {1, 11, 'a'};
    newType i2 = {2, 22, 'b'};
    newType i3 = {3, 33, 'c'};
    newType i4 = {4, 44, 'd'};
    newType i5 = {5, 55, 'e'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    v1.Add(i4);
    v1.Add(i5);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(i4.a == v1[3].a);
    TEST(i4.b == v1[3].b);
    TEST(i4.c == v1[3].c);
    TEST(i5.a == v1[4].a);
    TEST(i5.b == v1[4].b);
    TEST(i5.c == v1[4].c);
    TEST(5 == v1.GetSize());

    v1.Shrink();
    TEST(5 == v1.GetCapacity());
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);
    TEST(i2.a == v1.At(1).a);
    TEST(i2.b == v1.At(1).b);
    TEST(i2.c == v1.At(1).c);
    TEST(i3.a == v1.At(2).a);
    TEST(i3.b == v1.At(2).b);
    TEST(i3.c == v1.At(2).c);
    TEST(i4.a == v1.At(3).a);
    TEST(i4.b == v1.At(3).b);
    TEST(i4.c == v1.At(3).c);
    TEST(i5.a == v1.At(4).a);
    TEST(i5.b == v1.At(4).b);
    TEST(i5.c == v1.At(4).c);
}

static void TestClean()
{
    Vector<newType> v1(15);
    
    TEST(0 == v1.GetSize());
    TEST(15 == v1.GetCapacity());

    newType i1 = {1, 11, 'a'};
    newType i2 = {2, 22, 'b'};
    newType i3 = {3, 33, 'c'};
    newType i4 = {4, 44, 'd'};
    newType i5 = {5, 55, 'e'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    v1.Add(i4);
    v1.Add(i5);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(i4.a == v1[3].a);
    TEST(i4.b == v1[3].b);
    TEST(i4.c == v1[3].c);
    TEST(i5.a == v1[4].a);
    TEST(i5.b == v1[4].b);
    TEST(i5.c == v1[4].c);
    TEST(5 == v1.GetSize());

    v1.Clean();
    TEST(0 == v1.GetSize());
    TRY(v1[0].a = 10);
}

static void TestReset()
{
    Vector<newType> v1(5);
    
    TEST(1 == v1.IsEmpty());
    TEST(0 == v1.GetSize());
    TEST(5 == v1.GetCapacity());

    newType i1 = {1, 11, 'a'};
    newType i2 = {2, 22, 'b'};
    newType i3 = {3, 33, 'c'};
    newType i4 = {4, 44, 'd'};
    newType i5 = {5, 55, 'e'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    v1.Add(i4);
    v1.Add(i5);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(i4.a == v1[3].a);
    TEST(i4.b == v1[3].b);
    TEST(i4.c == v1[3].c);
    TEST(i5.a == v1[4].a);
    TEST(i5.b == v1[4].b);
    TEST(i5.c == v1[4].c);
    TEST(0 == v1.IsEmpty());
    TEST(5 == v1.GetSize());
    TEST(5 == v1.GetCapacity());

    v1.Reset();
    TRY(v1.At(0) = i4);
    TEST(1 == v1.IsEmpty());
    TEST(0 == v1.GetSize());
    TEST(5 == v1.GetCapacity());

    newType i6 = {6, 66, 'f'};
    v1.Add(i1);
    v1.Add(i2);
    v1.Add(i3);
    v1.Add(i4);
    v1.Add(i5);
    v1.Add(i6);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);
    TEST(i3.a == v1[2].a);
    TEST(i3.b == v1[2].b);
    TEST(i3.c == v1[2].c);
    TEST(i4.a == v1[3].a);
    TEST(i4.b == v1[3].b);
    TEST(i4.c == v1[3].c);
    TEST(i5.a == v1[4].a);
    TEST(i5.b == v1[4].b);
    TEST(i5.c == v1[4].c);
    TEST(i6.a == v1[5].a);
    TEST(i6.b == v1[5].b);
    TEST(i6.c == v1[5].c);
    TRY(v1.At(6) = i2);
    TEST(0 == v1.IsEmpty());
    TEST(6 == v1.GetSize());
    TEST(15 == v1.GetCapacity());

    v1.Reset();
    TRY(v1.At(0) = i4);
    TEST(1 == v1.IsEmpty());
    TEST(0 == v1.GetSize());
    TEST(5 == v1.GetCapacity());
}

static void TestConstFind()
{
    Vector<newType> v1(10);
    newType arr[10];

    for(int i = 0; i < 10; ++i)
    {
        arr[i] = { i, i * 10, 'a' };
    }

    for(int i = 0; i < 10; ++i)
    {
        v1.Add(arr[i]);
    }

    const Vector<newType> v2(v1);
    
    for(int i = 0; i < 10; ++i)
    {
        TEST((&arr[i] == v2.Find(arr[i])));
    }
}

static void TestNonConstFind()
{
    Vector<newType> v1(10);
    newType arr[10];

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = { i, i * 10, 'a' };
    }

    for (int i = 0; i < 10; ++i)
    {
        v1.Add(arr[i]);
    }

    for (int i = 0; i < 10; ++i)
    {
        TEST((&arr[i] == v1.Find(arr[i])));
    }
}

static void TestIsExisting()
{
    Vector<newType> v1(10);
    newType i1 = { 1, 11, 'a' };

    TEST(false == v1.IsExisting(i1));
    v1.Add(i1);
    TEST(true == v1.IsExisting(i1));

}