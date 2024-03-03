namespace AG
{

template <class T>
struct IComparator
{
    virtual int Compare(const T& left, const T& right) const = 0;
};

}