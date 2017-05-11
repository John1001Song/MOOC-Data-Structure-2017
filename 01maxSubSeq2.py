size = int(input())

array = input().split()
array = list(map(int, array))

thisSum = maxSum = 0
i = 0

head = tempHead = array[0]
tail = array[size-1]

for i in range(0, size):
	thisSum += array[i]
	if thisSum > maxSum:
		maxSum = thisSum
		tail = array[i]
		head = tempHead
	elif thisSum < 0:
		 thisSum = 0
		 if i < size-1:
		 	tempHead = array[i+1]

flag = -1
negativeNumbCounter = size

for x in array:
	if x > 0:
		flag = 1
	if x < 0:
		negativeNumbCounter = negativeNumbCounter-1


if flag == 1:
	print(str(maxSum) + ' ' + str(head) + ' ' + str(tail))
if flag == -1 and negativeNumbCounter == 0:
	print(str(0) + ' ' + str(array[0]) + ' ' + str(array[size-1]))
else: 
	print(str(0) + ' ' + str(0) + ' ' + str(0))
