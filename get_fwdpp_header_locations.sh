#!/bin/bash

python3 -m fwdpy11 --includes|sed 's/-I//g'|cut -d" " -f2

