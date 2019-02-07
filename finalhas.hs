isLucky x = if x `mod` 7 == 0 then True else False
luckyList = [x| x <- [1..], isLucky x]
luckyLess x = [a| a <- luckyList, a<x]
