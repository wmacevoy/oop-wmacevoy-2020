from typing import List

class Satellite:
    def __init__(self, distance : float, orbits : str) :
        self._distance = distance
        self._orbits = orbits


    @property
    def distance(self):
        return self._distance

    @property
    def orbits(self):
        return self._orbits

    def clone(self) -> 'Satellite':
        return Satellite(self._distance, self._orbits)

class SatelliteBuilder:
    DEFAULT_DISTANCE : float = 384.4e6
    DEFAULT_ORBITS : str = "earth"

    def __init__(self, distance : float = DEFAULT_DISTANCE, 
                        orbits : str = DEFAULT_ORBITS) :
        self._distance = distance
        self._orbits = orbits

    def distance(self, value : float) -> 'SatelliteBuilder':
        self._distance = value
        return self

    def orbits(self, value : str) -> 'SatelliteBuilder':
        self._orbits = value
        return self

    def build(self) -> Satellite:
        return Satellite(self._distance, self._orbits)

# classes are "blueprints" for objects.

# Moon is a derived class of Satellite
# Satelliite is a base class of Moon

#  "Moon is a Satellite" --- sounds right 
#  "A crater is a Moon" --- sounds wrong
#  "Moon has a (collection of) Crater" 

# phobos is an instance of Moon (singular version of)
  
class Crater:
    pass

class Moon(Satellite):

    # constructor - used to initialize a new moon (instance of Moon)
    #
    #   make an instance, then the blueprint has to have a way to
    #   refer to "itself".  In python, that is "self"
    def __init__(self,distance : float, orbits : str,
           size : int,color : str, phase : int = 0) -> None:
        Satellite.__init__(self, distance, orbits)
        # properties...
        self._size : int = size
        self._color : str = color
        self._phase : int = phase
        self._craters : List[Crater] = []

    def isNewMoon(self) -> bool:
        return self._phase == 0

    def cycle(self) -> None:
        self._phase = (self._phase + 1) % 4

    @property
    def phase(self) -> int:
        return self._phase

    @property
    def color(self) -> str:
        return self._color

    @color.setter
    def color(self,value : str) -> None:
        if not value in ['grey','blue','white','silver']:
            raise ValueError('invalid moon color')
        self._color = value

    @property
    def size(self):
        return self._size

    def clone(self):
        return Moon(self._distance, self._orbits, self._size, self._color, self._phase)
