from collections import deque

def find_permutations(nums):
  numsLength = len(nums)
  result = []
  permutations = deque()
  permutations.append([])
  for currentNumber in nums:
    n = len(permutations)
    for _ in range(n):
      oldPermutation = permutations.popleft()
      for j in range(len(oldPermutation)+1):
        newPermutation = list(oldPermutation)
        newPermutation.insert(j, currentNumber)
        if len(newPermutation) == numsLength:
          result.append(newPermutation)
        else:
          permutations.append(newPermutation)

  return result