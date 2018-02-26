#room.py
# -*- coding: utf-8 -*-

class room:
    def __init__(self, code=0, number='', numperson='', comf='', prize=0):
        self.setCode(code)
        self.setNumber(number)
        self.setNumperson(numperson)
        self.setComf(comf)
        self.setPrize(prize)

    def setCode(self, value): self.__code=value
    def setNumber(self, value): self.__number=value
    def setNumperson(self, value): self.__numperson=value
    def setComf(self, value): self.__comf=value
    def setPrize(self, value): self.__prize=value

    def getCode(self): return self.__code
    def getNumber(self): return self.__number
    def getNumperson(self): return self.__numperson
    def getComf(self): return self.__comf
    def getPrize(self): return self.__prize

    def getShow(self):
        s='%s, %s %s %s, %s' %(self.getCode(), self.getNumber(), self.getNumperson(), self.getComf(), self.getPrize())
        return s
