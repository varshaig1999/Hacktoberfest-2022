def bSort(arr):
  for i in range(len(arr)):
    for j in range(0, len(arr) - i - 1):
      if array[j] > array[j + 1]:
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp


Arr= [-2, 4, 0, 1,69,-5, -9]

bSort(Arr)

print('Sorted Array in Ascending Order:')
print(Arr)
