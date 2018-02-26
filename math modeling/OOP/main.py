# -*- coding: utf-8 -*-
from client import client
from room import room
from sattlements import sattlements

a1=client(1, 1, 'Иванов', 'Иван', "Иванович", "6514 250550", '-')
b1=room(1, '301', 'Двухместный', 'Трехзвездочный', 4200)
typeOfClient = type(a1)
c1=sattlements(1, a1, b1, '12.11.2017', '14.11.2017', '-')
