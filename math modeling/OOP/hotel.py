#hotel.py
#-*- coding:utf-8 -*-

from clientlistedit import clientListEdit
from sattlementslistedit import sattlementsListEdit
from roomslistedit import roomsListEdit

class hotel:
    def __init__(self):
        self.__clients=clientListEdit()
        self.__rooms=roomsListEdit()
        self.__sattlementss=sattlementsListEdit()
    def  removeClient(self, code):
        self.__clients.removeList(self, code)
        for c in self.__sattlementss.getCodes():
          self.__sattlementss.removeClient(c, code)
    def removeRoom(self,code):
        self.__rooms.removeList(self,code)
        for c in self.__rooms.getCodes():
            self.__sattlementss.setRoom(c, None)
    def clear(self):
        self.__sattlementss.clear()
        self.__clients.clear()
        self.__rooms.clear()
    def newClient(self,code=0, client=0, family='', name='', sname='', data='', comment=''):
        self.__clients.newRec(code,client,family,name,sname,data,comment)
    def findClientByCode(self, code):return self.__clients.findByCode(code)
    def getClientNclient(self, code):return self.__clients.getNclient(code)
    def getClientFamily(self, code):return self.__clients.getFamily(code)
    def getClientName(self, code):return self.__clients.getName(code)
    def getClientSname(self, code):return self.__clients.getSname(code)
    def getClientData(self, code):return self.__clients.getData(code)
    def getClientComment(self, code):return self.__clients.getComment(code)
    def getClientCodes(self): return self.__clients.getCodes();

    def setClientFamily(self, code, value):self.__clients.setFamily(code, value)
    def setClientName(self, code, value):self.__clients.setName(code, value)
    def setClientSname(self, code, value):self.__clients.setSname(code, value)
    def setClientData (self, code, value):self.__clients.setData(code, value)
    def setClientComment (self, code, value):self.__clients.setComment(code, value)
    def getShowClient(self,code):return self.__clients.getSshow(code)

    def newRoom(self, code=0, number='', numperson='', comf='', prize=0):self.__rooms.newRec(code,number,numperson,comf,prize)
    def findRoomByCode(self, code):return self.__rooms.findByCode(code)
    def getRoomCodes(self):return self.__rooms.getCodes()
    def getRoomNumber(self, code):return self.__rooms.getNumber(code)
    def getRoomNumperson(self, code):return self.__rooms.getNumperson(code)
    def getRoomComf(self, code):return self.__rooms.getComf(code)
    def getRoomPrize(self, code):return self.__rooms.getPrize(code)

    def setRoomNumber(self, code, value):self.__rooms.setNumber(code,value)
    def setRoomNumperson(self, code, value):self.__rooms.setNumperson(code, value)
    def setRoomComf(self, code, value):self.__rooms.setComf(code, value)
    def setRoomPrize(self, code, value):self.__rooms.setPrize(code,value)
    def getShowRoom(self, code):return self.__rooms.getShow(code)

    def newSattlements(self, code=0, client=None, number=None, sdate='', rdate='', note=''):self.__sattlementss.newRec(code,client,number,sdate,rdate,note)
    def findSattlementsByCode(self, code):return self.__sattlementss.findByCode(code)
    def setSattlementsClient(self, code, value):self.__sattlementss.setClient(code, value)
    def setSattlementsNumber(self, code, value):self.__sattlementss.setNumber(code, value)
    def setSattlementsSdate(self, code, value):self.__sattlementss.setSdate(code, value)
    def setSattlementsRdate(self, code, value): self.__sattlementss.setRdate(code, value)
    def setSattlementsNote(self, code, value): self.__sattlementss.setNote(code, value)

    def getSattlementsClient(self, code):return self.__clients.getClient(code)
    def getSattlementsClientCode(self, code):return self.__sattlementss.getClientCode(code)
    def getSattlementsRoom(self, code):return self.__sattlementss.getRoom(code)
    def getSattlementsRoomCode(self,code):return self.__sattlementss.getNumberCode(code)
    def getSattlementsSdate(self, code): return self.__sattlementss.getSdate(code)
    def getSattlementsRdate(self, code): return self.__sattlementss.getRdate(code)
    def getSattlementsNote(self, code): return self.__sattlementss.getNote(code)
    def getSattlementsClientGostinica(self, code):return self.__sattlementss.getClientGostinica(code)
    def getSattlementsGostinica(self,code):return self.__sattlementss.getGostinica(code)
    def getSattlementsCodes(self):return self.__sattlementss.getCodes()
    def getShowSattlements(self, code):return self.__sattlementss.getShow(code)
