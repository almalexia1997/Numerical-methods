# -*- coding: utf-8 -*-

from Hotel import hotel
from dataxml import dataxml
from datasql import datasql

hot1=hotel()
dat1=dataxml()
dat2=datasql()

dat1.read('old.xml', hot1)
dat2.write('new.sqlite', hot1)
hot1.clear()
dat2.read('new.sqlite', hot1)
for c in hot1.getSattlementsCodes():
    print (hot1.getShowSattlements(c))
