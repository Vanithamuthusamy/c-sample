import cx_Oracle
class account(object):
    def acc(self):
        self.details()
    def details(self):
        print("................account details...............")
        print(" ")
        print("ENTER THE FIRST NAME")
        self.fname()
    def fname(self):
        self.fn=str(input())
        print("ENTER THE LAST NAME")
        self.lname()
    def lname(self):
        self.ln=str(input())
        print("ENTER THE CITY")
        self.city()
    def city(self):
        self.ci=str(input())
        print("ENTER THE STATE")
        self.state()
    def state(self):
        self.st=str(input())
        print("ENTER THE PINCODE")
        self.pincode()
    def pincode(self):
        self.pin=int(input())
        print("ENTER THE ACCOUNT NUMBER")
        self.acc_num()
    def acc_num(self):
        self.an=int(input())
        print("ENTER THE INITIAL DEPOSIT AMOUNT")
        self.idamount()
    def idamount(self):
        self.ida=int(input())
        self.detail(self.fn,self.ln,self.ci,self.st,self.pin,self.an,self.ida)
class cus(account):
    def detail(self,fn2,ln2,ci2,st2,pin2,an2,ida2):
        self.addi=fn2
        con=cx_Oracle.connect("VANITHA/12@127.0.0.1/XE")
        cur=con.cursor()
        sql = "insert into account VALUES('%s','%s','%s','%s','%d','%d','%d')" % (fn2,ln2,ci2,st2,pin2,an2,ida2)
        cur.execute(sql)
        con.commit()
        addi=fn2
        print("...........................CUSTOMER DETAILS..........................................")
        print(" ")
        print("ENTER TO SET CUSTOMER ID")
        self.getcustid()
    def getcustid(self):
        self.cusid=str(input())
        print("ENTER CUSTOMER NAME")
        self.custname()
    def custname(self):
        self.cusna=str(input())
        con=cx_Oracle.connect("VANITHA/12@127.0.0.1/XE")
        cur=con.cursor()
        sql = "insert into cus VALUES('%s','%s')" % (self.cusid,self.cusna)
        cur.execute(sql)
        con.commit()
class address(cus,account):
  def add(self):
    global val1
    global dis
    global idn
    print("ENTER THE CUSTOMER ID")
    idn=str(input())
    con=cx_Oracle.connect("VANITHA/12@127.0.0.1/XE")
    cur=con.cursor()
    sql ="select cusname from cus where cuid='%s'" % (idn)
    cur.execute(sql)
    valu=cur.fetchone()
    if valu is None:
      print("ID YOU ENTERED IS WRONG PLEASE ENTER THE VALID ID")
      vv=str(input())
      idn=vv
      sql = "select amount from cus where cusid='%s'" % (vv)
      cur.execute(sql)
      valu1=cur.fetchone()
      #hh=valu1[0]
      print("YOUR CURRENT BALANCE IS: ")
      print(valu1[0])
    else:
       sql = "select amount from cus where cusid='%s'" % (idn)
       cur.execute(sql)
       valu1=cur.fetchone()
       print("YOUR CURRENT BALANCE IS: ")
       print(valu1[0])
       print(" ")
class modify():
    def modify(self):
        print("ENTER THE ACCOUNT ID")
        j1=int(input())
        print(" ")
        print("PLEASE CHOOSE OPTION TO MODIFY")
        print("1.DEPOSIT")
        print("2.WITHDRAW")
        print("3.TRANSFER")
        vv=str(input())
        con=cx_Oracle.connect("VANITHA/12@127.0.0.1/XE")
        cur=con.cursor()
        if vv=="1":
            print("ENTER THE AMOUNT TO DEPOSIT")
            dep=int(input())
            dep1=int(valu1[0])+int(dep)
            sql="update account set initialdepamount='%s'where accountnumber='%s'"%(dep1,j1)
            cur.execute(sql)
        elif vv=="2":
            print("ENTER THE AMOUNT TO WITHDRAW")
            dep=int(input())
            dep1=int(valu1[0])-int(dep)
            sql="update account set initialdepamount='%s'where accountnumber='%s'"%(dep1,j1)
            cur.execute(sql)
        elif vv=="3":
            print("ENTER THE AMOUNT TO TRANSFER")
            dep=int(input())
            print("ENTER THE ACCOUNT NUMBER TO WHICH THE AMOUNT HAS TO BE TRANSFERED")
            acno=int(input())
            dep1=int(valu1[0])-int(dep)
            sql="update account set initialdepamount='%s'where accountnumber='%s'"%(dep1,j1)
            cur.execute(sql)
class demo():
    while(1):
        print(".................WELCOME TO TG BANK.................")
        print(" ")
        print("ALREADY HAVE AN ACCOUNT")
        j=str(input())
        print("     ")
        if j=="yes":
            print("............LOGIN WITH YOUR ACCOUNT.........")
            mm=address()
            mm.add()
            print(" ")
            print("DO YOU WANT TO ALTER THE DATABASE YES/NO :")
            hg=str(input())
            if hg=="yes":
                dd=modify()
                dd.modify()
            else:
                print("...............THANK YOU................")
                print(" ")
        else:
            print("CREATE ACCOUNT")
            mm=address()
            on=cus()
            on.acc()
        
