#include <unistd.h>
#include "bitmap.hpp"

int main()
{
    bitset bitmap(10000000);
    bitmap.set(100);
    sleep(1);
    bitmap.set(1000);
    sleep(1);
    bitmap.set(10000);
    sleep(1);

    cout<<"100 in bitmap:"<<bitmap.test(100)<<endl;
    sleep(1);
    cout<<"1000 in bitmap:"<<bitmap.test(1000)<<endl;
    sleep(1);
    cout<<"10000 in bitmap:"<<bitmap.test(10000)<<endl;
    sleep(1);

    bitmap.reset(1000);
    sleep(1);
    cout<<"reset 1000 done:"<<bitmap.test(1000)<<endl;
    sleep(1);
    return 0;
}
