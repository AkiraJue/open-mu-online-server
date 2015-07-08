# Introduction #

In this guide we will be setting up your omos server.


# Details #

To install omos you will need:
  * SQL Server 2000 ( http://download.microsoft.com/download/SQLSVR2000/Trial/2000/NT45/EN-US/SQLEVAL.exe ).
  * SVN Client (See source download guide).
  * WinRAR Archiver.
  * Notepad.

# Step 1-3 #

  * **STEP 1**: Download lastest source code from reposity (see source downloading guide).
  * **STEP 2**: Download microsoft sql server 2000.
  * **STEP 3**: Cofigure SQL password / Server IP in theese files.
    * CashShopServer/**CashShopOption.ini** - _Local IP_
    * CashShopServer/**AllowableIPList.txt** - _Local IP_
    * ConnectServer/Data/**ServerList.dat** - _Global IP_
    * DataServer1/**AllowableIPList.txt** - _Local IP_
    * DataServer2/**AllowableIPList.txt** - _Local IP_
    * EventServer/**svconfig.ini** - _SQL password_
    * ExDB/**ExDB.ini** - _SQL password_
    * RankingServer/**svconfig.ini** - _SQL password_
    * /Data/Lang/Jpn/**CommonLoc.cfg** - _Global IP_
    * /Data/Lang/Kor/**CommonLoc.cfg** - _Global IP_
    * /Data/**CommonServer.cfg** - _Local IP_
    * /Data/**IpList.dat** - _Local IP_
    * /Data/**MapServerInfo.dat** - _Global IP_

# Step 4-11 #

  * **STEP 4**: Unpack donwloaded sql server files (Commonly to c://SQLEVA).
  * **STEP 5**: Start Autorun.exe
  * **STEP 6**: Select SQL 2000 Server Components
  * **STEP 7**: Click Install Database Server
  * **STEP 8**: Click 8 Times Next Next . . .
  * **STEP 9**: Choose " Use Local System Account " Then Next.
  * **STEP 10**: Choose Mixed Mod "And Add your SQL Account Password" Press Next 2 Times ... Wait still its been Succesfully Installed.
  * **STEP 11**: Go to Start>Programm Files> Microsoft SQL Server > Service Manager > Put your PC Name ex: MY-PC , Then just start the Service Manager.

# Step 12- #

  * **STEP 12**: Go to Start> Programm Files>Microsoft SQL Server> Enterprise Manager and Open it.
  * **STEP 13**: Click Microsoft SQL Servers> SQL Server Group> (local) (Windows NT)
  * **STEP 14**: Open Databases > Right Click on Databases > New Database >
  * **STEP 15**: Now you have to make Databases ,
    * MuOnline,MuEvent,MuRanking
  * **STEP 16**: Then Make the Databases
  * **STEP 17**: Now Right Copy your Server Files to C:\ or D:\
  * **STEP 18**: Right Click On your Database you Made example: "MuOnline" > All Tasks> Restore Database> From Device > Select Device > Add > Then find on C:\ Or D:\ You Server Files and Open the File "dbbaks or DBBAKS"
Take MuOnline or Whatever Database your Restoring > Click OK 2 Times > Go to Options > Now u will See This

![http://img524.imageshack.us/img524/7842/thg.gif](http://img524.imageshack.us/img524/7842/thg.gif)


C:\Here Put The Place Which U Want To Restore Your Database\MuOnline\_Data.MDF

So if Your Files are on C:\
and name of your Files is "MuServer" Then put this on the line
C:\MuServer\DBBAKS or dbbaks\MuOnline\_Data.MDF
and under of the Line put This
C:\MuServer\DBBAKS or dbbaks\MuOnline\_Log.LDF

  * **STEP 19**: Then Just Tick the "Force Restore over existing database" and Press OK.