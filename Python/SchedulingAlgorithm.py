#Shortest-Job First & Priority Preepmtive program
class Task:
    def __init__(self, name, burst, arrival, prt):
        self.name = name
        self.burst = burst
        self.arrival = arrival
        self.prt = prt
        
def calAvg(wt, tat):
    #calculate average waiting and turn-around time
    totalWt = 0.0; totalTat = 0.0
    for i in range(len(wt)):
        totalWt+=wt[i]
        totalTat+=tat[i]
    totalWt/=len(wt)
    totalTat/=len(tat)
    return totalWt, totalTat

def printProcess(listA, wt, tat, path):
    #print process path
    print("\n=========================",
          "\nurutan penjadwalan")
    for i in path:
        print(i, end="->")
    print("end",
          "\n=========================")
    #print detail of process
    print("| Name \t\t| burst time \t| arrival\t|"
          +" priority \t| waiting time \t| turn-around time")
    for i in range(len(listA)):
        print("|%s\t\t|%i\t\t|%i\t\t|%i\t\t|%i\t\t|%i\t\t" 
              %(listA[i].name, listA[i].burst, listA[i].arrival,
                listA[i].prt, wt[i], tat[i]))
    #print average waiting time and turn-around time
    avgWt, avgTat = calAvg(wt, tat)
    print("\nAverage waiting time : %f" %(avgWt))
    print("Average turn-around time : %f" %(avgTat))

def ganttChart(listA, size, tipe):
    #declare variable
    minb = 99999 #shortest remaining burst time or high priority
    time = 0; done = 0
    index = 0; check = False
    bt = [] #burst time
    wt = [] #waiting time
    tat = [] #turn-around time
    path = [] #ganttChart

    for i in range(len(listA)):
           bt.append(listA[i].burst)
           wt.append(0)
           tat.append(0)
    while(done < size):
        for i in range(len(listA)):
            if(tipe == 1):
            #find the shortest-job in listA
                if((listA[i].arrival <= time) &
                     (bt[i]<minb) & (bt[i]>0)):
                    minb = bt[i]
                    index = i 
                    check = True
            elif(tipe == 2):
            #find the high priority(low number) in listA
                if((listA[i].arrival <= time) &
                   (listA[i].prt<minb) & (bt[i]>0)):
                    minb = listA[i].prt
                    index = i
                    check = True
            else:
                print("Input salah")
                return
        if check == False:
            #if don't find shortest-job
            path.append("idle")
            time+=1
            continue
        
        #process the shortest-job
        bt[index]-=1
        if tipe == 1:
            minb = bt[index]
        path.append(listA[index].name)
        if bt[index] == 0:
            #process[index] has done
            minb = 99999
            done+=1; check = False
            finish = time + 1
            #Calculate waiting time
            wt[index] = (finish - listA[index].burst 
                        - listA[index].arrival)
            #Calculate turn-around time
            tat[index] = (listA[index].burst + wt[index])
        time+=1
    printProcess(listA, wt, tat, path)



#Main program
size = int(input("jumlah proses(int) : "))
taskList = []
for i in range(size):
    task = Task((input("nama proses  : ")),
                int(input("burst time   : ")),
                int(input("arrival time : ")),
                int(input("prioritas    : ")))
    taskList.append(task)
print("Pilihan (preemptive): \n",
      "1. Shortest-job First\n",
      "2. Priority")
tipe = int(input("Pilihan : "))
ganttChart(taskList, size, tipe)
