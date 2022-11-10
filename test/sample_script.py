#!/usr/bin/env python
# -*- coding: utf-8 -*-

from std_msgs.msg import Int64
from cpp_in_python import SubTwoInts

a = Int64(4)
b = Int64(2)
subtwoints = SubTwoInts()
difference = subtwoints.sub(a, b)
print(difference)