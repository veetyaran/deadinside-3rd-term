#include <stdio.h>
#include "data.h"

using namespace std;

int binarySearch(data a, int n, data x)
{
    int head = 0, tail = n - 1, mid = 0;
    if(a[head] > a[tail]) return -1;
    else{
        while (head != tail))
        {
            mid = head + (tail - head)/2;
            if(a[mid] < x) head = mid + 1;
            else tail = mid;            
            if(tail == head) return head;
        }
    }
}