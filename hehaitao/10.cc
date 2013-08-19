/*
 * ============================================================================
 *
 *       Filename:  10.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/11/13 09:44:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#include    <vector>
#include    <iostream>
using namespace std;
typedef int ElementT;
typedef vector<ElementT> VectorT;
typedef VectorT::iterator VectorItor;
typedef VectorT::const_iterator ConstVectorItor;

bool FindTwoEle(const VectorT &src_vector, const ElementT &dst_sum)
{
    ConstVectorItor begin = src_vector.begin();
    ConstVectorItor end = --src_vector.end();

    for ( ; begin != end; )
    {
        ElementT temp_sum = *begin + *end;

        if (temp_sum == dst_sum)
        {
            cout << "begin:" << *begin << "\tend:" << *end << endl;
            return true;
        }
        else if (temp_sum > dst_sum)
        {
            end--;
        }
        else if (temp_sum < dst_sum)
        {
            begin++;
        }
    }

    return false;
}

int main()
{
    const ElementT dst_sum = 15;
    ElementT temp[] = {1, 2, 4, 7, 11, 15};
    VectorT src_vector(temp, temp + sizeof(temp)/sizeof(ElementT));

    bool result = FindTwoEle(src_vector, dst_sum);

    if (result)
    {
        cout << "Find it" << endl;
    }
    else
    {
        cout << "Can't find it" << endl;
    }

    return 0;
}
