#!/bin/bash
clang-3.5 -c mytest.c -emit-llvm -o mytest.bs
llvm-dis < mytest.bs > llvmout.bb