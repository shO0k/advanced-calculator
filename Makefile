#pragma once
a.out: main.cc functions.cc
    g++ -O3 main.cc functions.cc
clean:
    rm a.out
