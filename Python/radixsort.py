def radix_sort(nums):
    RADIX = 10
    placement = 1
    max_digit = max(nums)

    while placement < max_digit:
      buckets = [list() for _ in range( RADIX )]
      for i in nums:
        tmp = int((i / placement) % RADIX)
        buckets[tmp].append(i)
      a = 0
      for b in range( RADIX ):
        buck = buckets[b]
        for i in buck:
          nums[a] = i
          a += 1
      placement *= RADIX
    return nums
user_input = input("Input numbers separated by a space:\n").strip()
nums = [int(item) for item in user_input.split(' ')]
print(radix_sort(nums))
