--1.Приведите пример простейших нетривиальных выражений, принадлежащих следующему типу:

--1) ((Char, Integer), String, [Double])

(('a',5),"hello",[5.69,3.98,2.32])

--2) [(Double, Bool, (String, Integer))]

[(4.2234,True,("string",5)),(5.32,False,("hello",6))]

--3) ([Integer], [Double],[(Bool, Char)])

([5,6,4,3],[4.32,5.433],[(True,'s'),(False,'f')])

--4) [[[(Integer, Bool)]]]

[[[(5,True),(4,False)],[(3,True),(2,False)]]]

--5) (((Char, Char), Char), [String])

((('a','b'),'c'),["hello","world"])

--6) (([Double], [Bool]), [Integer])

(([2.3,5.34],[True,True]),[7,9,0])

--7) [Integer, (Integer, [Bool])]

[0,(7,[True,False])]

--8) (Bool, ([Bool], [Integer]))

(True,([True,False],[7,8,9]))

--9) [([Bool], [Double])]

[([True,False],[9.98,6.87]),([False,True],[5.98,4.87])]

--10) [([Integer], [Char])]

[([8,9,7],"kgj"),([8,7],"ui")]

--Требование нетривиальности в данном случае означает, что встречающиеся в выражениях списки
--должны содержать больше одного элемента.

--2. Определите следующие функции:

--1)Функция max3, по трем целым возвращающая наибольшее из них.

max3:: Integer -> Integer -> Integer -> Integer
max3 x y z = if x>=y && x>=z then x
else if y>=x && y>=z then y
else z

--Нестрогое условие нам необходимо для тех случаев когда среди чисел xyz имеются равные

--2) Функция min3, по трем целым возвращающая наименьшее из них.

min3 :: Integer -> Integer -> Integer -> Integer
min3 x y z = if x<=y && x<=z then x
else if y<=x && y<=z then y
else z

--Нестрогое условие нам необходимо для тех случаев когда среди чисел x y z имеются равные

--3) Функция sort2, по двум целым возвращающая пару, в которой наименьшее из них стоит на первом месте,
--а наибольшее – на втором.

sort2 :: (Integer -> Integer -> ( Integer, Integer))
sort2 x y = if x>y then (y,x) else (x,y)

--4) Функция bothTrue :: Bool-> Bool -> Bool, которая возвращает True тогда и только
--тогда, когда оба ее аргумента будут равны True. Не используйте
--при определении функции стандартные логические операции ( &&, ||, и т.п).

bothTrue :: Bool-> Bool -> Bool
bothTrue x y = if [x,y]==[True,True] then True else False

--5) Функция solve2::Double->Double->(Bool,Double), которая по 
--двум числам представляющим собой коэффициенты линейного уравнения ax+b=0, возвращает
--пару, первый элемент которой равен True, если решение
--существует и False в противном
--случае; при этом второй элемент равен либо значению корня, либо 0.0.

solve2::Double->Double->(Bool,Double)
solve2 a b = if a==0 && b/=0 then (False,0.0)
else (True,-b/a)

--у линейного уравнения одной переменной нет решений
--тогда и только тогда когда коэффициент при x равен нулю а
--свободный коэффициент b не равен нулю.

--6) Функция isParallel, возвращающая True если два отрезка концы которых задаются в
аргументах функции, параллельны (или лежат на одной прямой). Например, значение
выражения isParallel (1,1) (2,2)
(2,0) (4,2) должно быть равно True поскольку
отрезки (1,1) - (2,2) и (2,0) – (4.2 ) параллельны.

isParallel :: (Double,Double)->(Double,Double)->(Double,Double)->(Double,Double)->Bool
isParallel (a,b) (c,d) (e,f) (g,h) = if (c-a)/(g-e) == (d-b)/(h-f) then
True else False

--Необходимое и достаточное условие коллинеарности векторов, выраженное в координатах

--7) Функция isIncluded, аргументами
--которой служат параметры двух окружностей на плоскости (координаты центров и
--радиусы); функция возвращает True, если вторая
--окружность целиком содержится внутри первой.

isIncluded :: (Double,Double)-> Double ->(Double,Double)-> Double-> Bool
isIncluded (a,b) c (d,e) f = if (d-a)^2 + (e-b)^2 <= (f-c)^2 then
True else False

--8) Функция isRectangular, принимающая в качестве
--параметров координаты трех точек на плоскости и возвращающая True, если образуемый ими треугольник – прямоугольный.

isRectangular ::
(Double,Double)->(Double,Double)->(Double,Double)->Bool
isRectangular (a,b) (c,d) (e,f) = if (c-a)*(e-a)+(d-b)*(f-b)==0 ||
(a-c)*(e-c)+(b-d)*(f-d)==0 || (a-e)*(c-e)+(b-f)*(d-f)==0 then True else False

--Необходимое и достаточное условие ортогональности векторов, выраженное в координатах.

--9) Функция isTriangle, определяющая
--можно ли из отрезков с заданными длинами x.y,z, построить
--треугольник.

isTriangle :: Double -> Double -> Double -> Bool
isTriangle x y z = if z<(x+y) && z>(x-y) then True else
False

--третья сторона должна быть меньше суммы двух других сторон и больше --их разности.

--10) Функция isSorted, принимающая на
--вход три числа и возвращающая True если они
--упорядочены по возрастанию или по убыванию.

isSorted :: Double->Double->Double->Bool
isSorted x y z = if (x>y && y>z) || (x<y &&
y<z) then True else False
