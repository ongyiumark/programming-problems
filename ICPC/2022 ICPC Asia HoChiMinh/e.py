import math

class Point:
  def __init__(self, x, y):
    self.x = x
    self.y = y

  def __mul__(self, s):
    return Point(s*self.x, s*self.y)
  
  def __sub__(self, p):
    return Point(self.x-p.x, self.y-p.y)

  def __repr__(self):
    return f"({self.x}, {self.y})"

def dot(a, b):
  return a.x*b.x + a.y*b.y

def cross(a, b):
  return a.x*b.y - b.x*a.y

def twice_area(points):
  ret = 0
  n = len(points)
  for i in range(n):
    ret += cross(points[i], points[(i+1)%n])
  return abs(ret)

def six_area_centroid(points):
  n = len(points)
  x = y = 0
  for i in range(n):
    cur = points[i]
    nxt = points[(i+1)%n]
    x += (cur.x + nxt.x)*cross(cur, nxt)
    y += (cur.y + nxt.y)*cross(cur, nxt)

  return Point(x,y)

EPS = 1e-6
def get_angle(a, b):
  cos_ret = dot(a,b)/math.sqrt(dot(a,a))/math.sqrt(dot(b,b))
  ret = math.acos(cos_ret)
  if cross(a, b) < 0:
    ret = 2*math.pi - ret
  return ret


import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)
n = int(input())
points = [None]*n
for i in range(n):
  x, y = [int(t) for t in input().split()]
  points[i] = Point(x,y)

six_area = twice_area(points)*3
centroid = six_area_centroid(points)
for i in range(n):
  points[i] = points[i]*six_area

roll_edge = [0]*n
def find_edge(x):
  if roll_edge[x] == x: return x
  else:
    roll_edge[x] = find_edge(roll_edge[x])
    return roll_edge[x]

for i in range(n):
  cur = points[i]
  nxt = points[(i+1)%n]

  l2_edge = dot(nxt-cur, nxt-cur)
  if dot(centroid-cur, nxt-cur) > l2_edge: roll_edge[i] = (i+1)%n
  elif dot(centroid-nxt, cur-nxt) > l2_edge: roll_edge[i] = (i-1+n)%n
  else: roll_edge[i] = i

ans = [0]*n
for i in range(n):
  j = find_edge(i)
  if i != j: continue
  left, right = i, i
  while find_edge(left) == i: left = (left-1+n)%n
  while find_edge(right) == i: right = (right+1)%n
  left = (left+1)%n
  right = (right-1+n)%n
  
  a = points[left]-centroid
  b = points[(right+1)%n]-centroid
  angle = get_angle(a, b)

  ans[i] = angle/(2*math.pi)

for result in ans:
  print(f"{result:.20f}")

