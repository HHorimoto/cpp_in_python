#ifndef SUB_TWO_INTS_H
#define SUB_TWO_INTS_H

#include <std_msgs/Int64.h>

namespace cpp_in_python
{
    class SubTwoInts
    {
    public:
        std_msgs::Int64 sub(const std_msgs::Int64 &a, const std_msgs::Int64 &b);
    };

} // namespace cpp_in_python

#endif // SUB_TWO_INTS_H