#include "../../../code/templates/containers/Array.hpp"
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
static void TestInsert();
static void TestRemoveAt();
static void TestRemoveObj();
static void TestReserve();
static void TestTruncate();
static void TestShrink();
static void TestClean();
static void TestReset();
static void TestConstFind();
static void TestNonConstFind();
static void TestIsExisting();

int Array_main()
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
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}

static void TestAssignmentOperator()
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

static void TestIsEmpty()
{
    Array<int> a1;

    TEST(1 == a1.IsEmpty());
    int i1 = 1;
    a1.Add(i1);
    TEST(0 == a1.IsEmpty());
}

static void TestGetSize()
{
    Array<int> a1;

    TEST(0 == a1.GetSize());
    int i1 = 1;
    a1.Add(i1);
    a1.Add(i1);
    a1.Add(i1);
    a1.Add(i1);
    TEST(4 == a1.GetSize());
    a1.RemoveAt(3);
    //TRY(1 == a1.Remove(3));
    TEST(3 == a1.GetSize());
}

static void TestGetCapacity()
{
    Array<int> a1;

    TEST(10 == a1.GetCapacity());

    Array<int> a2(20);

    TEST(20 == a2.GetCapacity());
}

static void TestParenthesesOperator()
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

static void TestParenthesesOperatorConst()
{
    Array<int> a1;
    int i1 = 1;

    a1.Add(i1);
    TEST(i1 == a1[0]);

    const Array<int> a2(a1);
    TEST(i1 == a2[0]);
}

static void TestAt()
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

static void TestAtConst()
{
    Array<int> a1;
    int i1 = 1;

    a1.Add(i1);
    TEST(i1 == a1.At(0));
    
    const Array<int> a2(a1);
    TEST(i1 == a2.At(0));
}

static void TestAdd()
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

static void TestInsert()
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

static void TestRemoveAt()
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

    a1.RemoveAt(0);
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

    a1.RemoveAt(2);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i5 == a1[2]);

    TRY(a1.RemoveAt(22));
}

static void TestRemoveObj()
{
    Array<int> a1;

    int i1 = 11;
    a1.Add(i1);
    TEST(i1 == a1[0]);

    int i2 = 22;
    a1.Add(i2);
    TEST(i1 == a1[0]);
    TEST(i2 == a1[1]);

    int i3 = 33;
    a1.At(0) = i3;
    TEST(i3 == a1[0]);
    TEST(i2 == a1[1]);

    a1.RemoveObj(i3);
    TEST(i2 == a1[0]);

    a1.Add(i3);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);

    int i4 = 44;
    a1.Add(i4);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i4 == a1[2]);

    int i5 = 55;
    a1.Add(i5);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i4 == a1[2]);
    TEST(i5 == a1[3]);

    a1.RemoveObj(i4);
    TEST(i2 == a1[0]);
    TEST(i3 == a1[1]);
    TEST(i5 == a1[2]);

    int i6 = 66;
    TEST(false == a1.RemoveObj(i6));
}

static void TestReserve()
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

static void TestTruncate()
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

static void TestShrink()
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

static void TestClean()
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

static void TestReset()
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

static void TestConstFind()
{
    Array<int> a1(6);
    const int element_0 = 0, element_1 = 1, element_2 = 2, element_3 = 3, element_4 = 4, extern_4 = 4, extern_5 = 5;

    a1.Add(element_0);
    a1.Add(element_1);
    a1.Add(element_2);
    a1.Add(element_3);
    a1.Add(element_4);

    const Array<int> a2(a1);

    TEST((element_0 == *a2.Find(element_0)));
    TEST((element_1 == *a2.Find(element_1)));
    TEST((element_2 == *a2.Find(element_2)));
    TEST((element_3 == *a2.Find(element_3)));
    TEST((element_4 == *a2.Find(element_4)));
    TEST(!a2.Find(extern_5));
    TEST(a2.Find(extern_4));
}

static void TestNonConstFind()
{
    Array<int> a1(6);
    int element_0 = 0, element_1 = 1, element_2 = 2, element_3 = 3, element_4 = 4, extern_4 = 4, extern_5 = 5;

    a1.Add(element_0);
    a1.Add(element_1);
    a1.Add(element_2);
    a1.Add(element_3);
    a1.Add(element_4);

    TEST((element_0 == *a1.Find(element_0)));
    TEST((element_1 == *a1.Find(element_1)));
    TEST((element_2 == *a1.Find(element_2)));
    TEST((element_3 == *a1.Find(element_3)));
    TEST((element_4 == *a1.Find(element_4)));
    TEST(!a1.Find(extern_5));
    TEST(a1.Find(extern_4));
}

static void TestIsExisting()
{
    Array<int> a1(6);
    int iExist0 = 0, iExist1 = 1, iExist2 = 2, i3 = 3, i4 = 4;

    a1.Add(iExist0);
    a1.Add(iExist1);
    a1.Add(iExist2);

    TEST(a1.IsExisting(iExist2));
    TEST(a1.IsExisting(iExist1));
    TEST(a1.IsExisting(iExist0));
    TEST(!a1.IsExisting(i3));
    TEST(!a1.IsExisting(i4));
}