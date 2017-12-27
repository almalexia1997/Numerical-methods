import math

"""
>>> from quaternion import Quaternion as H
>>> import math
>>> q1 = H(0.5, 0, -math.sqrt(3)/2, 0)
"""

def dbl2str(n):
    st=str(n)
    d = abs(int(n));
    dt = len(str(d))
    if type(n)==type(int()) or n==int(n):
        s = '%d' % (d)
    elif n>0: 
        s = '%d.%s' % (d, st[dt+1:dt+7])
    else:
        s = '%d.%s' % (d, st[dt+2:dt+8])
    ss = '+' if n >= 0 else '-'
    return ss, s
    


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
    
    def __mul__(q1, q2):
        if type(q2)!=type(Quaternion()):
            q2 = Quaternion(q2, 0, 0, 0)
        return Quaternion(
            q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
            q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y,
            q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x,
            q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w,
        )

    def __abs__(q):
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
        return Quaternion(q.w, -q.x, -q.y, -q.z)

    def as_tuple(self):
        return (self.w, self.x, self.y, self.z)
    
    def __repr__(q):
        args = list(
            dbl2str(q.w) +
            dbl2str(q.x) +
            dbl2str(q.y) +
            dbl2str(q.z)
        )
        if args[0]=='+': args[0] = ''
        return '(%s%s %s %si %s %sj %s %sk)' % tuple(args)
    
    def trig_step(self):
        l = math.sqrt(abs(self))
        q2 = Quaternion(0, self.x, self.y, self.z)
        l2 = math.sqrt(abs(q2))
        ksi = q2*(1./l2)
        if ksi.__repr__()[3:4] == '-':
            ksi_str = '(' + ksi.__repr__()[3:4] + ksi.__repr__()[5:]
        else:
            ksi_str = '(' + ksi.__repr__()[5:]
        alpha=math.acos(self.w/l)
        grad_alpha = math.degrees(alpha)
        if math.sin(alpha)==l2/l:
            alpha = alpha
        else:
            alpha = 2*math.pi - alpha
        return [l, grad_alpha, ksi_str]
    
    def trig(self):
        result = self.trig_step()
        return '%f * (cos(%f) + %s * sin(%f)' % (result[0], result[1], result[2], result[1])
    
    def __pow__(self, n):
        result = self.trig_step()
        return '%f * (cos(%f) + %s * sin(%f)' % (result[0]**n, result[1]*n, result[2], result[1]*n)

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
        grad_alpha = math.degrees(alpha)
        print(grad_alpha)
        if math.sin(alpha)==l2/l:
            alpha = alpha
        else:
            alpha = 2*math.pi - alpha
        result = '%f * (cos(%f) + %s * sin(%f)' % (l, grad_alpha, ksi_str, grad_alpha)
        return result

