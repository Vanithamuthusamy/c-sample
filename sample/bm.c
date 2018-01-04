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
        sql = "insert into account VALUES('%s','%s','%s','%s','%d','%d',%d')" % (fn2,ln2,ci2,st2,pin2,an2,ida2)
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
    con.commit()
class demo():
    while(1):
        print(".................WELCOME TO TG BANK.................")
        print(" ")
        print("ALREADY HAVE AN ACCOUNT")
        j=str(input())
        print("     ")
        if j=="yes":
            print("ok")
        else:
            print("CREATE ACCOUNT")
            on=cus()
            on.acc()
        
