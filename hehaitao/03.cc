/*
 * ============================================================================
 *
 *       Filename:  3.cc
 *
 *    Description:  vector<int> the max sum of all subarrays in O(n) time limit
 *
 *        Version:  1.0
 *        Created:  07/08/13 10:11:27
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

typedef vector<int>::iterator IntItor;
bool MaxSum(vector<int> src_vector, int &max_sum)
{
    if (src_vector.size() == 0)
        return false;

    int cur_sum = 0;
    max_sum = 0;

    for (IntItor itor = src_vector.begin(); itor != src_vector.end(); itor++)
    {
        cur_sum += *itor;

        if (cur_sum < 0)
            cur_sum = 0;

        if (cur_sum > max_sum)
            max_sum = cur_sum;
    }

    if (max_sum == 0)
    {
        max_sum = *(src_vector.begin());

        for (IntItor itor = src_vector.begin();  itor != src_vector.end(); itor++)
        {
            if (*itor > max_sum)
            {
                max_sum = *itor;
            }
        }
    }

    return true;
}

int main()
{
    int array[] = {3, 2, -3, 4};
    vector<int> temp(array, array + sizeof(array)/sizeof(int));
    int max_sum = 0;

    if (MaxSum(temp, max_sum))
        cout << "max_sum:" << max_sum << endl;
}
