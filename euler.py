import math

# Function
def f(x,y):
    return x+2*y

# Initialization 
x = 0 
y = 0
xn = 0.1
n = 10    

h= (xn+x)/n

print('xn\t\t   yn\t\t slope\t\t')
print('-----------------------------------------')

for i in range(0, n):
    # Euler's Method
    slope = f(x,y)
    y=y+xn*slope
    x=x+0.1
    
    #Actual
    ya=2*(math.e)**x-3*x-3

# Results
    print('%f\t %f \t%f'% (x,y,slope))