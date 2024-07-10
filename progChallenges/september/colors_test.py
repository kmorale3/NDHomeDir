import unittest
import colors

# Test Case

class ColorsTestCase(unittest.TestCase):

    def test__00__count_colors(self):
        self.assertEqual(
            colors.count_colors([0,1,2]),
            [1, 1, 1]
        )

if __name__ == '__main__':
    unittest.main()