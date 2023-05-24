import math

# Function
def f(x,y):
    return 8*x**2

# Initialization 
x = 0 
y = 1
h = 0.25
n = 5



print('xn\t\t   yn\t\t actual')
print('-----------------------------------------')

for i in range(0, n):
    # Euler's Method

    k1 = f(x, y)
    k2 = f((x + h/2), (y + k1 * h/2))
    k3 = f((x + h/2), (y + k2 * h/2))
    k4 = f((x + h), (y + k3 * h))
    y = y + 1 / 6 * (k1 + 2 * k2 + 2 * k3 + k4) * h
    x=x+h
    
    ac = x**8
    
# Results
    print('%f\t %f\t %f'% (x,y,ac))