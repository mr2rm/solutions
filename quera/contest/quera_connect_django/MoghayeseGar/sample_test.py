import unittest
from moghayeseGar import compare


class Test(unittest.TestCase):

	def sample_test_1(self):
		self.assertEqual('las', compare('ali', 'salib'))

	def sample_test_2(self):
		self.assertEqual('Both strings are empty!', compare('nima', 'amin'))
