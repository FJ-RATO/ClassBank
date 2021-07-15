import math
#e1
impar = lambda num : (num % 2) != 0
#print(impar(3))

#e2
pos = lambda num : num < 0
#print(pos(-1)) 

#e3
check = lambda n1,n2 : abs(n1) < abs(n2)
#print(check(2,.4))

#4
polar = lambda x,y : (math.sqrt(x*x+y*y), math.atan(x/y))
#print(polar(1,1))

#5
def plz(h,f,g):
    return lambda x,y,z : h(f(x,y), g(y,z))

#6
def uni(lst,func):
    if lst == []:
        return True
    if func(lst[0]):
        uni(lst[1:],func)
    return False

#9
def small(lst,func):
    if lst == []:
        return []
    if len(lst) == 1:
        return lst[0]

    if  func(lst[0],lst[1]):
        return small([lst[0]]+lst[2:],func)
    
    return small(lst[1:],func)

print(small([6,2,3,4,4,2,1],lambda a,b: a < b))

#10

    