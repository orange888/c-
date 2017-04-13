#pragma
#include <iostream>
#include <vector>
using namespace std;

class bitset
{
private:
    vector<size_t> datas;
    size_t converse(const size_t & val)
    {
        return val >> 5;
    }
public:
    bitset(size_t size)
    {
        //use int save data
        //>> 5 == /32 +1 == start 0
        datas.reserve((size >> 5) + 1);
        datas.assign((size >> 5) + 1, 0);
    }
    ~bitset()
    {}

    bool test(const size_t & val)//test data is exist
    {
        size_t index = converse(val);
        size_t pos = val % 32;

        return datas[index]&(1<<pos);
    }
    bool set(const size_t &val) //1
    {
        size_t index = converse(val);
        size_t pos = val % 32;
        datas[index] |= (1<<pos);
        return true;
    }
    bool reset(const size_t &val) //0
    {
        size_t index = converse(val);
        size_t pos = val % 32;
        datas[index] &= ~(1<<pos);
        return true;
    }
    void cleaar()
    {
        datas.clear();
    }
};
