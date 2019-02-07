import Data.Char
doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
doublesmallNumber x = if x > 100
                     then x
                     else x*2
doublesmallNumber' x = (if x> 100 then x else x*2) +1

lit = [x*2| x <-[1..10], x*2 <5]

boomBang lst = [if x < 10 then "boom" else "bang"| x <- lst, odd x]
length' lst = sum [1| _<- lst]
triangles = [(a,b,c)| c<- [1..10], b <- [1..10], a<- [1..10]]

rightTriangles = [ (a,b,c) | c <- [1..10], b <- [1..c], a <- [1..b], a^2 + b^2 == c^2, a+b+c == 24]

squareNum :: Num x => [x] -> [x]
squareNum [] = []
squareNum [x] = [x*x]
squareNum (x:xs) = (x*x): squareNum(xs)

letlist = ['a'.. 'z']
upperCase [] = []
upperCase (x : xs) = toUpper x: upperCase xs

onlyOnes [] = []
onlyOnes (x:xs) = 1 `elem` x : onlyOnes xs
-- | (if x == 1 then True else False)