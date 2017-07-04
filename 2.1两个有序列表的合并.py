#2.1两个有序列表的合并.py

list1 = input()
list2 = input()
result = []

list1 = [int(s) for s in list1.split() if s.isdigit]
list2 = [int(s) for s in list2.split() if s.isdigit]

if list1 != []:
	list1.remove(-1)

if list2 != []:
	list2.remove(-1)

result = list1 + list2

result.sort()

if result == []:
	print('NULL')
elif result != []:
	print(result)

