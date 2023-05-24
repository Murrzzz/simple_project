import math

# Function
def f(x,y):
    return x+2*y

# Initialization 
x = 0 
y = 0
h = 0.25
n = 6    



print('xn\t\t   yn\t\t actual')
print('-----------------------------------------')

for i in range(0, n):
    # Euler's Method

    l=(h/2) *(f(x,y)+f(x+h,y+h *f(x,y)))
    y=y+l
    x=x+h
    
    ac = x**2
    
# Results
    print('%f\t %f\t %f'% (x,y,ac))