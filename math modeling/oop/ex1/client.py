# -*- coding: utf-8 -*-

class client:
    def __init__(self, code=0, client=0, family='', name='', sname='', data='', comment=''):
        self.setCode(code)
        self.setClient(client)
        self.setFamily(family)
        self.setName(name)
        self.setSname(sname)
        self.setData(data)
        self.setComment(comment)

    def setCode(self, value): self.__code=value
    def setClient(self, value): self.__client=value
    def setFamily(self, value): self.__family=value
    def setName(self, value): self.__name=value
    def setSname(self, value): self.__sname=value
    def setData(self, value): self.__data=value
    def setComment(self, value): self.__comment=value

    def getCode(self): return self.__code
    def getClient(self): return self.__client
    def getFamily(self): return self.__family
    def getName(self): return self.__name
    def getSname(self): return self.__sname
    def getData(self): return self.__data
    def getComment(self): return self.__comment

    def getShow(self):
        s='%s, %s %s %s, %s, %s' % (self.getClient(), self.getFamily(), self.getName(), self.getSname(), self.getData(), self.getComment())
        return s
    def getShow2(self):
        s='{0}, {1} {2} {3}, {4}, {5}'.format(self.getClient(), self.getFamily(), self.getName(), self.getSname(), self.getData(), self.getComment())
        return s
