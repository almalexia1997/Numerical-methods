# -*- coding: utf-8 -*-
from client import client
from rooms import rooms
from settlements import settlements
client_1 = client(1, 1, 'Иванов', 'Иван', "Иванович", "6514 250550", '-')
room_1 = rooms(1, '301', 'Двухместный', 'Трехзвездочный', 4200)
settlement_1=settlements(1, client_1, room_1, '12.11.2017', '14.11.2017', '-')
client_1.setComment('постоянный клиент')

print("class client: ", client_1.getShow())
print ("class rooms: ", room_1.getShow())
print ("class settlements: ", settlement_1.getShow())
    
