--1. Определите функцию, принимающую на вход целое число nи возвращающую список, содержащий n элементов, упорядоченных по возрастанию.
--1) Список натуральных чисел

sp_natur :: Integer -> [Integer]
sp_natur 0 =[]
sp_natur n = sp_natur(n-1)++[n]

--2) Список нечетных натуральных чисел

sp_nechet :: Integer -> [Integer]
sp_nechet 0 = []
sp_nechet n = sp_nechet(n-1)++[n*2-1]

--3) Список четных натуральных чисел

sp_chet :: Integer -> [Integer]
sp_chet 0 = []
sp_chet n = sp_chet(n-1)++[2*n]

--4) Список квадратов натуральных чисел

sp_kvadr :: Integer -> [Integer]
sp_kvadr 0 =[]
sp_kvadr n = sp_kvadr(n-1)++[n*n]

--5) Список факториалов

sp_factor :: Integer -> [Integer]
sp_factor 0 =[]
sp_factor n = sp_factor(n-1)++[n*n-1]

--6) Список степеней двойки

sp_dva :: Integer -> [Integer]
sp_dva 0 = []
sp_dva n = sp_dva(n-1)++[2^n]

--7) Список треугольных чисел*

sp_treug 0 = []
sp_treug n = sp_treug(n-1)++[n*(n+1)*0.5]

--8) Список пирамидальных чисел**

sp_piramid 0 = []
sp_piramid n = sp_piramid(n-1)++[n*(n+1)*0.5+n-1]

--2. Определите следующие функции:
--2) Функция вычленения n-го элемента из заданного списка

delete_elem :: Integer->[a]-> a
delete_elem 1 (h:t)= h
delete_elem n (h:t)= delete_elem (n-1) t

-- 9)Функция makePositive, которая меняет знак всех отрицательных элементов списка чисел, 
--например: makePositive [-1,0,5,-10,-20] дает [1,0,5,10,20].

makePositive ::
[Integer]->[Integer]
makePositive [] = []
makePositive
(h:t) = [abs h]++makePositive(t)
