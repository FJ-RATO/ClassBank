lista = ['a','b','c','d','e','f']
lista_n = [1,2,3,4,5,6]
lista_cap = [1,2,3,2,1]
lista_lista = [[1,2,3],[4,5],[6,7,8,9]]
#e1
def comprimento(lst):
    if lst == []:
        return 0
    return 1 + comprimento(lst[1:])

print(f"O comprimento da lista é {comprimento(lista)}")

#e2
def soma(lst):
    if lst == []:
        return 0
    return lst[0] + soma(lst[1:])

print(f"A soma é {soma(lista_n)}")

#e3
def check(lst,elem):
    if lst == []:
        return False
    return lst[0] == elem or check(lst[1:],elem) 

print(f"4 está na lista : {check(lista_n,4)}")

#4
def concatenar(l1,l2):
    if l1 == []:
        return l2[:]
    rec = concatenar(l1[1:],l2)
    rec[:0] = l1[:1]
    return rec

print(concatenar(lista,lista_n))

#5
def reverse(lst):
    if lst == []:
        return lst
    return lst[-1:] + reverse(lst[:-1])

print(reverse(lista))

#6
def capicua(lst):
    if lst[0] != lst[-1]:
        return False
    if len(lst) < 2:
        return True
    return capicua(lst[1:-1])

print(capicua(lista))
print(capicua(lista_cap))

#7
def list_list(lst)
    