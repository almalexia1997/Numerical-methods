import math

def dbl2str(n):
    st=str(n)
    d = abs(int(n));
    dt = len(str(d))
    if type(n)==type(int()):
        s = '%d' % (n)  
    elif n>0: 
        s = '%d.%s' % (d, st[dt+1:dt+7])
    else:
        s = '%d.%s' % (d, st[dt+2:dt+8])
    ss = '+' if n >= 0 else '-'
    return ss, s
    
"""
from quaternion import Quaternion as H
q1 = H(2, 3, 2, 3)
q2 = H(2, 3, 2, 3)
q1 * q2
"""

class Quaternion(object):
    def __init__(q, w=0, x=0, y=0, z=0):
        q.w = w
        q.x = x
        q.y = y
        q.z = z

    def __add__(q1, q2):
        return Quaternion(
            q1.w + q2.w,
            q1.x + q2.x,
            q1.y + q2.y,
            q1.z + q2.z,
        )

    def __sub__(q1, q2):
        return Quaternion(
            q1.w - q2.w,
            q1.x - q2.x,
            q1.y - q2.y,
            q1.z - q2.z,
        )
    
   
    def mul_scal(self, a):
        return  Quaternion(
            float(self.w) * float(a),
            float(self.x) * float(a),
            float(self.y) * float(a),
            float(self.z) * float(a),
        )    
    
    def __mul__(q1, q2):
        return Quaternion(
            q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
            q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y,
            q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x,
            q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w,
        )

    def __div__(q1, q2):
        s = float(q2.w*q2.w + q2.x*q2.x + q2.y*q2.y + q2.z*q2.z)
        return Quaternion(
            (  q1.w*q2.w + q1.x*q2.x + q1.y*q2.y + q1.z*q2.z) / s,
            (- q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y) / s,
            (- q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x) / s,
            (- q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w) / s
        )

    def __abs__(q): #norma!!!
        return q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;

    def __neg__(q):
        return Quaternion(-q.w, -q.x, -q.y, -q.z)

    def __invert__(q):
        """Conjugate of Quaternion.

        >>> q = Quaternion((2, 2, 2, 2))
        >>> print(q)
        (2 + 2i + 2j + 2k)
        >>> print(~q)
        (2 - 2i - 2j - 2k)
        >>> print(~~q)
        (2 + 2i + 2j + 2k)

        """
        return Quaternion((q.w, -q.x, -q.y, -q.z))

    def as_tuple(self):
        return (self.w, self.x, self.y, self.z)

    def __repr__(q):
        args = list(
            dbl2str(q.w) +
            dbl2str(q.x) +
            dbl2str(q.y) +
            dbl2str(q.z)
        )
        if args[0] == '+':
            args[0] = ''
        return '(%s%s %s %si %s %sj %s %sk)' % tuple(args)
 
    def trig(self):
        l = math.sqrt(abs(self)) #float
        q2 = Quaternion(0, self.x, self.y, self.z) #quaternion
        l2 = math.sqrt(abs(q2)) #float
        ksi = q2.mul_scal(1./l2) # quaternion
        if ksi.__repr__()[3:4] == '-': #the third digit always zero
            ksi_str = '(' + ksi.__repr__()[3:4] + ksi.__repr__()[5:] #convert ksi to a string
        else:
            ksi_str = '(' + ksi.__repr__()[5:] #convert ksi to a string
        alpha=math.acos(self.w/l) #float
        if math.sin(alpha)==l2/l:
            alpha = alpha
        else:
            alpha = 2*math.pi - alpha
        cos_alpha = math.cos(alpha)
        sin_alpha = math.sin(alpha)
        if sin_alpha>0:
            sin_alpha = str(sin_alpha)[:8]
        else:
            sin_alpha = '(' + str(sin_alpha)[:9] + ')'
        result = '%f * (%f + %s * %s)' % (l, cos_alpha, ksi_str, sin_alpha)
        return result
