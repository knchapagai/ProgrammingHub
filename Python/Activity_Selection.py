def MaxActivities(s, f ):
	n = len(f)
	print ("The following activities are selected")

	i = 0
	print (i,end=' ')

	for j in range(1, n):

		if s[j] >= f[i]:
			print (j,end=' ')
			i = j


s = [1 , 3 , 0 , 5 , 8 , 5]
f = [2 , 4 , 6 , 7 , 9 , 9]
MaxActivities(s , f)
