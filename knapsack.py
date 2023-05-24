import math
import matplotlib.pyplot as plt

val = [1000, 3000, 2500]
wt = [10, 20, 18 ]
W =40
n = len(val)

def knapSack(W, wt, val, n):
    if n == 0 or W == 0: #if the capacity is 0 
        return 0
    if (wt[n-1] > W):                    # if  the  weight is more than the capacity                                                                        
        return knapSack(W, wt, val, n-1) # the item will not include
    else:
        a =val[n-1] + knapSack(W-wt[n-1], wt, val, n-1) # included
        b =knapSack(W, wt, val, n-1)                    # nnot included
        return max(a,b)                                 #return the maximum

print (knapSack(W, wt, val, n))

