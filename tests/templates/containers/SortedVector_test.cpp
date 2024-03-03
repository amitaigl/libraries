#include "../../../code/templates/containers/SortedVector.hpp"
#include "../../../tests_engine/macros.hpp"
#include "../../../code/templates/algorithms/IComparator.hpp"

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
void TestRemove();
void TestReserve();
void TestTruncate();
void TestShrink();
void TestClean();
void TestReset();

typedef struct newType
{
    int a;
    int b;
    char c;
} newType;

IComparator<newType> compare;

int main()
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

void TestAssignmentOperator()
{
    SortedVector<newType> sv1(11, );

    newType i1 = {1,2,'a'};
    sv1.Add(i1);
    

    /*SortedVector<newType> sv1(11);

    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    SortedVector<newType> v2;

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

void TestIsEmpty()
{
    /*SortedVector<newType> v1;

    TEST(1 == v1.IsEmpty());
    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    TEST(0 == v1.IsEmpty());*/
}

void TestGetSize()
{
    /*SortedVector<newType> v1;

    TEST(0 == v1.GetSize());
    newType i1 = {1, 2, '1'};
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    v1.Add(i1);
    TEST(4 == v1.GetSize());
    v1.Remove(3);
    TEST(3 == v1.GetSize());*/
}

void TestGetCapacity()
{
    /*SortedVector<newType> v1;

    TEST(10 == v1.GetCapacity());

    SortedVector<newType> v2(20);

    TEST(20 == v2.GetCapacity());*/
}

void TestParenthesesOperator()
{
    /*SortedVector<newType> v1;
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

    TRY(v1[22] = i2);*/
}

void TestParenthesesOperatorConst()
{
    /*SortedVector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1[0].a);
    TEST(i1.b == v1[0].b);
    TEST(i1.c == v1[0].c);

    const SortedVector<newType> v2(v1);
    TEST(i1.a == v2[0].a);
    TEST(i1.b == v2[0].b);
    TEST(i1.c == v2[0].c);*/
}

void TestAt()
{
    /*SortedVector<newType> v1;

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

    TRY(v1.At(22) = i2);*/
}

void TestAtConst()
{
    /*SortedVector<newType> v1;
    newType i1 = {1, 2, '1'};

    v1.Add(i1);
    TEST(i1.a == v1.At(0).a);
    TEST(i1.b == v1.At(0).b);
    TEST(i1.c == v1.At(0).c);

    const SortedVector<newType> v2(v1);
    TEST(i1.a == v2.At(0).a);
    TEST(i1.b == v2.At(0).b);
    TEST(i1.c == v2.At(0).c);*/
}

void TestAdd()
{
    /*SortedVector<newType> v1;
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
    TEST(i2.c == v1[1].c);*/
}

void TestRemove()
{
    /*SortedVector<newType> v1;

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

    TRY(v1.Remove(22));*/
}

void TestReserve()
{
    /*SortedVector<newType> v1;

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
    TEST(12 == v1.GetCapacity());*/
}

void TestTruncate()
{
    /*SortedVector<newType> v1(12);

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
    TEST(12 == v1.GetCapacity());*/
}

void TestShrink()
{
    /*SortedVector<newType> v1;

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
    TEST(i5.c == v1.At(4).c);*/
}

void TestClean()
{
    /*SortedVector<newType> v1(15);
    
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
    TRY(v1[0].a = 10);*/
}

void TestReset()
{
    /*SortedVector<newType> v1(5);
    
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
    TEST(5 == v1.GetCapacity());*/
}