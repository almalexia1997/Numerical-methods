#-*- coding:utf-8 -*-

import os,xml.dom.minidom

class dataxml:
    def read(self, inp, hot):
        dom = xml.dom.minidom.parse(inp)
        dom.normalize()
        for node in dom.childNodes[0].childNodes:
            if (node.nodeType==node.ELEMENT_NODE)and(node.nodeName=="client"):
                code, nclient,family,name,sname,data,comment=0,0,"","","","",""
                for t in node.attributes.items():
                    if t[0]=="code":code=int(t[1])
                    if t[0]=="nclient":nclient=int(t[1])
                    if t[0]=="family":family=t[1]
                    if t[0] == "name": name = t[1]
                    if t[0] == "sname": sname = t[1]
                    if t[0] == "data": data = t[1]
                    if t[0] == "comment": comment = t[1]
                hot.newClient(code,nclient,family, name, sname, data, comment)

            if (node.nodeType==node.ELEMENT_NODE)and(node.nodeName=="rooms"):
                code, number, numperson , comf , prize=0,"","","",0
                for t in node.attributes.items():
                    if t[0]=="code":code = int(t[1])
                    if t[0] == "number": number = t[1]
                    if t[0] == "numperson": numperson = t[1]
                    if t[0] == "comf": comf = t[1]
                    if t[0]=="prize":prize = int(t[1])
                hot.newRoom(code,number,numperson,comf,prize)

            if (node.nodeType == node.ELEMENT_NODE) and (node.nodeName == "sattlements"):
                 code, client, number, sdate, rdate, note =0,None,None,"","",""
                 for t in node.attributes.items():
                     if t[0] == "code": code = int(t[1])
                     if t[0] == "client": client=hot.findClientByCode(int(t[1]))
                     if t[0] == "number": number = hot.findRoomByCode(int(t[1]))
                     if t[0] == "sdate": sdate = t[1]
                     if t[0] == "rdate": rdate = t[1]
                     if t[0] == "note": note = t[1]
                 hot.newSattlements(code,client,number,sdate,rdate,note)
    def write(self, out, hot):
        dom=xml.dom.minidom.Document()
        root=dom.createElement("hotel")
        dom.appendChild(root)
        for c in hot.getClientCodes():
            cli=dom.createElement("nclient")
            cli.setAttribute('code', str(c))
            cli.setAttribute('nclient', str(hot.getClientNclient(c)))
            cli.setAttribute('family',hot.getClientFamily(c))
            cli.setAttribute('name', hot.getClientName(c))
            cli.setAttribute('sname', hot.getClientSname(c))
            cli.setAttribute('data', hot.getClientData(c))
            cli.setAttribute('comment', hot.getClientComment(c))
            root.appendChild(cli)
        for c in hot.getRoomCodes():
            roo=dom.createElement("rooms")
            roo.setAttribute('code',str(c))
            roo.setAttribute('number', hot.getRoomNumber(c))
            roo.setAttribute('numperson', hot.getRoomNumperson(c))
            roo.setAttribute('comf', hot.getRoomComf(c))
            roo.setAttribute('prize', str(hot.getRoomPrize(c)))
            root.appendChild(roo)
        for c in hot.getSattlementsCodes():
            sat=dom.createElement("sattlements")
            sat.setAttribute('code', str(c))
            sat.setAttribute('client', str(hot.getSattlementsClientCode(c)))
            sat.setAttribute('number', str(hot.getSattlementsRoomCode(c)))
            sat.setAttribute('sdate', hot.getSattlementsSdate(c))
            sat.setAttribute('rdate', hot.getSattlementsRdate(c))
            sat.setAttribute('note', hot.getSattlementsNote(c))
            root.appendChild(sat)
        f = open(out, "w")
        f.write(dom.toprettyxml())
