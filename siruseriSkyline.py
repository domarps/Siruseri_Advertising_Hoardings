import collections
import re
 
class SetElement:
    def __init__(self):
        self.parent = self
 
    def root(self):
        if self.parent is self:
            return self
        else:
            return self.parent.root()
 
    def union(self, other):
        self.root().parent = other.root()
 
# Building has width, height, index
Building = collections.namedtuple('Building', 'w h i')
 
def main():
    numbuildings = int(input("How many buildings: "))
    buildings = []
   
    for n in range(numbuildings):
        (w, h) = re.match(r"([0-9]+) ([0-9]+)", input("w h: ")).groups()
        buildings.append(Building(int(w), int(h), n))
 
    sets = [SetElement() for elem in buildings]
    by_height = sorted(buildings, key=lambda n: n.h, reverse=True)
   
    max_i = len(buildings) - 1
    max_S = 0
    max_start = -1
    max_end = max_i + 1
 
    for elem in by_height:
        # Union with previous/next if shorter or equal
        # If we merge with both, both get the same root due to union
        if elem.i > 0 and elem.h <= buildings[elem.i - 1].h:
            sets[elem.i].union(sets[elem.i - 1])
           
        if elem.i < max_i and elem.h <= buildings[elem.i + 1].h:
            sets[elem.i].union(sets[elem.i + 1])
 
        # Now we know which set we belong to, just find our root
        cur_root = sets[elem.i].root()
 
        # Accumulator and walk index
        cur_w = elem.w
        cur_i = elem.i
       
        while cur_i > 0 and cur_root is sets[cur_i - 1].root():
            cur_w += buildings[cur_i - 1].w
            cur_i -= 1
 
        low_i = cur_i
        cur_i = elem.i # reset index
 
        while cur_i < max_i and cur_root is sets[cur_i + 1].root():
            cur_w += buildings[cur_i + 1].w
            cur_i += 1
 
        high_i = cur_i
 
        # latest addition is shortest building, so elem.h is cur_h
        cur_S = cur_w * elem.h
       
        if cur_S > max_S:
            max_S = cur_S
            max_start = low_i
            max_end = high_i
 
    print("S: {}, start: {}, end: {}".format(max_S, max_start, max_end))
 
if __name__ == "__main__":
    main()
