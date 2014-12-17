#!/usr/bin/env python
import sys
import unittest
import yaml
import re

try:
    import PyFXCM
except:
    print "Cannot import PyFXCM. Did you successfully build and install with 'make python-module; make install'?"
    
    
class TestPyFXCM(unittest.TestCase):
    def test_version(self):
        version_str = PyFXCM.version()
        simple_version_regex = re.compile("\d+[.]\d+[.]\d+")
        self.assert_(simple_version_regex.match(version_str))
        
        
        
        
        
if __name__ == '__main__':
    unittest.main()