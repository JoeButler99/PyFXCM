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
        
        
class TestPyFXCMLoginParams(unittest.TestCase):
    def test_constructor(self):
        l1 = PyFXCM.LoginParams('user','test')
        l2 = PyFXCM.LoginParams('user','test','Demo')
        l3 = PyFXCM.LoginParams('user','test','Demo','www.google.co.uk')
        for l in [l1,l2,l3]:
            self.assertEqual(l.get_login(), 'user')
            self.assertEqual(l.get_password(), 'test')
        self.assertEqual(l1.get_connection_type(), "Real")
        self.assertEqual(l2.get_connection_type(), "Demo")
        self.assertEqual(l3.get_connection_type(), "Demo")
        self.assertEqual(l1.get_url(), "http://www.fxcorporate.com/Hosts.jsp")
        self.assertEqual(l2.get_url(), "http://www.fxcorporate.com/Hosts.jsp")
        self.assertEqual(l3.get_url(), "www.google.co.uk")
        

        
        
if __name__ == '__main__':
    unittest.main()