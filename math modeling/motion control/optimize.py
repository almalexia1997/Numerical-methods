from sympy import Symbol, nsolve
import math
x1 = Symbol('x1')
x2 = Symbol('x2')
u1=math.sqrt(7)
u2=math.sqrt(3)
print ("u1 = %f\nu2 = %f" % (u1, u2))
f1 = 0.6 * x1 * x2 +0.3 * u1
f2 = 0.3 * x2 + 0.7 * x1 - 0.1 * x1 * u2
x = nsolve((f1, f2), (x1, x2), (-1, 1))
print("solution of system:\nx0 = [%f, %f] " % (x[0], x[1]))
f1 = 0.6 * x[0] * x[1] +0.3 * u1
f2 = 0.3 * x[1] + 0.7 * x[0] - 0.1 * x[0] * u2
print("check calculations:")
print ("f1 = %f\nf2 = %f" % (f1, f2))

