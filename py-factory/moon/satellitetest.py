import unittest

from moon import Satellite

class SatelliteTest(unittest.TestCase):
    def testSatellite(self):
        distance : float = 17
        orbits : str = "Mars"
        satellite : Satellite = Satellite(distance, orbits)

        self.assertEqual(satellite.distance,distance)
        self.assertEqual(satellite.orbits,orbits)

        
if __name__ == '__main__':
    unittest.main()