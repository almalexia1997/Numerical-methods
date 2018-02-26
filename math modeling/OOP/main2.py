# -*- coding: utf-8 -*-
from Hotel import hotel
from dataxml import dataxml as data

hot1=hotel()
dat1=data()
dat1.read("old.xml", hot1)
dat1.write ("new.xml", hot1)
for s in hot1.getSattlementsCodes():
   print (hot1.getShowSattlements(s))
