#include "../../../code/templates/containers/SortedVector.hpp"
#include "../../../tests_engine/macros.hpp"

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
static void TestRemove();
static void TestReserve();
static void TestTruncate();
static void TestShrink();
static void TestClean();
static void TestReset();

struct newType3
{
    int a;
    int b;
    char c;
};

// template <class T>
/*struct Comparator: public IComparator<T>
{
    int Compare(const T& left, const T& right) const
    {
        return left - right;
    }
};*/

struct Comparator: public IComparator<newType3>
{
    int Compare(const newType3& left, const newType3& right) const
    {
        return left.a - right.a;
    }
};

// Comparator<newType3> cmp;
Comparator cmp;


int SortedVector_main()
{
    try
    {
        TestAssignmentOperator();
        // TestIsEmpty();
        // TestGetSize();
        // TestGetCapacity();
        // TestParenthesesOperator();
        // TestParenthesesOperatorConst();
        // TestAt();
        // TestAtConst();
        // TestAdd();
        // TestRemove();
        // TestReserve();
        // TestTruncate();
        // TestShrink();
        // TestClean();
        // TestReset();
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

static void TestAssignmentOperator()
{
    SortedVector<newType3> sv1(cmp, 11);

    newType3 i1 = {1,2,'a'};
    sv1.Add(i1);
    

    /*SortedVector<newType3> sv1(11);

    newType3 i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    SortedVector<newType3> v2;

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
    TEST(11 == v2.GetCapacity());*/
}

static void TestIsEmpty()
{
    /*SortedVector<newType3> v1;

    TEST(1 == v1.IsEmpty());
    newType3 i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(0 == v1.IsEmpty());*/
}

static void TestGetSize()
{
    /*SortedVector<newType3> v1;

    TEST(0 == v1.GetSize());
    newType3 i1 = {1, 2, '1'};
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    TEST(4 == v1.GetSize());
    v1.Remove(3);
    TEST(3 == v1.GetSize());*/
}

static void TestGetCapacity()
{
    /*SortedVector<newType3> v1;

    TEST(10 == v1.GetCapacity());

    SortedVector<newType3> v2(20);

    TEST(20 == v2.GetCapacity());*/
}

static void TestParenthesesOperator()
{
    /*SortedVector<newType3> v1;
    newType3 i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType3 i2 = {3, 4, 'a'};
    v1[0] = i2;
    TEST(i2.a == v1[0].a);
    TEST(i2.b == v1[0].b);
    TEST(i2.c == v1[0].c);

    TRY(v1[22] = i2);*/
}

static void TestParenthesesOperatorConst()
{
    /*SortedVector<newType3> v1;
    newType3 i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    const SortedVector<newType3> v2(v1);
    TEST(i1.a == v2[0].a);
    TEST(i1.b == v2[0].b);
    TEST(i1.c == v2[0].c);*/
}

static void TestAt()
{
    /*SortedVector<newType3> v1;

    newType3 i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);

    newType3 i2 = {3, 4, 'a'};
    v1.At(0) = i2;
    TEST(i2.a == v1.At(0).a);
    TEST(i2.b == v1.At(0).b);
    TEST(i2.c == v1.At(0).c);

    TRY(v1.At(22) = i2);*/
}

static void TestAtConst()
{
    /*SortedVector<newType3> v1;
    newType3 i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);

    const SortedVector<newType3> v2(v1);
    TEST(i1.a == v2.At(0).a);
    TEST(i1.b == v2.At(0).b);
    TEST(i1.c == v2.At(0).c);*/
}

static void TestAdd()
{
    /*SortedVector<newType3> v1;
    newType3 i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType3 i2 = {11, 12, '2'};
    v1.Add(i2);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);*/
}

static void TestRemove()
{
    /*SortedVector<newType3> v1;

    newType3 i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    newType3 i2 = {11, 12, '2'};
    v1.Add(i2);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);
    TEST(i2.a == v1[1].a);
    TEST(i2.b == v1[1].b);
    TEST(i2.c == v1[1].c);

    newType3 i3 = {3, 4, 'a'};
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

    newType3 i4 = {4, 42, 'd'};
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

    newType3 i5 = {5, 52, 'e'};
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

    TRY(v1.Remove(22));*/
}

static void TestReserve()
{
    /*SortedVector<newType3> v1;

    v1.Reserve(8);
    TEST(10 == v1.GetCapacity());
    v1.Reserve(11);
    TEST(11 == v1.GetCapacity());

    newType3 i1 = {1, 11, 'a'};
    newType3 i2 = {2, 22, 'b'};
    newType3 i3 = {3, 33, 'c'};
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
    TEST(12 == v1.GetCapacity());*/
}

static void TestTruncate()
{
    /*SortedVector<newType3> v1(12);

    newType3 i1 = {1, 11, 'a'};
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

    newType3 i2 = {2, 22, 'b'};
    newType3 i3 = {3, 33, 'c'};
    newType3 i4 = {4, 44, 'd'};
    newType3 i5 = {5, 55, 'e'};
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
    TEST(12 == v1.GetCapacity());*/
}

static void TestShrink()
{
    /*SortedVector<newType3> v1;

    TEST(10 == v1.GetCapacity());

    newType3 i1 = {1, 11, 'a'};
    newType3 i2 = {2, 22, 'b'};
    newType3 i3 = {3, 33, 'c'};
    newType3 i4 = {4, 44, 'd'};
    newType3 i5 = {5, 55, 'e'};
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
    TEST(i5.c == v1.At(4).c);*/
}

static void TestClean()
{
    /*SortedVector<newType3> v1(15);
    
    TEST(0 == v1.GetSize());
    TEST(15 == v1.GetCapacity());

    newType3 i1 = {1, 11, 'a'};
    newType3 i2 = {2, 22, 'b'};
    newType3 i3 = {3, 33, 'c'};
    newType3 i4 = {4, 44, 'd'};
    newType3 i5 = {5, 55, 'e'};
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
    TRY(v1[0].a = 10);*/
}

static void TestReset()
{
    /*SortedVector<newType3> v1(5);
    
    TEST(1 == v1.IsEmpty());
    TEST(0 == v1.GetSize());
    TEST(5 == v1.GetCapacity());

    newType3 i1 = {1, 11, 'a'};
    newType3 i2 = {2, 22, 'b'};
    newType3 i3 = {3, 33, 'c'};
    newType3 i4 = {4, 44, 'd'};
    newType3 i5 = {5, 55, 'e'};
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

    newType3 i6 = {6, 66, 'f'};
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
    TEST(5 == v1.GetCapacity());*/
}