#!/usr/bin/env python
# coding: utf-8

# In[3]:


class Request:
    def __init__(self,input_name,input_start,input_end):
        self.name=input_name
        self.start=input_start
        self.end=input_end
r1=Request('A',2,3)
r2=Request('B',2,4)
r3=Request('C',1,4)
r4=Request('D',3,6)
r5=Request('E',6,7)
r6=Request('F',5,8)
r7=Request('G',7,9)
requests=[r1,r2,r3,r4,r5,r6,r7]
scheduled_requests = []
while len(requests)>0:
    earliest=requests[0]
    earliest_end=requests[0].end
    for request in requests:
        if request.end<earliest_end:
            earliest=request
            earliest_end=request.end
    print("Scheduling", earliest.name)
    scheduled_requests.append(earliest)
    unscheduled = list(requests)
    for request in requests:
        if request.start < earliest.end:
            unscheduled.remove(request)
    requests=unscheduled


# In[ ]:




