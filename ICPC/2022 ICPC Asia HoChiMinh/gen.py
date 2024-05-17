import subprocess
from random import choice, randint

def gen_input():
  alphabet = "ab"
  res = ["1"]
  n = 1000
  k = randint(2, n-1)
  res.append(''.join(choice(alphabet) for _ in range(n)))
  res.append(f"{k}")
  return '\n'.join(res)

while True:
  inp = gen_input()
  sol = subprocess.run(['./l'], text=True, capture_output=True, input=inp)
  if sol.returncode != 0:
    print(inp)
    break
