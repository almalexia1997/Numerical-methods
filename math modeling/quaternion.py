import math

def dbl2str(n):
    d = abs(int(n));
    f = int((n - d) * 1000000);
    s = '%d.%d' % (d, f) if f > 0 else '%d' % d
    ss = '+' if n >= 0 else '-'
    return ss, s

#print("введите скаляр")
a = int(input());

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
    
   
    def mul_skal(q1,a):
        return  Quaternion(
            q1.w * a,
            q1.x * a,
            q1.y * a,
            q1.z * a,
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

    def __abs__(q): #НОРМА!!!
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

    """    
    def normalize(q): #НЕ СОВСЕМ НОРМА!!!
        ===        
        Convert Quaternion to Unit Quaternion.

        Unit Quaternion is Quaternion who's length is equal to 1.

        >>> q = Quaternion((1, 3, 3, 3))
        >>> q.normalize()
        >>> print(q) # doctest: +ELLIPSIS
        (0.1889822... + 0.5669467...i + 0.5669467...j + 0.5669467...k)
        ===
        
        norm = abs(q)
        q.w = q.w / norm,
        q.x = q.x / norm,
        q.y = q.y / norm,
        q.z = q.z / norm,
    """
    
    def trig(q1):
        l = math.sqrt(abs(q1)) #skalar
        q2 = Quaternion(0, q1.x, q1.y, q1.z) #quat
        l2 = math.sqrt(abs(q2)) #skalar
        ksi = q2.mul_skal(q2,1/l2) # skalar
        alpha=math.acos(q1.w/l)
        if math.sin(alpha)==(l2/l):
            alpha = alpha
        else:
            alpha = 2*math.pi - alpha
        return '%d(%d + %d * %d)' % (l, math.cos(alpha), ksi, math.sin(alpha))
"""
if __name__ == "__main__":
    print('123')
    
    q1 = Quaternion(1, 2, 3, 4)
    print(q1),    
"""
