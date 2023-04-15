feq :: [Char] -> [Char] -> Bool 
feq [] [] = True 
feq xs [] = True
feq [] ys = True
feq (x:xs) (y:ys) = x <= y && feq xs ys

auto = ['a','u','t','o']
automovil = ['a','u','t','o','m','o','v','i','l']
hola = ['h','o','l','a']
mundo = ['m','u','n','d','o']
