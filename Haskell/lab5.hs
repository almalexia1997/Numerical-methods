import Data.Char

average :: [Double] -> Double
average s = foldr (+) 0 s / foldr (\x y -> 1+y) 0 s
dotLists a b = foldr (+) 0 (zipWith (*) a b)
countEven a = length (filter (even) a)
qSort' :: (a -> a -> Bool) -> [a] -> [a]
qSort' fc []     = []
qSort' fc (x:xs) = qSort' fc (filter (fc x) xs) ++ [x] ++ (qSort' fc (filter (\ y -> not $ fc x y) xs))
 
data KeyCode = Shift | CapsLock | Key CharderivingShow
 
getAlNum ::[KeyCode]->[KeyCode]
getAlNum xs =[x |x @(Key _)<- xs]
 
getRaw ::[KeyCode]->String
getRaw xs =[x | Key x <- xs]
 
isCapsLocked ::[KeyCode]->Bool
isCapsLocked xs =foldl aux False xs where
  aux a key =
case key of CapsLock ->not a _-> a
 
 
getString ::[KeyCode]->String
getString xs = result []where
  aux (f, caps, shift) key =
case key of Key c ->
if caps == shift then
(f .(toLower c :), caps, False)
else
(f .(toUpper c :), caps, False)
 
                Shift    ->(f,     caps, True)
                CapsLock ->(f,not caps, False)
 
(result,_,_)=foldl aux (id, False, False) xs
