#-*- coding:utf-8 -*-
from room import room
from generallist import generallist

class roomsListEdit(generallist):
    def newRec (self,  code=0, number='', numperson='', comf='', prize=0):self.appendList(room(code, number, numperson, comf, prize))
    def getNumber (self, code):return self.findByCode(code).getNumber()
    def getNumperson (self, code):return self.findByCode(code).getNumperson()
    def getComf (self, code):return self.findByCode(code).getComf()
    def getPrize (self, code):return self.findByCode(code).getPrize()
        
    def setNumber (self, code, value):self.findByCode(code).setNumber(value)
    def setNumperson (self, code, value):self.findByCode(code).setNumperson(value)
    def setComf (self, code, value):self.findByCode(code).setConf(value)
    def setPrize (self, code, value):self.findByCode(code).setPrize(value)

    def getShow(self, code):return self.findByCode(code).getShow()
