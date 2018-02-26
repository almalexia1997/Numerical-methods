#-*- coding:utf-8 -*-
from generallist import generallist

class clientlist(generallist):
    def getCLient (self, code):return self.findByCode(code).getClient()
    def getFamily (self, code):return self.findByCode(code).getFamily()
    def getName (self, code):return self.findByCode(code).getName()
    def getSname (self, code):return self.findByCode(code).getSname()
    def getData (self, code):return self.findByCode(code).getData()
    def getComment (self, code):return self.findByCode(code).getComment()

    def getGostinica(self,code):return self.findByCode(code).getGoctinica()
    def getListGostinica(self):
        s=''
        for code in self.getCodes():
             s+=self.getGostinica(code)+','
        if s:s=s[:-2]
        return s
