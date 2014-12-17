import sys
import unittest


try:
    import PyFXCM
except:
    print "Cannot import PyFXCM. Did you successfully build and install with 'make python-module; make install'?"