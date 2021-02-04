import unittest

from moon import Moon

class MoonTest(unittest.TestCase):
    def testDefaultMoon(self):
        size : int = 3
        color : str = "blue"
        phase : int = 0
        moon : Moon = Moon(size, color, phase)
        self.assertEqual(moon.phase,phase)
        self.assertEqual(moon.color,color)
        self.assertEqual(moon.size,size)

    def testCycle(self):
        size : int = 3
        color : str = "blue"
        phase : int = 0
        moon : Moon = Moon(size, color, phase)
        self.assertEqual(moon.phase,phase)
        self.assertEqual(moon.color,color)
        self.assertEqual(moon.size,size)
        moon.cycle()
        self.assertEqual(moon.phase,phase+1)
        
if __name__ == '__main__':
    unittest.main()