# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt

def f1(y2):
    return y2 

def f2(y2, n, eta):
    return -abs(y2)**(1-n)*n*(eta / 2.)*y2

def RK(yi, n, eta, h):
    k11 = f1(yi[1])
    k21 = f2(yi[1],n,eta)

    k12 = f1(yi[1] + 0.5*h*k21)
    k22 = f2(yi[1] + 0.5*h*k21,n,eta + 0.5*h)
 
    k13 = f1(yi[1] + 0.5*h*k22)
    k23 = f2(yi[1] + 0.5*h*k22,n,eta + 0.5*h)

    k14 = f1(yi[1] + h*k23)
    k24 = f2(yi[1] + h*k23,n,eta + h)

    K = [[k11,k12,k13,k14],[k21,k22,k23,k24]]

    N = len(yi)
    yj = yi[:]
    for i in xrange(N):
        yj[i] = yj[i] + h/6.0 * (K[i][0] + 2.0*K[i][1] + 2.0*K[i][2] + K[i][3])
    return yj

def RZK(etak, y0, n, h):
    ceta = 0.0
    dh = etak - ceta
    ch = dh if (abs(dh) < abs(h)) else h
    yi = y0
    fi = [[ceta,yi[0],yi[1]]]
    nn = 0
    while ((abs(ceta) < abs(etak)) and (nn < 100000)):
        yj = RK(yi,n,ceta,ch)
        yi = yj
        ceta = ceta + ch
        dh = etak - ceta
        ch = dh if (abs(dh) < abs(h)) else h
        fi.append([ceta,yi[0],yi[1]])
        nn += 1
    return fi

def Newton2(etak, y00, y1k, n, h, eps, delta):
    cy0 = y00
    cfk = RZK(etak,cy0,n,h)
    N = y1k - cfk[-1][1]
    R = abs(N)
    count = 1
    while ((R > eps) and (count < 200)):
        cfk = RZK(etak,[cy0[0],cy0[1] + delta],n,h)
        N1 = y1k - cfk[-1][1]
        dNdx = (N1 - N)/delta
        ga = -N/dNdx
        cy0[1] = cy0[1] + ga
        cfk = RZK(etak,cy0,n,h)
        N = y1k - cfk[-1][1]
        R = abs(N)
        print "%i\t%0.12f" % (count, R,)
        count = count + 1
    return cy0[1], cfk

etak = 10
delta = 1e-4 # 0.0001
eps = 1e-8 # 0.00000001
h = 0.01

n = 0.8
y0 = [1.0, 0.1]
y1k = 0.

phi10, data = Newton2(etak, y0, y1k, n, h, eps, delta)
print phi10

s1 = data[:]
leta = [el[0] for el in s1]
lf = [el[1] for el in s1]
#plt.suptitle(r'$\varphi_{\eta}(0) = %0.12f$' % (y0[1],), fontsize = 20)
plt.subplot(111)
plt.plot(leta,lf)
plt.xlim(0,10)
#plt.ylim(0, 1.01)
plt.xlabel(r'$\eta$', fontsize = 20)
plt.ylabel(r'$\frac{u}{U}$', rotation = 'horizontal', fontsize = 24)
plt.grid()
plt.show()

# y0 = [1, -1.12837]  # 2-произвольное число
# RZK(y0, etaN, 0.1)
