#datasql.py
# -*- coding: utf-8 -*-

import os
import sqlite3 as db

emptydb = """
PRAGMA foreign_keys = ON;
PRAGMA encoding = 'utf-8';

create table client
(code integer primary key,
client integer,
family text,
name  text,
sname text,
data text,
comment text);

create table room
(code integer primary key,
number text,
numperson text,
comf text,
prize integer);

create table sattlements
(code integer primary key,
client integer references client(code) on update cascade on delete cascade,
number integer references room(code) on update cascade on delete set null,
sdate text,
rdate text,
note text);
"""

class datasql:
    def read(self,inp,hot):
        conn = db.connect(inp)
        curs = conn.cursor()
        curs.execute('select code, client, family, name, sname, data, comment from client')
        data = curs.fetchall()
        for r in data:
            hot.newClient(r[0],r[1],r[2],r[3],r[4],r[5],r[6])
        curs.execute('select code, number, numperson, comf,  prize from room')
        data = curs.fetchall()
        for r in data:
            hot.newRoom(r[0],r[1],r[2],r[3],r[4])
        curs.execute('select code, client, number, sdate, rdate, note from sattlements')
        data = curs.fetchall()
        for r in data:
            hot.newSattlements(r[0], hot.findClientByCode(int(r[1])), hot.findRoomByCode(int(r[2])),r[3],r[4],r[5])
        conn.close()

    def write(self, out, hot):
        conn = db.connect(out)
        curs = conn.cursor()
        curs.executescript(emptydb)

        for c in hot.getClientCodes():
            curs.execute("insert into client(code, client, family, name, sname, data, comment)values('%s', '%s', '%s', '%s', '%s', '%s', '%s')"%(
              str(c),
              str(hot.getClientNclient(c)),
              hot.getClientFamily(c),
              hot.getClientName(c),
              hot.getClientSname(c),
              hot.getClientData(c),
              hot.getClientComment(c)))
        for c in hot.getRoomCodes():
            curs.execute("insert into room(code, number, numperson, comf, prize)values('%s', '%s', '%s', '%s', '%s')" % (
            str(c),
            hot.getRoomNumber(c),
            hot.getRoomNumperson(c),
            hot.getRoomComf(c),
            str(hot.getRoomPrize(c))))
        for c in hot.getSattlementsCodes():
            curs.execute("insert into sattlements(code, client, number, sdate, rdate, note)values('%s', '%s', '%s', '%s', '%s', '%s')" % (
            str(c),
            str(hot.getSattlementsClientCode(c)),
            str(hot.getSattlementsRoomCode(c)),
            hot.getSattlementsSdate(c),
            hot.getSattlementsRdate(c),
            hot.getSattlementsNote(c)))
        conn.commit()
        conn.close()
