import unittest

from moon import Satellite, SatelliteBuilder

class SatelliteTest(unittest.TestCase):
    def testSatellite(self):
        distance : float = 17
        orbits : str = "Mars"
        satellite : Satellite = Satellite(distance, orbits)

        self.assertEqual(satellite.distance,distance)
        self.assertEqual(satellite.orbits,orbits)

class SatelliteBuilderTest(unittest.TestCase):
    def testBuildSatellite(self):
        distance : float = 17
        orbits : str = "Mars"

        builder = SatelliteBuilder()
        sat1 = builder.orbits(orbits).build()
        sat2 = builder.distance(2*distance).build()

        self.assertEqual(sat1.distance,distance)
        self.assertEqual(sat1.orbits,orbits)
        self.assertEqual(sat2.distance,2*distance)
        self.assertEqual(sat2.orbits,orbits)
        
if __name__ == '__main__':
    unittest.main()