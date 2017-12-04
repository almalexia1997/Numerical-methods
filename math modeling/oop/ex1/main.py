# -*- coding: utf-8 -*-
from ex1.client import client
from ex1.rooms import rooms
from ex1.settlements import settlements
a1=client(1, 1, 'Иванов', 'Иван', "Иванович", "6514 250550", '-')
b1=rooms(1, '301', 'Двухместный', 'Трехзвездочный', 4200)
typeOfClient = type(a1)
c1=settlements(1, a1, b1, '12.11.2017', '14.11.2017', '-')
print (a1.getShow())
print (a1.getShow2())
a1.setComment('постоянный клиент')
print (a1.getComment())
print(a1.getShow())
print (b1.getShow())
print (c1.getClient())
print (c1.getShow())
