#!/usr/bin/env python
import sys
import re
filename = sys.argv[1]
with open(filename, 'r') as f:
    contents = f.read()
includes = re.findall('^#include "[^"]+"', contents, re.MULTILINE)
includes.extend(re.findall('^#include <[^>]+>', contents, re.MULTILINE))
functions = re.findall("^\S+ \w+\([^)]*\)(?= {)", contents, re.MULTILINE)
typedefs = re.findall("^typedef .+", contents, re.MULTILINE)
res = [f'{x}\n' for x in includes]
res.append("\nusing namespace std;\n\n")
res.extend([f'{x}\n' for x in typedefs])
res.append("\n")
res.extend([f'{x};\n' for x in functions])
with open(f'{filename[:-3]}h', 'w') as f:
    f.writelines(res)