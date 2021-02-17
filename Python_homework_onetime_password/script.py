import sqlite3
import os
import datetime
from random import randint

print ("СИСТЕМА ВЫДАЧИ ОДНОРАЗОВЫХ ПАРОЛЕЙ")

if os.path.isfile("db.sqlite"):
    print ("Соединение с базой установлено")
else:
    print ("Соединение с базой НЕ УСТАНОВЛЕНО")
    input("нажмите Enter чтобы выйти")
    exit()

conn = sqlite3.connect("db.sqlite", timeout = 2)
cursor = conn.cursor()
is_logged_in = False
current_user = ""

print("-------------------")
print ("""команды:
l - вход в базу, логин
lo - выход из базы, разлогиниться
r - регистрация
s - показать данные из базы (нужно войти)
exit - выход из программы""")
print("-------------------")

#регистрация нового пользователя
def reg_user():
    #записываем имя пользователя
    reg_login = input("введите логин: ")
    
    if len(reg_login) != 0:      
        #ищем в базе есть ли уже такой логин
        cursor.execute("SELECT login FROM users WHERE login = '%s'" % reg_login)
        conn.commit()
        result = cursor.fetchall()
        #если нет результата, т.е ник не занят
        if len(result) == 0 :
            #записываем логин в бд
            cursor.execute("INSERT INTO users VALUES (null, '%s')" % reg_login)
            conn.commit()
            print ("регистрация завершена")
            print ("%s  - ваш логин для входа в БД" % reg_login)
            print("-------------------")
        else:
            print ("такой пользователь уже есть")
            reg_user()
    else:
        print ("вы ничего не ввели")
        print(" ")
        reg_user()
    

#генерация пароля
def gen_passord():
    str_abc = "abcdefghijklmnopqrstuvwxyz"
    str_abcd = str_abc.upper()
    str_int = "0123456789"
    str_first_pass = ""
    
    for i in range (0,8):
        str_first_pass += str_abc[randint(i, len(str_abc) - 1)]
        
    for i in range (0,8):
        str_first_pass += str_abcd[randint(i, len(str_abcd) - 1)]

    for i in range (0,10):
        str_first_pass += str_int[randint(i, len(str_int) - 1)]
        
    str_second_pass = ""
    
    i = 0
    ii = 9
    
    while (i < ii):
        letter = str_first_pass[randint(i, len(str_first_pass) - 1)]
        if str_second_pass.find(letter) == -1:
            str_second_pass += letter
            i += 1
    
            
    password = str_second_pass
    print ("ваш одноразовый пароль - %s, время действия пароля 60 секунд" % password)
    return password


#ввод пароля
def input_password(id_user, c_time, n_time):
    #а вот здесь юзер войдёт
    input_pass = input ("введите ваш пароль для входа: ")
    input_str = input_pass
    cursor.execute("SELECT password FROM logs WHERE id_user = %s AND time = '%s'" % (id_user, c_time))
    check = cursor.fetchall()
    check_str = ''.join(check[0])
           
    time_of_input = datetime.datetime.now()     
       
    if (time_of_input > n_time):
        print ("срок действия пароля закончился, войдите заново")
        log_user()
    else:           
        if input_str == check_str:
            cursor.execute("INSERT INTO user_status VALUES (null, %s, 'online')" % id_user)
            conn.commit()    
            print ("вы вошли в базу данных, теперь можно её посмотреть")  
            print("-------------------")             
        else:
            print ("пароли не совпадают")
            input_password(id_user, c_time, n_time)
                              
#логирование
def log_user():
    log_login = input("введите ваш логин: ")
    
    if len(log_login) != 0:
        #ищем id юзера
        cursor.execute("SELECT id FROM users WHERE login = '%s'" % log_login)
        result = cursor.fetchall()
        if len(result) == 0:
            print ("нет такого пользователя: ")
            log_user()
        else:
            id_user = str(result[0])[1]
            
            cursor.execute("SELECT * FROM user_status WHERE id_user = '%s'" % id_user)
            
            res = cursor.fetchall()
            
            if len(res) == 0:
            
                #берем текущую дату
                current_date = datetime.datetime.now()
                #дата до которой действует пароль (+60 секунд к текущей)          
                new_date = current_date + datetime.timedelta(0,60)
                
                #генерируем пароль и выводим его
                password = gen_passord()
                
                #записываем данные лога
                cursor.execute("INSERT INTO logs VALUES(null, '%s', '%s', '%s')" % (id_user, current_date, password))
                conn.commit()
                         
                input_password(id_user, current_date, new_date)
            
            else:
                print ("вы уже вошли")
                print("-------------------") 
    else:            
        print ("вы ничего не ввели: ")
        log_login = ""
        log_user()
        
    return id_user
   
#логаут   
def logout(current_user):
    cursor.execute("DELETE FROM user_status WHERE id_user = '%s'" % current_user)
    conn.commit()
    print ("вы вышли из базы")
    print("-------------------") 
     
 
 
 
 
def show_db(is_logged_in):
    if is_logged_in == True:
        print ('БАЗА ДАННЫХ')
        
        cursor.execute("SELECT * FROM some_data")
        data = cursor.fetchall()
        
        print ("/ id / student / gruppa /")
        i = 0
        #print (str(data[i][1]))
        i = 0
        ii = len(data)
        
        while i < ii:
            print ("/ %s / %s / %s " % (data[i][0], data[i][1], data[i][2]))
            i += 1
        print("-------------------")      
    else:
        print ("вы не вошли, невозможно отобразить базу данных") 
        print("-------------------") 
        
         
command = ""



while command != "exit":
    command = input("ввод команды: ")

    if command == "r":    
        reg_user()
        
    elif command == "l":
        
        if is_logged_in == False:
            current_user = log_user()
            is_logged_in = True
        else:
            print ("вы уже вошли")
            print("-------------------") 
            
            
    elif command == "lo":
        if is_logged_in == True:
            #разлогиниваемся
            logout(current_user)
            is_logged_in = False
        
        else:
            print ("нельзя выйти, т.к вы не вошли")
            print("-------------------") 
    
    
    
    elif command == "s":
        show_db(is_logged_in)
    
    
    elif command == "exit":
       
        if len(current_user) != 0:
            #logout(current_user)
            exit()
        else:
            exit()

    else:
        print ("вы ничего не ввели")
        print("-------------------")

