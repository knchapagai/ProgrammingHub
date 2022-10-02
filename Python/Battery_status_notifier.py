#this program is designed to give a notification on windows laptops when battery chages completely
while(True):
    import psutil
    from win10toast import ToastNotifier
    battery = psutil.sensors_battery()
    p=battery.percent
    power=battery.power_plugged
    if int(p)>=100 and power==True:
        n = ToastNotifier()
        msg="Battery Status: "+str(p)+"%\nFull charged, Remove charger to save power."
        n.show_toast("Battery",msg , duration = 20,)