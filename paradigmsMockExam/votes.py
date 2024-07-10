import math
class Votes:
   def __init__(self,v):
      self.v = v

   def __add__(self, vote):
      return self.v + vote.v

   def __eq__(self, vote):
      return self.v == vote.v

    

v1 = Votes(12)
v2 = Votes(5)
v3 = Votes(12)
print(v1 + v2)
print(v1 == v2)
print(v1 == v3)

assert v1+v2 == 17
assert v1==v3