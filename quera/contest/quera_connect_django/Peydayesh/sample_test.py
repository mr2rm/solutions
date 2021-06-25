import unittest
from peydayesh import find


class Test(unittest.TestCase):

    def sample_test_1(self):
        self.assertEqual(4, find(1, 2, 3))

    def sample_test_2(self):
        self.assertEqual(2, find(1, 4, 3))
