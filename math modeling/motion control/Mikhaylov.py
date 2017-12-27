from matplotlib import pyplot as plt

a=[0.4, 1, 4, 1.5, 0.8]
x=[]
y=[]
eps=0.1

for w in range(0, 10):
    w1=w*eps 
    x.append(a[0]*w1**4-a[2]*w1**2+a[4])  #Re
    y.append(a[3]*w1-a[1]*w1**3)          #Im

plt.xlim(-1, 1)
plt.ylim(-1, 1)
plt.plot(x,y)
plt.grid(True)
plt.show()
