#include <iostream>
using namespace std;

class ciao {

    public:
        ciao(){};

        void hello()
        {
            cout << "\nHello World!!\n\n";
        }
};

int main()
{
    ciao c;

    c.hello();

    return 0;
}