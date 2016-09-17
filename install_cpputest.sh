#!/bin/bash

git clone git://github.com/cpputest/cpputest.git
cd cpputest/cpputest_build
cmake .. -DC++11=ON -DCOVERAGE=ON -DCMAKE_INSTALL_PREFIX=.
sudo make install || exit 1