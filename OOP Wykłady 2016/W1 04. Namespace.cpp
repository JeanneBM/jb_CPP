#include <iostream>

namespace A{
    int fun();
}

namespace B {namespace C {namespace D{
    int fun() {return 3;}
} } }

int main()
{
    int a = A::fun();
    int b = B::C::D::fun();
    std::cout << "Hello !! a=" << a << " b=" << b << std::endl;

    using namespace B::C;
    a=D::fun();
    std::cout << "Hello !! a=" << a << " b=" << b << std::endl;

    using D::fun;
    int c = fun();
    std::cout << "Hello !! a=" << a << " b=" << b << " c=" << c << std::endl;

    namespace AA=B::C::D;
    namespace BB=A;
    a = AA::fun();
    b = BB::fun();
    std::cout << "Hello !! a=" << a << " b=" << b << std::endl;

    using namespace AA;
    using namespace BB;
    a = AA::fun();
    b = BB::fun();
    std::cout << "Hello !! a=" << a << " b=" << b << std::endl;

    a = fun();
    b = fun();
    std::cout << "Hello !! a=" << a << " b=" << b << std::endl;
}

int A::fun()
{
    return 1;
}
