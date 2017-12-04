# -*- coding: utf-8 -*-


class settlements:
    def __init__(self, code=0, client=None, number=None, sdate='', rdate='', note=''):

        self.setCode(code)
        self.setClient(client)
        self.setNumber(number)
        self.setSdate(sdate)
        self.setRdate(rdate)
        self.setNote(note)

    def setCode(self, value): self.__code=value
    def setClient(self, value): self.__client=value
    def setNumber(self, value): self.__number=value
    def setSdate(self, value): self.__sdate=value
    def setRdate(self, value): self.__rdate=value
    def setNote(self, value): self.__note=value

    def getCode(self): return self.__code
    def getClient(self): return self.__client.getShow()
    def getNumber(self): return self.__number.getShow()
    def getSdate(self): return self.__sdate
    def getRdate(self): return self.__rdate
    def getNote(self): return self.__note

    def getShow(self):
        s='{0}, \n|{1},|\n| {2},|\n {3}, {4}, {5}'.format(self.getCode(), self.getClient(), self.getNumber(), self.getSdate(), self.getRdate(), self.getNote())
        return s
