#-*- coding:utf-8 -*-
from sattlements import sattlements
from generallist import generallist

class sattlementsListEdit (generallist):
    def newRec (self, code=0, client=None, number=None, sdate='', rdate='', note=''):self.appendList(sattlements( code, client, number, sdate, rdate, note))
    def setClient(self, code, value):self.findByCode(code).setClient(value)
    def setNumber(self, code, value):self.findByCode(code).setNumber(value)
    def setSdate(self, code, value):self.findByCode(code).setSdate(value)
    def setRdate(self, code, value):self.findByCode(code).setRdate(value)
    def setNote(self, code, value):self.findByCode(code).setNote(value)

    def getClient(self, code):return self.findByCode(code).getClient()

    def getClientCode(self, code): return self.findByCode(code).getClientCode()

    def getNumber(self, code): return self.findByCode(code).getNumber()
    def getNumberCode(self, code):return self.findByCode(code).getNumberCode()
    def getSdate(self, code): return self.findByCode(code).getSdate()
    def getRdate(self, code): return self.findByCode(code).getRdate()
    def getNote(self, code): return self.findByCode(code).getNote()

    def getShow(self,code):return self.findByCode(code).getShow()

