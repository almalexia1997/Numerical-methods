#-*- coding:utf-8 -*-


class generallist:
   def __init__(self):self.__list=[]
   def clear(self):self.__list=[]
   def findByCode(self, code):
       for l in self.__list:
           if l.getCode()==code:
             return l
             break
   def getCodes(self):return [s.getCode() for s in self.__list]
   def appendList(self, value): self.__list.append(value)
   def removeList(self, code):
        for s in self.__list:
            if s.getCode()==code:self.__list.remove(s)
   def getName(self, code):return self.findByCode(code).getName()


   def getNewCode(self):
    m=0
    for c in self.getCodes():
        if c>m:m=c
        return m+1
