#!/usr/bin/env python

from glob import iglob, glob
from subprocess import call
from os import path
files = iglob('**/*.gcda', recursive=True)
for file in files:
    call([
        'gcov', file, '--branch-counts', '--branch-probabilities',
        '--preserve-paths', '--object-directory',
        path.dirname(file)
    ])
toDelete = glob('#*.gcov') + glob('*test*.gcov')
call(['rm', '-f'] + toDelete)
