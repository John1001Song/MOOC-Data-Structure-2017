size = int(input())
array = input().split()
array = list(map(int, array))

thisSum = maxSum = 0

for x in array:
	thisSum += x
	if thisSum > maxSum:
		maxSum = thisSum
	elif thisSum < 0:
		thisSum = 0

#print(size)

#for x in array:
#	print (x)

#print(array)
print(maxSum)