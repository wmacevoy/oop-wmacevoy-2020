import unittest

from moon import Moon

class MoonTest(unittest.TestCase):

    def testSatellite(self):
        distance : float = 17
        orbits : str = "Mars"
        satellite : Moon = Moon(distance, orbits, 3, "black")

        self.assertEqual(satellite.distance,distance)
        self.assertEqual(satellite.orbits,orbits)

    def testDefaultMoon(self):
        distance : float = 17
        orbits : str = "Mars"
        size : int = 3
        color : str = "blue"
        phase : int = 0
        moon : Moon = Moon(distance, orbits, size, color, phase)
        self.assertEqual(moon.phase,phase)
        self.assertEqual(moon.color,color)
        self.assertEqual(moon.size,size)

    def testCloneMoon(self):
        distance : float = 17
        orbits : str = "Mars"
        size = 3
        color = "black"
        phase = 2
        moon : Moon = Moon(distance, orbits, size, color, phase)

        clonedMoon = moon.clone()

        newPhase = (phase+1)%4

        moon.cycle()


        self.assertEqual(moon.distance,distance)
        self.assertEqual(clonedMoon.distance,distance)
        self.assertEqual(moon.orbits,orbits)
        self.assertEqual(clonedMoon.orbits,orbits)
        self.assertEqual(moon.phase,newPhase)
        self.assertEqual(clonedMoon.phase,phase)
        self.assertEqual(moon.color,color)
        self.assertEqual(clonedMoon.color,color)
        self.assertEqual(moon.size,size)
        self.assertEqual(clonedMoon.size,size)


    def testCycle(self):
        distance : float = 17
        orbits : str = "Mars"
        size : int = 3
        color : str = "samantha"
        phase : int = 2
        moon : Moon = Moon(distance, orbits, size, color, phase)
        self.assertEqual(moon.phase,phase)
        self.assertEqual(moon.color,color)
        self.assertEqual(moon.size,size)
        moon.color = "white"
        if moon.phase == 2:
            print("half moon")
        moon.cycle()
        self.assertEqual(moon.phase,phase+1)
        
if __name__ == '__main__':
    unittest.main()