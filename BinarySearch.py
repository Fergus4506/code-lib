def BinarySearch(n,grid):
    low,upper=0,len(grid)-1
    while low<=upper:
        mid=(low+upper)//2
        if grid[mid]==n:
            return mid
        elif n>grid[mid]:
            low=mid+1
        else:
            upper=mid-1
    return -1
x=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
print(BinarySearch(18,x))
print(BinarySearch(55,x))