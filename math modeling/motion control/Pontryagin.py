from sympy import Symbol
from mpmath import odefun
import math

x1 = Symbol('x1')
x2 = Symbol('x2')

psi1 = Symbol('psi1')
psi2 = Symbol('psi2')

a=1
m=1
c=1
x01=1
tk=10
x=[]

def g(t, x):
    x1, x2, psi1, psi2 = x[0], x[1], x[2], x[3]
    return [x2, psi2/(2*a)-c*x1, psi2*c, -psi1]

for t in range(0, tk):
    f = odefun(g(t, x), 0, [x01, 0])
    for x in [0, 1, 2.5, 10]:
        nprint(f(x), 15)

#print ("u1 = %f\nu2 = %f" % (u1, u2))
#f1 = 0.6 * x1 * x2 +0.3 * u1
#f2 = 0.3 * x2 + 0.7 * x1 - 0.1 * x1 * u2
#x = nsolve((f1, f2), (x1, x2), (-1, 1))
#print("solution of system:\nx0 = [%f, %f] " % (x[0], x[1]))
#f1 = 0.6 * x[0] * x[1] +0.3 * u1
#f2 = 0.3 * x[1] + 0.7 * x[0] - 0.1 * x[0] * u2
#print("check calculations:")
#print ("f1 = %f\nf2 = %f" % (f1, f2))
