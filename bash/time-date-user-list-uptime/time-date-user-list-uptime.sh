#!/bin/sh

echo "\nShow the time and date, list all logged-in users, and give the system uptime. \nSave this information to a logfile\n"
LOGFILE=script.log

echo "\nCurrent date: `date`" > $LOGFILE
#echo "List of all logged-in users: \n `who` \n" >> $LOGFILE
echo "Uptime: `uptime` " >> $LOGFILE

exit 0
