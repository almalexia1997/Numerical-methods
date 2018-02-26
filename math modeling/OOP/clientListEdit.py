#-*- coding:utf-8 -*-
from clientlist import clientlist
from generallist import generallist
from client import client as cl

class clientListEdit (generallist):
    def newRec (self, code=0, client=0, family='', name='', sname='', data='', comment=''):
        self.appendList(cl(code,client,family,name,sname,data,comment))
    def getNclient (self, code):return self.findByCode(code).getClient()
    def getFamily (self, code):return self.findByCode(code).getFamily()
    def getName (self, code):return self.findByCode(code).getName()
    def getSname (self, code):return self.findByCode(code).getSname()
    def getData (self, code):return self.findByCode(code).getData()
    def getComment (self, code):return self.findByCode(code).getComment()


    def setClient (self, code, value):self.findByCode(code).setClient(value)
    def setFamily (self, code, value):self.findByCode(code).setFamily(value)
    def setName (self, code, value):self.findByCode(code).setName(value)
    def setSname (self, code, value):self.findByCode(code).setSname(value)
    def setData (self, code, value):self.findByCode(code).setData(value)
    def setComment (self, code, value):self.findByCode(code).setComment(value)

    def getShow(self, code):return self.findByCode(code).getShow()
