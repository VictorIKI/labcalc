import random
random.seed()
k=10**10
#cord =[[1,2,3]]*k

#while success==false

for i in range(k):
    x = random.uniform(0,1)
    y = random.uniform(0,1)
    z = random.uniform(0,1)
    if(x**2+y**2+z**2==1):
        print('success')
