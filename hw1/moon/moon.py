
class Moon:

    # constructor
    def __init__(self,size : int,color : str, phase : int = 0) -> None:

        # properties...
        self._size : int = size
        self._color : str = color
        self._phase : int = phase

    def isNewMoon(self) -> bool:
        return self._phase == 0

    def cycle(self) -> None:
        self._phase = (self._phase + 1) % 4

    @property
    def phase(self):
        return self._phase

    @property
    def color(self):
        return self._color

    @property
    def size(self):
        return self._size



    

