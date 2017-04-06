type Point2 =(Float,Float)
 
data Area = Rectangular Point2 Point2 
| Circle Point2 Float
| Union [Area]
| Intersection [Area]
derivingShow
 
contains :: Area -> Point2 ->Bool
contains (Rectangular (x, y)(x1, y1))(x2, y2)=and[x <= x2, x1 >= x2, y <= y2, y1 >= y2]
 
contains (Circle (x, y) r)(x2, y2)=((x-x2)^2+(y-y2)^2)<= r^2
 
contains (Union t) p =any(\t1 -> contains t1 p) t
contains (Intersection t) p =all(\t1 -> contains t1 p) t
 
 
isRectangular :: Area ->Bool
isRectangular (Rectangular __)= True 
isRectangular (Union t)=all isRectangular t
isRectangular (Intersection t)=all isRectangular t
isRectangular _= False
 
 
isEmpty :: Area ->[Point2]->Bool
isEmpty area ps =not$any(contains area) ps
