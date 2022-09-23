#include <cpp_in_python/sub_two_ints.h>

using namespace cpp_in_python;

std_msgs::Int64 SubTwoInts::sub(const std_msgs::Int64 &a, const std_msgs::Int64 &b)
{
    std_msgs::Int64 difference;
    difference.data = a.data - b.data;
    return difference;
}