from tkinter import *
from tkinter import font, ttk, messagebox
from PIL import Image, ImageTk
import pymysql
import dbConfig

# Connect to Database
bank_db = pymysql.connect(
    host = dbConfig.DB_HOST,
    user = dbConfig.DB_USER,
    password = dbConfig.DB_PASSWORD,
    database = dbConfig.DB_NAME
)

# Getting the DB Cursor to execute Query 
my_cursor = bank_db.cursor()

# Accounts Table Name
accounts_Table = 'accounts'

# Add the main
my_cursor.execute(f"CREATE TABLE IF NOT EXISTS {accounts_Table} (name varchar(255), accno varchar(20), dob varchar(20), addr varchar(255), zip varchar(50), phone varchar(50), balance decimal(20,4), password varchar(255), id int AUTO_INCREMENT PRIMARY KEY)")


# Main Content Starts Here :-
root = Tk()
root.title("Bank Management")
root.resizable(width=False, height=False)

photo = PhotoImage(file = "./bankicon.png")
root.iconphoto(True, photo)
months = ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun','Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec')

def myfont(s):
    return ("Poppins",s, font.BOLD)

def getaccno(id, ff, lf):
    return "MYB" + str(ord(ff.upper()) + ord(lf.upper()) - 128).zfill(2) +id.zfill(3)

