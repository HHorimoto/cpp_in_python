#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse
from std_msgs.msg import Int64
from cpp_in_python import SubTwoInts

parser = argparse.ArgumentParser()
parser.add_argument('arg_1', type=int)
parser.add_argument('arg_2', type=int)
args = parser.parse_args()

a = Int64(args.arg_1)
b = Int64(args.arg_2)
subtwoints = SubTwoInts()
difference = subtwoints.sub(a, b)
print(difference.data)