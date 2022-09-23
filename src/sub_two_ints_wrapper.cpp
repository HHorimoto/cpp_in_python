#include <boost/python.hpp>

#include <string>

#include <ros/serialization.h>
#include <std_msgs/Int64.h>

#include <cpp_in_python/sub_two_ints.h>

/* Read a ROS message from a serialized string.
 */
template <typename M>
M from_python(const std::string str_msg)
{
    size_t serial_size = str_msg.size();
    boost::shared_array<uint8_t> buffer(new uint8_t[serial_size]);
    for (size_t i = 0; i < serial_size; ++i)
    {
        buffer[i] = str_msg[i];
    }
    ros::serialization::IStream stream(buffer.get(), serial_size);
    M msg;
    ros::serialization::Serializer<M>::read(stream, msg);
    return msg;
}

/* Write a ROS message into a serialized string.
 */
template <typename M>
std::string to_python(const M &msg)
{
    size_t serial_size = ros::serialization::serializationLength(msg);
    boost::shared_array<uint8_t> buffer(new uint8_t[serial_size]);
    ros::serialization::OStream stream(buffer.get(), serial_size);
    ros::serialization::serialize(stream, msg);
    std::string str_msg;
    str_msg.reserve(serial_size);
    for (size_t i = 0; i < serial_size; ++i)
    {
        str_msg.push_back(buffer[i]);
    }
    return str_msg;
}

class SubTwoIntsWrapper : public cpp_in_python::SubTwoInts
{
public:
    SubTwoIntsWrapper() : SubTwoInts() {}

    std::string sub(const std::string &str_a, const std::string &str_b)
    {
        std_msgs::Int64 a = from_python<std_msgs::Int64>(str_a);
        std_msgs::Int64 b = from_python<std_msgs::Int64>(str_b);
        std_msgs::Int64 sum = SubTwoInts::sub(a, b);

        return to_python(sum);
    }
};

BOOST_PYTHON_MODULE(_sub_two_ints_wrapper_cpp)
{
    boost::python::class_<SubTwoIntsWrapper>("SubTwoIntsWrapper", boost::python::init<>())
        .def("sub", &SubTwoIntsWrapper::sub);
}