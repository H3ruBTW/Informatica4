#include <iostream>
#include <string>
using namespace std;

class test1
{
private:
    /* data */
    string tpri1 = "Sono la variabile privata di test1";
public:
    string tpub1 = "Sono la variabile pubblica di test1";
    
    test1(){
        cout << "Sono stato creato" << endl
             << tpri1 << endl
             << tpub1 << endl;
    }

    string getTpriv1()
    {
        return tpri1;
    }
};

class test2 : public test1
{
private:
    /* data */
    string tpri2 = "Sono la variabile privata di test2";
public:
    string tpub2 = "Sono la variabile pubblica di test2";

    test2(): test1(){
        cout << tpri2 << endl
             << tpub2 << endl;
    }

    string getTpriv2()
    {
        return tpri2;
    }
};

class test3 : public test2
{
private:
    /* data */
public:
    test3(): test2(){};
};

int main()
{
    cout << "Test 1:" << endl;
    test1 test;

    cout << "Test 2:" << endl;
    test2 test2;

    cout << "Test 3:" << endl;
    test3 test3;

    return 0;
}
