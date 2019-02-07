-- | Ben Gertz
-- | April 23, 2018
-- | CMPS 1600 - Kurdia
-- | Lab 7

-- | this is 1.a. below are the lists
pants = ["jeans", "khakis", "shorts"]
tops = ["white shirt", "grey turtleneck", "pink polo", "green hoodie"]
shoes = ["brogues", "converse", "sandals", "crocks"]
scarfs = ["paisley scarf", "knit loop"]
-- | this is the function to make the tuples of all permutations
outfitter p t s sc = [ (a,b,c,d) | a <- p, b <- t, c <- s, d <- sc]

-- | part b

outfits = outfitter pants tops shoes scarfs
-- | the initial length of outfits was 24. To increase the number of outfits it is most efficient to add to pants first because it
-- | has the least amount of items intially. for the second article of clothing it is equallaly wise to buy either a pant or a 
-- | pair of shoes because they are the same length
-- | after adding scarfs the list length is 96 given that we also added the two new outfits from earlier 

-- | part c

l = ["Mr.", "Ms.", "Mrs.", "Dr.", "Prof.", "Rev."]
and' = "and"
honorer l = [[a ++ " and " ++ b] | a<-l, b <-l] ++ [[a] | a<- l]

-- | part D. This takes the natophonetic alphabet and a word and translates that word into a list of its natophonetic counterpart.
-- | w is the word given and l is the natophonetic list.

natolst = [('A',"Alfa"), ('B',"Bravo"), ('C',"Charlie"), ('D',"Delta"), ('E',"Echo"), ('F',"Foxtrot"), ('G',"Golf"), ('H', "Hotel"), ('I', "India"), ('J', "Juliett"), ('K', "Kilo"), ('L', "Lima"), ('M', "Mike"), ('N', "November"), ('O', "Oscar"), ('P', "Papa"), ('Q', "Quebec"), ('R', "Romeo"), ('S', "Sierra"), ('T',"Tango"), ('U',"Uniform"), ('V',"Victor"), ('W',"Whiskey"), ('X',"X-ray"), ('Y',"Yankee"), ('Z',"Zulu")]
word = "TEST"

nato w l = [snd a | b <- w, a <- l, fst a ==  b]

-- | part 2 functions. part A

remainder' x y = x `mod` y

-- | Part B
-- | isEven' x = if x `mod` 2 == 0 then True else False
isEven' x = even x

-- | Part C merge

lst1 = [1,3,5,7,9]
lst2 = [0,2,4,6,8]


merge _ [] = []
merge [] _ = []
merge (x:xs) (y:ys) = [min x y] ++ if min x y == x then merge xs (y:ys) else merge (x:xs) ys

-- | Part D

lst3 = [0..10]
removeMultiple [] _ = []
removeMultiple (x:xs) a = if remainder' x a /= 0 then [x] ++ removeMultiple xs a else removeMultiple xs a

-- | Part 3 It turns out that what I wrote for part one is beyond what was asked and what was needed for this part.
-- | I'm am going to paste the functions again down here
-- | outfitter p t s sc = [ (a,b,c,d) | a <- p, b <- t, c <- s, d <- sc]

-- | honorer l = [[a ++ " and " ++ b] | a<-l, b <-l] ++ [[a] | a<- l]

-- | nato w l = [snd a | b <- w, a <- l, fst a ==  b]

-- | Validating credit card Information
-- | lastDigit

lastDigit :: Integer -> Integer

lastDigit x = mod x 10
-- | drop last digit

dropLastDigit :: Integer -> Integer
dropLastDigit x = quot x 10

-- | to Rev Digits

toRevDigits :: Integer -> [Integer]
toRevDigits 0 = []
toRevDigits x = [lastDigit x] ++ toRevDigits (dropLastDigit x)

-- | doubleEveryOther

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther (x:y:xs) = x : 2*y : doubleEveryOther xs
doubleEveryOther a = a

-- | sumDigits

sumDigits :: [Integer] -> Integer
sumDigits [] = 0
sumDigits (x:xs) = if x > 9 then lastDigit x +  dropLastDigit x + sumDigits xs else x + sumDigits xs

-- | luhn
luhn :: Integer -> Bool
luhn x = if remainder' (sumDigits (doubleEveryOther (toRevDigits x))) 10 == 0 then True else False





