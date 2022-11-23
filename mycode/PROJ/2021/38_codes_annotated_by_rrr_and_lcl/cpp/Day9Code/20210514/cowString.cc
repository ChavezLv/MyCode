#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    //String s1;
    String()
    : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;
        initRefCount();
    }

    //String s1("hello");
    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefCount();
    }

    //String s2 = s1
    String(const String &rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(const String &)" << endl;
        increaseRefCount();
    }

    //String s3("world");
    //s3 = s1;
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;

        if(this != &rhs)//1、自复制
        {
            release();//2、释放左操作数

            _pstr = rhs._pstr;//3、浅拷贝
            increaseRefCount();
        }

        return *this;//4、返回*this
    }

    //s3[0] = 'H';
    char &operator[](size_t idx)
    {
        if(idx < size())
        {
            if(getRefCount() > 1)//是共享
            {
                char *ptmp = new char[strlen(_pstr) + 5]() + 4;
                strcpy(ptmp, _pstr);
                decreaseRefCount();
                _pstr = ptmp;
                initRefCount();
            }
            return _pstr[idx];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        release();
    }

    const char *c_str() const
    {
        return _pstr;
    }

    int getRefCount() const
    {
        return *(int *)(_pstr - 4);
    }

    size_t size() const
    {
        return strlen(_pstr);
    }

    void initRefCount()
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increaseRefCount()
    {
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefCount()
    {
        --*(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefCount();
        if(0 == getRefCount())
        {
            delete [] (_pstr - 4);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);
private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test()
{
    String s1("hello");
    cout << "s1 = " << s1 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s1's RefCount = %d\n", s1.getRefCount());

    cout << endl;
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s1's RefCount = %d\n", s1.getRefCount());
    printf("s2's RefCount = %d\n", s2.getRefCount());

    cout << endl;
    String s3("world");
    cout << "s3 = " << s3 << endl;
    printf("s3's address: %p\n", s3.c_str());
    printf("s3's RefCount = %d\n", s3.getRefCount());

    cout << endl << "执行s3 = s1操作" << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    printf("s1's RefCount = %d\n", s1.getRefCount());
    printf("s2's RefCount = %d\n", s2.getRefCount());
    printf("s3's RefCount = %d\n", s3.getRefCount());

    cout << endl << "对s3[0] = \'H\'" << endl;
    s3[0] = 'H';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    printf("s1's RefCount = %d\n", s1.getRefCount());
    printf("s2's RefCount = %d\n", s2.getRefCount());
    printf("s3's RefCount = %d\n", s3.getRefCount());

    cout << endl << "对s1[0]读操作的时候" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    printf("s1's RefCount = %d\n", s1.getRefCount());
    printf("s2's RefCount = %d\n", s2.getRefCount());
    printf("s3's RefCount = %d\n", s3.getRefCount());
}

int main(int argc, char **argv)
{
    test();
    return 0;
}