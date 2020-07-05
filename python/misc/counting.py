#!/usr/bin/env python
# Python: Counting
# how many in the range low, high

def inBucket(t, low, high):
  count = 0
  for num in t:
    if low < num < high:
      count = count + 1
  return count

def main():
	print inBucket([1, 2, 3, 4, 5, 6, 7, 8, 9], 3, 7)
	print inBucket("ciccio", 3, 7)
	

if __name__ == '__main__':
	main()