# Defining all the FUnctions
def createAcc():
    createWindow = Tk()
    createWindow.title("Create Account - MyBank")

    fnameLabel = Label(createWindow, text="First Name").grid(row=0, column=0, sticky=E)
    fname = Entry(createWindow, width=30)
    fname.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)

    lnameLabel = Label(createWindow, text="Last Name").grid(row=1, column=0, sticky=E)
    lname = Entry(createWindow, width=30)
    lname.grid(row=1, column=1, columnspan=3, sticky=W, padx=10)

    addrLabel = Label(createWindow, text="Address").grid(row=2, column=0, sticky=E)
    addr = Entry(createWindow, width=30)
    addr.grid(row=2, column=1, columnspan=3, sticky=W, padx=10)

    zipLabel = Label(createWindow, text="ZipCode").grid(row=3, column=0, sticky=E)
    zip = Entry(createWindow, width=30)
    zip.grid(row=3, column=1, columnspan=3, sticky=W, padx=10)

    dobLabel = Label(createWindow, text="Date Of Birth").grid(row=4, column=0, sticky=E)

    dobd = ttk.Combobox(createWindow, width=6)
    dobd['values'] = tuple(range(1, 32))
    dobd['state'] = 'readonly'
    dobd.current(0)
    dobd.grid(row=4, column=1, sticky=E)

    dobm = ttk.Combobox(createWindow, width=6)
    dobm['values'] = months
    dobm['state'] = 'readonly'
    dobm.current(0)
    dobm.grid(row=4, column=2)

    doby = ttk.Combobox(createWindow, width=8)
    doby['values'] = tuple(range(2021, 1959, -1))
    doby['state'] = 'readonly'
    doby.current(0)
    doby.grid(row=4, column=3, sticky=W)


    phoneLabel = Label(createWindow, text="Phone No.").grid(row=5, column=0, sticky=E)
    phone = Entry(createWindow, width=30)
    phone.grid(row=5, column=1, columnspan=3, sticky=W, padx=10)

    balanceLabel = Label(createWindow, text="Initial Amount").grid(row=6, column=0, sticky=E)
    balance = Entry(createWindow, width=30)
    balance.grid(row=6, column=1, columnspan=3, sticky=W, padx=10)

    passwordLabel = Label(createWindow, text="Password").grid(row=7, column=0, sticky=E)
    password = Entry(createWindow, show='*', width=30)
    password.grid(row=7, column=1, columnspan=3, padx=10)

    def create(reslab):
        
        fn, ln = fname.get().strip(),lname.get().strip()
        ad, zipc = addr.get().strip(), zip.get().strip() 
        ph, inibal, pw = phone.get().strip(), balance.get().strip(), password.get().strip()

        if(len(fn) and len(ln) and len(ad) and len(zipc) and len(ph) and len(inibal) and len(pw)):
            sql_command = "INSERT INTO accounts (name, dob, addr, zip, phone, balance, password) VALUES (%s,%s,%s,%s,%s,%s,%s)"

            dob = str(dobd.get()).zfill(2) + "/" + str(months.index(dobm.get())+1).zfill(2) + '/' + str(doby.get())

            values = (
                fn + " " + ln,
                dob,
                ad,
                zipc,
                ph,
                inibal,
                pw
            )
            my_cursor.execute(sql_command, values)
            bank_db.commit()
            new_id = my_cursor.lastrowid
            accountNo = getaccno(str(new_id), fn[0], ln[0])

            sql = "UPDATE accounts SET accno = %s WHERE id = %s"
            val = (accountNo, new_id)

            my_cursor.execute(sql, val)
            bank_db.commit()
               
            reslab.configure(text="Account Successfully Created !!\nYour Account No. is " + accountNo)
            reslab.configure(fg="green")

            fname.delete(0, END)
            lname.delete(0, END)
            addr.delete(0, END)
            zip.delete(0, END)
            password.delete(0, END)
            phone.delete(0, END)
            balance.delete(0, END)
            
            dobd.current(0)
            dobm.current(0)
            doby.current(0)

        else:
            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")
            
    createSubmit = Button(createWindow, text="Create Account", command=lambda: create(resultLabel))
    createSubmit.grid(row=8, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

    resultLabel = Label(createWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=9, column=0, columnspan=4, padx=10, pady=10)

    createWindow.mainloop()

def deposit():
    depoWindow = Tk()
    depoWindow.title("Deposit Money - MyBank")

    global resultLabel
    accnoLabel = Label(depoWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(depoWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    depositAmtLabel = Label(depoWindow, text="Deposit Amount").grid(row=1, column=0, sticky=E)
    depositAmt = Entry(depoWindow, width=30)
    depositAmt.grid(row=1, column=1, sticky=W, padx=10)

    passwordLabel = Label(depoWindow, text="Password").grid(row=2, column=0, sticky=E)
    password = Entry(depoWindow, show='*', width=30)
    password.grid(row=2, column=1, sticky=W, padx=10)

    def depositMoney(reslab):
        acc, dep, pwd = accno.get().strip(), depositAmt.get().strip(), password.get().strip()

        if len(acc) and len(dep) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2]:
                sql = "UPDATE accounts SET balance = %s WHERE id = %s"
                val = (float(res[0][-3]) + float(dep), res[0][-1])

                my_cursor.execute(sql, val)
                bank_db.commit()

                reslab.configure(text="Deposit of Rs. "+ dep +" Successful !!")
                reslab.configure(fg="green")

                accno.delete(0, END)
                password.delete(0, END)
                depositAmt.delete(0, END)
                
        else:
            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    depoSubmit = Button(depoWindow, text="Deposit Now", command=lambda: depositMoney(resultLabel))
    depoSubmit.grid(row=3, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(depoWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=9, column=0, columnspan=2, padx=10, pady=10)

    depoWindow.mainloop()

def withdraw():
    withdrawWindow = Tk()
    withdrawWindow.title("Withdraw Money - MyBank")

    global resultLabel
    accnoLabel = Label(withdrawWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(withdrawWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    withdrawAmtLabel = Label(withdrawWindow, text="Withdraw Amount").grid(row=1, column=0, sticky=E)
    withdrawAmt = Entry(withdrawWindow, width=30)
    withdrawAmt.grid(row=1, column=1, sticky=W, padx=10)

    passwordLabel = Label(withdrawWindow, text="Password").grid(row=2, column=0, sticky=E)
    password = Entry(withdrawWindow, show='*', width=30)
    password.grid(row=2, column=1, sticky=W, padx=10)

    def withdrawMoney(reslab):
        acc, wdr, pwd = accno.get().strip(), withdrawAmt.get().strip(), password.get().strip()

        if len(acc) and len(wdr) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            bal = float(res[0][-3]) - float(wdr)

            if len(res) == 1 and pwd == res[0][-2] and bal < 0:
                reslab.configure(text="Oops, Insufficient Balance !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2] and bal >= 0:
                sql = "UPDATE accounts SET balance = %s WHERE id = %s"
                val = (bal, res[0][-1])

                my_cursor.execute(sql, val)
                bank_db.commit()

                reslab.configure(text="Rs. "+ wdr +" Withdrawn Successful !!")
                reslab.configure(fg="green")

                accno.delete(0, END)
                password.delete(0, END)
                withdrawAmt.delete(0, END)
                
        else:
            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    withdrawSubmit = Button(withdrawWindow, text="Withdraw Now", command=lambda: withdrawMoney(resultLabel))
    withdrawSubmit.grid(row=3, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(withdrawWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=9, column=0, columnspan=2, padx=10, pady=10)

    withdrawWindow.mainloop()

def details():
    detailsWindow = Tk()
    detailsWindow.title("Show Details - MyBank")

    accnoLabel = Label(detailsWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(detailsWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    passwordLabel = Label(detailsWindow, text="Password").grid(row=1, column=0, sticky=E)
    password = Entry(detailsWindow, show='*', width=30)
    password.grid(row=1, column=1, sticky=W, padx=10)

    def show(reslab, resFrame):
        acc, pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")

                if len(detailsWindow.grid_slaves(row=4, column=0)):
                    detailsWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")

                if len(detailsWindow.grid_slaves(row=4, column=0)):
                    detailsWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                
                return

            if len(res) == 1 and pwd == res[0][-2]:

                reslab.configure(text="__REQUESTED DETAILS__")
                reslab.configure(fg="green")
                
                if len(detailsWindow.grid_slaves(row=4, column=0)):
                    detailsWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                
                labs = ["NAME", "ACCOUNT NO.", "DATE OF BIRTH", "ADDRESS", "PINCODE","CONTACT NO.", "Cur. BALANCE"]
                resFrame = Frame(detailsWindow)
                            
                for i in range(len(labs)):
                    curLabel = Label(resFrame, text=labs[i], bd=5).grid(row=i, column=0)
                    cur = Label(resFrame, text=res[0][i], bd=5).grid(row=i, column=1)

                resFrame.grid(row=4, column=0, columnspan=2, pady=10)

                accno.delete(0, END)
                password.delete(0, END)

        else:
            if len(detailsWindow.grid_slaves(row=4, column=0)):
                detailsWindow.grid_slaves(row=4, column=0)[0].grid_forget()

            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    resFrame = Frame(detailsWindow)

    detailsSubmit = Button(detailsWindow, text="Show Details", command=lambda: show(resultLabel, resFrame))
    detailsSubmit.grid(row=2, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(detailsWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

    detailsWindow.mainloop()

def balanceEnq():
    balanceEnqWindow = Tk()
    balanceEnqWindow.title("Know Your Balance - MyBank")

    accnoLabel = Label(balanceEnqWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(balanceEnqWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    passwordLabel = Label(balanceEnqWindow, text="Password").grid(row=1, column=0, sticky=E)
    password = Entry(balanceEnqWindow, show='*', width=30)
    password.grid(row=1, column=1, sticky=W, padx=10)

    def knowBal(reslab):
        acc, pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")

                if len(balanceEnqWindow.grid_slaves(row=4, column=0)):
                    balanceEnqWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")

                if len(balanceEnqWindow.grid_slaves(row=4, column=0)):
                    balanceEnqWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                
                return

            if len(res) == 1 and pwd == res[0][-2]:

                reslab.configure(text="__REQUESTED DETAILS__")
                reslab.configure(fg="green")
                
                if len(balanceEnqWindow.grid_slaves(row=4, column=0)):
                    balanceEnqWindow.grid_slaves(row=4, column=0)[0].grid_forget()
                            
                balLabel = Label(balanceEnqWindow, text="BALANCE = Rs."+ str(res[0][-3]), font=myfont(17))
                balLabel.grid(row=4, column=0, columnspan=2, pady=10)

                accno.delete(0, END)
                password.delete(0, END)

        else:
            if len(balanceEnqWindow.grid_slaves(row=4, column=0)):
                balanceEnqWindow.grid_slaves(row=4, column=0)[0].grid_forget()

            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    balanceEnqSubmit = Button(balanceEnqWindow, text="Get My Balance", command=lambda: knowBal(resultLabel))
    balanceEnqSubmit.grid(row=2, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(balanceEnqWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

    balanceEnqWindow.mainloop()

def updateAcc():
    updateWindow = Tk()
    updateWindow.title("Update Account - MyBank")

    accLabel = Label(updateWindow, text="Account No.").grid(row=0, column=0, sticky=E)
    accno = Entry(updateWindow, width=30)
    accno.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)

    passwordLabel = Label(updateWindow, text="Password").grid(row=1, column=0, sticky=E)
    password = Entry(updateWindow, show='*', width=30)
    password.grid(row=1, column=1, columnspan=3, padx=10)

    def find_Update(reslab):
        acc, pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2]:
                reslab.configure(text="UPDATE WINDOW is Open to Edit")
                reslab.configure(fg="darkgreen")

                upd = Frame(updateWindow)

                accNoLabel = Label(upd, text="Account No.").grid(row=0, column=0, sticky=E)
                accNo = Label(upd, text=acc)
                accNo.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)
                
                name = res[0][0].split(' ')

                fnameLabel = Label(upd, text="First Name").grid(row=1, column=0, sticky=E)
                fname = Entry(upd, width=30)
                fname.insert(0, name[0])
                fname.grid(row=1, column=1, columnspan=3, sticky=W, padx=10)

                lnameLabel = Label(upd, text="Last Name").grid(row=2, column=0, sticky=E)
                lname = Entry(upd, width=30)
                lname.insert(0, name[1])
                lname.grid(row=2, column=1, columnspan=3, sticky=W, padx=10)

                addrLabel = Label(upd, text="Address").grid(row=3, column=0, sticky=E)
                addr = Entry(upd, width=30)
                addr.insert(0, res[0][3])
                addr.grid(row=3, column=1, columnspan=3, sticky=W, padx=10)

                zipLabel = Label(upd, text="ZipCode").grid(row=4, column=0, sticky=E)
                zip = Entry(upd, width=30)
                zip.insert(0, res[0][4])
                zip.grid(row=4, column=1, columnspan=3, sticky=W, padx=10)

                dobLabel = Label(upd, text="Date Of Birth").grid(row=5, column=0, sticky=E)

                dob_arr = res[0][2].split('/')
                dob_arr = list(map(int, dob_arr))

                dobd = ttk.Combobox(upd, width=6)
                dobd['values'] = tuple(range(1, 32))
                dobd['state'] = 'readonly'
                dobd.current(dob_arr[0]-1)
                dobd.grid(row=5, column=1, sticky=E)

                dobm = ttk.Combobox(upd, width=6)
                dobm['values'] = months
                dobm['state'] = 'readonly'
                dobm.current(dob_arr[1]-1)
                dobm.grid(row=5, column=2)

                doby = ttk.Combobox(upd, width=8)
                doby['values'] = tuple(range(2021, 1959, -1))
                doby['state'] = 'readonly'
                print(dob_arr)
                doby.current(2021-dob_arr[2])
                doby.grid(row=5, column=3, sticky=W)

                phoneLabel = Label(upd, text="Phone No.").grid(row=6, column=0, sticky=E)
                phone = Entry(upd, width=30)
                phone.grid(row=6, column=1, columnspan=3, sticky=W, padx=10)
                phone.insert(0, res[0][-4])

                def update(reslab1):
                    
                    fn, ln = fname.get().strip(),lname.get().strip()
                    ad, zipc = addr.get().strip(), zip.get().strip() 
                    ph = phone.get().strip()

                    if(len(fn) and len(ln) and len(ad) and len(zipc) and len(ph)):
                        sql_command = "UPDATE accounts SET name = %s, dob = %s, addr = %s, zip = %s, phone = %s WHERE id = %s"

                        dob = str(dobd.get()).zfill(2) + "/" + str(months.index(dobm.get())+1).zfill(2) + '/' + str(doby.get())

                        values = (
                            fn + " " + ln,
                            dob,
                            ad,
                            zipc,
                            ph,
                            res[0][-1]
                        )
                        my_cursor.execute(sql_command, values)
                        bank_db.commit()

                        reslab.configure(text="Account "+ res[0][1] +" Updated Succesfully!!")
                        reslab.configure(fg="green")

                        accno.delete(0,END)
                        password.delete(0,END)

                        upd.destroy()
                    else:
                        reslab1.configure(text="Details Can't be Updated As Blank!!")
                        reslab1.configure(fg="red")

                updateSubmit = Button(upd, text="Update Details", command=lambda: update(resultLabel1))
                updateSubmit.grid(row=7, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

                resultLabel1 = Label(upd, text="Results Will Be Shown Here", fg="blue")
                resultLabel1.grid(row=8, column=0, columnspan=4, padx=10, pady=10)

                upd.grid(row=4, column=0, columnspan=4, pady=10)
        else:
            reslab.configure(text = "Fill All Details")
            reslab.configure(fg = "red")
            
    findSubmit = Button(updateWindow, text="Find Account to Update", command=lambda: find_Update(resultLabel))
    findSubmit.grid(row=2, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

    resultLabel = Label(updateWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=3, column=0, columnspan=4, padx=10, pady=10)

    updateWindow.mainloop()

def closeAcc():
    closeWindow = Tk()
    closeWindow.title("Close Account - MyBank")

    global resultLabel
    accnoLabel = Label(closeWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(closeWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    passwordLabel = Label(closeWindow, text="Password").grid(row=2, column=0, sticky=E)
    password = Entry(closeWindow, show='*', width=30)
    password.grid(row=2, column=1, sticky=W, padx=10)

    def deleteAcc(reslab):
        acc,pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2]:

                accno.delete(0, END)
                password.delete(0, END)

                sure = messagebox.askyesno("Warning - MyBank", "Your Account Will be Permenantly Deleted. Are You Sure to Close This Account?")
                if not sure:
                    return

                sql = "DELETE FROM accounts WHERE id = %s"
                val = (res[0][-1],)

                my_cursor.execute(sql, val)
                bank_db.commit()

                reslab.configure(text="Account "+ res[0][1] +" Closed Forever!!")
                reslab.configure(fg="green")
                
                
        else:
            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    closeSubmit = Button(closeWindow, text="Delete Account", command=lambda: deleteAcc(resultLabel))
    closeSubmit.grid(row=3, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(closeWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=9, column=0, columnspan=2, padx=10, pady=10)

    closeWindow.mainloop()

def changePassword():
    cpWindow = Tk()
    cpWindow.title("Change Password - MyBank")

    accLabel = Label(cpWindow, text="Account No.").grid(row=0, column=0, sticky=E)
    accno = Entry(cpWindow, width=30)
    accno.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)

    passwordLabel = Label(cpWindow, text="Password").grid(row=1, column=0, sticky=E)
    password = Entry(cpWindow, show='*', width=30)
    password.grid(row=1, column=1, columnspan=3, padx=10)

    def find_Update(reslab):
        acc, pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2]:
                reslab.configure(text="__UPDATE PASSWORD HERE__")
                reslab.configure(fg="darkgreen")

                upd = Frame(cpWindow)

                newPwdLabel = Label(upd, text="New Password").grid(row=0, column=0, sticky=E)
                newPwd = Entry(upd, show='*')
                newPwd.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)

                confirmPwdLabel = Label(upd, text="Confirm Password").grid(row=1, column=0, sticky=E)
                confirmPwd = Entry(upd, show='*')
                confirmPwd.grid(row=1, column=1, columnspan=3, sticky=W, padx=10)

                def update(reslab1):
                    
                    np, cnp = newPwd.get().strip(),confirmPwd.get().strip()

                    if len(np) and len(cnp) and (np == cnp == res[0][-2]):
                        reslab1.configure(text="New Password and Current Password can't be Same !!")
                        reslab1.configure(fg="red")

                    elif len(np) and len(cnp) and (np == cnp):
                        sql_command = "UPDATE accounts SET password = %s WHERE id = %s"
                        values = (np, res[0][-1])

                        my_cursor.execute(sql_command, values)
                        bank_db.commit()

                        reslab.configure(text="Password Updated Succesfully!!")
                        reslab.configure(fg="green")

                        accno.delete(0,END)
                        password.delete(0,END)

                        upd.destroy()

                    elif len(np) and len(cnp) and (np != cnp):
                        reslab1.configure(text="Confirm Password Doesn't Match")
                        reslab1.configure(fg="red")

                    else:
                        reslab1.configure(text="Details Can't be Updated As Blank!!")
                        reslab1.configure(fg="red")

                updateSubmit = Button(upd, text="Update Details", command=lambda: update(resultLabel1))
                updateSubmit.grid(row=2, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

                resultLabel1 = Label(upd, text="Results Will Be Shown Here", fg="blue")
                resultLabel1.grid(row=3, column=0, columnspan=4, padx=10, pady=10)

                upd.grid(row=4, column=0, columnspan=4, pady=10)
        else:
            reslab.configure(text = "Fill All Details")
            reslab.configure(fg = "red")
            
    findSubmit = Button(cpWindow, text="Find Account", command=lambda: find_Update(resultLabel))
    findSubmit.grid(row=2, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

    resultLabel = Label(cpWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=3, column=0, columnspan=4, padx=10, pady=10)

    cpWindow.mainloop()

def transfer():
    transWindow = Tk()
    transWindow.title("Money Transfer - MyBank")

    global resultLabel
    accnoLabel = Label(transWindow, text="Account Number").grid(row=0, column=0, sticky=E)
    accno = Entry(transWindow, width=30)
    accno.grid(row=0, column=1, sticky=W, padx=10)

    passwordLabel = Label(transWindow, text="Password").grid(row=1, column=0, sticky=E)
    password = Entry(transWindow, show='*', width=30)
    password.grid(row=1, column=1, sticky=W, padx=10)

    def findAcc(reslab):
        acc, pwd = accno.get().strip(), password.get().strip()

        if len(acc) and len(pwd):
            sql = "SELECT * FROM accounts WHERE accno = %s"
            my_cursor.execute(sql, (acc,))
            res = my_cursor.fetchall()

            if not len(res):
                reslab.configure(text="This Account No. Doesn't Exist !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd != res[0][-2]:
                reslab.configure(text="Invalid Password !!")
                reslab.configure(fg="red")
                return

            if len(res) == 1 and pwd == res[0][-2]:
                reslab.configure(text="You Are ALLOWED to TRANSFER Money")
                reslab.configure(fg="darkgreen")

                upd = Frame(transWindow)

                transferAccLabel = Label(upd, text="Recipient Account").grid(row=0, column=0, sticky=E)
                transferAcc = Entry(upd)
                transferAcc.grid(row=0, column=1, columnspan=3, sticky=W, padx=10)

                transferAmtLabel = Label(upd, text="Tranfer Amount").grid(row=1, column=0, sticky=E)
                transferAmt = Entry(upd)
                transferAmt.grid(row=1, column=1, columnspan=3, sticky=W, padx=10)

                def moneyTransfer(reslab1):
                    
                    rec, amt = transferAcc.get().strip(), transferAmt.get().strip()
                    
                    if len(rec) and len(amt):
                        sql = "SELECT * FROM accounts WHERE accno = %s"
                        my_cursor.execute(sql, (rec,))
                        recDetails = my_cursor.fetchall()
                        mybal = float(res[0][-3]) - float(amt)

                        if not len(recDetails):
                            reslab1.configure(text="Recipient's Account Doesn't Exist!!")
                            reslab1.configure(fg="red")

                        elif mybal < 0:
                            reslab1.configure(text="Low Balance!! Unable to Meet the Transfer Amount")
                            reslab1.configure(fg="red")

                        else:
                            sql_command = "UPDATE accounts SET balance = %s WHERE id = %s"
                            
                            values = (mybal, res[0][-1])
                            my_cursor.execute(sql_command, values)
                            bank_db.commit()

                            values = (float(recDetails[0][-3]) + float(amt), recDetails[0][-1])
                            my_cursor.execute(sql_command, values)
                            bank_db.commit()

                            reslab.configure(text="Money Transfer Succesful !!")
                            reslab.configure(fg="green")

                            accno.delete(0,END)
                            password.delete(0,END)

                            upd.destroy()
                    else:
                        reslab1.configure(text ="Fill All Details !!")
                        reslab1.configure(fg = "red")

                transferSubmit = Button(upd, text="Transfer Money", command=lambda: moneyTransfer(resultLabel1))
                transferSubmit.grid(row=2, column=0, columnspan=4, padx=10, pady=10, ipadx=100)

                resultLabel1 = Label(upd, text="Results Will Be Shown Here", fg="blue")
                resultLabel1.grid(row=3, column=0, columnspan=4, padx=10, pady=10)

                upd.grid(row=4, column=0, columnspan=4, pady=10)
                
        else:
            reslab.configure(text="Fill All Details!!")
            reslab.configure(fg="red")

    withdrawSubmit = Button(transWindow, text="Validate Account", command=lambda: findAcc(resultLabel))
    withdrawSubmit.grid(row=2, column=0, columnspan=2, padx=10, pady=10, ipadx=100)

    resultLabel = Label(transWindow, text="Results Will Be Shown Here", fg="blue")
    resultLabel.grid(row=3, column=0, columnspan=2, padx=10, pady=10)

    transWindow.mainloop()


# Building the GUI
title_bar = Label(root, text="Welcome to MyBank", font=myfont(16))
title_bar.grid(row=0, column=0, sticky=E)

photo = Image.open("bankicon.png").resize((40, 40))
photo = ImageTk.PhotoImage(photo)

canvas = Canvas(root, width=50, height=50)
canvas.grid(row=0, column=1, sticky=W)
canvas.create_image(0,0,anchor=NW, image=photo)

createBtn = Button(root, text="CREATE Account".center(40),bd=5, command=createAcc)
createBtn.grid(row=1, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

depositBtn = Button(root, text="DEPOSIT Money".center(40),bd=5, command=deposit)
depositBtn.grid(row=2, column=0,columnspan=2, padx=12, pady=10, ipadx=20)

withdrawBtn = Button(root, text="WITHDRAW Money".center(40),bd=5, command=withdraw)
withdrawBtn.grid(row=3, column=0,columnspan=2, padx=12, pady=10, ipadx=20)

detailsBtn = Button(root, text="DISPLAY Account Details".center(40),bd=5, command=details)
detailsBtn.grid(row=4, column=0,columnspan=2, padx=2, pady=10, ipadx=20)

balanceBtn = Button(root, text="BALANCE Enquiry".center(40),bd=5, command=balanceEnq)
balanceBtn.grid(row=5, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

updateBtn = Button(root, text="UPDATE Details".center(40),bd=5, command=updateAcc)
updateBtn.grid(row=6, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

changePwdBtn = Button(root, text="CHANGE PASSWORD".center(40),bd=5, command=changePassword)
changePwdBtn.grid(row=7, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

transferBtn = Button(root, text="TRANSFER Money".center(40),bd=5, command=transfer)
transferBtn.grid(row=8, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

closeBtn = Button(root, text="CLOSE Account".center(40),bd=5, command=closeAcc)
closeBtn.grid(row=9, column=0,columnspan=2, padx=10, pady=10, ipadx=20)

copyrightLabel = Label(root, text="Copyright @Rahul Roy | All Rights Reserved", font=myfont(10))
copyrightLabel.grid(row=10, column=0,columnspan=2, padx=10, pady=10, ipadx=90)

root.mainloop()