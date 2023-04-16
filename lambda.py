from functools import reduce

#建立簡易函數
mul=lambda a,b:a*b
print(mul(4,8))
#->print((lambda a,b:a*b)(4,8))

#幫助建立篩選過後的新陣列
n=[3,56,6,4,84,56546,4654,6,64]
res1=filter(lambda x:x>10,n)
print(list(res1))
#list是必要的，因為上面的filter加上lambda
#會比較像是一個函式，如果不加list的話她會認為你只是在確認
#這個函式的代號而已，要給資料型態他才會執行
#map也使用相同的方式使用

res2=reduce(lambda x,y:x+y,n)
print(res2)
#reduce->將當下這一項經由lambda處理後傳至下一項

#幫助進行多建值排序
x=[]
for i in range(20):
    x.append([i,20-i,(20-i)//2+i])
x.sort(key=lambda x:x[0])
print(x)
x.sort(key=lambda x:x[1])
print(x)
x.sort(key=lambda x:x[2])
print(x)